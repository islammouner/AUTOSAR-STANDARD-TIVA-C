/**********************************************************************************************************************

 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  Mcu_Hw.h
 *       Module:  Mcu_Hw
 *
 *  Description:  header file for Registers definition    
 *  
 *********************************************************************************************************************/
#ifndef MCU_HW_H
#define MCU_HW_H

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "Std_Types.h"
#include "Platform_Types.h"
/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/
/*INTERRUPT REGISTER CONFIG*/
typedef struct 
{
    uint32 VECACT   :8;
    uint32          :3;
    uint32 RETBASE  :1;
    uint32 VECPEND  :8;
    uint32          :2;
    uint32 ISRPEND  :1;
    uint32 ISRPRE   :1;
    uint32          :1;
    uint32 PENDSTCLR:1;
    uint32 PENDSTSET:1;
    uint32 UNPENDSV :1;
    uint32 PENDSV   :1;
    uint32          :2;
    uint32 NMISET   :1; 
}INTCTRL_BF;

typedef union 
{
    uint32 R;
    INTCTRL_BF B;
}INTCTRL_Tag;

typedef struct 
{
	uint32 				:5;
	uint32	MEM		:3;
	uint32  			:5;
	uint32	BUS		:3;
	uint32 				:5;
	uint32  USAGE :3;
	uint32  			:8;

}INT_SYSPRI1_BF;
typedef union 
{
    uint32 R;
    INT_SYSPRI1_BF B;
}INTSYSPRI1_Tag;

typedef struct 
{
	uint32 			:29;
	uint32 SVC	:3;

}INT_SYSPRI2_BF;
typedef union 
{
    uint32 R;
    INT_SYSPRI2_BF B;
}INTSYSPRI2_Tag;

typedef struct 
{
	uint32 				 :5;
	uint32	DEBUG  :3;
	uint32  		 	 :13;
	uint32	PENDSV :3;
	uint32 				 :5;
	uint32	TICK	 :3;

}INT_SYSPRI3_BF;
typedef union 
{
    uint32 R;
    INT_SYSPRI3_BF B;
}INTSYSPRI3_Tag;


typedef struct 
{
	uint32 						:5;
	uint32 INTA				:3;
	uint32 						:5;
	uint32 INTB				:3;
	uint32 						:5;
	uint32 INTC				:3;
	uint32 						:5;
	uint32 INTD				:3;
	
}INT_PRI_BF;


typedef union
{
		uint32 R;
    INT_PRI_BF B;
}INT_PRI_Tag;



/*CLOCK REGISTERS CONFIG*/
typedef struct 
{
    uint32 MOSCDIS   :1;
    uint32           :3;
    uint32 OSCSRC    :2;
    uint32 XTAL      :5;
    uint32 BYPASS    :1;
    uint32           :1;
    uint32 PWRDN     :1;
    uint32           :3;
    uint32 PWMDIV    :3;
    uint32 USEPWMDIV :1;
    uint32           :1;
    uint32 USESYSDIV :1;
    uint32 SYSDIV    :4;
    uint32 ACG       :1;
    uint32           :4;
}RCC_Tag_BF;

typedef union 
{
    uint32 R;
    RCC_Tag_BF B;
}RCC_Tag;


typedef struct
{
	uint32	GPIOA_EN :1;
	uint32	GPIOB_EN :1;
	uint32	GPIOC_EN :1;
	uint32	GPIOD_EN :1;
	uint32	GPIOE_EN :1;
	uint32	GPIOF_EN :1;
	
}RCGCGPIO_Tag_BF;
typedef union 
{
	uint32	R;
	RCGCGPIO_Tag_BF B;
}RCGCGPIO_Tag;

/*GPIO RESGISTERS CONFIG*/

