/** ****************************************************************************************************
 * @file 			NV Memory.h
 * @brief			This is the Source file used to support Sleep and wake from sleep
 * ****************************************************************************************************
 * @author			Hab S. Collector \n
 * Last Edited By:	Hab S. Collector \n
 *
 * @date			7/26/20 \n
 * Last Edit Date:  8/2/20 \n
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
#include "LED_Control.h"
#include "stm32l0xx_hal.h"
#include "adc.h"
#include "tim.h"
#include "lptim.h"
#include "gpio.h"


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
	// Disable external Zero IRQ to avoid re-trigger and Clear EXTI line to be sure there is no ongoing interrupt of line
    __HAL_GPIO_EXTI_CLEAR_IT(SW_Zero_Pin);
	HAL_NVIC_DisableIRQ(EXTI4_15_IRQn);

    // STEP :
    // Slow the system clock way down
    RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};

    RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK | RCC_CLOCKTYPE_SYSCLK |
                                  RCC_CLOCKTYPE_PCLK1 | RCC_CLOCKTYPE_PCLK2;
    RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_MSI; // This is changed from RCC_SYSCLKSOURCE_HSI used for normal run mode;
    RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
    RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV16;
    RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;
    if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_0) != HAL_OK)
    {
      Error_Handler();
    }

	// STEP :
	// Set board to its quiescent state: LEDs off, 7-Seg off, Sensor off
	all_LedOFF();
	segONE_OFF();
	segTENTH_OFF();
	POWER_OFF_SESNOR_DP();

	// STEP :
	// Set timers to low power
	// Timer 1 and Timer 21
	HAL_TIM_Base_Stop_IT(&htim2);
	HAL_TIM_Base_MspDeInit(&htim2);
#ifdef 	USE_TIM21_NOT_SYSTICK
	HAL_TIM_Base_Stop_IT(&htim21);
	HAL_TIM_Base_MspDeInit(&htim21);
#endif
	// System Tick
    HAL_SuspendTick();

    // STEP :
    // ADC to turn off
    HAL_ADC_MspDeInit(&hadc);

    // STEP :
    // Disable GPIO
    __HAL_RCC_GPIOA_CLK_DISABLE();
    __HAL_RCC_GPIOB_CLK_DISABLE();
    __HAL_RCC_GPIOC_CLK_DISABLE();
    __HAL_RCC_GPIOH_CLK_DISABLE();


    // STEP :
    // Set Flash for low power during sleep
    __HAL_FLASH_SLEEP_POWERDOWN_ENABLE();


    // STEP :
    // Enable IRQ to allow Zero wake from sleep
    HAL_NVIC_EnableIRQ(EXTI4_15_IRQn);

    // STEP:
    // Just to be safe run a few NOP to allow time to settle
    for (uint16_t NOP_CycleCount = 0; NOP_CycleCount < NOP_CYCLES_BEFORE_SLEEP; NOP_CycleCount++)
    {
    	__NOP();	// Not really necessary - but just to ensure any pending commands are flushed
    }

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
    // Slow the system clock way down
    RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};

    RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK | RCC_CLOCKTYPE_SYSCLK |
                                  RCC_CLOCKTYPE_PCLK1 | RCC_CLOCKTYPE_PCLK2;
    RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_HSI;
    RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
    RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV16;
    RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;
    if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_0) != HAL_OK)
    {
      Error_Handler();
    }

	// STEP :
	// Resume Timer ticks and IRQs for run time use
	HAL_TIM_Base_MspInit(&htim2);
	HAL_TIM_Base_Start_IT(&htim2);
#ifdef USE_TIM21_NOT_SYSTICK
	HAL_TIM_Base_MspInit(&htim21);
	HAL_TIM_Base_Start_IT(&htim21);
#endif
	HAL_ResumeTick();

	// STEP :
	// Enable GPIOs for run time use
	MX_GPIO_Init();

	// STEP :
	// Perform action to restart ADC and make ready for run time use
	HAL_ADCEx_EnableVREFINT();
	HAL_ADC_MspInit(&hadc);

} // END OF wakeFromSleepTasks



void lowPowerConfig_GPIO(void)
{

  GPIO_InitTypeDef GPIO_InitStructure;
  /* Configure all GPIO port pins in Analog Input mode (floating input trigger OFF) */
  uint32_t PinsToSet = 0x00000000;
  PinsToSet = ~(SW_CLK_Pin | SW_DIO_Pin);
  PinsToSet = PinsToSet & GPIO_PIN_All;
  GPIO_InitStructure.Pin = PinsToSet;
  GPIO_InitStructure.Speed = GPIO_SPEED_FREQ_LOW;
  GPIO_InitStructure.Mode = GPIO_MODE_ANALOG;

  // Mode Register set to Analog Mode
//  GPIOA->MODER = 0xFFFFFFFF;
//  GPIOB->MODER = 0xFFFFFFFF;
//  GPIOC->MODER = 0xFFFFFFFF;
//  GPIOH->MODER = 0xFFFFFFFF;

  // PullUp PullDown Register set to pull-down
  GPIOA->PUPDR = 0x24AAAAAA;
  GPIOB->PUPDR = 0xAAAAAAAA;
  GPIOC->PUPDR = 0xAAAAAAAA;
  GPIOH->PUPDR = 0xAAAAAAAA;

  HAL_GPIO_Init(GPIOA, &GPIO_InitStructure);
  HAL_GPIO_Init(GPIOB, &GPIO_InitStructure);
  HAL_GPIO_Init(GPIOC, &GPIO_InitStructure);

} // END OF lowPowerConfig_GPIO


void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin)
{

	if (GPIO_Pin == SW_Zero_Pin)
	{
		SuperStarStatus.TimeToSleep = !SuperStarStatus.TimeToSleep;
	}


}
