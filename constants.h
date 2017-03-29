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
#define LED_VSYNC               PORTBbits.RB6
#define LED_FINISH_FRAME        PORTBbits.RB2
#define LED_FIFO_FULL           PORTEbits.RE1
//CAM OUTPUTS
#define VSYNC                   PORTBbits.RB7
#define PIXEL_OUT               PORTD
//#define HREF                    PORTBbits.RB3
//FIFO OUTPUTS
#define EMPTY                   PORTBbits.RB3
#define FULL                    PORTBbits.RB5
//FIFO INPUTS
#define WRITE_ENABLE_NEG        PORTBbits.RB4
#define READ_ENABLE_NEG         PORTCbits.RC2
#define READ_CLOCK              PORTCbits.RC1
#define READ_RESET_NEG          PORTCbits.RC0
#define WRITE_RESET_NEG         PORTEbits.RE0
#define OUTPUT_ENABLE_NEG       PORTEbits.RE2


//FORMAT SIZES
#define VGA_COMPRIMENTO         640
#define VGA_LARGURA             480
#define QVGA_COMPRIMENTO        320
#define QVGA_LARGURA            240
#define CIF_COMPRIMENTO         352
#define CIF_LARGURA             288
#define QCIF_COMPRIMENTO        176
#define QCIF_LARGURA            144

//CAM ADDRESS
#define CAM_ADDR_WRITE          0X42
#define CAM_ADDR_READ           0X43

