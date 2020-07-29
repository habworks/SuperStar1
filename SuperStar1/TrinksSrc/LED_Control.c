#include "LED_Control.h"
#include "stm32l0xx_hal.h"
#include "stm32l0xx_hal_gpio.h"
#include "stm32l0xx_hal_rcc.h"
#include "MainSupport.h"


void init_OSC32_InOutAsGPIO()
{
	GPIO_InitTypeDef GPIO_InitStructure = {0};
	RCC_OscInitTypeDef RCC_OscInitStruct = {0};


	//RCC_AHBPeriphClockCmd(RCC_AHBPeriph_GPIOC, ENABLE);
	//RCC_APB1PeriphClockCmd(RCC_APB1Periph_PWR, ENABLE);
	// GPIO Function lost in STANDBY, PC14,PC15 revert to analog inputs
	GPIO_InitStructure.Pin = GPIO_PIN_14 | GPIO_PIN_15; //MC_GLED2_Pin|MC_RLED2_Pin
	GPIO_InitStructure.Mode = GPIO_MODE_OUTPUT_PP;
	GPIO_InitStructure.Pull = GPIO_NOPULL;
	GPIO_InitStructure.Speed = GPIO_SPEED_FREQ_LOW;
	HAL_GPIO_Init(GPIOC, &GPIO_InitStructure);

	SET_BIT(RCC->CR, RCC_CR_HSEON);
	CLEAR_BIT(RCC->CSR, RCC_CSR_LSEON);
/*
	RCC_OscInitStruct.PLL.PLLState = RCC_PLL_OFF;
	if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
	{
		Error_Handler();
	}

	CLEAR_BIT(RCC->CR, RCC_CR_PLLON);
	CLEAR_BIT(RCC->CSR, RCC_CSR_LSION);
	*/

	//PWR_RTCAccessCmd(ENABLE); // Enable access to LSE
	//RCC_LSEConfig(RCC_LSE_OFF); // PC14 PC15 as GPIO
}



/***********************************************************************************************************
* @brief Green and Red LEDs all off
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
	OFF_DIG_TENTH_C();
	OFF_DIG_TENTH_D();
	OFF_DIG_TENTH_E();
	OFF_DIG_TENTH_F();
	OFF_DIG_TENTH_G();

} // END OF segTENTH_OFF



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
	volatile uint32_t DummyVar = 0;
	volatile uint32_t FullCount = 400000;

	//STEP 2:
	//Turn on all red LEDs.
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

	//STEP 3:
	/*Use a for statement to create the wait time. Create a new variable called DelayCounter. For as long
	as DelayCounter remains less than FullCount then the lights will stay on. Firstly, set it equal to 0 and then
	increment it by 1. Then increment DummyVar.*/
	for(uint32_t DelayCounter = 0; DelayCounter < FullCount; DelayCounter++)
	  {
		  DummyVar++;
	  }

	//STEP 4:
	//Turn off all red LEDs.
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
	for(uint32_t DelayCounter = 0; DelayCounter < FullCount; DelayCounter++)
		  {
			  DummyVar++;
		  }

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
