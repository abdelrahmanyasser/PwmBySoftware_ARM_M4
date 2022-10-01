#if(0)
#include "Port.h"
#include "Dio.h"
#include "Gpt.h"
#include "Mcu_Hw.h"
#include "IntCtrl.h"

/* PWM resolution, you can lower resolution by changing this number */
/* Higher the resolution higher the CPU overhead */
/* Good results from 20 ... 50 */
#define PWM_SAMPLES (50u)

/* PWM Task variables Config
 * WARNING: Do not change this variables!!
 * NOTE: If you want to change the on and off time use the function:
 * 
 * calculateOnOffTime(uint8 dutyCycle);
 */
 
static volatile uint32 g_globalTicks = 0;
static volatile uint8 g_onTime = 0;
static volatile uint8 g_offTime = 0;
static volatile uint8 g_dutyCycle = 0;

static volatile uint8 g_logicAnalyzer = 0;

/* App function prototypes */
void pwmBySoftware(void);
void calculateOnOffTime(uint8 dutyCycle);
void increaseDutyCycle(void);



int main()
{
	/* Init Hardware */
	Port_Init(Port_ConfigSet);
	Gpt_Init(Gpt_ConfigSet);

    /* Set Callback functions before initializing NVIC */
	Gpt_SetCallBack(PWM_TIMER, pwmBySoftware);

	/* Init Interrupts */
	IntCtrl_Init();
	
	/* Please Enter Initial DutyCycle ! */
    /* This function calculate the on & off time required for the software PWM function */
	calculateOnOffTime(30);
	
	/* 1 count of TIMER0 equals 1 us */
	/** To Achieve a frequency of 500 HZ
	 *  that means a wave period of 1/500 = 2 ms
	 *  ;; Divide that by PWM_SAMPLES, assume is 100
	 *  ;; Thus we need an over flow every 20 count or 20 us 
	 */
	Gpt_StartTimer(PWM_TIMER, 20);
  
	while(1);
}


/* App function Definitions*/
void calculateOnOffTime(uint8 dutyCycle)
{
	if (dutyCycle >= 100)
	{
		/* Avoid led turn off locking */
		dutyCycle = 99;
	}
	g_onTime = (dutyCycle * PWM_SAMPLES) / 100;
	g_offTime = PWM_SAMPLES - g_onTime;
}

/* PWM Task */
void pwmBySoftware(void)
{
	g_globalTicks++;
	if(	g_globalTicks == g_offTime)
	{
		g_logicAnalyzer = 1;
		Dio_WriteChannel(PWM_LED, PIN_HIGH);
	}
	else if (g_globalTicks >= PWM_SAMPLES)
	{
		g_logicAnalyzer = 0;
		Dio_WriteChannel(PWM_LED, PIN_LOW);
		g_globalTicks = 0;
	}
}

#endif