//REGISTRADORES CAM
#define REG_00_GAIN             0X00
#define REG_01_BLUE             0X80
#define REG_02_RED              0X80
#define REG_03_VREF             0X03
#define REG_04_COM1             0X00
#define REG_05_BAVE             0X00
#define REG_06_GbAVE            0X00
#define REG_07_AECHH            0X00
#define REG_08_RAVE             0X00
#define REG_09_COM2             0X00
#define REG_0A_PID              0X76
#define REG_0B_VER              0X70
#define REG_0C_COM3             0X00
#define REG_0D_COM4             0X40
#define REG_0E_COM5             0X01
#define REG_0F_COM6             0X43
#define REG_10_AECH             0X40
#define REG_11_CLKRC            0X80
#define REG_12_COM7             0X00
#define REG_13_COM8             0X8F
#define REG_14_COM9             0X4A
#define REG_15_COM10            0X00
//RESERVED
//#define REG_16_RSVD             0X00
#define REG_17_HSTART           0X11
#define REG_18_HSTOP            0X61
#define REG_19_VSTRT            0X03
#define REG_1A_VSTOP            0X7B
#define REG_1B_PSHFT            0X00
#define REG_1C_MIDH             0X7F
#define REG_1D_MIDL             0XA2
#define REG_1E_MVFP             0X00
//RESERVED
//#define REG_1F_LAEC             0X00
#define REG_20_ADCCTR0          0X04
#define REG_21_ADCCTR1          0X02
#define REG_22_ADCCTR2          0X01
#define REG_23_ADCCTR3          0X80
#define REG_24_AEW              0X75
#define REG_25_AEB              0X63
#define REG_26_VPT              0XD4
#define REG_27_BBIAS            0X80
#define REG_28_GbIAS            0X80
//RESERVED
//#define REG_29_RSVD             0X00
#define REG_2A_EXHCH            0X00
#define REG_2B_EXHCL            0X00
#define REG_2C_RBIAS            0X80
#define REG_2D_ADVFL            0X00
#define REG_2E_ADVFH            0X00
#define REG_2F_YAVE             0X00
#define REG_30_HSYST            0X08
#define REG_31_HSYEN            0X30
#define REG_32_HREF             0X80
#define REG_33_CHLF             0X08
#define REG_34_ARBLM            0X03
//RESERVER
//#define REG_35_RSVD             0X00
//#define REG_36_RSVD             0X00
#define REG_37_ADC              0X04
#define REG_38_ACOM             0X12
#define REG_39_OFON             0X00
#define REG_3A_TSLB             0X0C
#define REG_3B_COM11            0X00
#define REG_3C_COM12            0X40
#define REG_3D_COM13            0X99
#define REG_3E_COM14            0X0E
#define REG_3F_EDGE             0X88
#define REG_40_COM15            0XC0
#define REG_41_COM16            0X10
#define REG_42_COM17            0X08
//RESERVED
//#define REG_43_AWBC1            0X14
//#define REG_44_AWBC2            0XF0
//#define REG_45_AWBC3            0X45
//#define REG_46_AWBC4            0X61
//#define REG_47_AWBC5            0X51
//#define REG_48_AWBC6            0X79
//#define REG_49_RSVD             0X00
//#define REG_4A_RSVD             0X00
#define REG_4B_REG4B            0X00
#define REG_4C_DNSTH            0X00
//RESERVED
//#define REG_4D_RSVD             0X00
//#define REG_4E_RSVD             0X00
#define REG_4F_MTX1             0X40
#define REG_50_MTX2             0X34
#define REG_51_MTX3             0X0C
#define REG_52_MTX4             0X17
#define REG_53_MTX5             0X29
#define REG_54_MTX6             0X40
#define REG_55_BRIGHT           0X00
#define REG_56_CONTRAS          0X40
#define REG_57_CONTRAS_CENTER   0X80
#define REG_58_MTXS             0X1E
//RESERVED
//#define REG_59_RSVD             0X00
//#define REG_5A_RSVD             0X00
//#define REG_5B_RSVD             0X00
//#define REG_5C_RSVD             0X00
//#define REG_5D_RSVD             0X00
//#define REG_5E_RSVD             0X00
//#define REG_5F_RSVD             0X00
//#define REG_60_RSVD             0X00
//#define REG_61_RSVD             0X00
#define REG_62_LCC1             0X00
#define REG_63_LCC2             0X00
#define REG_64_LCC3             0X10
#define REG_65_LCC4             0X80
#define REG_66_LCC5             0X00
#define REG_67_MANU             0X80
#define REG_68_MANV             0X80
#define REG_69_GFIX             0X00
#define REG_6A_GGAIN            0X00
#define REG_6B_DBLV             0X3A
#define REG_6C_AWBCTR3          0X02
#define REG_6D_AWBCTR2          0X55
#define REG_6E_AWBCTR1          0X00
#define REG_6F_AWBCTR0          0X9A
#define REG_70_SCALING_XSC      0X4A
#define REG_71_SCALING_YSC      0X35
#define REG_72_SCALING_DCWCTR   0X11
#define REG_73_SCALING_PCLK_DIV 0X00
#define REG_74_REG74            0X00
#define REG_75_REG75            0X0F
#define REG_76_REG76            0X01
#define REG_77_REG77            0X10
//RESERVED
//#define REG_78_RSVD             0X00
//#define REG_79_RSVD             0X00
#define REG_7A_GAM1             0X02
#define REG_7B_GAM2             0X07
#define REG_7C_GAM3             0X1F
#define REG_7D_GAM4             0X49
#define REG_7E_GAM5             0X5A
#define REG_7F_GAM6             0X6A
#define REG_80_GAM7             0X79
#define REG_89_GAM8             0X87
//#define REG_89_GAM9             0X94
//#define REG_89_GAM10            0X9F
//#define REG_89_GAM11            0XAF
#define REG_86_GAM12            0XBB
#define REG_87_GAM13            0XCF
#define REG_88_GAM14            0XEE
//#define REG_89_GAM15            0XEE
//#define REG_8A_RSVD             0X00
//#define REG_90_RSVD             0X00
//#define REG_91_RSVD             0X00
#define REG_92_DM_LNL           0X00
#define REG_93_DM_LNH           0X00
#define REG_94_LCC6             0X50
#define REG_95_LCC7             0X50
//RESERVED
//#define REG_96_RSVD             0X00
//#define REG_97_RSVD             0X00
//#define REG_98_RSVD             0X00
//#define REG_99_RSVD             0X00
//#define REG_9A_RSVD             0X00
//#define REG_9B_RSVD             0X00
//#define REG_9C_RSVD             0X00
#define REG_9D_BD50ST           0X99
#define REG_9E_BD60ST           0X7F
//RESERVED
//#define REG_9F                  0X00
//#define REG_A0                  0X00
//#define REG_A1                  0X00
//#define REG_A2                  0X00
//#define REG_A3                  0X00
//#define REG_A4                  0X00
//#define REG_A5                  0X00
//#define REG_A6                  0X00
//#define REG_A7                  0X00
//#define REG_A8                  0X00
//#define REG_A9                  0X00
//#define REG_AA                  0X00
//#define REG_AB                  0X00
#define REG_AC_STR_OPT          0X00
#define REG_AD_STR_R            0X80
#define REG_AE_STR_G            0X80
#define REG_AF_STR_B            0X80
//RESERVED
//#define REG_B0_RSVD             0X00
//#define REG_B1_RSVD             0X00
//#define REG_B2_RSVD             0X00
#define REG_B3_THL_ST           0X80
//RESERVED
//#define REG_B4_RSVD             0X00
#define REG_B5_THL_DLT          0X04
//RESERVED
//#define REG_B6_RSVD             0X00
//#define REG_B7_RSVD             0X00
//#define REG_B8_RSVD             0X00
//#define REG_B9_RSVD             0X00
//#define REG_BA_RSVD             0X00
//#define REG_BB_RSVD             0X00
//#define REG_BC_RSVD             0X00
//#define REG_BD_RSVD             0X00
#define REG_BE_AD_CHB           0X00
#define REG_BF_AD_CHR           0X00
#define REG_C0_AD_CHGb          0X00
#define REG_C1_AD_CHGr          0X00
//RESERVED
//#define REG_C2_RSVD             0X00
//#define REG_C3_RSVD             0X00
//#define REG_C4_RSVD             0X00
//#define REG_C5_RSVD             0X00
//#define REG_C6_RSVD             0X00
//#define REG_C7_RSVD             0X00
//#define REG_C8_RSVD             0X00
#define REG_C9_SATCTR           0X04