typedef struct 
{
volatile uint32 GPIODATA[255];
volatile uint32 DATA;
volatile uint32 GPIODIR;
volatile uint32 GPIOIS;
volatile uint32 GPIOIBE;
volatile uint32 GPIOIEV;
volatile uint32 GPIOIM;
volatile uint32 GPIORIS;
volatile uint32 GPIOMIS;
volatile uint32 GPIOICR;
volatile uint32 GPIOAFSEL;
volatile uint32 Reserved[55];
volatile uint32 GPIODR2R;
volatile uint32 GPIODR4R;
volatile uint32 GPIODR8R;
volatile uint32 GPIOODR;
volatile uint32 GPIOPUR;
volatile uint32 GPIOPDR;
volatile uint32 GPIOSLR;
volatile uint32 GPIODEN;
volatile uint32 GPIOLOCK;
volatile uint32 GPIOCR;
volatile uint32 GPIOAMSEL;
volatile uint32 GPIOPCTL;
volatile uint32 GPIOADCCTL;
volatile uint32 GPIODMACTL;
}GPIO_REGISTERS_Tag;


/*GPT Registers Config*/
typedef struct 
{
		volatile uint32 GPTMCFG;
		volatile uint32 GPTMTAMR;
		volatile uint32 GPTMTBMR;
		volatile uint32 GPTMCTL;
		volatile uint32 GPTMSYNC;
		volatile uint32 Reserved;
		volatile uint32 GPTMIMR;
		volatile uint32 GPTMRIS;
		volatile uint32 GPTMMIS;
		volatile uint32 GPTMICR;
		volatile uint32 GPTMTAILR;
		volatile uint32 GPTMTBILR;
		volatile uint32 GPTMTAMATCHR;
		volatile uint32 GPTMTBMATCHR;
		volatile uint32 GPTMTAPR;
		volatile uint32 GPTMTBPR;
		volatile uint32 GPTMTAPMR;
		volatile uint32 GPTMTBPMR;
		volatile uint32 GPTMTAR;
		volatile uint32 GPTMTBR;
		volatile uint32 GPTMTAV;
		volatile uint32 GPTMTBV;
		volatile uint32 GPTMRTCPD;
		volatile uint32 GPTMTAPS;
		volatile uint32 GPTMTBPS;
		volatile uint32 GPTMTAPV;
		volatile uint32 GPTMTBPV;
}GPT_REGISTERS_Tag;

typedef struct
{
	uint32	Timer0_EN :1;
	uint32	Timer1_EN :1;
	uint32	Timer2_EN :1;
	uint32	Timer3_EN :1;
	uint32	Timer4_EN :1;
	uint32	Timer5_EN :1;
	
}RCGCTIMER_Tag_BF;
typedef union
{
	uint32	R;
	RCGCTIMER_Tag_BF B;
}RCGCTIMER_Tag;
/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/
/*CORTEXM4 PERI MACROS*/
#define CORTEXM4_PERI_BASE_ADDRESS             0xE000E000
#define APINT                                  *((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0xD0C))
#define INTCTRL                                 ((volatile INTCTRL_Tag*)(CORTEXM4_PERI_BASE_ADDRESS+0xD04))
#define SYSPRI1																  ((volatile INTSYSPRI1_Tag*)(CORTEXM4_PERI_BASE_ADDRESS+0xD18))
#define SYSPRI2																  ((volatile INTSYSPRI2_Tag*)(CORTEXM4_PERI_BASE_ADDRESS+0xD1C))
#define SYSPRI3														  	  ((volatile INTSYSPRI3_Tag*)(CORTEXM4_PERI_BASE_ADDRESS+0xD20))

