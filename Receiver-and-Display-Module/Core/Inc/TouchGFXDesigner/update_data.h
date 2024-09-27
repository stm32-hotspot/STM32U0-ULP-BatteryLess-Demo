/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : update_data.h
  * @brief          : Header for update_data.c file.
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
#include <stdint.h>
    
#ifndef __UPDATE_DATA_H
#define __UPDATE_DATA_H

#ifdef __cplusplus
extern "C" {
#endif

typedef struct 
{
    uint16_t temp;
    uint16_t lux;
    uint8_t new_data_flag;
} MeasuredDataTypeDef;

MeasuredDataTypeDef getData(void);
void setData(MeasuredDataTypeDef d);

#ifdef __cplusplus
}
#endif

#endif /* __UPDATE_DATA_H */
