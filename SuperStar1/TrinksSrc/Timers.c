/** ****************************************************************************************************
 * @file 			Timers.c
 * @brief			This Source file used to support uC Peripheral: Low Power Timer (LPTIM), Timer2 (TIM2),  Timer21 (TIM21)
 * ****************************************************************************************************
 * @author			Hab S. Collector \n
 * Last Edited By:	Trinkie H. Collector \n
 *
 * @date			7/22/20 \n
 * Last Edit Date:  8/7/20 \n
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
* Last Edited By:  	Trinkie H. Collector \n
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
	static uint8_t DelayBeforeCalibrateTick = 0;

	TimeToSleep++;

	// STEP :
	// If calibration interval flag is set - clear on the next IRQ
	if (SuperStarStatus.Calibrate_LPTCLK.SetToCalibrate == true)
	{
		DelayBeforeCalibrateTick++;
		if (DelayBeforeCalibrateTick > 1)
		{
			SuperStarStatus.Calibrate_LPTCLK.SetToCalibrate = false;
			DelayBeforeCalibrateTick = 0;
		}
	}

	if (TimeToSleep >= 5)
	{
		//SuperStarStatus.TimeToSleep = true;
		TimeToSleep = 0;
	}


} // END OF callbackLPTIM1_IRQ



/** ****************************************************************************************************
* @brief This is the function that is called by the HAL in response to TIM2 OR TIM21 IRQ Callback.
* TIM2:
* This IRQ is responsible for the PWM control of the LEDs.  This IRQ works basically like a PWM.
* The PWM frequency is TIMER_PWM_PERIOD_COUNT x the IRQ time of this timer (100us) - Therefore 10 x 100us = 1ms or 1KHz.
* This routine creates a  Positive PWM Duty Cycle for use in conserving power by limiting LED energy output.
* The routine calculates the desired PWM as a single digit number (0 to 10) which corresponds to 0 to 100%.  The
* Positive part of the cycle is created by settings the LEDs high for that count of time.  The total cycle
* is 10.
*
* TIM21:
* Not used
*
* @author 			Hab S. Collector \n
* Last Edited By:  	Trinkie S. Collector \n
*
* @note The clock rate is not set here - look in cube MX
* @note The frequency of PWM becomes timer clock rate x 10
* @note This function is defined weak by the HAL library - its actual implementation is done here
* @note This function is part of an IRQ handler - it should not block and it should be very quick
*
* @param Struct handle to TIM2
* @return void
*
* TIM2: WORK IN PROGRESS
* STEP 1:
* STEP 2:
* STEP 3:
*
* **************************************************************************************************** */
void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *TimerInIRQ)
{

	// TIM2 IRQ HANDLER
	if (TimerInIRQ->Instance == TIM2)
	{
		volatile static uint8_t PWM_OnCount = 0;
		volatile static uint8_t PWM_TotalCount = 0;
		volatile uint8_t PWM_AsCount;
		//SuperStarStatus.Calibrate_LPTCLK.TickCount++;

		// STEP :
		// Increment distance time counter
		SuperStarStatus.DistanceMeasureTimeOut++;
		SuperStarStatus.RoundTripTicksToTarget++;

		// STEP :
		// Determine the PWM On time as a count (0 - 10) value
		// TODO: Figure out why it was necessary to break up this arithmetic statement.  As a single line the code basically does not run as it should
		PWM_AsCount = (SuperStarStatus.LED_DutyCylcePercent + ROUND_UP_BY_TEN);
		PWM_AsCount /= PWM_PERIOD_FULL_COUNT;

		// STEP :
		// Increment the PWM Positive (On Count) and the overall total count
		PWM_OnCount++;
		PWM_TotalCount++;

		// STEP :
		// Determine if this count is on the high (set) or low side of the PWM (clear)
/*
		if (PWM_OnCount <= PWM_AsCount)
			HAL_GPIO_WritePin(Sens_Echo_GPIO_Port, Sens_Echo_Pin, GPIO_PIN_SET);
		else
			HAL_GPIO_WritePin(Sens_Echo_GPIO_Port, Sens_Echo_Pin, GPIO_PIN_RESET);
*/

		// STEP :
		// Determine if time to start a new period of PWM - If so reset PWM On count and total PWM count
		if (PWM_OnCount >= PWM_PERIOD_FULL_COUNT)
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
		SuperStarStatus.Calibrate_LPTCLK.TickCount++;
#endif
	}

} // END OF FUNCTION HAL_TIM_PeriodElapsedCallback



/** ****************************************************************************************************
* @brief This is the call back function of the SysTick IRQ.  It is used here as a generic timer
*
* @author 			Hab S. Collector \n
* Last Edited By:  	Trinkie H. Collector \n
*
* @note This function is prototyped weak elsewhere
* @note This is the SysTick timer
* @note Systick Timer clock rate IRQ = 1kHz
* @note Defined as part of the core system - I think it is here by default
* @note This function is part of an IRQ handler - it should not block and it should be very quick
*
* @param void
* @return void
*
* STEP 1: Increment the tick values used in functions: miliSecondDelay and calibrate_LPTIMCLK
* **************************************************************************************************** */
void HAL_IncTick(void)
{

	// STEP 1:
	// Increment the tick values used in functions: miliSecondDelay and calibrate_LPTIMCLK
#ifndef USE_TIM21_NOT_SYSTICK
	SuperStarStatus.MiliSecondCounter++;
	SuperStarStatus.Calibrate_LPTCLK.TickCount++;
#endif

} // END OF HAL_IncTick