#define INT_PRI0															  ((volatile INT_PRI_Tag*)(CORTEXM4_PERI_BASE_ADDRESS+0x400))
#define INT_PRI1															  ((volatile INT_PRI_Tag*)(CORTEXM4_PERI_BASE_ADDRESS+0x404))
#define INT_PRI2															  ((volatile INT_PRI_Tag*)(CORTEXM4_PERI_BASE_ADDRESS+0x408))
#define INT_PRI3															  ((volatile INT_PRI_Tag*)(CORTEXM4_PERI_BASE_ADDRESS+0x40C))
#define INT_PRI4															  ((volatile INT_PRI_Tag*)(CORTEXM4_PERI_BASE_ADDRESS+0x410))
#define INT_PRI5															  ((volatile INT_PRI_Tag*)(CORTEXM4_PERI_BASE_ADDRESS+0x414))
#define INT_PRI6															  ((volatile INT_PRI_Tag*)(CORTEXM4_PERI_BASE_ADDRESS+0x418))
#define INT_PRI7															  ((volatile INT_PRI_Tag*)(CORTEXM4_PERI_BASE_ADDRESS+0x41C))
#define INT_PRI8															  ((volatile INT_PRI_Tag*)(CORTEXM4_PERI_BASE_ADDRESS+0x420))
#define INT_PRI9															  ((volatile INT_PRI_Tag*)(CORTEXM4_PERI_BASE_ADDRESS+0x424))
#define INT_PRI10															  ((volatile INT_PRI_Tag*)(CORTEXM4_PERI_BASE_ADDRESS+0x428))
#define INT_PRI11														  	((volatile INT_PRI_Tag*)(CORTEXM4_PERI_BASE_ADDRESS+0x42C))
#define INT_PRI12														  	((volatile INT_PRI_Tag*)(CORTEXM4_PERI_BASE_ADDRESS+0x430))
#define INT_PRI13														  	((volatile INT_PRI_Tag*)(CORTEXM4_PERI_BASE_ADDRESS+0x434))
#define INT_PRI14														  	((volatile INT_PRI_Tag*)(CORTEXM4_PERI_BASE_ADDRESS+0x438))
#define INT_PRI15														  	((volatile INT_PRI_Tag*)(CORTEXM4_PERI_BASE_ADDRESS+0x43C))
#define INT_PRI16														  	((volatile INT_PRI_Tag*)(CORTEXM4_PERI_BASE_ADDRESS+0x440))
#define INT_PRI17														  	((volatile INT_PRI_Tag*)(CORTEXM4_PERI_BASE_ADDRESS+0x444))
#define INT_PRI18														  	((volatile INT_PRI_Tag*)(CORTEXM4_PERI_BASE_ADDRESS+0x448))
#define INT_PRI19														  	((volatile INT_PRI_Tag*)(CORTEXM4_PERI_BASE_ADDRESS+0x44C))
#define INT_PRI20														  	((volatile INT_PRI_Tag*)(CORTEXM4_PERI_BASE_ADDRESS+0x450))
#define INT_PRI21														  	((volatile INT_PRI_Tag*)(CORTEXM4_PERI_BASE_ADDRESS+0x454))
#define INT_PRI22														  	((volatile INT_PRI_Tag*)(CORTEXM4_PERI_BASE_ADDRESS+0x458))
#define INT_PRI23														  	((volatile INT_PRI_Tag*)(CORTEXM4_PERI_BASE_ADDRESS+0x45C))
#define INT_PRI24														  	((volatile INT_PRI_Tag*)(CORTEXM4_PERI_BASE_ADDRESS+0x460))
#define INT_PRI25														  	((volatile INT_PRI_Tag*)(CORTEXM4_PERI_BASE_ADDRESS+0x464))
#define INT_PRI26														  	((volatile INT_PRI_Tag*)(CORTEXM4_PERI_BASE_ADDRESS+0x468))
#define INT_PRI27														  	((volatile INT_PRI_Tag*)(CORTEXM4_PERI_BASE_ADDRESS+0x46C))
#define INT_PRI28																((volatile INT_PRI_Tag*)(CORTEXM4_PERI_BASE_ADDRESS+0x470))
#define INT_PRI29														  	((volatile INT_PRI_Tag*)(CORTEXM4_PERI_BASE_ADDRESS+0x474))
#define INT_PRI30														  	((volatile INT_PRI_Tag*)(CORTEXM4_PERI_BASE_ADDRESS+0x478))
#define INT_PRI31																((volatile INT_PRI_Tag*)(CORTEXM4_PERI_BASE_ADDRESS+0x47C))
#define INT_PRI32														  	((volatile INT_PRI_Tag*)(CORTEXM4_PERI_BASE_ADDRESS+0x480))
#define INT_PRI33														  	((volatile INT_PRI_Tag*)(CORTEXM4_PERI_BASE_ADDRESS+0x484))
#define INT_PRI34														  	((volatile INT_PRI_Tag*)(CORTEXM4_PERI_BASE_ADDRESS+0x488))

	


#define INT_EN0																 *((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0x100))
#define INT_EN1																 *((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0x104))		
#define INT_EN2																 *((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0x108))
#define INT_EN3																 *((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0x10C))
#define INT_EN4																 *((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0x110))
#define INT_DIS0															 *((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0x180))
#define INT_DIS1															 *((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0x184))
#define INT_DIS2															 *((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0x188))
#define INT_DIS3															 *((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0x18C))
#define INT_DIS4															 *((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0x190))



