/** ****************************************************************************************************
 * @file 			DistanceSensor.c
 * @brief			This is the Source file used to support the main.c CubeMx generated file
 * ****************************************************************************************************
 * @author			Trinkie H. Collector \n
 * Last Edited By:	Trinkie H. Collector \n
 *
 * @date			7/19/20 \n
 * Last Edit Date:  8/7/20 \n
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
#include "DistanceSensor.h"
#include "MainSupport.h"
#include "LED_Control.h"
#include "Timers.h"

extern Type_SuperStarStatus SuperStarStatus;

/***********************************************************************************************************
* @brief Rolling average Target Distance
*
* @author 			Trinkie H. Collector \n
* Last Edited By:  	Trinkie H. Collector \n
*
* @note This function is intended to calculate the rolling, or constantly updated, average of distance in the array
* @note the distance will be collected from the sensor x times a second.
*
* @param NewDistance
* @return AverageDistance
*
* WHY: Creating an average that self regulates/ updates helps to filter the distance to be displayed from obstructions.
* STEP 1: Store a new value
* STEP 2: Calculate the sum of the array.
* STEP 3: Calculate the average.
* STEP 4: Increment StoredIndex and test.
* STEP 5: Return the average.
* **********************************************************************************************************/
float rollingAverageTargetDistance (float NewDistance)
{
	static float DistArray[DISTANCE_ARRAY_SIZE] = {0};
	static uint8_t StoredIndex = 0;
	float AverageDistance;
	float Sum_OfDistance = 0;

	//STEP 1: Store a new value.
	DistArray[StoredIndex] = NewDistance;

	//STEP 2: Calculate the sum of the array.
	for(uint8_t Index = 0; Index < DISTANCE_ARRAY_SIZE; Index++)
	{
		Sum_OfDistance = Sum_OfDistance + DistArray[Index];
	}

	//STEP 3: Calculate the average.
	AverageDistance = Sum_OfDistance / DISTANCE_ARRAY_SIZE;

	//STEP 4: Increment StoredIndex and test.
	StoredIndex++;
	if(StoredIndex > DISTANCE_ARRAY_SIZE - 1)
	{
		StoredIndex = 0;
	}

	//STEP 5: Return the average.
	return (AverageDistance);
}//END OF rollingAverageTargetDistance



/***********************************************************************************************************
* @brief Real Number
*
* @author 			Trinkie H. Collector \n
* Last Edited By:  	Trinkie H. Collector \n
*
* @note The display consist of two seven segments hat display up to 9 so the max allowed distance is 9.9
* @note The Minimum display distance is 0.
*
* @param Distance as a real number
* @return void
*
* WHY: Convert float to integer and then display integer.
* STEP 1: Declare all variables
* STEP 2: If statement for minimum and max, if distance doesn't fit then don't display.
* STEP 3: Set the integer portion of the distance distance equal to the integer version of distance.
* STEP 4: Set the fraction to be the float minus the integer.
* STEP 5: RoundNum will add 0.05 to the fraction. This will allow for the tenth place to increment if the hundredths place
* is greater or equal to five example, 0.45 is around .50, so to display .50, .05 must be added to the fraction.
* STEP 6: Multiply the fraction by ten to make it an integer that the seven segment can display.
* STEP 7: Insert the respective variables into the display functions.
* **********************************************************************************************************/
void realDistance (float Distance)
{
	//STEP 1: Declare all variables
	float Fraction;
	uint8_t Integer;
	float RoundNum;

	//STEP 2: If statement for minimum and max, if distance doesn't fit then don't display.
	if ((Distance > MAX_DIST) || (Distance < MIN_DIST))
		{
			segONE_OFF();
			segTENTH_OFF();
			return;
		}

	//STEP 3: Set the integer portion of the distance distance equal to the int version of distance.
	Integer = (uint8_t)Distance;

	//STEP 4: Set the fraction to be the float minus the integer.
	Fraction = (float)Distance - Integer;

	//STEP 5: RoundNum will add 0.05 to the fraction. This will allow for the tenth place to increment if the hundredths place
	//is greater or equal to five example, 0.45 is around .50, so to display .50, .05 must be added to the fraction.
	RoundNum = Fraction + ROUND_ASSIST;

	//STEP 6: Multiply the fraction by ten to make it an integer that the seven segment can display.
	RoundNum = RoundNum * 10;

	//STEP 7: Insert the respective variables into the display functions.
	displayNumTENTH(RoundNum);
	displayNumONE(Integer);

} // END OF realDistance