/** ****************************************************************************************************
* @brief Cretes a simple blocking delay based on the SysTick timer.  By setting the Status millisecond var
* to 0, it will be updated  / incremented in the IRQ handler 1 tick per millisecond.  A test is performed
* until that amount of time has passed.
*
* @author 			Hab S. Collector \n
* Last Edited By:  	Trinkie H. Collector \n
*
* @note The clock rate of TIM21 must be set to 1KHz (T = 1ms)
* @note Status var is updated in IRQ
*
* @param Delay value in milliseconds
* @return void
*
* WHY: A delay will be useful for many things - especially in the display of information
*
* STEP 1: Set to zero and block until DelayInMiliSeconds has reached.  SuperStarStatus.MiliSecondCounter is incremented by HAL SysTick Timer IRQ
* **************************************************************************************************** */
void miliSecondDelay(const uint32_t DelayInMiliSeconds)
{

	// STEP 1:
	// Set to zero and block until DelayInMiliSeconds has reached.  SuperStarStatus.MiliSecondCounter is incremented by HAL SysTick Timer IRQ
	SuperStarStatus.MiliSecondCounter = 0;
	while (SuperStarStatus.MiliSecondCounter < DelayInMiliSeconds);

} // END OF miliSecondDelay



/** ****************************************************************************************************
* @brief Calibration to calculate the compare value register used by the LPTIM to set the IRQ interval.
* The desired interval is entered as IRQ_IntervalInMiliSeconds interval.  This function works with the
* HAL timer - the HAL timer is used as the time base reference.
*
* @author 			Hab S. Collector \n
* Last Edited By:  	Trinkie H. Collector \n
*
* @note The LPTIM must be init before calling this function - this function will stop the LPTIM if running
* @note The clock rate of LPTIM is 37KHz and it has a divider
* @note The value returned is what the LPTIM compare register should be set to in order to obtain the
* desired IRQ_IntervalInMiliSeconds interval
* @note User must used the return value to start the LPTIM
* @note The tick interval of the calibration timer (systick) must be significantly faster than the tick
* interval of the LPTIM
* @note It is unclear how much this routine will improve the overall accuracy of the LPTIM
*
* @param Delay value in milliseconds
* @return Value the LPTIM should be set to for desired IRQ interval
*
* WHY: In this application the LPTIM is clocked by the LSI RC clock.  This clock source has a nominal
* value of 37KHz, but it is highly inaccurate and likely to drift over time, temperature and voltage.  The
* calibration will help to ensure the right timer period is kept over time.
*
* STEP 1: Stop the LPTIM if running and clear any pending IRQs
* STEP 2: Set the initial conditions to start calibration
* STEP 3: Start the LPTIM to IRQ at the test interval compare (LPTIM_CALIBRATION_COMPARE)
* STEP 4: Calculate the LPTIM ACTUAL clock frequency - it is nominal 37KHz but may be different as the LSI RC is most inaccurate
* STEP 5: Calculate LPTIM Compare value necessary to reach desired IRQ based on the actual clock frequency of the LPTIM
* **************************************************************************************************** */
uint32_t calibrate_LPTIMCLK(uint32_t const IRQ_IntervalInMiliSeconds)
{

	// STEP 1:
	// Stop the LPTIM if running and clear any pending IRQs
	HAL_LPTIM_Counter_Stop_IT(&hlptim1);
	LPTIM1->ICR |= 0x3F;

	// STEP 2:
	// Set the initial conditions to start calibration
	SuperStarStatus.Calibrate_LPTCLK.SetToCalibrate = true;
	SuperStarStatus.Calibrate_LPTCLK.TickCount = 0;

	// STEP 3:
	// Start the LPTIM to IRQ at the test interval compare (LPTIM_CALIBRATION_COMPARE)
	while(HAL_LPTIM_Counter_Start_IT(&hlptim1, LPTIM_CALIBRATION_COMPARE) != HAL_OK);
	// Wait until the test case is false - the test case is set with the LPTIM IRQ handler
	// During this time the HAL will increment the Calibrate TickCount - The tick count is measure in 1ms intervals and is assumed to be accurate
	while (SuperStarStatus.Calibrate_LPTCLK.SetToCalibrate == true);
	HAL_LPTIM_Counter_Stop_IT(&hlptim1);

	// STEP 4:
	// Calculate the LPTIM ACTUAL clock frequency - it is nominal 37KHz but may be different as the LSI RC is most inaccurate
	double MeasuredPeriod = SuperStarStatus.Calibrate_LPTCLK.TickCount * 0.001;
	double LPTCLK_frequency = (1.0 / (MeasuredPeriod / LPTIM_CALIBRATION_COMPARE)) * LPTIM_CLOCK_PRESCALER;

	// STEP 5:
	// Calculate LPTIM Compare value necessary to reach desired IRQ based on the actual clock frequency of the LPTIM
	double LPT_IRQ_Period = IRQ_IntervalInMiliSeconds * 0.001;
	double LPT_IRQ_CompareValue = LPT_IRQ_Period / (1.0 / (LPTCLK_frequency / LPTIM_CLOCK_PRESCALER));
	return ((uint32_t)LPT_IRQ_CompareValue);

} // END OF calibrate_LPTIMCLK