/*System control macros*/
#define SYSTEM_CONTROL_BASE_ADDRESS            0x400FE000
#define RCC                                    ((volatile RCC_Tag*)(SYSTEM_CONTROL_BASE_ADDRESS+0x060))
#define RCGCGPIO															*((volatile uint32*)(SYSTEM_CONTROL_BASE_ADDRESS+0x608))
#define RCGCGPIO_R														 ((volatile RCGCGPIO_Tag*)(SYSTEM_CONTROL_BASE_ADDRESS+0x608))
	

/*ENABLE/DISABLE CLOCK FOR GPIO*/
#define GPIOA_CLK_EN()			(RCGCGPIO_R->B.GPIOA_EN |= 0x01)
#define GPIOB_CLK_EN()			(RCGCGPIO_R>B.GPIOB_EN |= 0x01)
#define GPIOC_CLK_EN()			(RCGCGPIO_R->B.GPIOC_EN |= 0x01)
#define GPIOD_CLK_EN()			(RCGCGPIO_R->B.GPIOD_EN |= 0x01)
#define GPIOE_CLK_EN()			(RCGCGPIO_R->B.GPIOE_EN |= 0x01)
#define GPIOF_CLK_EN()			(RCGCGPIO_R->B.GPIOF_EN |= 0x01)
#define GPIOA_CLK_DIS()			(RCGCGPIO_R->B.GPIOA_EN &= 0x00)
#define GPIOB_CLK_DIS()			(RCGCGPIO_R->B.GPIOB_EN &= 0x00)
#define GPIOC_CLK_DIS()			(RCGCGPIO_R->B.GPIOC_EN &= 0x00)
#define GPIOD_CLK_DIS()			(RCGCGPIO_R->B.GPIOD_EN &= 0x00)
#define GPIOE_CLK_DIS()			(RCGCGPIO_R->B.GPIOE_EN &= 0x00)
#define GPIOF_CLK_DIS()			(RCGCGPIO_R->B.GPIOF_EN &= 0x00)

/*GPIO REGISTERS/PIN OFFSET*/
#define Port_Numbers				6
#define GPIOA_APB_BASEADDRESS 							0x40004000
#define GPIOB_APB_BASEADDRESS								0x40005000
#define GPIOC_APB_BASEADDRESS								0x40006000
#define GPIOD_APB_BASEADDRESS								0x40007000
#define GPIOE_APB_BASEADDRESS								0x40024000
#define GPIOF_APB_BASEADDRESS								0x40025000
#define GPIO_DATA_BASEADDRESS								0x3FC

#define PIN0_OFFSET									0x0004
#define PIN1_OFFSET									0x0008
#define PIN2_OFFSET									0x0010
#define PIN3_OFFSET									0x0020
#define PIN4_OFFSET									0x0040
#define PIN5_OFFSET									0x0080
#define PIN6_OFFSET									0x0100
#define PIN7_OFFSET									0x0200





/*GPIO Register Group*/
#define GPIOA_R			((GPIO_REGISTERS_Tag *)(GPIOA_APB_BASEADDRESS))
#define GPIOB_R			((GPIO_REGISTERS_Tag *)(GPIOB_APB_BASEADDRESS))
#define GPIOC_R			((GPIO_REGISTERS_Tag *)(GPIOC_APB_BASEADDRESS))
#define GPIOD_R			((GPIO_REGISTERS_Tag *)(GPIOD_APB_BASEADDRESS))
#define GPIOE_R			((GPIO_REGISTERS_Tag *)(GPIOE_APB_BASEADDRESS))
#define GPIOF_R			((GPIO_REGISTERS_Tag *)(GPIOF_APB_BASEADDRESS))


