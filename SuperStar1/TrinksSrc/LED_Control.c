#include "LED_Control.h"
#include "stm32l0xx_hal.h"
#include "stm32l0xx_hal_gpio.h"
#include "stm32l0xx_hal_rcc.h"
#include "MainSupport.h"
#include "Timers.h"



/***********************************************************************************************************
* @brief Yellow LEDs ON and OFF
*
* @author 			Trinkie H. Collector \n
* Last Edited By:  	Trinkie H. Collector \n
*
* @note This function is intended to turn an the yellow LEDs by turning on the green and red LEDs
*
* @param none
* @return none
*
* WHY: Make code more efficient by creating a default function that turns on the yellow LEDs with a single call.
*
* STEP 1: Create functions for yellow LEDS to be on by setting the correct green and yellow LEDS on.
* **********************************************************************************************************/
//YELLOW LED 1 ON AND OFF
void onYellowLED_1 (void)
{
	ON_RLED1();
	ON_GLED1();
}
void offYellowLED_1 (void)
{
	OFF_RLED1();
	OFF_GLED1();
}

///////////////////////////////////

//YELLOW LED 2 ON AND OFF
void onYellowLED_2 (void)
{
	ON_RLED2();
	ON_GLED2();
}
void offYellowLED_2 (void)
{
	OFF_RLED2();
	OFF_GLED2();
}

///////////////////////////////////

//YELLOW LED 3 ON AND OFF
void onYellowLED_3 (void)
{
	ON_RLED3();
	ON_GLED3();
}
void offYellowLED_3 (void)
{
	OFF_RLED3();
	OFF_GLED3();
}

///////////////////////////////////

//YELLOW LED 4 ON AND OFF
void onYellowLED_4 (void)
{
	ON_RLED4();
	ON_GLED4();
}
void offYellowLED_4 (void)
{
	OFF_RLED4();
	OFF_GLED4();
}

///////////////////////////////////

//YELLOW LED 5 ON AND OFF
void onYellowLED_5 (void)
{
	ON_RLED5();
	ON_GLED5();
}
void offYellowLED_5 (void)
{
	OFF_RLED5();
	OFF_GLED5();
}

///////////////////////////////////

//YELLOW LED 6 ON AND OFF
void onYellowLED_6 (void)
{
	ON_RLED6();
	ON_GLED6();
}
void offYellowLED_6 (void)
{
	OFF_RLED6();
	OFF_GLED6();
}

///////////////////////////////////

//YELLOW LED 7 ON AND OFF
void onYellowLED_7 (void)
{
	ON_RLED7();
	ON_GLED7();
}
void offYellowLED_7 (void)
{
	OFF_RLED7();
	OFF_GLED7();
}

///////////////////////////////////

//YELLOW LED 8 ON AND OFF
void onYellowLED_8 (void)
{
	ON_RLED8();
	ON_GLED8();
}
void offYellowLED_8 (void)
{
	OFF_RLED8();
	OFF_GLED8();
}
// END OF yellowLEDs_ONandOFF



/***********************************************************************************************************
* @brief all-LEDoff
*
* @author 			Trinkie H. Collector \n
* Last Edited By:  	Trinkie H. Collector \n
*
* @note This function is intended to turn off all green and red LEDs
*
* @param none
* @return none
*
* WHY: Make code more efficient by creating a default function that turns off all 16 LEDs
*
* STEP 1: Turn off each LED
* **********************************************************************************************************/
void all_LedOFF (void)
{

	//STEP 1:
	//Turn off each LED
		OFF_GLED1();
		OFF_GLED2();
		OFF_GLED3();
		OFF_GLED4();
		OFF_GLED5();
		OFF_GLED6();
		OFF_GLED7();
		OFF_GLED8();
		OFF_RLED1();
		OFF_RLED2();
		OFF_RLED3();
		OFF_RLED4();
		OFF_RLED5();
		OFF_RLED6();
		OFF_RLED7();
		OFF_RLED8();

}  // END OF all_LedOFF



