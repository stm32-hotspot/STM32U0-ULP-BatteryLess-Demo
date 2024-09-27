/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : MB1642ButtonController.hpp
  * @brief          : Header for MB1642ButtonController.c file.
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

#ifndef MB1642ABUTTONCONTROLLER_HPP_
#define MB1642ABUTTONCONTROLLER_HPP_

#include <platform/driver/button/ButtonController.hpp>

class MB1642ButtonController : public touchgfx::ButtonController
{
    virtual void init();
    virtual bool sample(uint8_t& key);

private:
    uint8_t getKeyState(void);

    uint8_t previousState;
};

#endif /* MB1642BUTTONCONTROLLER_HPP_ */