/*Register Group Direct Access*/
/*
#define GPIODATA(PORT_OFFSET)									*((volatile uint32*)(PORT_OFFSET+0x000))
#define GPIODIR(PORT_OFFSET)									*((volatile uint32*)(PORT_OFFSET+0x400))
#define GPIOIS(PORT_OFFSET)										*((volatile uint32*)(PORT_OFFSET+0x404))
#define GPIOIBE(PORT_OFFSET)									*((volatile uint32*)(PORT_OFFSET+0x408))
#define GPIOIEV(PORT_OFFSET)									*((volatile uint32*)(PORT_OFFSET+0x40C))
#define GPIOIM(PORT_OFFSET)										*((volatile uint32*)(PORT_OFFSET+0x410))
#define GPIORIS(PORT_OFFSET)									*((volatile uint32*)(PORT_OFFSET+0x414))
#define GPIOMIS(PORT_OFFSET)									*((volatile uint32*)(PORT_OFFSET+0x418))
#define GPIOICR(PORT_OFFSET)									*((volatile uint32*)(PORT_OFFSET+0x41C))
#define GPIOAFSEL(PORT_OFFSET)								*((volatile uint32*)(PORT_OFFSET+0x420))
#define GPIODR2R(PORT_OFFSET)									*((volatile uint32*)(PORT_OFFSET+0x500))
#define GPIODR4R(PORT_OFFSET)									*((volatile uint32*)(PORT_OFFSET+0x504))
#define GPIODR8R(PORT_OFFSET)									*((volatile uint32*)(PORT_OFFSET+0x508))
#define GPIOODR(PORT_OFFSET)									*((volatile uint32*)(PORT_OFFSET+0x50C))
#define GPIOPUR(PORT_OFFSET)									*((volatile uint32*)(PORT_OFFSET+0x510))
#define GPIOPDR(PORT_OFFSET)									*((volatile uint32*)(PORT_OFFSET+0x514))
#define GPIOSLR(PORT_OFFSET)									*((volatile uint32*)(PORT_OFFSET+0x518))
#define GPIODEN(PORT_OFFSET)									*((volatile uint32*)(PORT_OFFSET+0x51C))
#define GPIOLOCK(PORT_OFFSET)									*((volatile uint32*)(PORT_OFFSET+0x520))
#define GPIOCR(PORT_OFFSET)										*((volatile uint32*)(PORT_OFFSET+0x524))
#define GPIOAMSEL(PORT_OFFSET)								*((volatile uint32*)(PORT_OFFSET+0x528))
#define GPIOPCTL(PORT_OFFSET)									*((volatile uint32*)(PORT_OFFSET+0x52C))
#define GPIOADCCTL(PORT_OFFSET)								*((volatile uint32*)(PORT_OFFSET+0x530))
#define GPIODMACTL(PORT_OFFSET)								*((volatile uint32*)(PORT_OFFSET+0x534))	

*/
/*GPT 16/32 Registers Base Address*/
#define Timer0_BaseAddress			0x40030000
#define Timer1_BaseAddress			0x40031000
#define Timer2_BaseAddress			0x40032000
#define Timer3_BaseAddress			0x40033000
#define Timer4_BaseAddress			0x40034000
#define Timer5_BaseAddress			0x40035000
#define RCGCTIMER_R							((volatile RCGCTIMER_Tag*)(SYSTEM_CONTROL_BASE_ADDRESS+0x604))
#define RCGCTIMER							 *((volatile uint32*)(SYSTEM_CONTROL_BASE_ADDRESS+0x604))



#define Timer0_Reg			((GPT_REGISTERS_Tag *)(Timer0_BaseAddress))
#define Timer1_Reg			((GPT_REGISTERS_Tag *)(Timer1_BaseAddress))
#define Timer2_Reg			((GPT_REGISTERS_Tag *)(Timer2_BaseAddress))
#define Timer3_Reg			((GPT_REGISTERS_Tag *)(Timer3_BaseAddress))
#define Timer4_Reg			((GPT_REGISTERS_Tag *)(Timer4_BaseAddress))
#define Timer5_Reg			((GPT_REGISTERS_Tag *)(Timer5_BaseAddress))


