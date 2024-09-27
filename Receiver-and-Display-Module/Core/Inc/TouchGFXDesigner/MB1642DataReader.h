/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : MB1642DataReader.h
  * @brief          : Header for MB1642DataReader.c file.
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

#ifndef DataReader_H
#define DataReader_H

#include <stdint.h>

uint32_t DataReader_IsReceivingData(void);
void     DataReader_WaitForReceiveDone(void);
void     DataReader_Init(void);
void     DataReader_ReadData(uint32_t address24, uint8_t* buffer, uint32_t length);
void     DataReader_StartDMAReadData(uint32_t address24, uint8_t* buffer, uint32_t length);
void     DataReader_DMACallback(void);

#endif //DataReader_H