/***********************************************************************************************************
* @brief Distance to Target // How to Measure Distance
*
* @author 			Trinkie H. Collector \n
* Last Edited By:  	Trinkie H. Collector \n
*
* @note Distance = speed * time
* @note Speed of sound = 1125.3
*
* @param void
* @return float
*
* WHY: Display distance from the target on the seven segment in real time
* STEP 1: Power on the sensor and give it time to settle.
* STEP 2: Create a trigger pulse.
* STEP 3: Begin to measure the timeout from 0.
* STEP 4: Wait for Echo to go high. If there is no Echo, then break and send Error Code. If the Echo appears, then continue.
* STEP 5: Begin counting from the number of ticks the Echo takes to get to target from 0.
* STEP 6: Wait for Echo to go low. If it doens't go low, then break and send Error Code. If it does, then continue.
* STEP 7: Convert ticks to time. divide by two because the sensor records a round trip.
* STEP 8: Turn off power to the sensor. This saves power and allows for the sensor to not be on when there is no displacement to measure.
* STEP 9: Calculate distance to target in feet
* **********************************************************************************************************/
float distanceToTarget (void)
{
	bool_t EchoReceived;
	bool_t DistanceSensorError = false;  // TODO: When you make your function - do you really need this or can you just return the error value
	volatile float TimeToTarget;


	//STEP 1: Power on the sensor and give it time to settle
	POWER_ON_SENSOR_DP();
	miliSecondDelay(500);  // TODO: Determine by experiment the shortest time I can wait after power on before making a measurement

	//STEP 2: Create a trigger pulse.  Pulse width to be at least 10us wide.
	SENSOR_TRIGGER_HIGH();
	miliSecondDelay(1);
	SENSOR_TRIGGER_LOW();

	//STEP 3: Set timeout time to zero - will begin to measure the timeout
	SuperStarStatus.DistanceMeasureTimeOut = 0;

	//STEP 4: Echo Timeout... If there is no Echo, then break and send Error Code. If the Echo appears then continue.
	do
	{
		if (SuperStarStatus.DistanceMeasureTimeOut > 10000)  // TODO: Trinks determine a good timeout value to use.  This was just chosen arbitrarily
			{
				return(MEASURE_ERROR);
			}
		EchoReceived = SENSOR_ECHO_RECIVED();
	}while(EchoReceived == false);

	//STEP 5: Zero to begin measure - tick time measure to target and back is between echo rising and falling edges
	SuperStarStatus.RoundTripTicksToTarget = 0;

	//STEP 6: Wait for Echo to go low. If it doens't go low, then break and send Error Code. If it does, then continue.
	do
	{
		if (SuperStarStatus.DistanceMeasureTimeOut > 10000) // TODO: Trinks use defines for all constants in this function
			{
				return (MEASURE_ERROR);
			}
		EchoReceived = SENSOR_ECHO_RECIVED();
	}while (EchoReceived == true);

	//STEP 7: Capture the time to target: Convert ticks to time.  Time to target is 1/2 this time.
	TimeToTarget = ((SuperStarStatus.RoundTripTicksToTarget * TICKS_TO_SECONDS)/ 2);

	// STEP 8: Turn off power to the sensor
	POWER_OFF_SESNOR_DP();

	//STEP 9: Calculate distance to target in feet: Formula is Distance = Speed x Time.  Use speed of sound in ft/s
	float DistanceToTarget;
	DistanceToTarget = SPEED_OF_SOUND * TimeToTarget;  // 1125.3 if Speed of sound in ft/s - ft/s x s = ft
	return(DistanceToTarget);

} //END HERE