/***********************************************************************************************************
* @brief Seven-segment ONE all off
*
* @author 			Trinkie H. Collector \n
* Last Edited By:  	Trinkie H. Collector \n
*
* @note This function is intended to turn off all of the segments of the seven segment on the LEFT hand side.
* @note The LEFT hand seven segment represents the ones place.
*
* @param none
* @return none
*
* WHY: Make code more efficient by creating a default function that turns off a whole display.
*
* STEP 1: turn off each segment
* **********************************************************************************************************/
void segONE_OFF (void)
{

	//STEP 1 :
	//turn off each segment
	OFF_DIG_ONE_A();
	OFF_DIG_ONE_B();
	OFF_DIG_ONE_C();
	OFF_DIG_ONE_D();
	OFF_DIG_ONE_E();
	OFF_DIG_ONE_F();
	OFF_DIG_ONE_G();

} // END OF segONE_OFF



/***********************************************************************************************************
* @brief Seven-segment TENTH all off
*
* @author 			Trinkie H. Collector \n
* Last Edited By:  	Trinkie H. Collector \n
*
* @note This function is intended to turn off all of the segments of the seven segment on the RIGHT hand side.
* @note The RIGHT hand seven segment represents the tenths place.
*
* @param none
* @return none
*
* WHY: Make code more efficient by creating a default function that turns off a whole display.
*
* STEP 1: turn off each segment
* **********************************************************************************************************/
void segTENTH_OFF (void)
{

	//STEP 1:
	//turn off each segment
	OFF_DIG_TENTH_A();
	OFF_DIG_TENTH_B();
	OFF_DIG_TENTH_C();
	OFF_DIG_TENTH_D();
	OFF_DIG_TENTH_E();
	OFF_DIG_TENTH_F();
	OFF_DIG_TENTH_G();

} // END OF segTENTH_OFF



/***********************************************************************************************************
* @brief Turn off seven segment
*
* @author 			Trinkie H. Collector \n
* Last Edited By:  	Trinkie H. Collector \n
*
* @note This function is intended to turn off all of the segments of the seven segment on BOTH sides.
*
* @param none
* @return none
*
* WHY: Make code more efficient by creating a default function that turns off a both displays.
*
* STEP 1: Use a
* **********************************************************************************************************/
void turnOffSevenSeg (void)
{
	segONE_OFF();
	segTENTH_OFF();
} //END OF turnOffSevenSeg



