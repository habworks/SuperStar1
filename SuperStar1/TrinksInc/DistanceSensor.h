/** ****************************************************************************************************
 * @file 			DistanceSensor.h
 * @brief			This Header file used to support uC Peripheral: Low Power Timer (LPTIM), Timer2 (TIM2),  Timer21 (TIM21)
 * ****************************************************************************************************
 * @author			Trinkie H. Collector \n
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
#ifndef DISTANCE_SENSOR_H
#define DISTANCE_SENSOR_H


//MACROS
#define SENSOR_ECHO_RECIVED()			HAL_GPIO_ReadPin(Sens_Echo_GPIO_Port, Sens_Echo_Pin);
#define SENSOR_TRIGGER_HIGH()			HAL_GPIO_WritePin(Sens_Trig_GPIO_Port, Sens_Trig_Pin, GPIO_PIN_SET);
#define SENSOR_TRIGGER_LOW() 			HAL_GPIO_WritePin(Sens_Trig_GPIO_Port, Sens_Trig_Pin, GPIO_PIN_RESET);



//DEFINES
#define STOP_DISTANCE_THRESHOLD			0 		//STOP WHEN USER REACHED THEIR SET PARK 0.0 - 0.5
#define CAUTION_DISTANCE_THRESHOLD		3  		//SLOW WHEN USER IS WITHIN 3 FEET OF THEIR SET PARK 0.5 - 3.9
#define GO_DISTANCE_THRESHOLD			4 		//PROCEED FREELY WHILE USER IS WITHIN 3.9 - 9.9 or max
#define DISTANCE_ARRAY_SIZE				5 	 	//BIGGER = MORE ACCUARTE
#define ROUND_ASSIST					0.05	//USE FOR realDist, USE FOR TENTHS
#define MAX_DIST						9.9		//HIGHEST DISTANCE SESNOR CAN DISPLAY
#define MIN_DIST						0.0		//LOWEST DISTANCE SENOR CAN CONVEY + DISPLAY
#define MEASURE_ERROR				-9999.999 	//OBSCURE NUMBER = ERROR
#define TICKS_TO_SECONDS				100e-6	//TO CONVERT TICKS TO TIME EACH TICK LAST FOR 100e-6
#define SPEED_OF_SOUND					1125.3	//1125.3 = SPEED OF SOUND IN ft/s (ft/s x s = ft -> SPEED_OF_SOUND * TimeToTarget = Dist

//FUNCTION PROTOTYPES
float rollingAverageTargetDistance (float NewDistance);
void realDistance (float Distance);
float distanceToTarget (void);

#endif
