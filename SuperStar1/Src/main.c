/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2020 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under BSD 3-Clause license,
  * the "License"; You may not use this file except in compliance with the
  * License. You may obtain a copy of the License at:
  *                        opensource.org/licenses/BSD-3-Clause
  *
  ******************************************************************************
  */
/* USER CODE END Header */

/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "adc.h"
#include "gpio.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include "LED_Control.h"

/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */
/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/

/* USER CODE BEGIN PV */

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */

/* USER CODE END 0 */

/**
  * @brief  The application entry point.
  * @retval int
  */
int main(void)
{
  /* USER CODE BEGIN 1 */

  /* USER CODE END 1 */

  /* MCU Configuration--------------------------------------------------------*/

  /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
  HAL_Init();

  /* USER CODE BEGIN Init */

  /* USER CODE END Init */

  /* Configure the system clock */
  SystemClock_Config();

  /* USER CODE BEGIN SysInit */

  /* USER CODE END SysInit */

  /* Initialize all configured peripherals */
  MX_GPIO_Init();
  MX_ADC_Init();
  /* USER CODE BEGIN 2 */
  volatile uint32_t DummyVar = 0;
  volatile uint32_t FullCount = 200000;

  /* USER CODE END 2 */

  /* Infinite loop */




  while(1)
  {
	  DIG_ONE_A();
	  DIG_TENS_G();
	  GPIO_PinState SwitchState;
	  SwitchState = HAL_GPIO_ReadPin(SW_Zero_GPIO_Port, SW_Zero_Pin);
	  if(SwitchState == GPIO_PIN_SET)
		{
		  ON_RLED1();
		}
	  else
		{
		  OFF_RLED1();
		}

	  DIG_ONE_A();
	  DIG_ONE_B();
	  DIG_ONE_C();
	  DIG_ONE_D();
	  DIG_ONE_E();
	  DIG_ONE_F();
	  DIG_ONE_G();
	  DIG_DP();
	  DIG_TENS_A();
	  DIG_TENS_B();
	  DIG_TENS_C();
	  DIG_TENS_C();
	  DIG_TENS_D();
	  DIG_TENS_E();
	  DIG_TENS_F();
	  DIG_TENS_G();
	  //ALL SEGEMENTS + DP SHOULD BE ON//
	  for(uint32_t DelayCounter = 0; DelayCounter < FullCount; DelayCounter++)
	 		  {
	 			  DummyVar++;
	 		  }
	  OFF_DIG_ONE_A();
	  OFF_DIG_ONE_B();
	  OFF_DIG_ONE_C();
	  OFF_DIG_ONE_D();
	  OFF_DIG_ONE_E();
	  OFF_DIG_ONE_F();
	  OFF_DIG_ONE_G();
	  OFF_DIG_TENS_A();
	  OFF_DIG_TENS_B();
	  OFF_DIG_TENS_C();
	  OFF_DIG_TENS_D();
	  OFF_DIG_TENS_E();
	  OFF_DIG_TENS_F();
	  OFF_DIG_TENS_G();
	 //ALL SGEMENTS SHOULD BE OFF//



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





    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */
  }
  /* USER CODE END 3 */
}

/**
  * @brief System Clock Configuration
  * @retval None
  */
void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};

  /** Configure the main internal regulator output voltage 
  */
  __HAL_PWR_VOLTAGESCALING_CONFIG(PWR_REGULATOR_VOLTAGE_SCALE1);
  /** Initializes the CPU, AHB and APB busses clocks 
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_MSI;
  RCC_OscInitStruct.MSIState = RCC_MSI_ON;
  RCC_OscInitStruct.MSICalibrationValue = 0;
  RCC_OscInitStruct.MSIClockRange = RCC_MSIRANGE_6;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_NONE;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }
  /** Initializes the CPU, AHB and APB busses clocks 
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_MSI;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV1;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_0) != HAL_OK)
  {
    Error_Handler();
  }
}

/* USER CODE BEGIN 4 */

/* USER CODE END 4 */

/**
  * @brief  This function is executed in case of error occurrence.
  * @retval None
  */
void Error_Handler(void)
{
  /* USER CODE BEGIN Error_Handler_Debug */
  /* User can add his own implementation to report the HAL error return state */

  /* USER CODE END Error_Handler_Debug */
}

#ifdef  USE_FULL_ASSERT
/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t *file, uint32_t line)
{ 
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line number,
     tex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
