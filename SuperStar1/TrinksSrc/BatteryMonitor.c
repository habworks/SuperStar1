//TODO: Trinks add file header comments

#include "BatteryMonitor.h"
#include "MainSupport.h"
#include "adc.h"
#include "LED_Control.h"

extern Type_SuperStarStatus SuperStarStatus;


/** ****************************************************************************************************
* @brief Read the battery voltage
*
* @author 			Hab S. Collector \n
* Last Edited By:  	Trinkie  H. Collector \n
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



/***********************************************************************************************************
* @brief Rolling Average Voltage
*
* @author 			Trinkie H. Collector \n
* Last Edited By:  	Trinkie H. Collector \n
*
* @note This function is intended to calculate the rolling, or constantly updated, average of distance in the array
* @note the distance will be collected from the sensor x times a second.
*
* @param NowVolatge
* @return AverageVoltage
*
* WHY: Allow user to visually see when they need to replay their batter
*
* STEP 1: Store a new value
* STEP 2: Calculate the sum of the array.
* STEP 3: Calculate the average.
* STEP 4: Increment StoredIndex and test.
* STEP 5: Return the average.
* **********************************************************************************************************/
float rollingAverageBatVolt (float NowVoltage)
{
	static float VoltArray[VOLT_ARRAY_SIZE] = {0};
	static uint8_t StoredIndex = 0;
	float AverageVoltage;
	float Sum_OfVoltage = 0;

	//STEP 1: Store a new value.
	VoltArray[StoredIndex] = NowVoltage;

	//STEP 2: Calculate the sum of the array.
	for(uint8_t Index = 0; Index < VOLT_ARRAY_SIZE; Index++)
		{
			Sum_OfVoltage = Sum_OfVoltage + VoltArray[Index];
		}

	//STEP 3: Calculate the average.
	AverageVoltage = Sum_OfVoltage / VOLT_ARRAY_SIZE;

	//STEP 4: Increment StoredIndex and test.
	StoredIndex++;
	if(StoredIndex > VOLT_ARRAY_SIZE - 1)
		{
			StoredIndex = 0;
		}

	//STEP 5: Return the average.
	return (AverageVoltage);
}

//IF battery voltage is greater (>)than threshold THEN EO_NoError
//(ELSE) IF battery voltage is NOT greater than threshold OR EQUAL TO (<=) THEN E2_LowBat
// macro is BATTERY_LOW_VOLATGE_THRESHOLD it is set at 8
/***********************************************************************************************************
* @brief errorCheck
*
* @author 			Trinkie H. Collector \n
* Last Edited By:  	Trinkie H. Collector \n
*
* @note IF battery voltage is greater (>)than threshold THEN EO_NoError
* @note IF battery voltage is NOT greater than threshold OR EQUAL TO (<=) THEN E2_LowBat
*
* @param NowVolatge
* @return AverageVoltage
*
* WHY: Allow user to visually see when they need to replay their batter
*
* STEP 1: Store a new value
* STEP 2: Calculate the sum of the array.
* STEP 3: Calculate the average.
* STEP 4: Increment StoredIndex and test.
* STEP 5: Return the average.
* **********************************************************************************************************/
void errorCheck (float AverageVolatge)
{
	if (AverageVoltage > BATTERY_LOW_VOLATGE_THRESHOLD )
		{
			SuperStarStatus.ErrorCodeEnum = E0_NoError ;

		}

	if (AverageVoltage <= BATTERY_LOW_VOLATGE_THRESHOLD )
		{
			SuperStarStatus.ErrorCodeEnum = E2_LowBat ;
		}
} //END OF errorCheck
