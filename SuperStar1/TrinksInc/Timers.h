/** ****************************************************************************************************
 * @file 			Timers.h
 * @brief			This Header file used to support uC Peripheral: Low Power Timer (LPTIM), Timer2 (TIM2),  Timer21 (TIM21)
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

#ifndef _TIMERS_H_
#define _TIMERS_H_
#include "stdint.h"


// DEFINES: TIMER 1 PWM CALCULATION
#define PWM_PERIOD_FULL_COUNT			(10U)

// DEFINES: ASSOCIATED WITH LPTIM TIMER
#define LPTIM_IRQ_IN_MILI_SECONDS		(3000U)
#define SLEEP_TIME_IN_MILI_SECONDS		LPTIM_IRQ_IN_MILI_SECONDS
#define LPTIM_CALIBRATION_COMPARE		(100U)						// Arbitrary value used in calibration of LPTIM clock
#define LPTIM_CLOCK_PRESCALER			(32U)						// Value muse equal the LPTIM clock pre-scaler
#define LPTIM_CYCLE_TO_CALIBRATION		(6U)						// How many cycles of main while loop before issuing a calibration of the LPTIM clock

// DEFINES: BUILD CONFIGURATION
#define _USE_TIM21_NOT_SYSTICK


// FUNCTION PROTOTYPES
void callbackLPTIM1_IRQ(void);
void miliSecondDelay(const uint32_t DelayInMiliSeconds);
uint32_t calibrate_LPTIMCLK(const uint32_t IRQ_InMiliSeconds);

#endif
