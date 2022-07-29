/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/**        \file  IntCrtl.c
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
#include "IntCtrl.h"
#include "Mcu_Hw.h"
#include "IntCtrl_Types.h"
/**********************************************************************************************************************
*  LOCAL MACROS CONSTANT\FUNCTION
*********************************************************************************************************************/	
#define APINT_KEY 		(0xFA05)
/**********************************************************************************************************************
 *  LOCAL DATA 
 *********************************************************************************************************************/
/*volatile INT_PRI_Tag *INTPRI[35]=
{
	INT_PRI0,
	INT_PRI1,
	INT_PRI2,
	INT_PRI3,
	INT_PRI4,
	INT_PRI5,
	INT_PRI6,
	INT_PRI7,
	INT_PRI8,
	INT_PRI9,
	INT_PRI10,
	INT_PRI11,
	INT_PRI12,
	INT_PRI13,
	INT_PRI14,
	INT_PRI15,
	INT_PRI16,
	INT_PRI17,
	INT_PRI18,
	INT_PRI19,
	INT_PRI20,
	INT_PRI21,
	INT_PRI22,
	INT_PRI23,
	INT_PRI24,
	INT_PRI25,
	INT_PRI26,
	INT_PRI27,
	INT_PRI28,
	INT_PRI29,
	INT_PRI30,
	INT_PRI31,
	INT_PRI32,
	INT_PRI33,
	INT_PRI34,
};
INT_Config_Type * INT_Config[CONFIGURED_INTERRUPT];
*/
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
* \Syntax          : void IntCrtl_Init(void)                                      
* \Description     : initialize Nvic\SCB Module by parsing the Configuration 
*                    into Nvic\SCB registers                                    
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : None                     
* \Parameters (out): None                                                      
* \Return value:   : None
*******************************************************************************/
void IntCtrl_Init(void)
{
		
	  /*TODO Configure Grouping\SubGrouping System in APINT register in SCB*/
    APINT = APINT_KEY|GP8_SUB1;
    /*TODO : Assign Group\Subgroup priority in NVIC_PRIx Nvic and SCB_SYSPRIx Registers*/  
		INT_PRI0->B.INTD=5;
		INT_PRI4->B.INTD |= 0x04 ;
		
		SYSPRI1->B.BUS=BUS_PRI;				/*SET BUS_FAULT PERIOIRTY*/
		SYSPRI1->B.MEM=MEM_PRI;				/*SET Memory_FAULT PERIOIRTY*/
	  SYSPRI1->B.USAGE=USAGE_PRI;		/*SET USAGE_FAULT PERIOIRTY*/
		SYSPRI2->B.SVC=SVC_PRI;				/*SET SVC PERIOIRTY*/
	  SYSPRI3->B.DEBUG=DEBUG_PRI;		/*SET DEBUG PERIOIRTY*/
		SYSPRI3->B.PENDSV=PENDSV_PRI;	/*SET PENDSV PERIOIRTY*/
		SYSPRI3->B.TICK=TICK_PRI;			/*SET TICK PERIOIRTY*/
	  /*TODO : Enable\Disable based on user configurations in NVIC_ENx and SCB_Sys Registers */
		SET_BIT(INT_EN0,TIMER0A); /*Enable Interrupt for TIMER0A*/
}

/**********************************************************************************************************************
 *  END OF FILE: IntCrtl.c
 *********************************************************************************************************************/
