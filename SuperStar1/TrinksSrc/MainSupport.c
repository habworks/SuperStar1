/** ****************************************************************************************************
 * @file 			MainSupport.c
 * @brief			This is the Source file used to support the main.c CubeMx generated file
 * ****************************************************************************************************
 * @author			Hab S. Collector \n
 * Last Edited By:	Hab S. Collector \n
 *
 * @date			7/19/20 \n
 * Last Edit Date:  7/25/20 \n
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

#include "MainSupport.h"
#include "LED_Control.h"
#include "BatteryMonitor.h"
#include "NV_Memory.h"
#include "Timers.h"
#include "Sleep.h"
#include "adc.h"
#include "stm32l0xx_hal_adc_ex.h"
#include "lptim.h"
#include "tim.h"

// GLOBAL VARS
volatile Type_SuperStarStatus SuperStarStatus;



/** ****************************************************************************************************
* @brief This function will perform the initialization routines necessary for SuperStar. It will include
* all items that need to be processed ONE TIME before the main endless while loop.
* This function should be placed within function main between comments:  USER CODE BEGIN 2 and USER CODE END 2
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
void main_Init(void)
{

	// STEP :
	// Init SuperStar Status
	// TODO: Trinks set all SuperStar Status members to zero or default state
	SuperStarStatus.TimeToSleep = false;

	// STEP :
	// Setup Flash memory
	// TODO: Trinks this is a quick way to program the calibration - think about if you want to do something different
#ifdef USE_LOAD_DEFAULT_CAL_VALUE
	writeByteNVM(MEMORY_OFFSET_ADC_CALIBRATION_PROGRAMED, ADC_CALIBRATION_INSTALLED);
	writeFloatNVM(MEMORY_OFFSET_ADC_VDDA_VREF, 3.3201);
	writeFloatNVM(MEMORY_OFFSET_DIVIDER_RATIO, 0.3638);
#endif
	flashMemoryPwrDwnWhenInSleep();
	// STEP :
	// Perform the ADC Calibration
	while(HAL_ADCEx_Calibration_Start(&hadc, ADC_SINGLE_ENDED) != HAL_OK);

	// STEP :
	// Load SuperStart Settings from memory
	uint8_t ADC_CalibrationCode;
	ADC_CalibrationCode = readByteNVM(MEMORY_OFFSET_ADC_CALIBRATION_PROGRAMED);
	if (ADC_CalibrationCode == ADC_CALIBRATION_INSTALLED)
	{
		SuperStarStatus.InitTest.ADC_CalValuesLoaded = true;
		SuperStarStatus.ADC_DividerRatio = readFloatNVM(MEMORY_OFFSET_DIVIDER_RATIO);
		SuperStarStatus.ADC_VDDA_Vref = readFloatNVM(MEMORY_OFFSET_ADC_VDDA_VREF);
	}
	else
	{
		SuperStarStatus.InitTest.ADC_CalValuesLoaded = false;
		SuperStarStatus.ADC_DividerRatio = DEFAULT_VOLTAGE_DIVIDER_RATIO;
		SuperStarStatus.ADC_VDDA_Vref = DEFAULT_VOLTAGE_VDDA_REFERENCE;
	}
	/* TODO: Trinks add code to see if zero offset is loaded if not load the default */

	// STEP :
	// Init the Low Power Timer (LPTIM)
	while(HAL_LPTIM_Counter_Start_IT(&hlptim1, 23437) != HAL_OK);

	// STEP :
	// Init the Timer2
	while(HAL_TIM_Base_Start_IT(&htim2) != HAL_OK);

	// STEP :
	// Init the Timer21
	while(HAL_TIM_Base_Start_IT(&htim21) != HAL_OK);

} // END OF FUNCTION init_main



/** ****************************************************************************************************
* @brief This function will perform the main while loop routines necessary for SuperStar. It will include
* all items that need to be processed continually within main.c while never ending loop.
* This function should be placed within function main between comments:  USER CODE BEGIN WHILE and USER CODE END WHILE
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
* **************************************************************************************************** */

uint8_t TestNum;

void main_WhileLoop(void)
{

	// HOW TO READ BATTERY VOLTAGE
	float PresentBatteryVoltage;
	PresentBatteryVoltage = readBatteryVoltage();
  // HOW TO CALCULATE DUTY CYCLE OF BATTERY
	SuperStarStatus.LED_DutyCylcePercent = ((PresentBatteryVoltage/BATTERY_NOMINAL_VOLTAGE) * PERCENT_100);

<<<<<<< HEAD
	// LED TESING:
	ON_RLED1();
	ON_RLED2();
	ON_RLED3();
	ON_RLED4();
	ON_RLED5();
	ON_RLED6();
	ON_RLED7();
	ON_RLED8();
	//ALL RED SHOULD BE ON//
	miliSecondDelay(500);

	OFF_RLED1();
	OFF_RLED2();
	OFF_RLED3();
	OFF_RLED4();
	OFF_RLED5();
	OFF_RLED6();
	OFF_RLED7();
	OFF_RLED8();
	//ALL RED LEDs SHOULD BE OFF//

	//NEXT COLOR//
	ON_GLED1();
	ON_GLED2();
	ON_GLED3();
	ON_GLED4();
	ON_GLED5();
	ON_GLED6();
	ON_GLED7();
	ON_GLED8();

	miliSecondDelay(500);

	// TEST SLEEP
	// ADD LEDS OFF
	OFF_GLED1();
	OFF_GLED2();
	OFF_GLED3();
	OFF_GLED4();
	OFF_GLED5();
	OFF_GLED6();
	OFF_GLED7();
	OFF_GLED8();
	miliSecondDelay(1000);

#ifdef USE_SLEEP_MODE
	if (SuperStarStatus.TimeToSleep == true)
	{
		// Setup to sleep
		prepareToSleepTasks();

		/* Enter Sleep Mode - Set to wake from LPTim IRQ */
		HAL_PWR_EnterSLEEPMode(PWR_LOWPOWERREGULATOR_ON, PWR_SLEEPENTRY_WFI);
		//HAL_PWR_EnterSTOPMode(PWR_LOWPOWERREGULATOR_ON, PWR_STOPENTRY_WFI);

		// Processor has awoke - reconfigure to run
		wakeFromSleepTasks();

		SuperStarStatus.TimeToSleep = false;
	}
#endif
=======
>>>>>>> 16ccc00d192a4524aec811c02cb2a0fa43230e4a

	static uint8_t TestNumONE = 0;
	static uint8_t TestNumTENTHS = 9;

	static uint8_t ErrorCode = 0;
	displayErrorCode(ErrorCode);
	ErrorCode++;


	POWER_ON_SENSOR_DP();
	//displayNumONE(TestNumONE);
	//displayNumTENTH(TestNumTENTHS);
	TestNumONE++;
	TestNumTENTHS--;;

	ledFLASH_test_1();


} // END OF FUNCTION init_WhileLoop



