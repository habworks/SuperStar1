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


bool_t displayNum(uint8_t DigitToDisplay)
{
	if (DigitToDisplay >= 10)
	{
		OFF_DIG_ONE_A();
		OFF_DIG_ONE_B();
		OFF_DIG_ONE_C();
		OFF_DIG_ONE_D();
		OFF_DIG_ONE_E();
		OFF_DIG_ONE_F();
		OFF_DIG_ONE_G();
		OFF_DIG_TENS_A();
		return (false);
	}

	OFF_DIG_ONE_A();
	OFF_DIG_ONE_B();
	OFF_DIG_ONE_C();
	OFF_DIG_ONE_D();
	OFF_DIG_ONE_E();
	OFF_DIG_ONE_F();
	OFF_DIG_ONE_G();

			switch (DigitToDisplay)
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
					OFF_DIG_ONE_A();
					OFF_DIG_ONE_B();
					OFF_DIG_ONE_C();
					OFF_DIG_ONE_D();
					OFF_DIG_ONE_E();
					OFF_DIG_ONE_F();
					OFF_DIG_ONE_G();
					break;
			}

			if (DigitToDisplay >= 10)
				{
					OFF_DIG_ONE_A();
					OFF_DIG_ONE_B();
					OFF_DIG_ONE_C();
					OFF_DIG_ONE_D();
					OFF_DIG_ONE_E();
					OFF_DIG_ONE_F();
					OFF_DIG_ONE_G();
					OFF_DIG_TENS_A();
					return (false);
				{
				OFF_DIG_TENS_A();
				OFF_DIG_TENS_B();
				OFF_DIG_TENS_C();
				OFF_DIG_TENS_C();
				OFF_DIG_TENS_D();
				OFF_DIG_TENS_E();
				OFF_DIG_TENS_F();
				OFF_DIG_TENS_G();
				switch (DigitToDisplay)
				{
					case 0:
						DIG_TENS_A();
						DIG_TENS_B();
						DIG_TENS_C();
						DIG_TENS_D();
						DIG_TENS_E();
						DIG_TENS_F();
						break;
					case 1:
						DIG_TENS_B();
						DIG_TENS_C();
						break;
					case 2:
						DIG_TENS_A();
						DIG_TENS_B();
						DIG_TENS_G();
						DIG_TENS_E();
						DIG_TENS_D();
						break;
					case 3:
						DIG_TENS_A();
						DIG_TENS_B();
						DIG_TENS_G();
						DIG_TENS_C();
						DIG_TENS_D();
						break;
					case 4:
						DIG_TENS_F();
						DIG_TENS_G();
						DIG_TENS_B();
						DIG_TENS_C();
						break;
					case 5:
						DIG_TENS_A();
						DIG_TENS_F();
						DIG_TENS_G();
						DIG_TENS_C();
						DIG_TENS_D();
						break;
					case 6:
						DIG_TENS_A();
						DIG_TENS_F();
						DIG_TENS_G();
						DIG_TENS_C();
						DIG_TENS_D();
						DIG_TENS_E();
						break;
					case 7:
						DIG_TENS_A();
						DIG_TENS_B();
						DIG_TENS_C();
						break;
					case 8:
						DIG_TENS_A();
						DIG_TENS_B();
						DIG_TENS_C();
						DIG_TENS_D();
						DIG_TENS_E();
						DIG_TENS_F();
						DIG_TENS_G();
						break;
					case 9:
						DIG_TENS_A();
						DIG_TENS_B();
						DIG_TENS_F();
						DIG_TENS_G();
						DIG_TENS_C();
						break;
					default:
						OFF_DIG_TENS_A();
						OFF_DIG_TENS_B();
						OFF_DIG_TENS_C();
						OFF_DIG_TENS_C();
						OFF_DIG_TENS_D();
						OFF_DIG_TENS_E();
						OFF_DIG_TENS_F();
						OFF_DIG_TENS_G();
						break;
			}
	return (true);

}
