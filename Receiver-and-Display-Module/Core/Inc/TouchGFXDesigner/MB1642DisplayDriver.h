/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : MB1642DisplayDriver.h
  * @brief          : Header for MB1642DisplayDriver.c file.
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

#ifndef __DISPLAY_H
#define __DISPLAY_H

#ifdef __cplusplus
extern "C" {
#endif

void     touchgfxDisplayDriverTransmitBlock(const uint8_t* pixels, uint16_t x, uint16_t y, uint16_t w, uint16_t h);
int      touchgfxDisplayDriverTransmitActive(void);
int      touchgfxDisplayDriverShouldTransferBlock(uint16_t bottom);
void     DisplayDriver_DMACallback(void);
void     DisplayDriver_Init(void);
void     DisplayDriver_DisplayOn(void);
void     DisplayDriver_DisplayReset(void);
void     DisplayDriver_DisplayInit(void);
void     DisplayDriver_TransferCompleteCallback(void);

#ifdef __cplusplus
}
#endif

#endif

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
