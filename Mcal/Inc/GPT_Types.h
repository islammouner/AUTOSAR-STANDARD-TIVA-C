/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  GPT_Types.h
 *    Component:  -
 *       Module:  -
 *
 *  Description:  Provision of Standard Types
 *
 *********************************************************************************************************************/



#ifndef GPT_TYPES_H
#define GPT_TYPES_H

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "Mcu_Hw.h"
#include "GPT_Cfg.h"
/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/
/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/
typedef uint32 Gpt_ValueType;
typedef enum 
{
	Timer0=0,
	Timer1=1,
	Timer2=2,
	Timer3=3,
	Timer4=4,
	Timer5=5,
	Timer0_W=6,
	Timer1_W=7,
	Timer2_W=8,
	Timer3_W=9,
	Timer4_W=10,
	Timer5_W=11,
	
}Gpt_ChannelType;
typedef enum 
{
	GPT_CH_MODE_ONESHOT=0,
	GPT_CH_MODE_PERIODIC=1
}Gpt_ModeType;

typedef enum 
{
	GPT_PREDEF_TIMER_1US_16BIT=0,
	GPT_PREDEF_TIMER_1US_26BIT=1,
	GPT_PREDEF_TIMER_1US_32BIT=2,
}Gpt_PredefTimerType;

typedef enum
{
	Gpt_Polling=0,
	Gpt_Interrupt=1
}GPT_InterruptType;
typedef struct 
{
	Gpt_ChannelType	GptChannelId;
	Gpt_ValueType	GptChannelTickFrequency;
	Gpt_ModeType 	ChannelMode;
	Gpt_PredefTimerType	PredefTimer;
	GPT_InterruptType		GptInterrupt;
	/*TODO Pointer to callback function*/
}Gpt_ConfigTimer;




 
/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/

 
/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/


#endif /* STD_TYPES_H */
/**********************************************************************************************************************
 *  END OF FILE: Std_Types.h
 *********************************************************************************************************************/