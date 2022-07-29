

/**********************************************************************************************************************

 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  Gpio_Types.h
 *       Module:  -
 *
 *  Description:  <Write File DESCRIPTION here>     
 *  
 *********************************************************************************************************************/
#ifndef GPIO_TYPES_H
#define GPIO_TYPES_H

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "Std_Types.h"
#include "Mcu_Hw.h"
#include "Dio_Types.h"
/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/

typedef enum 
{	
		DIO=0,
		EX_INT=1,
		UART=2,
		TIMER=3,
		ADC=4,
		CAN=5,
		SSI=6,
		I2C=7,
		USB=8
}Port_PinModeType;
typedef enum 
{
		OpenDrain=0,
		PULL_UP=1,
		PULL_DOWN=2,
		SlewRate=3
}Port_PinInternalAttachType;
typedef enum 
{
	Current_2MA=0,
	Current_4MA=1,
	Current_8MA=2

}Port_PinOutputCurrentType;
typedef enum 
{
	INPUT=0,
	OUTPUT=1
}Port_PinDirectionType;

typedef struct  
{
	Dio_ChannelType PortPinNumber;
	Port_PinModeType PortPinMode;
	Dio_Level_Type PORTPinLevelValue;
	Port_PinDirectionType PortPinDirection;
	Port_PinInternalAttachType	PortPinInternalAttach;
	Port_PinOutputCurrentType	PortPinOutputCurrent;
	
}PORT_Config_Channel;





#endif  /* GPIO_TYPES_H */

/**********************************************************************************************************************
 *  END OF FILE: GPIO_Types.h
 *********************************************************************************************************************/








