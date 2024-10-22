
/**
  ******************************************************************************
  * @file    s2868a2_conf.h
  * @author  SRA Application Team
  * @brief   This file contains definitions for the S2868A2 components bus interfaces
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

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __S2868A2_CONF_H__
#define __S2868A2_CONF_H__

#ifdef __cplusplus
extern "C" {
#endif

#include "stm32u0xx_hal.h"
#include "custom_bus.h"
#include "custom_errno.h"

#include "stm32u0xx_hal_exti.h"
#include "s2868a2_s2lpgpio_setting.h"
#include "RTE_Components.h"

/* Global configuration ---------------------------------------------------*/
extern volatile int irq_disable_cnt;

/* Defines ---------------------------------------------------------------*/

/* S2868A2_RADIO_GPIO_0 is set as EXTI */
#define S2LP_NVIC_GPIO_0_DisableIRQ()	HAL_NVIC_DisableIRQ( S2868A2_RADIO_GPIO_0_IRQn)
#define S2LP_NVIC_GPIO_0_EnableIRQ()	HAL_NVIC_EnableIRQ( S2868A2_RADIO_GPIO_0_IRQn)

/* S2868A2_RADIO_GPIO_1 is NOT set as EXTI */
#define S2LP_NVIC_GPIO_1_DisableIRQ()
#define S2LP_NVIC_GPIO_1_EnableIRQ()

/* S2868A2_RADIO_GPIO_2 is NOT set as EXTI */
#define S2LP_NVIC_GPIO_2_DisableIRQ()
#define S2LP_NVIC_GPIO_2_EnableIRQ()

/* S2868A2_RADIO_GPIO_3 is NOT set as EXTI */
#define S2LP_NVIC_GPIO_3_DisableIRQ()
#define S2LP_NVIC_GPIO_3_EnableIRQ()

#define S2868A2_ENTER_CRITICAL()	\
   do{                                                                \
		 irq_disable_cnt++;		\
		 S2LP_NVIC_GPIO_0_DisableIRQ();        \
		 S2LP_NVIC_GPIO_1_DisableIRQ();        \
		 S2LP_NVIC_GPIO_2_DisableIRQ();        \
		 S2LP_NVIC_GPIO_3_DisableIRQ();        \
   }while(0)
#define S2868A2_EXIT_CRITICAL()                             \
   do{                                                                \
     if (irq_disable_cnt > 0)                                         \
       irq_disable_cnt--;                                             \
     if (irq_disable_cnt==0)                                          \
	 {	\
		S2LP_NVIC_GPIO_0_EnableIRQ();        \
		S2LP_NVIC_GPIO_1_EnableIRQ();        \
		S2LP_NVIC_GPIO_2_EnableIRQ();        \
		S2LP_NVIC_GPIO_3_EnableIRQ();        \
	}	\
   }while(0)

#define S2868A2_SPI_Init                                    BSP_SPI1_Init
#define S2868A2_SPI_DeInit                                  BSP_SPI1_DeInit
#define S2868A2_SPI_SendRecv                                BSP_SPI1_SendRecv
#define EEPROM_SPI_SendRecv                                 BSP_SPI1_SendRecv
#define S2868A2_Delay                                       HAL_Delay
#define hspi                                                hspi1

#define EEPROM_INSTANCE                                     (0)

#define S2868A2_EEPROM_SPI_CS_PORT                          GPIOB
#define S2868A2_EEPROM_SPI_CS_PIN                           GPIO_PIN_4
#define S2868A2_EEPROM_SPI_CS_RCC                           __HAL_RCC_GPIOB_CLK_ENABLE
#define S2868A2_EEPROM_SPI_CS_SPEED                         GPIO_SPEED_FREQ_HIGH
#define S2868A2_EEPROM_SPI_CS_PULL_MODE                     GPIO_PULLUP

