/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/**        \file  Gpt_Lcfg.c
 *        \brief  General purpose timers Link time configuration
 *
 *      \details  
 *
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "Gpt.h"


/**********************************************************************************************************************
 *  GLOBAL DATA
 *********************************************************************************************************************/

Gpt_ConfigType Gpt_ConfigSet[GPT_NUM_OF_CONFIG_CHANNELS] = \
{
	{
		.GptChannelId = TIMER0,
		.GptChannelTickFrequency = 1000000,
		.GptChannelMode = GPT_CH_MODE_CONTINUOUS,
	},
	{
		.GptChannelId = TIMER1,
		.GptChannelTickFrequency = 1000000,
		.GptChannelMode = GPT_CH_MODE_CONTINUOUS,
	}
};


/**********************************************************************************************************************
 *  END OF FILE: Gpt_Lcfg.c
 *********************************************************************************************************************/