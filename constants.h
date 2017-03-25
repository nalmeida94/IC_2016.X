/* 
 * File:   constants.h
 * Author: Nathan
 * Created on 30 de Novembro de 2015, 20:46
 */
#ifndef CONSTANTS_H
#define	CONSTANTS_H

#ifdef	__cplusplus
extern "C" {
#endif
#ifdef	__cplusplus
}
#endif
#endif	/* CONSTANTS_H */

//LEDS
#define LED_VSYNC           PORTBbits.RB6
#define LED_FINISH_FRAME    PORTBbits.RB2
#define LED_FIFO_FULL       PORTEbits.RE1
//CAM OUTPUTS
#define VSYNC               PORTBbits.RB7
#define PIXEL_OUT           PORTD
//#define HREF                PORTBbits.RB3
//FIFO OUTPUTS
#define EMPTY               PORTBbits.RB3
#define FULL                PORTBbits.RB5
//FIFO INPUTS
#define WRITE_ENABLE        PORTBbits.RB4
#define READ_ENABLE         PORTCbits.RC2
#define READ_CLOCK          PORTCbits.RC1
#define READ_RESET          PORTCbits.RC0
#define WRITE_RESET         PORTEbits.RE0


//FORMAT SIZES
#define VGA_COMPRIMENTO     640
#define VGA_LARGURA         480
#define QVGA_COMPRIMENTO    320
#define QVGA_LARGURA        240
#define CIF_COMPRIMENTO     352
#define CIF_LARGURA         288
#define QCIF_COMPRIMENTO    176
#define QCIF_LARGURA        144
