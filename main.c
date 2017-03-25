#include <xc.h>
#include <stdio.h>
#include <string.h>
#include "config.h"
#include "constants.h"
#include "i2c.h"
#include "usart.h"
#include "ad.h"
#include "timer0.h"


void read_RTC_I2c(unsigned char pos_memoria);

bit hasAnError = 0;
unsigned char receivedData = 'X';
unsigned char leitura = 0;

//TIMER variables
unsigned short int maxContCycle = 0;
unsigned short int val = 0;

//LEDS
bit changingLed_VSYNC = 0;
bit changingLed1 = 0;
//dado recebido
unsigned char data;
//chegou um pixel pelo I2C
//bit send = 0;
//acabou de enviar uma imagem completa
bit finish = 0;
//existe uma foto requisitada
bit requisitar_foto = 0;
//tamanho da imagem recebida
unsigned char comprimento = 0;
unsigned char largura = 0;
//tamanho da imagem já recebida


void interrupt interruptions(void){
    //USART
    if (RCIF){
        //checking for framing and overrun erros
        if (FERR || OERR){
            CREN = 0; //if an error occur, clear the error desabling the reciever
            hasAnError = 1;
            CREN = 1;
        }
        receivedData = RCREG;        
    }
    //TIMER0
    if(INTCONbits.TMR0IF){
        val++;       
        INTCONbits.TMR0IF = 0;        
    }
    //PORTB
    if(INTCONbits.RBIF){
        //borda de subida VSYNC, novo quadro chegando
        if(VSYNC){
            //foto requisitada
            if(requisitar_foto){
                WRITE_ENABLE = 1;
                requisitar_foto = 0;
            }                        
            changingLed_VSYNC = ~changingLed_VSYNC;
            LED_VSYNC = changingLed_VSYNC;
        }
        //buffer encheu, deu merda. Verifica se realmente FULL == 1
        if(FULL){
            //OQ DEVO FAZER SE A FIFO ENCHER????
            //TODO
            LED_FIFO_FULL = 1;
            READ_RESET = 1;
            WRITE_RESET = 1;
            __delay_ms(20);
            READ_RESET = 0;
            WRITE_RESET = 0;
            LED_FIFO_FULL = 0;
        }
        INTCONbits.RBIF = 0;        
    }
}

void setMaxContCycle(unsigned short int secondsInACycle){
    maxContCycle = (int)(secondsInACycle/Timer0_SecondsInACycle);
}

void writeOV7670_I2c(){
    I2C_Idle(); //Verifica e aguarda até o barramento I2C estar disponível.
    I2C_Start(); //Inicializa a comunicação I2c
    
    I2C_Idle(); 
    I2C_Write_Byte(0xD0); // End. fixo para DS1307: 1101000X, onde x = 0 é para gravação.
    I2C_Idle(); //Verifica e aguarda até o barramento I2C estar disponível.
    I2C_Write_Byte(0x00); // End. onde começa a programação do relógio, end. dos segundos.
    I2C_Idle(); //Verifica e aguarda até o barramento I2C estar disponível.
    I2C_Write_Byte(0x00); // Inicializa com 00 segundos.
    I2C_Idle(); //Verifica e aguarda até o barramento I2C estar disponível.
    I2C_Write_Byte(0x08); // Inicializa com 8 minutos.
    I2C_Idle(); //Verifica e aguarda até o barramento I2C estar disponível.
    I2C_Write_Byte(0x08); // Inicializa com 08:00hs (formato 24 horas).
    I2C_Idle(); //Verifica e aguarda até o barramento I2C estar disponível.
    I2C_Write_Byte(0x04); // Inicializa com terça
    I2C_Idle(); //Verifica e aguarda até o barramento I2C estar disponível.
    I2C_Write_Byte(0x17); // Inicializa com dia 17
    I2C_Idle(); //Verifica e aguarda até o barramento I2C estar disponível.
    I2C_Write_Byte(0x04); // Inicializa com mês 04
    I2C_Idle(); //Verifica e aguarda até o barramento I2C estar disponível.
    I2C_Write_Byte(0x13); // Inicializa com ano 13
    I2C_Idle(); //Verifica e aguarda até o barramento I2C estar disponível.
    
    I2C_Stop(); //Finaliza a comunicação I2c
}


void configPortBInterrupt(){
    INTCONbits.RBIE = 1;
    INTCONbits.RBIF = 0;    
    INTCONbits.GIE = 1;
    INTCONbits.PEIE = 1;
}

void configPinsOV7670(){
    WRITE_RESET = 1;            //RESETA O BUFFER DE ESCRITA
    READ_RESET = 1;             //RESETA O BUFFER DE LEITURA
    WRITE_ENABLE = 0;           //NÃO PODE ESCREVER NA FIFO AINDA
    READ_ENABLE = 1;            //PODE LER DA FIFO
    READ_CLOCK = 0;             //CLOCK 0
    LED_FINISH_FRAME = 0;       //NÃO TERMINOU NENHUM FRAME
    LED_VSYNC = 0;              //NÃO RECEBEU NENHUM VSYNC
    __delay_us(10);
    WRITE_RESET = 0;
    READ_RESET = 0;
}

void main(void){
    //PODE GERAR RBIF
    TRISBbits.RB7 = 1;      //VSYNC
    TRISBbits.RB6 = 0;      //LED VSYNC
    TRISBbits.RB5 = 1;      //FULL
    TRISBbits.RB4 = 0;      //WRITE ENABLE
    //NÃO PODE GERAR RBIF
    TRISBbits.RB3 = 1;      //EMPTY
    TRISBbits.RB2 = 0;      //LED FINISH FRAME
    TRISCbits.RC2 = 0;      //READ ENABLE
    TRISCbits.RC1 = 0;      //READ CLOCK
    TRISCbits.RC0 = 0;      //READ RESET
    TRISEbits.RE0 = 0;      //WRITE RESET
    TRISEbits.RE1 = 0;      //LED FIFO FULL
    
    //PORTD, PIXEL
    TRISD = 0;              //TUDO ENTRADA DO PIXEL
    
    
    //timer
    configTimer();
    setMaxContCycle(30);
 
    //usart
    configRS232();
    configUSARTInterrupts();
                
    //I2C
    InitI2C_Master();
    
    //interrupts
    configPortBInterrupt();

    //CONFIG CAMERA
    writeOV7670_I2c();
    configPinsOV7670();

    while(1){
        //FIFO ESTÁ VAZIA, TEM PIXEL PARA PEGAR
        if(!EMPTY){
            //REQUISITAR PIXEL
            __delay_us(1);
            READ_CLOCK = 1;
            __delay_us(1);
            READ_CLOCK = 0;
            //PIXEL PRONTO
            data = PIXEL_OUT;
            putch(data);            
        }
        //FIFO ESTÁ VAZIA, NÃO TEM PIXEL
        if(EMPTY){
            LED_FINISH_FRAME = 1;
            __delay_ms(10);
        }                        
        //CONTADOR PARA REQUISITAR IMAGEM
        if(val == maxContCycle){
            //REQUISITAR FOTO
            requisitar_foto = 1;            
            val = 0;                  
        }
    }
}