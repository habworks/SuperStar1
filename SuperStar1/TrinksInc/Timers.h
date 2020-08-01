/** ****************************************************************************************************
 * @file 			Timers.h
 * @brief			This Header file used to support uC Peripheral: Low Power Timer (LPTIM), Timer2 (TIM2),  Timer21 (TIM21)
 * ****************************************************************************************************
 * @author			Hab S. Collector \n
 * Last Edited By:	Hab S. Collector \n
 *
 * @date			7/22/20 \n
 * Last Edit Date:  7/24/20 \n
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
#define TIMER1_PWM_PERIOD_COUNT			(10U)

// DEFINES: CONFIGURE
#define _USE_TIM21_NOT_SYSTICK


// FUNCTION PROTOTYPES
void callbackLPTIM1_IRQ(void);
void miliSecondDelay(const uint32_t DelayInMiliSeconds);

#endif
