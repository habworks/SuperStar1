/** ****************************************************************************************************
 * @file 			Timers.c
 * @brief			This Source file used to support uC Peripheral: Low Power Timer (LPTIM), Timer2 (TIM2),  Timer21 (TIM21)
 * ****************************************************************************************************
 * @author			Hab S. Collector \n
 * Last Edited By:	Hab S. Collector \n
 *
 * @date			7/22/20 \n
 * Last Edit Date:  8/1/20 \n
 * @version       	See Main.C
 *
 * @param Development_Environment \n
 * Hardware:		ST32LM082 \n
 * IDE:             Atollic TrueStudio, VER 9.3.0 \n
 * Compiler:        GCC \n
 * Editor Settings: 1 Tab = 4 Spaces, Recommended Courier New 11
 *
 * @note            This file supports the use of Non Volatile memory on STM32L010C6
 *                  This is a category 2 device as defined in ST Manual RM0451
 *                  See section 4.1, page 45 for memory map information
 * 					This is an embedded application
 *		            It will be necessary to consult the reference documents before you can review this code.
 *                  It is suggested that the documents be reviewed in the order shown.
 *			          SuperStar Technical Manual
 *				      SuperStar User Manual
 *
 * @copyright		IMR Engineering
 * **************************************************************************************************** */

#include "Timers.h"
#include "MainSupport.h"
#include "LED_Control.h"
#include "lptim.h"
#include "tim.h"


extern Type_SuperStarStatus SuperStarStatus;


/** ****************************************************************************************************
* @brief This is the function that is ultimately used as the Low Power Timer (LPTim) IRQ Callback.  This
* function is responsible for the slow, background tick that will wake the processor every WAKEUP_PERIOD
* seconds
*
* @author 			Hab S. Collector \n
* Last Edited By:  	Hab S. Collector \n
*
* @note To be placed in the main.c
* @note Avoids excessive edit of main.c when using STM32CubeMX
*
* @param void
* @return void
*
* STEP 1:
* STEP 2:
* STEP 3:
* **************************************************************************************************** */
void callbackLPTIM1_IRQ(void)
{

	static uint8_t TimeToSleep = 0;

	TimeToSleep++;

	// Dummy test
	HAL_GPIO_TogglePin(Sens_Trig_GPIO_Port, Sens_Trig_Pin);

	if (TimeToSleep >= 5)
	{
		//SuperStarStatus.TimeToSleep = true;
		TimeToSleep = 0;
	}


} // END OF callbackLPTIM1_IRQ



/** ****************************************************************************************************
* @brief This is the function that is called by the HAL in response to TIM2 OR TIM21 IRQ Callback.
* TIM2:
* This if condition is responsible for the PWM control of the LEDs.  This function works basically like a PWM.
* The PWM frequency is TIMER1_PWM_PERIOD_COUNT (10) x the IRQ time of the timer.  A Positive PWM is created
* by calculating the desired PWM as a single digit number (0 to 10) which corresponds to 10 to 100%.  The
* Positive part of the cycle is created by settings the LEDs high for that count of time.  The total cycle
* is 10.
*
* TIM21:
* This if condition is responsible for creating a simple 1ms blocking delay.  The timer is set to tick every
* 1 mili-second.
*
* @author 			Hab S. Collector \n
* Last Edited By:  	Hab S. Collector \n
*
* @note The clock rate is not set here - look in cube MX
* @note The frequency of PWM becomes timer clock rate x 10
* @note This function is defined weak by the HAL library - its actual implementation is done here
*
* @param Struct handle to TIM2
* @return void
*
* TIM2:
* STEP 1:
* STEP 2:
* STEP 3:
*
* TIM21:
* STEP 1:
* **************************************************************************************************** */
void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *TimerInIRQ)
{

//	HAL_GPIO_TogglePin(Sens_Echo_GPIO_Port, Sens_Echo_Pin);

	// TIM2 IRQ HANDLER
	if (TimerInIRQ->Instance == TIM2)
	{
		volatile static uint8_t PWM_OnCount = 0;
		volatile static uint8_t PWM_TotalCount = 0;
		volatile uint8_t PWM_AsCount;

		// STEP :
		// Determine the PWM On time as a count (0 - 10) value
		// TODO: Figure out why it was necessary to break up this arithmetic statement.  As a single line the code basically does not run as it should
		PWM_AsCount = (SuperStarStatus.LED_DutyCylcePercent + ROUND_UP_BY_TEN);
		PWM_AsCount /= TIMER1_PWM_PERIOD_COUNT;

		// STEP :
		// Increment the PWM Positive (On Count) and the overall total count
		PWM_OnCount++;
		PWM_TotalCount++;

		// STEP :
		// Determine if on the high (set) or low side of the PWM (clear)
		if (PWM_OnCount <= PWM_AsCount)
			HAL_GPIO_WritePin(Sens_Echo_GPIO_Port, Sens_Echo_Pin, GPIO_PIN_SET);
		else
			HAL_GPIO_WritePin(Sens_Echo_GPIO_Port, Sens_Echo_Pin, GPIO_PIN_RESET);

		// STEP :
		// Determine if time to start a new period of PWM
		if (PWM_OnCount >= TIMER1_PWM_PERIOD_COUNT)
		{
			PWM_OnCount = 0;
			PWM_TotalCount = 0;
		}
	}

	// TIIM21 IRQ HANDLER
	if (TimerInIRQ->Instance == TIM21)
	{
#ifdef USE_TIM21_NOT_SYSTICK
		SuperStarStatus.MiliSecondCounter++;
#endif
	}

} // END OF FUNCTION HAL_TIM_PeriodElapsedCallback



/** ****************************************************************************************************
* @brief This is the call back function of the SysTick IRQ.  It is used here as a generic timer
*
* @author 			Hab S. Collector \n
* Last Edited By:  	Hab S. Collector \n
*
* @note This function is prototyped weak elsewhere
* @note This is the systick timer
* @note Systick Timer clock rate IRQ = 1kHz
* @note Defined as part of the core system - I think it is here by default
*
* @param void
* @return void
*
* STEP 1:
* **************************************************************************************************** */
void HAL_IncTick(void)
{

	// HAL_GPIO_TogglePin(Sens_Trig_GPIO_Port, Sens_Trig_Pin);
#ifndef USE_TIM21_NOT_SYSTICK
	SuperStarStatus.MiliSecondCounter++;
#endif

} // END OF HAL_IncTick



/** ****************************************************************************************************
* @brief Cretes a simple blocking delay based on the TIM21 timer.  By setting the Status milisecond var
* to 0, it will be updated in the IRQ handler.  A test is performed until that amount of time has passed.
*
* @author 			Hab S. Collector \n
* Last Edited By:  	Hab S. Collector \n
*
* @note The clock rate of TIM21 must be set to 1KHz (T = 1ms)
* @note Status var is updated in IRQ
*
* @param Delay value in miliseconds
* @return void
*
* **************************************************************************************************** */
void miliSecondDelay(const uint32_t DelayInMiliSeconds)
{

	// Set to zero and block here until DelayInMiliSeconds amount of time has expired.  SuperStarStatus.MiliSecondCounter is incremented by TIM21 IRQ
	SuperStarStatus.MiliSecondCounter = 0;
	while (SuperStarStatus.MiliSecondCounter < DelayInMiliSeconds);

} // END OF miliSecondDelay





