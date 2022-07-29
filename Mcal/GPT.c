/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/**        \file  GPT.c
 *        \brief  Nested Vector Interrupt Controller Driver
 *
 *      \details  The Driver Configure All MCU interrupts Priority into gorups and subgroups
 *                Enable NVIC Interrupt Gate for Peripherals
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
 #include "GPT.h"
/**********************************************************************************************************************
*  LOCAL MACROS CONSTANT\FUNCTION
*********************************************************************************************************************/	
GPT_REGISTERS_Tag * GPT[6]={ Timer0_Reg,
														 Timer1_Reg,
														 Timer2_Reg,
														 Timer3_Reg,
														 Timer4_Reg,
														 Timer5_Reg
};
/**********************************************************************************************************************
 *  LOCAL DATA 
 *********************************************************************************************************************/
uint32 Current_Value=0;
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
void Gpt_Init(const Gpt_ConfigType* ConfigPtr)
{
	uint8 i =0;
	for (i=0;i<CONFIGURED_TIMERS;i++)
	{
		
		SET_BIT(RCGCTIMER,ConfigPtr->Timer[i].GptChannelId);/*Enable Clock for Timerx*/
		CLEAR_BIT(GPT[ConfigPtr->Timer[i].GptChannelId]->GPTMCTL,0) ;/*Clear TnEN bit*/
		GPT[ConfigPtr->Timer[i].GptChannelId]->GPTMCFG=0x00000000;
								switch (ConfigPtr->Timer[i].PredefTimer)
									
								{
									case GPT_PREDEF_TIMER_1US_16BIT:
										SET_BIT(GPT[ConfigPtr->Timer[i].GptChannelId]->GPTMCFG,3);
										break;
									case GPT_PREDEF_TIMER_1US_32BIT:
										CLEAR_BIT(GPT[ConfigPtr->Timer[i].GptChannelId]->GPTMCFG,0);
										break;
									case GPT_PREDEF_TIMER_1US_26BIT:
										break;
								}
				
								switch (ConfigPtr->Timer[i].ChannelMode)
								{				
										case GPT_CH_MODE_ONESHOT:					
											SET_BIT(GPT[ConfigPtr->Timer[i].GptChannelId]->GPTMTAMR,0);	 /*Choose One Shoot Mode*/
											CLEAR_BIT(GPT[ConfigPtr->Timer[i].GptChannelId]->GPTMTAMR,4);	 /*Timer Count DOWN*/
											break;
										case GPT_CH_MODE_PERIODIC:
											SET_BIT(GPT[ConfigPtr->Timer[i].GptChannelId]->GPTMTAMR,1);  /*Choose the periodic Mode*/
											CLEAR_BIT(GPT[ConfigPtr->Timer[i].GptChannelId]->GPTMTAMR,4);	 /*Timer Count DOWN*/
										/*	GPT[ConfigPtr->Timer[i].GptChannelId]->GPTMTAILR |= ConfigPtr->Timer[i].GptChannelTickFrequency;*/ /*Load Reigster Value*/										
											break;
								}
								
								/*Clear Interrupts*/
								GPT[ConfigPtr->Timer[i].GptChannelId]->GPTMIMR &= 0x00000000;
								 		
				}
}

void Gpt_DisableNotification(Gpt_ChannelType Channel)
{
	CLEAR_BIT(GPT[Channel]->GPTMIMR,0);
}

void Gpt_EnableNotification(Gpt_ChannelType Channel)
{
	SET_BIT(GPT[Channel]->GPTMIMR,0);
}

void Gpt_StartTimer(Gpt_ChannelType Channel ,Gpt_ValueType Value)
{
	Current_Value=GPT[Channel]->GPTMTAILR |= Value;
	
	SET_BIT(GPT[Channel]->GPTMCTL,0);
}

void Gpt_StopTimer(Gpt_ChannelType Channel)
{
	CLEAR_BIT(GPT[Channel]->GPTMCTL,0);
}


Gpt_ValueType Gpt_GetTimeElapsed (Gpt_ChannelType Channel)
{
	return (Gpt_ValueType)(0xFFFFFFFF-GPT[Channel]->GPTMTAILR);
}
Gpt_ValueType Gpt_GetTimeRemaining(Gpt_ChannelType Channel)
{

	return (GPT[Channel]->GPTMTAILR-Current_Value);
}
/*
Std_ReturnType Gpt_GetPredefTimerValue(Gpt_PredefTimerType PredefTimer, uint32* TimeValuePtr)
{
	
return 0;
}
void Gpt_Notification_	(void)
{

}	*Shall be defined as pointer to function defined by the user (CallBack)*/
/**********************************************************************************************************************
 *  END OF FILE: GPT.c
 *********************************************************************************************************************/