/***********************************************************************************************************
* @brief LED Flash Test One
*
* @author 			Trinkie H. Collector \n
* Last Edited By:  	Trinkie H. Collector \n
*
* @note This function is intended to test all of the 16 LEDs by turning all red and green LEDs on and off.
* @note There is a set wait time that allows for each color to be visible before it turns off duration that
* allows for the red and green to be seen(DummyVar AND FullCount).
*
* @param none
* @return none
*
* WHY: To test that all of the LEDs work and bring color to the board.
*
* STEP 1: Declare DummyVar and FullCount and set values for each.
* STEP 2: Turn on all red LEDs.
* STEP 3: Use a for statement to create the wait time. Create a new variable called DelayCounter. For as long
* as DelayCounter remains less than FullCount then the lights will stay on. Firstly, set it equal to 0 and then
* increment it by 1. Then increment DummyVar.
* STEP 4: Turn off all red LEDs.
* STEP 5: Turn on all green LEDs.
* STEP 6: Use a for statement to create the wait time. Create a new variable called DelayCounter. For as long
* as DelayCounter remains less than FullCount then the lights will stay on. Firstly, set it equal to 0 and then
* increment it by 1. Then increment DummyVar.
* STEP 7: Turn off all green LEDs.
* **********************************************************************************************************/
void ledFLASH_test_1 (void)
{
	//STEP 1:
	//Declare DummyVar and FullCount and set values for each.

	//STEP 2:
	//Turn on all red LEDs.
	ON_RLED1();
	ON_RLED2();
	ON_RLED3();
	ON_RLED4();
	ON_RLED5();
	ON_RLED6();
	ON_RLED7();
	ON_RLED8();

	//STEP 3:
	/*Use a for statement to create the wait time. Create a new variable called DelayCounter. For as long
	as DelayCounter remains less than FullCount then the lights will stay on. Firstly, set it equal to 0 and then
	increment it by 1. Then increment DummyVar.*/
	miliSecondDelay(500);

	//STEP 4:
	//Turn off all red LEDs.
	OFF_RLED1();
	OFF_RLED2();
	OFF_RLED3();
	OFF_RLED4();
	OFF_RLED5();
	OFF_RLED6();
	OFF_RLED7();
	OFF_RLED8();

	//STEP 5:
	//Turn on all green LEDs.
	ON_GLED1();
	ON_GLED2();
	ON_GLED3();
	ON_GLED4();
	ON_GLED5();
	ON_GLED6();
	ON_GLED7();
	ON_GLED8();

	//STEP 6:
	/*Use a for statement to create the wait time. Create a new variable called DelayCounter. For as long
	as DelayCounter remains less than FullCount then the lights will stay on. Firstly, set it equal to 0 and then
	increment it by 1. Then increment DummyVar*/
	miliSecondDelay(500);

	//STEP 7:
	// Turn off all green LEDs.
	OFF_GLED1();
	OFF_GLED2();
	OFF_GLED3();
	OFF_GLED4();
	OFF_GLED5();
	OFF_GLED6();
	OFF_GLED7();
	OFF_GLED8();
}



/***********************************************************************************************************
* @brief Seven-segment display ONE
*
* @author 			Trinkie H. Collector \n
* Last Edited By:  	Trinkie H. Collector \n
*
* @note This function is intended to display the digits 0-9(including both 0 and 9) for the LEFT hand seven segment
* @note The left hand seven segment represents the ones place.
*
* @param DigitToDisplayONE dependent on TestNumONE
* @return true or false
*
* WHY: Knowing the segments can display each digit independently while counting up from 0 to 9  \n
*
* STEP 1: If the variable is greater than or equal to 0 then the segment displays will reset. If the if statement returns
* false then all of the seven segments will turn off to reset the ONE's number display.
* STEP 2: The switch statement will display the different numbers based on the increments of variable TestNumONES which is counting up from 0.
* STEP 3: Return true to begin the function again.
* **********************************************************************************************************/
bool_t displayNumONE(uint8_t DigitToDisplayONE)
{

	//STEP 1:
	// If the variable is greater than or equal to 0 then the segment displays will reset. If the if statement returns
	//false then all of the seven segments will turn off to reset the ONE's number display.
	if (DigitToDisplayONE >= 10)
	{
		segONE_OFF();
		return (false);
	}
	segONE_OFF();

	//STEP 2:
	//The switch statement will display the different numbers based on the increments of variable TestNumONES which is counting up from 0.
	switch (DigitToDisplayONE)
	{
		case 0:
			DIG_ONE_A();
			DIG_ONE_B();
			DIG_ONE_C();
			DIG_ONE_D();
			DIG_ONE_E();
			DIG_ONE_F();
			break;
		case 1:
			DIG_ONE_B();
			DIG_ONE_C();
			break;
		case 2:
			DIG_ONE_A();
			DIG_ONE_B();
			DIG_ONE_G();
			DIG_ONE_E();
			DIG_ONE_D();
			break;
		case 3:
			DIG_ONE_A();
			DIG_ONE_B();
			DIG_ONE_G();
			DIG_ONE_C();
			DIG_ONE_D();
			break;
		case 4:
			DIG_ONE_F();
			DIG_ONE_G();
			DIG_ONE_B();
			DIG_ONE_C();
			break;
		case 5:
			DIG_ONE_A();
			DIG_ONE_F();
			DIG_ONE_G();
			DIG_ONE_C();
			DIG_ONE_D();
			break;
		case 6:
			DIG_ONE_A();
			DIG_ONE_F();
			DIG_ONE_G();
			DIG_ONE_C();
			DIG_ONE_D();
			DIG_ONE_E();
			break;
		case 7:
			DIG_ONE_A();
			DIG_ONE_B();
			DIG_ONE_C();
			break;
		case 8:
			DIG_ONE_A();
			DIG_ONE_B();
			DIG_ONE_C();
			DIG_ONE_D();
			DIG_ONE_E();
			DIG_ONE_F();
			DIG_ONE_G();
			break;
		case 9:
			DIG_ONE_A();
			DIG_ONE_B();
			DIG_ONE_F();
			DIG_ONE_G();
			DIG_ONE_C();
			break;
		default:
			segONE_OFF();
			break;
	}

	//STEP 3:
	//Return true to begin the function again.
	return (true);

} // END OF displayNumONE



