/**********************************************************************************************************************

 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  IntCtrl_Types.h
 *       Module:  -
 *
 *  Description:  <Write File DESCRIPTION here>     
 *  
 *********************************************************************************************************************/
#ifndef INTCTRL_TYPES_H
#define INTCTRL_TYPES_H

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "Std_Types.h"

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/
 #define  GP8_SUB1            0x200       /*8 Groups , 1 SUBGROUP */
 #define  GP4_SUB2            0x500         /*4 Groups , 2 SUBGROUP */
 #define  GP2_SUB4            0x600      /*2 Groups , 4 SUBGROUP */
 #define  GP1_SUB8            0x700      /*1 Groups , 8 SUBGROUP */

/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/
typedef enum
{
    GPIO_PORT_A=0,
    GPIO_PORT_B=1,
    GPIO_PORT_C=2,
    GPIO_PORT_D=3,
    GPIO_PORT_E=4,
    UART0=5,
    UART1=6,
    SSI0=7,
    I2C0=8,
    PWM0_FAULT=9,
    PWM0_GENERATOR0=10,
    PWM0_GENERATOR1=11,
    PWM0_GENERATOR2=12,
    QEI0=13,
    ADC0_SEQUENCE0=14,
    ADC0_SEQUENCE1=15,
    ADC0_SEQUENCE2=16,
    ADC0_SEQUENCE3=17,
    WDT0_1=18,
    TIMER0A=19,
    TIMER0B=20,
    TIMER1A=21,
    TIMER1B=22,
    TIMER2A=23,
    TIMER2B=24,
    ANALOG_CMP0=25,
    ANALOG_CMP1=26,
    SYS_CONTROL=28,
    FLASH_EEPROM_MEMORY_CONTROL=29,
    GPIO_PORT_F=30,
    UART2=33,
		SSI1=34,
}IntCtrl_InterruptType;
typedef enum 
{
    RESET=1,
    NMI=2,
    HARD_FAULT=3,
    MEMORY_MANAGMENT=4,
    BUS_FAULT=5,
    USAGE_FAULT=6,
    SV_CALL=11,
    DEBUG_MONITOR=12,
    PENDSV=14,
    SysTick=15  
}IntCtrl_ExceptionType;

typedef struct 
{
	IntCtrl_InterruptType InterruptNo;
	

}INT_Config_Type;
#endif  /* INTCTRL_TYPES_H */

/**********************************************************************************************************************
 *  END OF FILE: IntCtrl_Types.h
 *********************************************************************************************************************/
