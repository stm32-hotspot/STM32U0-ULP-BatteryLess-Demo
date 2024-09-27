/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : update_data.c
  * @brief          : 
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

/* Includes ------------------------------------------------------------------*/
#include "update_data.h"

#ifdef __cplusplus
extern "C" {
#endif

static MeasuredDataTypeDef MData;

MeasuredDataTypeDef getData(void){
  MeasuredDataTypeDef temp = MData;
  MData.new_data_flag = 0;
  return temp;
}

void setData(MeasuredDataTypeDef d){
    MData.lux = d.lux;
    MData.temp = d.temp;
    MData.new_data_flag = d.new_data_flag;
}

void resetNewDataFlag(MeasuredDataTypeDef d){
  
}


#ifdef __cplusplus
}
#endif