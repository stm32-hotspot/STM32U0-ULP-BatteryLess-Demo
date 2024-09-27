/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * File Name          : TouchGFXDataReader.cpp
  ******************************************************************************
  * This file was created by TouchGFX Generator 4.23.0. This file is only
  * generated once! Delete this file from your project and re-generate code
  * using STM32CubeMX or change this file manually to update it.
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

#include <TouchGFXDataReader.hpp>

/* USER CODE BEGIN TouchGFXDataReader.cpp */

bool TouchGFXDataReader::addressIsAddressable(const void* address)
{
    // Calling parent implementation of addressIsAddressable().
    //
    // To overwrite the generated implementation, omit call to parent function
    // and implemented needed functionality here.

    return TouchGFXGeneratedDataReader::addressIsAddressable(address);
}

void TouchGFXDataReader::copyData(const void* src, void* dst, uint32_t bytes)
{
    // Calling parent implementation of copyData().
    //
    // To overwrite the generated implementation, omit call to parent function
    // and implemented needed functionality here.

    TouchGFXGeneratedDataReader::copyData(src, dst, bytes);
}

void TouchGFXDataReader::startFlashLineRead(const void* src, uint32_t bytes)
{
    // Calling parent implementation of startFlashLineRead().
    //
    // To overwrite the generated implementation, omit call to parent function
    // and implemented needed functionality here.

    TouchGFXGeneratedDataReader::startFlashLineRead(src, bytes);
}

const uint8_t* TouchGFXDataReader::waitFlashReadComplete()
{
    // Calling parent implementation of waitFlashReadComplete().
    //
    // To overwrite the generated implementation, omit call to parent function
    // and implemented needed functionality here.

    return TouchGFXGeneratedDataReader::waitFlashReadComplete();
}

/* USER CODE END TouchGFXDataReader.cpp */
