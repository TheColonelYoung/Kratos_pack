/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2021 STMicroelectronics.
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
#include "stm32g0xx_hal.h"

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
#define LED_EN_Pin GPIO_PIN_14
#define LED_EN_GPIO_Port GPIOC
#define CD_Pin GPIO_PIN_15
#define CD_GPIO_Port GPIOC
#define BOOT_Pin GPIO_PIN_0
#define BOOT_GPIO_Port GPIOA
#define CS_MON_Pin GPIO_PIN_1
#define CS_MON_GPIO_Port GPIOA
#define WAKEUP_Pin GPIO_PIN_4
#define WAKEUP_GPIO_Port GPIOA
#define B2_MON_Pin GPIO_PIN_6
#define B2_MON_GPIO_Port GPIOA
#define B1_MON_Pin GPIO_PIN_7
#define B1_MON_GPIO_Port GPIOA
#define OUT_MON_Pin GPIO_PIN_1
#define OUT_MON_GPIO_Port GPIOB
#define ME_EN_Pin GPIO_PIN_8
#define ME_EN_GPIO_Port GPIOA
#define CS_EN_Pin GPIO_PIN_11
#define CS_EN_GPIO_Port GPIOA
#define PSEL_Pin GPIO_PIN_3
#define PSEL_GPIO_Port GPIOB
#define USD_DET_Pin GPIO_PIN_5
#define USD_DET_GPIO_Port GPIOB
#define CH_INT_Pin GPIO_PIN_8
#define CH_INT_GPIO_Port GPIOB
/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