/***********************************************************************************************************
* @brief Seven-segment display TENTH
*
* @author 			Trinkie H. Collector \n
* Last Edited By:  	Trinkie H. Collector \n
*
* @note This function is intended to display the digits 0-9(including both 0 and 9) for the RIGHT hand seven segment
* @note The right hand seven segment represents the tenth place which follows immediately after the decimal point.
*
* @param DigitToDisplayTENTHS dependent on TestNumTENTHS
* @return true or false
*
* WHY: Knowing the segments can display each digit independently while counting down from 9 to 0.  \n
*
* STEP 1: If the variable is less than 0 OR if the variable is less than 9 then the segment displays will reset.
* If the if statement returns false then all of the seven segments will turn off to reset the TENTH's number displays.
* STEP 2: The switch statement will display the different numbers based on the increments of the variable TestNumTENTHS, which is counting down from 9.
* STEP 3: Return true to begin the function again.
* **********************************************************************************************************/
bool_t displayNumTENTH(uint8_t DigitToDisplayTENTH)
{

	//STEP 1:
	//If the variable is less than 0 OR if the variable is less than 9 then the segment displays will reset.
	//If the if statement returns false then all of the seven segments will turn off to reset the TENTH's number displays.
	if ((DigitToDisplayTENTH < 0) || (DigitToDisplayTENTH > 9))
	{
		segTENTH_OFF();
		return (false);
	}
	segTENTH_OFF();

	//STEP 2:
	//The switch statement will display the different numbers based on the increments of the variable TestNumTENTHS, which is counting down from 9.
	switch (DigitToDisplayTENTH)
	{
		case 0:
			DIG_TENTH_A();
			DIG_TENTH_B();
			DIG_TENTH_C();
			DIG_TENTH_D();
			DIG_TENTH_E();
			DIG_TENTH_F();
			break;
		case 1:
			DIG_TENTH_B();
			DIG_TENTH_C();
			break;
		case 2:
			DIG_TENTH_A();
			DIG_TENTH_B();
			DIG_TENTH_G();
			DIG_TENTH_E();
			DIG_TENTH_D();
			break;
		case 3:
			DIG_TENTH_A();
			DIG_TENTH_B();
			DIG_TENTH_G();
			DIG_TENTH_C();
			DIG_TENTH_D();
			break;
		case 4:
			DIG_TENTH_F();
			DIG_TENTH_G();
			DIG_TENTH_B();
			DIG_TENTH_C();
			break;
		case 5:
			DIG_TENTH_A();
			DIG_TENTH_F();
			DIG_TENTH_G();
			DIG_TENTH_C();
			DIG_TENTH_D();
			break;
		case 6:
			DIG_TENTH_A();
			DIG_TENTH_F();
			DIG_TENTH_G();
			DIG_TENTH_C();
			DIG_TENTH_D();
			DIG_TENTH_E();
			break;
		case 7:
			DIG_TENTH_A();
			DIG_TENTH_B();
			DIG_TENTH_C();
			break;
		case 8:
			DIG_TENTH_A();
			DIG_TENTH_B();
			DIG_TENTH_C();
			DIG_TENTH_D();
			DIG_TENTH_E();
			DIG_TENTH_F();
			DIG_TENTH_G();
			break;
		case 9:
			DIG_TENTH_A();
			DIG_TENTH_B();
			DIG_TENTH_F();
			DIG_TENTH_G();
			DIG_TENTH_C();
			break;
		default:
			segTENTH_OFF();
			break;
	}

	//STEP 3:
	//Return true to begin the function again.
	return (true);

} // END OF displayNumTENTH



