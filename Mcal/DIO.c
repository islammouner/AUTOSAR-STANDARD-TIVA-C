/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/**        \file  DIO.c
 *        \brief  Nested Vector Interrupt Controller Driver
 *
 *      \details  The Driver Configure All MCU interrupts Priority into gorups and subgroups
 *                Enable NVIC Interrupt Gate for Peripherals
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "Std_Types.h"
#include "Mcu_Hw.h"
#include "DIO.h"
/**********************************************************************************************************************
*  LOCAL MACROS CONSTANT\FUNCTION
*********************************************************************************************************************/	
/**********************************************************************************************************************
 *  LOCAL DATA 
 *********************************************************************************************************************/
GPIO_REGISTERS_Tag *DIOX[Port_Numbers]={ GPIOA_R, /*Base Address for GPIOA Register Config*/
																				 GPIOB_R, /*Base Address for GPIOB Register Config*/
																				 GPIOC_R, /*Base Address for GPIOC Register Config*/
																				 GPIOD_R, /*Base Address for GPIOD Register Config*/
																				 GPIOE_R, /*Base Address for GPIOE Register Config*/
																				 GPIOF_R};/*Base Address for GPIOF Register Config*/


/**********************************************************************************************************************
 *  GLOBAL DATA
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL FUNCTIONS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 *********************************************************************************************************************/
/******************************************************************************
* \Syntax          : Dio_Level_Type Dio_ReadChannel (Dio_ChannelType ChannelId)                                     
* \Description     : Read pin value in GPIO 
*                                                
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : ChannelId                     
* \Parameters (out): Dio_Level_Type                                               
* \Return value:   : Dio_Level_Type
*******************************************************************************/
Dio_Level_Type Dio_ReadChannel (Dio_ChannelType ChannelId)
{
	return READ_BIT((DIOX[ChannelId.GPIO_Port]->DATA),ChannelId.GPIO_Pin);
	
}
/******************************************************************************
* \Syntax          : void ClkCtrl_Init(void)                                      
* \Description     : initialize Nvic\SCB Module by parsing the Configuration 
*                    into Nvic\SCB registers                                    
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : None                     
* \Parameters (out): None                                                      
* \Return value:   : None
*******************************************************************************/
void Dio_WriteChannel (Dio_ChannelType ChannelId,Dio_Level_Type Level)
{
	if(Level==HIGH)
	DIOX[ChannelId.GPIO_Port]->GPIODATA[1<<ChannelId.GPIO_Pin] |= (uint32) (1<<ChannelId.GPIO_Pin);
	else if (Level==LOW)
	DIOX[ChannelId.GPIO_Port]->GPIODATA[1<<ChannelId.GPIO_Pin] &= (uint32) ~(1<<ChannelId.GPIO_Pin);
}
/******************************************************************************
* \Syntax          : void ClkCtrl_Init(void)                                      
* \Description     : initialize Nvic\SCB Module by parsing the Configuration 
*                    into Nvic\SCB registers                                    
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : None                     
* \Parameters (out): None                                                      
* \Return value:   : None
*******************************************************************************/
Dio_PortLevelType Dio_ReadPort (Dio_PortType PortId)
{
	return DIOX[PortId]->DATA;
}
/******************************************************************************
* \Syntax          : void ClkCtrl_Init(void)                                      
* \Description     : initialize Nvic\SCB Module by parsing the Configuration 
*                    into Nvic\SCB registers                                    
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : None                     
* \Parameters (out): None                                                      
* \Return value:   : None
*******************************************************************************/
void Dio_WritePort (Dio_PortType PortId , Dio_PortLevelType Level )
{
	DIOX[PortId]->DATA = Level;
}
/******************************************************************************
* \Syntax          : void ClkCtrl_Init(void)                                      
* \Description     : initialize Nvic\SCB Module by parsing the Configuration 
*                    into Nvic\SCB registers                                    
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : None                     
* \Parameters (out): None                                                      
* \Return value:   : None
*******************************************************************************/
void Dio_FlipChannel (Dio_ChannelType ChannelId)
{
	DIOX[ChannelId.GPIO_Port]->GPIODATA[1<<ChannelId.GPIO_Pin] ^= (uint32) (1<<ChannelId.GPIO_Pin);
}




/**********************************************************************************************************************
 *  END OF FILE: ClkCtrl.c
 *********************************************************************************************************************/
 
 