/** ****************************************************************************************************
 * @file 			NV Memory.h
 * @brief			This is the Header file used to support Sleep.C
 * ****************************************************************************************************
 * @author			Hab S. Collector \n
 * Last Edited By:	Hab S. Collector \n
 *
 * @date			7/26/20 \n
 * Last Edit Date:  8/1/20 \n
 * @version       	See Main.C
 *
 * @param Development_Environment \n
 * Hardware:		ST32LM082 \n
 * IDE:             Atollic TrueStudio, VER 9.3.0 \n
 * Compiler:        GCC \n
 * Editor Settings: 1 Tab = 4 Spaces, Recommended Courier New 11
 *
 * @note            This file supports the use of sleep and wake from slepp  on STM32L010C6
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

#ifndef _SLEEP_H_
#define _SLEEP_H_

// DEFINES
#define NOP_CYCLES_BEFORE_SLEEP		(1000U)


// PROTOTYPE FUNCTIONS
void prepareToSleepTasks(void);
void wakeFromSleepTasks(void);
void lowPowerConfig_GPIO(void);

#endif
