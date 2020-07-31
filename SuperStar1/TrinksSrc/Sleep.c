/** ****************************************************************************************************
 * @file 			NV Memory.h
 * @brief			This is the Source file used to support Sleep and wake from sleep
 * ****************************************************************************************************
 * @author			Hab S. Collector \n
 * Last Edited By:	Hab S. Collector \n
 *
 * @date			7/26/20 \n
 * Last Edit Date:  7/26/20 \n
 * @version       	See Main.C
 *
 * @param Development_Environment \n
 * Hardware:		ST32LM082 \n
 * IDE:             Atollic TrueStudio, VER 9.3.0 \n
 * Compiler:        GCC \n
 * Editor Settings: 1 Tab = 4 Spaces, Recommended Courier New 11
 *
 * @note            This file supports the use of sleep and wake from sleep  on STM32L010C6
 *                  Low Power Sleep Mode is the mode of sleep in use
 *                  See section 34 of ST UM1749
 * 					See also: https://www.digikey.com/eewiki/display/microcontroller/Low-Power+Modes+on+the+STM32L0+Series
 *		            It will be necessary to consult the reference documents before you can review this code.
 *                  It is suggested that the documents be reviewed in the order shown.
 *			          SuperStar Technical Manual
 *				      SuperStar User Manual
 *
 * @copyright		IMR Engineering
 * **************************************************************************************************** */

#include "Sleep.h"
#include "MainSupport.h"
#include "stm32l0xx_hal.h"
#include "tim.h"


extern Type_SuperStarStatus SuperStarStatus;


/** ****************************************************************************************************
* @brief Performs all the necessary actions to prepare the uC to sleep in the lowest possible sleep state
*
* @author 			Hab S. Collector \n
* Last Edited By:  	Hab S. Collector \n
*
* @note It is possible to seep with just the necessary items set (as called out below)
* @note But for the lowest power possible additional actions must be taken
* @note The total power consumed during sleep is what the uC will consume + what the board in its sleep state
* @note It is necessary to set the board to its quiescent power state before sleep
*
* @param void
* @return void
*
* WHY: For max battery life the board must sleep most of its existence.
* To save the most power during sleep - need to place items in lowest possible power consumption state \n
*
* STEP 1:
* STEP 2:
* STEP 3:
* **************************************************************************************************** */
void prepareToSleepTasks(void)
{

	// STEP :
	// Set board to its quiescent state
	// allLEDsOff()
	// allSevenSegmentsOff()
	// poweroffSensor()


	// STEP :
	// Set the necessary condtions for sleep
	//HAL_SuspendTick();

	HAL_TIM_Base_Stop_IT(&htim2);
	HAL_TIM_Base_Stop_IT(&htim21);

	__NOP();	// Not really necessary - but just to ensure any pending commands are flushed
	__NOP();	// Not really necessary - but just to ensure any pending commands are flushed

	HAL_TIM_Base_MspDeInit(&htim2);
	HAL_TIM_Base_MspDeInit(&htim21);

    /* Enable the power down mode during Sleep mode */
    __HAL_FLASH_SLEEP_POWERDOWN_ENABLE();

    /* Suspend Tick increment to prevent wakeup by Systick interrupt.         */
    /* Otherwise the Systick interrupt will wake up the device within 1ms     */
    /* (HAL time base).                                                       */
    HAL_SuspendTick();
    //_SLEEP_POWERDOWN_ENABLE();

} // END OF prepareToSleepTasks



/** ****************************************************************************************************
* @brief Performs all the necessary actions to prepare the uC to do its normal running tasks after it has
* awoken from sleep
*
* @author 			Hab S. Collector \n
* Last Edited By:  	Hab S. Collector \n
*
* @note The clock speed was changed during sleep
* @note All IRQs other than LPTIM must be restarted
* @note Additional actions are necessary to restart the ADC after sleep
* @note The board went to sleep because it had nothing to do
*
* @param void
* @return void
*
* WHY: Sleep state and run states are different.  Coming out of sleep the board must be re-configured to
* its running mode for correct operation.  The actions to go into sleep must be essentially undone. \n
*
* STEP 1:
* STEP 2:
* STEP 3:
* **************************************************************************************************** */
void wakeFromSleepTasks(void)
{
	// STEP :
	// Resume Timer ticks and IRQs
	HAL_ResumeTick();

	HAL_TIM_Base_MspInit(&htim2);
	HAL_TIM_Base_MspInit(&htim21);

	HAL_TIM_Base_Start_IT(&htim2);
	HAL_TIM_Base_Start_IT(&htim21);

	// STEP :
	// Perform action to restart ADC
	HAL_ADCEx_EnableVREFINT();

} // END OF wakeFromSleepTasks
