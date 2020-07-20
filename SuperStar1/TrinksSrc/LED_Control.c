#include "LED_Control.h"
#include "stm32l0xx_hal.h"
#include "stm32l0xx_hal_gpio.h"
#include "stm32l0xx_hal_rcc.h"



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
