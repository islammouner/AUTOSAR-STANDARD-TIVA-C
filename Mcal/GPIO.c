/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/**          GPIO.c
 *          Nested Vector Interrupt Controller Driver
 *
 *					 The Driver Configure All MCU interrupts Priority into gorups and subgroups
 *                Enable NVIC Interrupt Gate for Peripherals
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "GPIO.h"
/**********************************************************************************************************************
*  LOCAL MACROS CONSTANT\FUNCTION
*********************************************************************************************************************/	
/**********************************************************************************************************************
 *  LOCAL DATA 
 *********************************************************************************************************************/
GPIO_REGISTERS_Tag *GPIOX[Port_Numbers]={GPIOA_R, /*Base Address for GPIOA Register Config*/
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
void Port_Init(const Port_ConfigType* ConfigPtr)
{
	uint8 i=0;
		for (i=0;i<CONFIGURED_PINS;i++)
	{
			SET_BIT(RCGCGPIO,ConfigPtr->Channel[i].PortPinNumber.GPIO_Port); /*Enable clock FOR PORTx*/
		
			if (ConfigPtr->Channel[i].PortPinMode==DIO)
			{
				GPIOX[ConfigPtr->Channel[i].PortPinNumber.GPIO_Port]->GPIODEN |= (1<<ConfigPtr->Channel[i].PortPinNumber.GPIO_Pin); /*Enable PIN In Port*/
				/*Configurations for Direction*/
				switch(ConfigPtr->Channel[i].PortPinDirection)
				{
					case OUTPUT:
						GPIOX[ConfigPtr->Channel[i].PortPinNumber.GPIO_Port]->GPIODIR |= (1<<ConfigPtr->Channel[i].PortPinNumber.GPIO_Pin);
								/*Configurations for Output Level*/
													switch(ConfigPtr->Channel[i].PORTPinLevelValue)
														{
														case LOW:
															GPIOX[ConfigPtr->Channel[i].PortPinNumber.GPIO_Port]->GPIODATA[1<<ConfigPtr->Channel[i].PortPinNumber.GPIO_Pin] &= (uint32) ~(1<<ConfigPtr->Channel[i].PortPinNumber.GPIO_Pin);
															break;
														case HIGH:
															GPIOX[ConfigPtr->Channel[i].PortPinNumber.GPIO_Port]->GPIODATA[1<<ConfigPtr->Channel[i].PortPinNumber.GPIO_Pin] |= (uint32) (1<<ConfigPtr->Channel[i].PortPinNumber.GPIO_Pin);
															break; 
														
														}
															/*Configurations for Output Current*/
													switch(ConfigPtr->Channel[i].PortPinOutputCurrent)
														{
														case Current_2MA:
															GPIOX[ConfigPtr->Channel[i].PortPinNumber.GPIO_Port]->GPIODR2R |= (1<<ConfigPtr->Channel[i].PortPinNumber.GPIO_Pin);
															break;
														case Current_4MA:
															GPIOX[ConfigPtr->Channel[i].PortPinNumber.GPIO_Port]->GPIODR4R |= (1<<ConfigPtr->Channel[i].PortPinNumber.GPIO_Pin);
															break;
														case Current_8MA:
															GPIOX[ConfigPtr->Channel[i].PortPinNumber.GPIO_Port]->GPIODR8R |= (1<<ConfigPtr->Channel[i].PortPinNumber.GPIO_Pin);
															break;
														}
														
						break;
					case INPUT:
						GPIOX[ConfigPtr->Channel[i].PortPinNumber.GPIO_Port]->GPIODIR &= ~(1<<ConfigPtr->Channel[i].PortPinNumber.GPIO_Pin);
					/*Configurations for Internal Attach*/
												switch(ConfigPtr->Channel[i].PortPinInternalAttach)
										{
											case PULL_DOWN:
												GPIOX[ConfigPtr->Channel[i].PortPinNumber.GPIO_Port]->GPIOPDR |= (1<<ConfigPtr->Channel[i].PortPinNumber.GPIO_Pin);
												break;
											case PULL_UP:
												GPIOX[ConfigPtr->Channel[i].PortPinNumber.GPIO_Port]->GPIOPUR |= (1<<ConfigPtr->Channel[i].PortPinNumber.GPIO_Pin);
												break;
											case OpenDrain:
												GPIOX[ConfigPtr->Channel[i].PortPinNumber.GPIO_Port]->GPIOODR |= (1<<ConfigPtr->Channel[i].PortPinNumber.GPIO_Pin);
												break;
											case SlewRate:
												GPIOX[ConfigPtr->Channel[i].PortPinNumber.GPIO_Port]->GPIOSLR |= (1<<ConfigPtr->Channel[i].PortPinNumber.GPIO_Pin);
												break;
										}
						break;
				}
				
			
				
			}
	
	}
}

/******************************************************************************/
/*void Port_Init(const Port_ConfigType* Configptr)*/

/**********************************************************************************************************************
 *  END OF FILE: GPIO.c
 *********************************************************************************************************************/
