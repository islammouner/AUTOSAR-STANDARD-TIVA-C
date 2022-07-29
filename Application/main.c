#include "IntCtrl.h"
#include "DIO.h"
#include "GPT_Cfg.h"
#include "GPIO_Cfg.h"
uint8 Flag=0;
uint8 LED_ON=0;
void TIMER0A_Handler (void)
{
	Flag=1;
	SET_BIT(Timer0_Reg->GPTMICR,0);
	LED_ON^=1;
}


int main(void)
{
	uint32 Value=0;
	Dio_ChannelType GP1;
	GP1.GPIO_Pin=PIN1;
	GP1.GPIO_Port=GPIOF;
	IntCtrl_Init();
	Gpt_Init(&GPT_Config);
	Port_Init(&GPIO_Config);
	Gpt_EnableNotification(Timer0);
	Gpt_StartTimer(Timer0,GPT_Config.Timer[0].GptChannelTickFrequency);
	Value = Gpt_GetTimeRemaining(Timer0);
	while(1)
	{
		Value = Gpt_GetTimeRemaining(Timer0);
		if(Flag==1)
		{
			if(LED_ON==1)
			{
			Gpt_StopTimer(Timer0);
			Gpt_StartTimer(Timer0,GPT_Config.Timer[0],0x00F42400);
			}
			else 
			{
				Gpt_StopTimer(Timer0);
				Gpt_StartTimer(Timer0,GPT_Config.Timer[0],0x4C4B400);
			}
			Dio_FlipChannel(GP1);
			Flag=0;
		}
	
	}
	
	return 0;
}