/*GPT Registers Direct Access*/
/*
#define 	GPTMCFG(BaseAddress)					*((volatile uint32*)(BaseAddress+0x000))
#define 	GPTMTAMR(BaseAddress)					*((volatile uint32*)(BaseAddress+0x004))
#define 	GPTMTBMR(BaseAddress)					*((volatile uint32*)(BaseAddress+0x008))
#define 	GPTMCTL(BaseAddress)					*((volatile uint32*)(BaseAddress+0x00C))
#define 	GPTMSYNC(BaseAddress)					*((volatile uint32*)(BaseAddress+0x010))
#define 	GPTMIMR(BaseAddress)					*((volatile uint32*)(BaseAddress+0x018))
#define 	GPTMRIS(BaseAddress)					*((volatile uint32*)(BaseAddress+0x01C))
#define 	GPTMMIS(BaseAddress)					*((volatile uint32*)(BaseAddress+0x020))
#define 	GPTMICR(BaseAddress)					*((volatile uint32*)(BaseAddress+0x024))
#define 	GPTMTAILR(BaseAddress)				*((volatile uint32*)(BaseAddress+0x028))
#define 	GPTMTBILR(BaseAddress)				*((volatile uint32*)(BaseAddress+0x02C))
#define 	GPTMTAMATCHR(BaseAddress)			*((volatile uint32*)(BaseAddress+0x030))
#define 	GPTMTBMATCHR(BaseAddress)			*((volatile uint32*)(BaseAddress+0x034))
#define 	GPTMTAPR(BaseAddress)					*((volatile uint32*)(BaseAddress+0x038))
#define 	GPTMTBPR(BaseAddress)					*((volatile uint32*)(BaseAddress+0x03C))
#define 	GPTMTAPMR(BaseAddress)				*((volatile uint32*)(BaseAddress+0x040))
#define 	GPTMTBPMR(BaseAddress)				*((volatile uint32*)(BaseAddress+0x044))
#define 	GPTMTAR(BaseAddress)					*((volatile uint32*)(BaseAddress+0x048))
#define 	GPTMTBR(BaseAddress)					*((volatile uint32*)(BaseAddress+0x04C))
#define 	GPTMTAV(BaseAddress)					*((volatile uint32*)(BaseAddress+0x050))
#define 	GPTMTBV(BaseAddress)					*((volatile uint32*)(BaseAddress+0x054))
#define 	GPTMRTCPD(BaseAddress)				*((volatile uint32*)(BaseAddress+0x058))
#define 	GPTMTAPS(BaseAddress)					*((volatile uint32*)(BaseAddress+0x05C))
#define 	GPTMTBPS(BaseAddress)					*((volatile uint32*)(BaseAddress+0x060))
#define 	GPTMTAPV(BaseAddress)					*((volatile uint32*)(BaseAddress+0x064))
#define 	GPTMTBPV(BaseAddress)					*((volatile uint32*)(BaseAddress+0x068))	
*/
/*ENABLE/DISABLE CLOCK FOR GPT*/
#define TIMER0_CLK_EN()				(RCGCTIMER->B.Timer0_EN |=0x01)
#define TIMER1_CLK_EN()				(RCGCTIMER->B.Timer1_EN |=0x01)
#define TIMER2_CLK_EN()				(RCGCTIMER->B.Timer2_EN |=0x01)
#define TIMER3_CLK_EN()				(RCGCTIMER->B.Timer3_EN |=0x01)
#define TIMER4_CLK_EN()				(RCGCTIMER->B.Timer4_EN |=0x01)
#define TIMER5_CLK_EN()				(RCGCTIMER->B.Timer5_EN |=0x01)
#define TIMER0_CLK_DIS()			(RCGCTIMER->B.Timer0_EN &=0x00)
#define TIMER1_CLK_DIS()			(RCGCTIMER->B.Timer1_EN &=0x00)
#define TIMER2_CLK_DIS()			(RCGCTIMER->B.Timer2_EN &=0x00)
#define TIMER3_CLK_DIS()			(RCGCTIMER->B.Timer3_EN &=0x00)
#define TIMER4_CLK_DIS()			(RCGCTIMER->B.Timer4_EN &=0x00)
#define TIMER5_CLK_DIS()			(RCGCTIMER->B.Timer5_EN &=0x00)
/*Bit Band*/
#define Peripheral_BitBand_BaseAddress 		0x40000000U
#define GPIO_Bit_Word_Address(Byte,Bit)				(Peripheral_BitBand_BaseAddress+0x4000+(Byte*32)+(Bit*4))

/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/



 
#endif  /* MCU_HW_H */

/**********************************************************************************************************************
 *  END OF FILE: Mcu_Hw.h
 *********************************************************************************************************************/
