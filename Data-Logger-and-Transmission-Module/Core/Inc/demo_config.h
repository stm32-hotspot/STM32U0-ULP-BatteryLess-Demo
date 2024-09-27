/* USER CODE BEGIN Header */
/**
 ******************************************************************************
  * @file 	 demo_config.h
  * @author      Etienne Sesmat
  * @brief       Header for demo_config.c file.
  *              This file contains macros to configure the application
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2024 STMicroelectronics.
  * All rights reserved.
  *
  * This software component is licensed under terms that can be found in the LICENSE file
  * in the root derictory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */

/* USER CODE BEGIN PD */
////    USE_STM32U083C_DISCO_REVB -> to put in preprocessor defined for DK revB or revC

#define THRESHOLD_LUX_NO_SENDING        (150)
#define RESISTOR_VALUE_OHM              (2200)          //R1 on schematic
#define COEF_CURRENT_TO_LUX             (250/80)        //lux / mA

#define PV_SUPPLIED                     (0)             // Force PV supplied
#define DEMO_RF                         (1)             // Force demo RF

#define MSI_RANGE                       RCC_MSIRANGE_8  // RCC_MSIRANGE_8    -->  MSI = 16 MHz   */

////   CONFIG POWER REGULATOR    ///// 
#if (USE_HSI16 > 0) || (MSI_RANGE < RCC_MSIRANGE_9)
#define PWR_REGULATOR_VOLTAGE           PWR_REGULATOR_VOLTAGE_SCALE2
#else
#define PWR_REGULATOR_VOLTAGE           PWR_REGULATOR_VOLTAGE_SCALE1
#endif

////    CONFIG PERIPHERALS      /////
#define USE_LCD                         (1)
#define USE_JOYSTICK_BUTTON             (1)

#define ENABLE_PVD                      PV_SUPPLIED
#define ENABLE_STOP2                    (1)
#define CONS_STOP2                      (0) // Debug to measure stop2 cons

////    CONFIGURE MEASURES       /////
//#define MEASURE_CURRENTPV               (0)
//#define MEASURE_TEMPERATURE_STTS22H     (1)
//#define AT_LEAST_ONE_MEASURE            (MEASURE_CURRENTPV || MEASURE_TEMPERATURE_STTS22H || MEASURE_TEMPERATURE_ADC || MEASURE_TIMEALIVE || MEASURE_VDDMCU)
//#define ENTER_DEMO                      (AT_LEAST_ONE_MEASURE)

/////   CONFIGURE DISPLAY       /////
//#if     MEASURE_CURRENTPV > 0
//#define DISPLAY_ILLUMINANCE             (1)
//#endif
//
//#if     MEASURE_TEMPERATURE_STTS22H > 0
//#define DISPLAY_TEMPERATURE_STTS22H     (1)
//#endif

/////   CONFIGURE GPIO         /////
#define LUX_GPIO_PIN                     GPIO_PIN_0
#define LUX_GPIO_PORT                    GPIOA
#define LUX_GPIO_CLK_ENABLE()            __HAL_RCC_GPIOA_CLK_ENABLE()
#define LUX_ADC_CHANNEL                  ADC_CHANNEL_1
#define ADC_NUMBER_MEASURES              (20)
#define ADC_MESURES_TAKEN_INTO_ACCOUNT   (5) //last X mesaures are taken into account (wait for adc value to stabilize)
#define VDDA_APPLI                       (2048UL)       //ADC VREF value
#define DIGITAL_SCALE_12BITS             ((uint32_t) 0xFFF)
#define VAR_CONVERTED_DATA_INIT_VALUE    (DIGITAL_SCALE_12BITS + 1)

/////    CONFIGURE LCD         /////
#if USE_LCD > 0
#define CLEAR_LCD                        (0)
#define DISP_STOP2                       (0)
#endif
        
/////    CONFIGURE RTC         /////
#define RTC_LSE_ENABLE                   (!CONS_STOP2)