/***********************************************************************************************************
* @brief Display Error Code
*
* @author 			Trinkie H. Collector \n
* Last Edited By:  	Trinkie H. Collector \n
*
* @note This function is intended to have the seven segments display E (for error) and a number 0-6
* @note E0=0, E1=1, E2=2, E3=3, E4=4, E5=5, E6=6. Anything above 6 will still display E6.
* @note E will always be on the ONE (the left) and the error number will be on TENTH (right).
*
* @param ErrorCode
* @return true or false
*
* WHY: Solution for the lack of UI elements on the device that will still display to the user there may
* be something wrong with the device.\n
*
* STEP 1: Use if statement. if Error Code is greater than or equal to 7, still display E6.
* STEP 2: If returned false, then use a switch statement with case 0 to 6 which will display E with
* the designated case.
* STEP 3: Return true to repeat the function.
* **********************************************************************************************************/
bool_t displayErrorCode(uint8_t ErrorCode)
{

	//STEP 1:
	//Use if statement. if Error Code is greater than or equal to 7, still display E6.
	if (ErrorCode >= 7)
	{
		// Display E6
		DIG_ONE_A();
		DIG_ONE_D();
		DIG_ONE_E();
		DIG_ONE_F();
		DIG_ONE_G();
		DIG_TENTH_A();
		DIG_TENTH_F();
		DIG_TENTH_G();
		DIG_TENTH_C();
		DIG_TENTH_D();
		DIG_TENTH_E();
	return (false);
	}
	segONE_OFF();
	segTENTH_OFF();

	//STEP 2:
	/*If returned false, then use a switch statement with case 0 to 6 which will display E with
	the designated case.*/
	switch(ErrorCode)
	{
	case 0:
		DIG_ONE_A();
		DIG_ONE_D();
		DIG_ONE_E();
		DIG_ONE_F();
		DIG_ONE_G();
		DIG_TENTH_A();
		DIG_TENTH_B();
		DIG_TENTH_C();
		DIG_TENTH_D();
		DIG_TENTH_E();
		DIG_TENTH_F();
		break;
	case 1:
		DIG_ONE_A();
		DIG_ONE_D();
		DIG_ONE_E();
		DIG_ONE_F();
		DIG_ONE_G();
		DIG_TENTH_B();
		DIG_TENTH_C();
		break;
	case 2:
		DIG_ONE_A();
		DIG_ONE_D();
		DIG_ONE_E();
		DIG_ONE_F();
		DIG_ONE_G();
		DIG_TENTH_A();
		DIG_TENTH_B();
		DIG_TENTH_G();
		DIG_TENTH_E();
		DIG_TENTH_D();
		break;
	case 3:
		DIG_ONE_A();
		DIG_ONE_D();
		DIG_ONE_E();
		DIG_ONE_F();
		DIG_ONE_G();
		DIG_TENTH_A();
		DIG_TENTH_B();
		DIG_TENTH_G();
		DIG_TENTH_C();
		DIG_TENTH_D();
		break;
	case 4:
		DIG_ONE_A();
		DIG_ONE_D();
		DIG_ONE_E();
		DIG_ONE_F();
		DIG_ONE_G();
		DIG_TENTH_F();
		DIG_TENTH_G();
		DIG_TENTH_B();
		DIG_TENTH_C();
		break;
	case 5:
		DIG_ONE_A();
		DIG_ONE_D();
		DIG_ONE_E();
		DIG_ONE_F();
		DIG_ONE_G();
		DIG_TENTH_A();
		DIG_TENTH_F();
		DIG_TENTH_G();
		DIG_TENTH_C();
		DIG_TENTH_D();
		break;
	case 6:
		DIG_ONE_A();
		DIG_ONE_D();
		DIG_ONE_E();
		DIG_ONE_F();
		DIG_ONE_G();
		DIG_TENTH_A();
		DIG_TENTH_F();
		DIG_TENTH_G();
		DIG_TENTH_C();
		DIG_TENTH_D();
		DIG_TENTH_E();
		break;
	default:
		segONE_OFF();
		segTENTH_OFF();
	}

	//STEP 3
	//Return true to repeat the function.
	return (true);

} // END OF displayErrorCode



