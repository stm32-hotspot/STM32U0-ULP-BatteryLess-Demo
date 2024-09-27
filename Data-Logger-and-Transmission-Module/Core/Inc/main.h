/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @author         : Etienne Sesmat
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

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include <stdio.h>
#include "demo_config.h" 
#include "stm32u083c_discovery.h"
#include "stm32u083c_discovery_glass_lcd.h"
#include "stm32u083c_discovery_env_sensors.h"
#include "stm32u083c_discovery_bus.h"  
#include "s2868a2_conf.h"
#include "demo_pv.h"
#include "app_x-cube-subg2.h"
/* USER CODE END Includes */

/* Exported types ------------------------------------------------------------*/
/* USER CODE BEGIN ET */
//extern TSC_HandleTypeDef htsc;

typedef struct
{
  uint32_t Measure;
  uint32_t Display;
} DemoTypedef;

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

/* USER CODE BEGIN Private defines */
//#define ID_DEMO_VERSION_1                   (1)
//#define ID_DEMO_VERSION_2                   (2)

#define ID_MEASURE_CURRENTPV                (1)
#define ID_MEASURE_TEMPERATURE_STTS22H      (3)
//#define ID_MEASURE_TEMPERATURE_ADC          (4)
//#define ID_MEASURE_TIMEALIVE                (5)
//#define ID_MEASURE_VDDMCU                   (6)

//#define ID_DISPLAY_CURRENTPV                (1)
#define ID_DISPLAY_ILLUMINENCE              (2)
#define ID_DISPLAY_TEMPERATURE_STTS22H      (3)
//#define ID_DISPLAY_TEMPERATURE_ADC          (4)
//#define ID_DISPLAY_TIMEALIVE                (5)
//#define ID_DISPLAY_VDDMCU                   (6)

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
