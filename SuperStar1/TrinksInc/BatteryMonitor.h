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

#ifndef _BATTERY_MONITOR_H_
#define _BATTERY_MONITOR_H_

// DEFINES
#define ADC_FULL_SCALE_VALUE			0x03FF
#define VOLTAGE_DIVIDER_RA				57600.0
#define VOLTAGE_DIVIDER_RB				100000.0
#define DEFAULT_VOLTAGE_DIVIDER_RATIO	(float)(VOLTAGE_DIVIDER_RA/(VOLTAGE_DIVIDER_RA + VOLTAGE_DIVIDER_RB))
#define DEFAULT_VOLTAGE_VDDA_REFERENCE	3.300
#define BATTERY_NOMINAL_VOLTAGE			9.000
#define VOLT_ARRAY_SIZE					20
#define BATTERY_LOW_VOLATGE_THRESHOLD 	8.0

// FUNCTION PROTOTYPES
float readBatteryVoltage(void);
float rollingAverageBatVolt (float NowVoltage);
void errorCheck (float AverageVoltage);

#endif
