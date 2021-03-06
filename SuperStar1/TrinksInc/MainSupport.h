/** ****************************************************************************************************
 * @file 			MainSupport.h
 * @brief			This is the Header file used to support MainSupport.C
 * ****************************************************************************************************
 * @author			Hab S. Collector \n
 * Last Edited By:	Trinkie H. Collector \n
 *
 * @date			7/19/20 \n
 * Last Edit Date:  8/3/20 \n
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

// DEFINES: BUILD CONFIGURATION
#define _USE_LOAD_DEFAULT_CAL_VALUE
#define _USE_SLEEP_MODE


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
	bool_t					ADC_CalValuesLoaded;		// ADC Calibration Values for Divider and Voltage Reference are loaded
	bool_t					ZeroOffsetLoaded;			// Zero Offset Loaded
}Type_InitTest;

typedef struct
{
	volatile bool_t			SetToCalibrate;
	volatile uint32_t		TickCount;
}Type_Calibrate_LPTCLK;

typedef enum
{
	E0_NoError = 0,  		// NO ERROR CODE, display nothing
	E1_NoZero = 1, 			// ZERO SWITCH NOT SET
	E2_LowBat = 2, 			// LOW BATTERY, (build to order�. User may use outlet power form wall) (then no need for ADC?)
	E3_NoEchoHigh = 3, 		// NO ECHO�.. An error we shouldn�t get� for testing
	E4_NoEchoLow = 4, 		// ECHO NEVER LOW� an error we shouldn�t get�. For testing
}Typedef_ErrorCodes;


typedef struct
{
	volatile bool_t			TimeToSleep;
	volatile uint16_t		RoundTripTicksToTarget;	// Distance Measure Time to target and back
	volatile uint16_t		DistanceMeasureTimeOut;
	volatile uint32_t		MiliSecondCounter;		// Used by TIM21 IRQ to create delay
	volatile float			LED_DutyCylcePercent;	// Duty Cycle LED should run at
	float					ZeroOffset;				// Value measured in feet
	float					ADC_DividerRatio;		// Ratio of the ADC Battery Voltage Diver
	float					ADC_VDDA_Vref;			// Voltage Reference of ADC VDDA Voltage Reference
	Type_InitTest			InitTest;
	Type_Calibrate_LPTCLK	Calibrate_LPTCLK;
	Typedef_ErrorCodes		ErrorCodeEnum;
}Type_SuperStarStatus;




// FUNCTION PROTOTYPES
void main_Init(void);
void main_WhileLoop(void);
float distanceToTarget (void);
void intDefaultState (void);

#endif