/***********************************************************************************************************
* @brief Display Stop
*
* @author 			Trinkie H. Collector \n
* Last Edited By:  	Trinkie H. Collector \n
*
* @note This function is intended to have all the LEDs turn red
* @note This will indicate to the user that they have reached their desired minimum distance for their park
* and need to stop moving.
*
* @param none
* @return none
*
* WHY: The user needs a visual indicator that they need to stop moving. Similar a regular stop sign or red light\n
*
* STEP 1: Turn on all red LEDs
* **********************************************************************************************************/
void displayStop (void)
{
	//STEP 1: Turn on all red LEDs//
	ON_RLED1();
	ON_RLED2();
	ON_RLED2();
	ON_RLED3();
	ON_RLED4();
	ON_RLED5();
	ON_RLED6();
	ON_RLED7();
	ON_RLED8();

} //END OF displayStop



/***********************************************************************************************************
* @brief Display Go
*
* @author 			Trinkie H. Collector \n
* Last Edited By:  	Trinkie H. Collector \n
*
* @note This function is intended to have all the LEDs turn green
* @note This will indicate to the user that they have not yet reached their desired minimum distance for their park
* and need to continue motion.
*
* @param none
* @return none
*
* WHY: The user needs a visual indicator that they need to continue moving. Similar to a regular green light\n
*
* STEP 1: Turn on all green LEDs
* **********************************************************************************************************/
void displayGo (void)
{
	//STEP 1: Turn on all green LEDs
	ON_GLED1();
	ON_GLED2();
	ON_GLED3();
	ON_GLED4();
	ON_GLED5();
	ON_GLED6();
	ON_GLED7();
	ON_GLED8();

} //END OF displayGo



/***********************************************************************************************************
* @brief Display Caution
*
* @author 			Trinkie H. Collector \n
* Last Edited By:  	Trinkie H. Collector \n
*
* @note This function is intended to have all the LEDs turn yellow
* @note This will indicate to the user that they are in range of their desired minimum distance for their park
* and need to be prepared to stop
* @note When red and green LEDs turn on simultaneously, then a yellow color will be present.
*
* @param none
* @return none
*
* WHY: The user needs a visual indicator that they need to proceed towards their target distance with caution due to
* the proximity and speed at which they are approaching their desired park. Similar to a yellow light
* STEP 1: Turn on all red LEDs.
* STEP 2: Turn on all green LEDs.
* **********************************************************************************************************/
void displayCaution (void)
{
	//STEP 1: Turn on all red LEDs
	ON_RLED1();
	ON_RLED2();
	ON_RLED3();
	ON_RLED4();
	ON_RLED5();
	ON_RLED6();
	ON_RLED7();
	ON_RLED8();
	//STEP 2: Turn on all green LEDs
	ON_GLED1();
	ON_GLED2();
	ON_GLED3();
	ON_GLED4();
	ON_GLED5();
	ON_GLED6();
	ON_GLED7();
	ON_GLED8();

} //END OF displayCaution



