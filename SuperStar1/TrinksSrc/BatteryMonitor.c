//TODO: Trinks add file header comments

#include "BatteryMonitor.h"
#include "MainSupport.h"
#include "adc.h"

extern Type_SuperStarStatus SuperStarStatus;


/** ****************************************************************************************************
* @brief Read the battery voltage
*
* @author 			Hab S. Collector \n
* Last Edited By:  	Hab S. Collector \n
*
* @note This function is intended for general use within the application
* @note No other pre or post function calls are necessary other than the initial ADC init
*
* @param void
* @return Battery Voltage in volts
*
* WHY: Knowing the battery voltage will allow us to correlate it to battery energy remaining \n
*
* STEP 1: Start ADC read \n
* STEP 2: Wait for ADC read to complete \n
* STEP 3: On completion success read ADC Digital Value and compute battery voltage on Fail stop and reset the ADC \n
* STEP 4: Return the battery voltage \n
* **************************************************************************************************** */
float readBatteryVoltage(void)
{

	uint16_t ADC_DigitalRead;
	float BatteryVoltage = 0.0;
	float BatteryVoltageDivided;
	HAL_StatusTypeDef ADC_Status;

	// STEP 1:
	// Start ADC read
	HAL_ADC_Start(&hadc);

	// STEP 2:
	// Wait for ADC read to complete
	ADC_Status = HAL_ADC_PollForConversion(&hadc, HAL_MAX_DELAY);

	// STEP 3:
	// On completion success read ADC Digital Value and compute battery voltage on Fail stop and reset the ADC
	if (ADC_Status != HAL_OK)
	{
	  HAL_ADC_Stop(&hadc);
	  MX_ADC_Init();
	}
	else
	{
	  ADC_DigitalRead = HAL_ADC_GetValue(&hadc);
	  BatteryVoltageDivided = (SuperStarStatus.ADC_VDDA_Vref / ADC_FULL_SCALE_VALUE) * ADC_DigitalRead;
	  BatteryVoltage = BatteryVoltageDivided / SuperStarStatus.ADC_DividerRatio;
	}

	// STEP 4:
	// Return the battery voltage
	return(BatteryVoltage);
	// TODO: On read fail do you want to return anything different
}