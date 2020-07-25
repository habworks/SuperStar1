/** ****************************************************************************************************
 * @file 			MainSupport.h
 * @brief			This is the Header file used to support MainSupport.C
 * ****************************************************************************************************
 * @author			Hab S. Collector \n
 * Last Edited By:	Hab S. Collector \n
 *
 * @date			7/19/20 \n
 * Last Edit Date:  7/19/20 \n
 * @version       	See Main.C
 *
 * @param Development_Environment \n
 * Hardware:		ST32LM082 \n
 * IDE:             Atollic TrueStudio, VER 9.3.0 \n
 * Compiler:        GCC \n
 * Editor Settings: 1 Tab = 4 Spaces, Recommended Courier New 11
 *
 * @note            This file is intended to make integration to the CubeMx generated main.c file easier and cleaner
 *                  The CubeMx generated main.c file function main is edited to include just 3 items:
 *                  include MainSupport.h, functions init_main, and main_while_loop
 *
 * 					This is an embedded application
 *		            It will be necessary to consult the reference documents before you can review this code.
 *                  It is suggested that the documents be reviewed in the order shown.
 *			          SuperStar Technical Manual
 *				      SuperStar User Manual
 *
 * @copyright		IMR Engineering
 * **************************************************************************************************** */

#ifndef _MAIN_SUPPORT_H_
#define _MAIN_SUPPORT_H_

#include "main.h"
#include "stdint.h"


// DEFINES: FIRMWARE REVISION
#define FRIMWARE_MAJOR	(0)
#define FIMRWARE_MINOR	(1)
// DEFINES: TRUE and FALSE
#ifdef FALSE
	#warning Trinks & Hab build warning: Note FALSE has already been defined - check previous definition
#endif
#ifdef TRUE
	#warning Trinks & Hab build warning: Note TRUE has already been defined - check previous definition
#endif
// DEFINES: true and false
#ifdef false
	#warning Trinks & Hab build warning: Note FALSE has already been defined - check previous definition
#else
	#define false 0
#endif
#ifdef true
	#warning Trinks & Hab build warning: Note FALSE has already been defined - check previous definition
#else
	#define true 1
#endif
// DEFINES: MISC
#define PERCENT_100		(100.0)
#define ROUND_UP_BY_ONE	(0.5)
#define ROUND_UP_BY_TEN (10.0)
#define _LOAD_DEFAULT_CAL_VALUE


// TYPEDEFS AND ENUMS
typedef _Bool bool;

#ifndef bool_t
	#ifdef FALSE
		#undef FALSE
	#endif
	#ifdef TRUE
		#undef TRUE
	#endif
typedef enum
{
	FALSE = 0,
	TRUE
}bool_t;
#endif

typedef struct
{
	bool_t		ADC_CalValuesLoaded;		// ADC Calibration Values for Divider and Voltage Reference are loaded
	bool_t		ZeroOffsetLoaded;			// Zero Offset Loaded
}Type_InitTest;

typedef struct
{
	volatile uint32_t		MiliSecondCounter;		// Used by TIM21 IRQ to create delay
	volatile float			LED_DutyCylcePercent;	// Duty Cycle LED should run at
	float					ZeroOffset;				// Value measured in feet
	float					ADC_DividerRatio;		// Ratio of the ADC Battery Voltage Diver
	float					ADC_VDDA_Vref;			// Voltage Reference of ADC VDDA Voltage Reference
	Type_InitTest			InitTest;
}Type_SuperStarStatus;


// FUNCTION PROTOTYPES
void main_Init(void);
void main_WhileLoop(void);

#endif
