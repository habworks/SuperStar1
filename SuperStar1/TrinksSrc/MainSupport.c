/** ****************************************************************************************************
 * @file 			MainSupport.c
 * @brief			This is the Source file used to support the main.c CubeMx generated file
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

#include "MainSupport.h"
#include "LED_Control.h"
#include "BatteryMonitor.h"
#include "NV_Memory.h"
#include "adc.h"
#include "stm32l0xx_hal_adc_ex.h"

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
* STEP 1: Perform the ADC Calibration
* STEP 2: Load SuperStart Settings from memory
* **************************************************************************************************** */
void main_Init(void)
{

	// TODO: Trinks this is a quick way to program the calibration - think about if you want to do something different
#ifdef LOAD_DEFAULT_CAL_VALUE
	writeByteNVM(MEMORY_OFFSET_ADC_CALIBRATION_PROGRAMED, ADC_CALIBRATION_INSTALLED);
	writeFloatNVM(MEMORY_OFFSET_ADC_VDDA_VREF, 3.3201);
	writeFloatNVM(MEMORY_OFFSET_DIVIDER_RATIO, 0.3638);
#endif

	// STEP :
	// Perform the ADC Calibration
	while(HAL_ADCEx_Calibration_Start(&hadc, ADC_SINGLE_ENDED) != HAL_OK);

	// STEP :
	// Load SuperStart Settings from memorySTEP 2: Load SuperStart Settings from memory
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
void main_WhileLoop(void)
{

	float PresentBatteryVoltage;

	PresentBatteryVoltage = readBatteryVoltage();

	volatile uint32_t DummyVar = 0;
	volatile uint32_t FullCount = 400000;

	// LED TESING:
	HAL_GPIO_WritePin(Sens_Trig_GPIO_Port, Sens_Trig_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(Sens_Echo_GPIO_Port, Sens_Echo_Pin, GPIO_PIN_SET);
	ON_RLED1();
	ON_RLED2();
	ON_RLED3();
	ON_RLED4();
	ON_RLED5();
	ON_RLED6();
	ON_RLED7();
	ON_RLED8();
	//ALL RED SHOULD BE ON//
	for(uint32_t DelayCounter = 0; DelayCounter < FullCount; DelayCounter++)
	  {
		  DummyVar++;
	  }
	HAL_GPIO_WritePin(Sens_Trig_GPIO_Port, Sens_Trig_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(Sens_Echo_GPIO_Port, Sens_Echo_Pin, GPIO_PIN_RESET);
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

	for(uint32_t DelayCounter = 0; DelayCounter < FullCount; DelayCounter++)
		  {
			  DummyVar++;
		  }

	OFF_GLED1();
	OFF_GLED2();
	OFF_GLED3();
	OFF_GLED4();
	OFF_GLED5();
	OFF_GLED6();
	OFF_GLED7();
	OFF_GLED8();
	//ALL GREEN LEDs SHOULD BE OFF//


} // END OF FUNCTION init_main


