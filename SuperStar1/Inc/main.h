/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
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

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MAIN_H
#define __MAIN_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32l0xx_hal.h"
#include "stm32l0xx_hal.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Exported types ------------------------------------------------------------*/
/* USER CODE BEGIN ET */

/* USER CODE END ET */

/* Exported constants --------------------------------------------------------*/
/* USER CODE BEGIN EC */

/* USER CODE END EC */

/* Exported macro ------------------------------------------------------------*/
/* USER CODE BEGIN EM */

/* USER CODE END EM */

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);

/* USER CODE BEGIN EFP */

/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define MC_GLED3_Pin GPIO_PIN_0
#define MC_GLED3_GPIO_Port GPIOC
#define MC_RLED3_Pin GPIO_PIN_13
#define MC_RLED3_GPIO_Port GPIOC
#define MC_GLED2_Pin GPIO_PIN_14
#define MC_GLED2_GPIO_Port GPIOC
#define MC_RLED2_Pin GPIO_PIN_15
#define MC_RLED2_GPIO_Port GPIOC
#define Sens_Echo_Pin GPIO_PIN_0
#define Sens_Echo_GPIO_Port GPIOH
#define Sens_Trig_Pin GPIO_PIN_1
#define Sens_Trig_GPIO_Port GPIOH
#define MC_GLED1_Pin GPIO_PIN_0
#define MC_GLED1_GPIO_Port GPIOA
#define MC_RLED1_Pin GPIO_PIN_1
#define MC_RLED1_GPIO_Port GPIOA
#define Sens_PWR_Pin GPIO_PIN_2
#define Sens_PWR_GPIO_Port GPIOA
#define Vbat_Level_Pin GPIO_PIN_3
#define Vbat_Level_GPIO_Port GPIOA
#define MS_SEG_4C1_Pin GPIO_PIN_4
#define MS_SEG_4C1_GPIO_Port GPIOA
#define MC_SEG_3E1_Pin GPIO_PIN_5
#define MC_SEG_3E1_GPIO_Port GPIOA
#define MC_SEG_2D1_Pin GPIO_PIN_6
#define MC_SEG_2D1_GPIO_Port GPIOA
#define MC_SEG_10G1_Pin GPIO_PIN_7
#define MC_SEG_10G1_GPIO_Port GPIOA
#define MC_SEG_9F1_Pin GPIO_PIN_0
#define MC_SEG_9F1_GPIO_Port GPIOB
#define MC_SEG_8B1_Pin GPIO_PIN_1
#define MC_SEG_8B1_GPIO_Port GPIOB
#define MC_SEG_7A1_Pin GPIO_PIN_2
#define MC_SEG_7A1_GPIO_Port GPIOB
#define MC_GLED8_Pin GPIO_PIN_10
#define MC_GLED8_GPIO_Port GPIOB
#define SW_Zero_Pin GPIO_PIN_11
#define SW_Zero_GPIO_Port GPIOB
#define SW_Zero_EXTI_IRQn EXTI4_15_IRQn
#define MC_RLED8_Pin GPIO_PIN_12
#define MC_RLED8_GPIO_Port GPIOB
#define MC_RLED7_Pin GPIO_PIN_13
#define MC_RLED7_GPIO_Port GPIOB
#define MC_GLED7_Pin GPIO_PIN_14
#define MC_GLED7_GPIO_Port GPIOB
#define MC_RLED6_Pin GPIO_PIN_15
#define MC_RLED6_GPIO_Port GPIOB
#define MC_GLED6_Pin GPIO_PIN_8
#define MC_GLED6_GPIO_Port GPIOA
#define MC_GLED5_Pin GPIO_PIN_9
#define MC_GLED5_GPIO_Port GPIOA
#define MC_RLED5_Pin GPIO_PIN_11
#define MC_RLED5_GPIO_Port GPIOA
#define MC_RLED4_Pin GPIO_PIN_12
#define MC_RLED4_GPIO_Port GPIOA
#define SW_DIO_Pin GPIO_PIN_13
#define SW_DIO_GPIO_Port GPIOA
#define SW_CLK_Pin GPIO_PIN_14
#define SW_CLK_GPIO_Port GPIOA
#define MC_GLED4_Pin GPIO_PIN_15
#define MC_GLED4_GPIO_Port GPIOA
#define MC_SEG_10G2_Pin GPIO_PIN_3
#define MC_SEG_10G2_GPIO_Port GPIOB
#define MC_SEG_9F2_Pin GPIO_PIN_4
#define MC_SEG_9F2_GPIO_Port GPIOB
#define MC_SEG_8B2_Pin GPIO_PIN_5
#define MC_SEG_8B2_GPIO_Port GPIOB
#define MC_SEG_7A2_Pin GPIO_PIN_6
#define MC_SEG_7A2_GPIO_Port GPIOB
#define MC_SEG_4C2_Pin GPIO_PIN_7
#define MC_SEG_4C2_GPIO_Port GPIOB
#define MC_SEG_3E2_Pin GPIO_PIN_8
#define MC_SEG_3E2_GPIO_Port GPIOB
#define MC_SEG_2D2_Pin GPIO_PIN_9
#define MC_SEG_2D2_GPIO_Port GPIOB
/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