/* SPIx Bus Pin mapping */
#define S2868A2_RADIO_SPI_NSS_CLK_ENABLE()                  __HAL_RCC_GPIOB_CLK_ENABLE()
#define S2868A2_RADIO_SPI_NSS_PORT                          GPIOB
#define S2868A2_RADIO_SPI_NSS_PIN                           GPIO_PIN_6
#define S2868A2_RADIO_SPI_NSS_SPEED                         GPIO_SPEED_FREQ_HIGH
#define S2868A2_RADIO_SPI_NSS_PULL_MODE                     GPIO_PULLUP

#define S2868A2_RADIO_TCXO_CTL_PORT                         GPIOC
#define S2868A2_RADIO_TCXO_CTL_PIN                          GPIO_PIN_7
#define S2868A2_RADIO_TCXO_CTL_GPIO_CLK_ENABLE()            __HAL_RCC_GPIOC_CLK_ENABLE()

/* GPIO0 as EXTI */
#define S2868A2_RADIO_GPIO_0_PORT                            GPIOC
#define S2868A2_RADIO_GPIO_0_GPIO_CLK_ENABLE()               __HAL_RCC_GPIOC_CLK_ENABLE()
#define S2868A2_RADIO_GPIO_0_PIN                             GPIO_PIN_1
#define S2868A2_RADIO_GPIO_0_EXTI_LINE                       EXTI_LINE_1
#define S2868A2_RADIO_GPIO_0_IRQn                            EXTI0_1_IRQn
#define H_EXTI_1                                             S2868A2_RADIO_GPIO_hexti[0]
#define S2868A2_RADIO_GPIO_0_MODE                            RADIO_MODE_EXTI_IN
#define S2868A2_RADIO_GPIO_0_EXTI_MODE                       GPIO_MODE_IT_FALLING
#define S2868A2_RADIO_GPIO_0_IT_PRIO                         0
#define S2868A2_RADIO_GPIO_0_IT_SUBPRIO                      0
#define S2868A2_RADIO_GPIO_0_SPEED                           GPIO_SPEED_FREQ_HIGH /* This value is not used for EXTI mode */
#define S2868A2_RADIO_GPIO_0_PULL_MODE                       GPIO_NOPULL

#define S2868A2_RADIO_GPIOn                                  (USE_S2868A2_RADIO_GPIO_0 + \
                                                            USE_S2868A2_RADIO_GPIO_1 + \
                                                            USE_S2868A2_RADIO_GPIO_2 + \
                                                            USE_S2868A2_RADIO_GPIO_3 + 1)

#if (S2868A2_RADIO_GPIOn == 1)
#error "At least one GPIO must be enabled (and in EXTI mode) for the radio to work."
#endif /*(S2868A2_RADIO_GPIOn == 1)*/

extern  EXTI_HandleTypeDef   S2868A2_RADIO_GPIO_hexti[S2868A2_RADIO_GPIOn -1];

// SDN A4
//#define S2868A2_RADIO_GPIO_SDN_PORT                          GPIOB
//#define S2868A2_RADIO_GPIO_SDN_CLOCK_ENABLE()                __HAL_RCC_GPIOB_CLK_ENABLE()
//#define S2868A2_RADIO_GPIO_SDN_PIN                           GPIO_PIN_5
//#define S2868A2_RADIO_GPIO_SDN_SPEED                         GPIO_SPEED_FREQ_HIGH
//#define S2868A2_RADIO_GPIO_SDN_PULL_MODE                     GPIO_NOPULL

// SDN A2
#define S2868A2_RADIO_GPIO_SDN_PORT                          GPIOA
#define S2868A2_RADIO_GPIO_SDN_CLOCK_ENABLE()                __HAL_RCC_GPIOA_CLK_ENABLE()
#define S2868A2_RADIO_GPIO_SDN_PIN                           GPIO_PIN_10
#define S2868A2_RADIO_GPIO_SDN_SPEED                         GPIO_SPEED_FREQ_HIGH
#define S2868A2_RADIO_GPIO_SDN_PULL_MODE                     GPIO_NOPULL

/*The LED on the Expansion Board is not selected  */
#define S2868A2_LEDn                                        (0)

#ifdef __cplusplus
}
#endif

#endif /* __S2868A2_CONF_H__*/