/***********************************************************************************************************
* @brief StartUpRoutine
*
* @author 			Trinkie H. Collector \n
* Last Edited By:  	Trinkie H. Collector \n
*
* @note The function is intend to allow for the colors to circle and follow after one another
* @note The first color is red, the second color is green, and the third color is yellow.
* @note	The function uses bit shifting. Each placement of the bit (and therefore a certain value)
* 		is to be synonymous to a different LED.
*
* @param none
* @return none
*
* WHY: The device should have a decorative routine for when a user's motion is first detected.
* STEP 1: Define the variables for each color LED.
* STEP 2: Set all the values equal to 1 as a starting point/position that will allow for shifting.
* STEP 3: Create a for loop so Red will start first and when the conditions are met, then green and yellow will.
* STEP 4: The GreenByte will not begin its color revolution until the third time the function loops.
* STEP 5: The YellowByte will not begin until the red has looped five times.
* STEP 6: Wait so that the changes in color can be distinct.
* STEP 7: Run a switch statement interrupt so that each color can be displayed for the correct LEDs, then wait again.
* STEP 8: Turn all LEDS off, the loop is over
* STEP 9: Repeat in reverse, this time shifting to the right, or decreasing in value
* **********************************************************************************************************/
uint32_t wait = 100;
void startUpRoutine(void)
{
	//STEP 1: Define the variables for each color LED and set the values equal to 0 as a starting point/position.
	//STEP 2: Set all the values equal to 1 as a starting point/position that will allow for shifting
	uint16_t RedByte = 0X01;
	uint16_t GreenByte = 0X01;
	uint16_t YellowByte = 0X01;


	//STEP 3: Create a for loop so Red will start first and when the conditions are met, then green and yellow will.
	for (uint16_t LedBitPosition = 0; LedBitPosition < 17; LedBitPosition++)
	{
		RedByte = RedByte << 1;
		if (RedByte > 0x04)
		{
			//STEP 4: The GreenByte will not begin its color revolution until the third time the function loops.
			GreenByte = GreenByte << 1;
		}
		if (RedByte > 0x08)
		{
			//STEP 5: The YellowByte will not begin until the red has looped five times.
			YellowByte = YellowByte << 1;
		}
		//STEP 6: Wait so that the changes in color can be distinct.
		miliSecondDelay(wait);
		//STEP 7: Run a switch statement interrupt so that each color can be displayed for the correct LEDs, then wait again.
		ledOnPlacement(RedByte, GreenByte, YellowByte);
		miliSecondDelay(wait);
	}
	//STEP 8: Turn all LEDS off, the loop is over
	all_LedOFF();
	miliSecondDelay(wait);
	//STEP 9: Call startUpRoutineReverse
	startUpRoutineReverse();
}
void startUpRoutineReverse(void)
{
	uint16_t RedByte = 0X2000;
	uint16_t GreenByte = 0X2000;
	uint16_t YellowByte = 0X2000;
	//STEP 9: Repeat in reverse, this time shifting to the right, or decreasing in value
	for (uint16_t LedBitPosition = 17; LedBitPosition > 0; LedBitPosition--)
	{
		YellowByte = YellowByte >> 1;
		if (YellowByte < 0x800)
		{

			GreenByte = GreenByte >> 1;
		}
		if (YellowByte < 0x100)
		{

			RedByte = RedByte >> 1;
		}
		miliSecondDelay(wait);
		ledOnPlacement(RedByte, GreenByte, YellowByte);
		miliSecondDelay(wait);
	}

	all_LedOFF();
} //END OF startUpRoutineReverse



/***********************************************************************************************************
* @brief Say Hi
*
* @author 			Trinkie H. Collector \n
* Last Edited By:  	Trinkie H. Collector \n
*
* @note This function is intended to greet the user.
*
* @param none
* @return none
*
* WHY: This function is intended to greet the user.
*
* STEP 1:
* STEP 2:
* STEP 3:
*
* **********************************************************************************************************/
//STEP 10: Say Hi!
void sayHi(void)
{
	turnOffSevenSeg();
	DIG_ONE_F();
	DIG_ONE_E();
	DIG_ONE_G();
	DIG_ONE_B();
	DIG_ONE_C();

	DIG_TENTH_C();
	DIG_TENTH_B();
} // END OF sayHi



