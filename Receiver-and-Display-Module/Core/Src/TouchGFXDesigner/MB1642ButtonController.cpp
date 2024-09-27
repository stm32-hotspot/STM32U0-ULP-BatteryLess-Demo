/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : MB1642ButtonController.cpp
  * @brief          : 
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

#include <MB1642ButtonController.hpp>
#include <main.h>
#include <touchgfx/hal/HAL.hpp>

void MB1642ButtonController::init()
{
    previousState = 0;
}

bool MB1642ButtonController::sample(uint8_t& key)
{
    uint8_t state = getKeyState();
    if (state == previousState)
    {
        return false;
    }
    previousState = state;
    if (state != 0)
    {
        key = state;
        return true;
    }
    return false;
}

uint8_t MB1642ButtonController::getKeyState(void)
{
    uint8_t keyPressed = 0;

    if (touchgfx::HAL::getInstance()->getDisplayOrientation() == touchgfx::ORIENTATION_PORTRAIT)
    {
        if (HAL_GPIO_ReadPin(BUTTON_CENTER_GPIO_Port, BUTTON_CENTER_Pin) == GPIO_PIN_RESET)
        {
            keyPressed = '5'; // Corresponds to keyboard keypad center
        }
        else if (HAL_GPIO_ReadPin(BUTTON_LEFT_GPIO_Port, BUTTON_LEFT_Pin) == GPIO_PIN_RESET)
        {
            keyPressed = '4'; // Corresponds to keyboard keypad left
        }
        else if (HAL_GPIO_ReadPin(BUTTON_RIGHT_GPIO_Port, BUTTON_RIGHT_Pin) == GPIO_PIN_RESET)
        {
            keyPressed = '6'; // Corresponds to keyboard keypad right
        }
        else if (HAL_GPIO_ReadPin(BUTTON_UP_GPIO_Port, BUTTON_UP_Pin) == GPIO_PIN_RESET)
        {
            keyPressed = '8'; // Corresponds to keyboard keypad up
        }
        else if (HAL_GPIO_ReadPin(BUTTON_DOWN_GPIO_Port, BUTTON_DOWN_Pin) == GPIO_PIN_RESET)
        {
            keyPressed = '2'; // Corresponds to keyboard keypad down
        }
        //Blue user button on Nucleo boad
        else if (HAL_GPIO_ReadPin(BUTTON_USER_GPIO_Port, BUTTON_USER_Pin) == GPIO_PIN_RESET)
        {
            keyPressed = '0';
        }
    }
    else
    {
        if (HAL_GPIO_ReadPin(BUTTON_CENTER_GPIO_Port, BUTTON_CENTER_Pin) == GPIO_PIN_RESET)
        {
            keyPressed = '5'; // Corresponds to keyboard keypad enter
        }
        else if (HAL_GPIO_ReadPin(BUTTON_LEFT_GPIO_Port, BUTTON_LEFT_Pin) == GPIO_PIN_RESET)
        {
            keyPressed = '8'; // Corresponds to keyboard keypad up
        }
        else if (HAL_GPIO_ReadPin(BUTTON_RIGHT_GPIO_Port, BUTTON_RIGHT_Pin) == GPIO_PIN_RESET)
        {
            keyPressed = '2'; // Corresponds to keyboard keypad down
        }
        else if (HAL_GPIO_ReadPin(BUTTON_UP_GPIO_Port, BUTTON_UP_Pin) == GPIO_PIN_RESET)
        {
            keyPressed = '6'; // Corresponds to keyboard keypad right
        }
        else if (HAL_GPIO_ReadPin(BUTTON_DOWN_GPIO_Port, BUTTON_DOWN_Pin) == GPIO_PIN_RESET)
        {
            keyPressed = '4'; // Corresponds to keyboard keypad left
        }
        //Blue user button on Nucleo boad
        else if (HAL_GPIO_ReadPin(BUTTON_USER_GPIO_Port, BUTTON_USER_Pin) == GPIO_PIN_RESET)
        {
            keyPressed = '0';
        }
    }

    return keyPressed;
}
