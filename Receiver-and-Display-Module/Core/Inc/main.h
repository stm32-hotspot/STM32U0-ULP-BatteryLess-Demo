/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2024 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
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
#include "stm32u0xx_hal.h"

//// S2LP ////
#include "s2868a2_conf.h"
#include "custom.h"
//////////////

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
//// Scale of graphs the LCD screen ////
#define SCALE_LUX_GRAPH_MIN       (0)
#define SCALE_LUX_GRAPH_MAX       (1000)
#define SCALE_LUX_GRAPH_INTERVAL  (200)

#define SCALE_TEMP_GRAPH_MIN      (16)
#define SCALE_TEMP_GRAPH_MAX      (36)
#define SCLAE_TEMP_GRAPH_INTERVAL (4)

//// S2LP ////
#define BSP_BUTTON_EXTI_IRQn EXTI4_15_IRQn
#define S2868A2_GPIO0_EXTI_Pin GPIO_PIN_1
#define S2868A2_GPIO0_EXTI_GPIO_Port GPIOC
#define S2868A2_GPIO0_EXTI_EXTI_IRQn EXTI0_1_IRQn
#define S2868A2_EEPROM_CS_Pin GPIO_PIN_4
#define S2868A2_EEPROM_CS_GPIO_Port GPIOB

// SDN on D2
#define S2868A2_SDN_Pin GPIO_PIN_10
#define S2868A2_SDN_GPIO_Port GPIOA

// SDN on D4
//#define S2868A2_SDN_Pin GPIO_PIN_5
//#define S2868A2_SDN_GPIO_Port GPIOB


#define S2868A2_S2LP_CS_Pin GPIO_PIN_6
#define S2868A2_S2LP_CS_GPIO_Port GPIOB
//////////////

//// GFX ////
#define BUTTON_USER_Pin GPIO_PIN_13
#define BUTTON_USER_GPIO_Port GPIOC
#define BUTTON_UP_Pin GPIO_PIN_0
#define BUTTON_UP_GPIO_Port GPIOC
#define DISPLAY_TEARING_EFFECT_Pin GPIO_PIN_0
#define DISPLAY_TEARING_EFFECT_GPIO_Port GPIOA
#define DISPLAY_TEARING_EFFECT_EXTI_IRQn EXTI0_1_IRQn
#define DISPLAY_RESET_Pin GPIO_PIN_1
#define DISPLAY_RESET_GPIO_Port GPIOA
#define FRAME_RATE_Pin GPIO_PIN_5
#define FRAME_RATE_GPIO_Port GPIOC
#define BUTTON_RIGHT_Pin GPIO_PIN_0
#define BUTTON_RIGHT_GPIO_Port GPIOB
#define DISPLAY_DCX_Pin GPIO_PIN_10
#define DISPLAY_DCX_GPIO_Port GPIOB
#define RENDER_TIME_Pin GPIO_PIN_6
#define RENDER_TIME_GPIO_Port GPIOC
#define BUTTON_CENTER_Pin GPIO_PIN_7
#define BUTTON_CENTER_GPIO_Port GPIOC
#define VSYNC_FREQ_Pin GPIO_PIN_8
#define VSYNC_FREQ_GPIO_Port GPIOC
#define FLASH_CS_Pin GPIO_PIN_8
#define FLASH_CS_GPIO_Port GPIOA
#define DISPLAY_CSX_Pin GPIO_PIN_9
#define DISPLAY_CSX_GPIO_Port GPIOA
#define BUTTON_DOWN_Pin GPIO_PIN_4
#define BUTTON_DOWN_GPIO_Port GPIOB
#define BUTTON_LEFT_Pin GPIO_PIN_6
#define BUTTON_LEFT_GPIO_Port GPIOB
//////////////

/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