/***********************************************************************************************************
* @brief ledOnPlacement
*
* @author 			Trinkie H. Collector \n
* Last Edited By:  	Trinkie H. Collector \n
*
* @note There has to be three different switch statements because there are three variables.
* @note Each case represents a uint16_t number presented in Hex (0xn)
* @note There are binary conversions as comments to the side of each case.
*
* @param uint16_t RedLedByte, uint16_t GreenLedByte, uint16_t YellowLedByte
* @return none
*
* WHY: Depending on the position/placement of each bit, something different must occur for each case.
* STEP 1: Create a switch statement for the LEDs
* STEP 2: Red switch statement
* STEP 3: Green switch statement
* STEP 4: Yellow switch statement
* **********************************************************************************************************/
void ledOnPlacement(uint16_t RedLedByte, uint16_t GreenLedByte, uint16_t YellowLedByte)
{
	//STEP 1: Create a switch statement for the LEDs


	//STEP 2: Red switch statement
	switch (RedLedByte)
		{
		case 0X02:
			ON_RLED1();					//RED
			OFF_GLED1();				//FOR REVERSE
			break;

		case 0X04:
			ON_RLED2();					//RED
			OFF_GLED2();				//FOR REVERSE
			break;

		case 0X08:
			ON_RLED3();					//RED
			OFF_GLED3();				//FOR REVERSE
			break;

		case 0X10:
			ON_RLED4();					//RED
			OFF_GLED4();				//FOR REVERSE
			break;

		case 0X20:
			ON_RLED5();					//RED
			OFF_GLED5();				//FOR REVERSE
			break;

		case 0X40:
			ON_RLED6();					//RED
			OFF_GLED6();				//FOR REVERSE
			break;

		case 0X80:
			ON_RLED7();					//RED
			OFF_GLED7();				//FOR REVERSE
			break;

		case 0X100:
			ON_RLED8();					//RED
			OFF_GLED8();				//FOR REVERSE
			break;
		}


	//STEP 3: Green switch statement
	switch (GreenLedByte)
		{
		case 0X08:
			OFF_RLED1();				//FOR GREEN
			ON_GLED1();
			break;

		case 0X10:
			OFF_RLED2();				//FOR GREEN
			ON_GLED2();
			break;

		case 0X20:
			OFF_RLED3();				//FOR GREEN
			ON_GLED3();
			break;

		case 0X40:
			OFF_RLED4();				//FOR GREEN
			ON_GLED4();
			break;

		case 0X80:
			OFF_RLED5();				//FOR GREEN
			ON_GLED5();
			break;

		case 0X100:
			OFF_RLED6();				//FOR GREEN
			ON_GLED6();
			break;

		case 0X200:
			OFF_RLED7();				//FOR GREEN
			ON_GLED7();
			break;

		case 0X400:
			OFF_RLED8();				//FOR GREEN
			ON_GLED8();
			break;
		}


	//STEP 4: Yellow switch statement
	switch (YellowLedByte)
		{
		case 0X20:
			onYellowLED_1();			//FOR YELLOW
			break;

		case 0X40:
			onYellowLED_2();			//FOR YELLOW
			break;

		case 0X80:
			onYellowLED_3();			//FOR YELLOW
			break;

		case 0X100:
			onYellowLED_4();			//FOR YELLOW
			break;

		case 0X200:
			onYellowLED_5();			//FOR YELLOW
			break;

		case 0X400:
			onYellowLED_6();			//FOR YELLOW
			break;

		case 0X800:
			onYellowLED_7();			//FOR YELLOW
			break;

		case 0X1000:
			onYellowLED_8();			//FOR YELLOW
			break;
		}

}//END OF ledOnPlacement






