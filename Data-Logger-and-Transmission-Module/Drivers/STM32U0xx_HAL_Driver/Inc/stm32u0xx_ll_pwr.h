/**
  ******************************************************************************
  * @file    stm32u0xx_ll_pwr.h
  * @author  MCD Application Team
  * @brief   Header file of PWR LL module.
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2023 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef STM32U0xx_LL_PWR_H
#define STM32U0xx_LL_PWR_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32u0xx.h"

/** @addtogroup STM32U0xx_LL_Driver
  * @{
  */

#if defined(PWR)

/** @defgroup PWR_LL PWR
  * @{
  */

/* Private types -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
/* Private constants ---------------------------------------------------------*/
/* Private macros ------------------------------------------------------------*/
/* Exported types ------------------------------------------------------------*/
/* Exported constants --------------------------------------------------------*/

/** @defgroup PWR_LL_Exported_Constants PWR Exported Constants
  * @{
  */

/** @defgroup PWR_LL_EC_CLEAR_FLAG Clear Flags Defines
  * @brief    Flags defines which can be used with LL_PWR_WriteReg function
  * @{
  */
#define LL_PWR_SCR_CSBF                    PWR_SCR_CSBF
#define LL_PWR_SCR_CWUF7                   PWR_SCR_CWUF7
#define LL_PWR_SCR_CWUF5                   PWR_SCR_CWUF5
#define LL_PWR_SCR_CWUF4                   PWR_SCR_CWUF4
#define LL_PWR_SCR_CWUF3                   PWR_SCR_CWUF3
#define LL_PWR_SCR_CWUF2                   PWR_SCR_CWUF2
#define LL_PWR_SCR_CWUF1                   PWR_SCR_CWUF1
/**
  * @}
  */

/** @defgroup PWR_LL_EC_GET_FLAG Get Flags Defines
  * @brief    Flags defines which can be used with LL_PWR_ReadReg function
  * @{
  */
#define LL_PWR_SR1_WUFI                    PWR_SR1_WUFI
#define LL_PWR_SR1_STOP2                   (PWR_SR1_STOPF_2 | PWR_SR1_STOPF_1)
#define LL_PWR_SR1_STOP1                   (PWR_SR1_STOPF_2 | PWR_SR1_STOPF_0)
#define LL_PWR_SR1_STOP0                   PWR_SR1_STOPF_2
#define LL_PWR_SR1_SBF                     PWR_SR1_SBF
#define LL_PWR_SR1_WUF7                    PWR_SR1_WUF7
#define LL_PWR_SR1_WUF5                    PWR_SR1_WUF5
#define LL_PWR_SR1_WUF4                    PWR_SR1_WUF4
#define LL_PWR_SR1_WUF3                    PWR_SR1_WUF3
#define LL_PWR_SR1_WUF2                    PWR_SR1_WUF2
#define LL_PWR_SR1_WUF1                    PWR_SR1_WUF1
#define LL_PWR_SR2_PVMO4                   PWR_SR2_PVMO4
#define LL_PWR_SR2_PVMO3                   PWR_SR2_PVMO3
#define LL_PWR_SR2_PVMO1                   PWR_SR2_PVMO1
#define LL_PWR_SR2_PVDO                    PWR_SR2_PVDO
#define LL_PWR_SR2_VOSF                    PWR_SR2_VOSF
#define LL_PWR_SR2_REGLPF                  PWR_SR2_REGLPF
#define LL_PWR_SR2_REGLPS                  PWR_SR2_REGLPS
#define LL_PWR_SR2_FLASHRDY                PWR_SR2_FLASH_RDY
/**
  * @}
  */

/** @defgroup PWR_LL_EC_REGU_VOLTAGE REGU VOLTAGE
  * @{
  */
#define LL_PWR_CR1_LPR                     PWR_CR1_LPR
/**
  * @}
  */

/** @defgroup PWR_LL_EC_REGU_VOLTAGE REGU VOLTAGE
  * @{
  */
#define LL_PWR_REGU_VOLTAGE_SCALE1         PWR_CR1_VOS_0
#define LL_PWR_REGU_VOLTAGE_SCALE2         PWR_CR1_VOS_1
/**
  * @}
  */

/** @defgroup PWR_LL_EC_MODE_PWR MODE PWR
  * @{
  */
#define LL_PWR_MODE_STOP0                  0x00000000U
#define LL_PWR_MODE_STOP1                  PWR_CR1_LPMS_0
#define LL_PWR_MODE_STOP2                  PWR_CR1_LPMS_1
#define LL_PWR_MODE_STANDBY                PWR_CR1_LPMS_2
#define LL_PWR_MODE_SHUTDOWN               (PWR_CR1_LPMS_1 | PWR_CR1_LPMS_0)
/**
  * @}
  */

#define LL_PWR_CR1_DBP                    PWR_CR1_DBP
#define LL_PWR_CR1_FPD_LPSLP              PWR_CR1_FPD_LPSLP
#define LL_PWR_CR1_FPD_LPRUN              PWR_CR1_FPD_LPRUN
#define LL_PWR_CR1_FPD_STOP               PWR_CR1_FPD_STOP

/** @defgroup PWR_LL_EC_PVM_VDDUSB_1 Peripheral voltage monitoring
  * @{
  */
#define LL_PWR_PVM_VDDUSB_1_2V             PWR_CR2_PVME1                                                 /* Monitoring VDDUSB vs. 1.2V */
#define LL_PWR_PVM_VDDA_1_62V              PWR_CR2_PVME3                                                 /* Monitoring VDDA_P vs. 1.62V  */
#define LL_PWR_PVM_VDDA_2_2V               PWR_CR2_PVME4                                                 /* Monitoring VDDA_P vs. 2.2V   */
/**
  * @}
  */

/** @defgroup PWR_LL_EC_PVDLEVEL PVDLEVEL
  * @{
  */
#define LL_PWR_PVDLEVEL_0                  0x00000000U                                                    /* VPVD0 around 2.0 V */
#define LL_PWR_PVDLEVEL_1                  PWR_CR2_PLS_0                                                  /* VPVD1 around 2.2 V */
#define LL_PWR_PVDLEVEL_2                  PWR_CR2_PLS_1                                                  /* VPVD2 around 2.4 V */
#define LL_PWR_PVDLEVEL_3                  (PWR_CR2_PLS_1 | PWR_CR2_PLS_0)                                /* VPVD3 around 2.5 V */
#define LL_PWR_PVDLEVEL_4                  PWR_CR2_PLS_2                                                  /* VPVD4 around 2.6 V */
#define LL_PWR_PVDLEVEL_5                  (PWR_CR2_PLS_2 | PWR_CR2_PLS_0)                                /* VPVD5 around 2.8 V */
#define LL_PWR_PVDLEVEL_6                  (PWR_CR2_PLS_2 | PWR_CR2_PLS_1)                                /* VPVD6 around 2.9 V */
#define LL_PWR_PVDLEVEL_7                  (PWR_CR2_PLS_2 | PWR_CR2_PLS_1 | PWR_CR2_PLS_0)                /* External input analog voltage   (Compare internally to VREFINT) */
/**
  * @}
  */

/** @defgroup PWR_LL_EC_WAKEUP WAKEUP
  * @{
  */
#define LL_PWR_WAKEUP_PIN1                 PWR_CR3_EWUP1
#define LL_PWR_WAKEUP_PIN2                 PWR_CR3_EWUP2
#define LL_PWR_WAKEUP_PIN3                 PWR_CR3_EWUP3
#define LL_PWR_WAKEUP_PIN4                 PWR_CR3_EWUP4
#define LL_PWR_WAKEUP_PIN5                 PWR_CR3_EWUP5
#define LL_PWR_WAKEUP_PIN7                 PWR_CR3_EWUP7
/**
  * @}
  */

/** @defgroup PWR_LL_EC_BATT_CHARG_RESISTOR BATT CHARG RESISTOR
  * @{
  */
#define LL_PWR_BATT_CHARG_RESISTOR_5K      0U
#define LL_PWR_BATT_CHARGRESISTOR_1_5K     PWR_CR4_VBRS
/**
  * @}
  */

/** @defgroup PWR_LL_EC_SRAM_CONTENT_RETENTION SRAM CONTENT RETENTION
  * @{
  */
#define LL_PWR_NO_SRAM_RETENTION        0U
#define LL_PWR_FULL_SRAM_RETENTION      PWR_CR3_RRS

/**
  * @}
  */
/** @defgroup PWR_LL_EC_GPIO GPIO
  * @{
  */
#define LL_PWR_GPIO_A                      ((uint32_t)(&(PWR->PUCRA)))
#define LL_PWR_GPIO_B                      ((uint32_t)(&(PWR->PUCRB)))
#define LL_PWR_GPIO_C                      ((uint32_t)(&(PWR->PUCRC)))
#define LL_PWR_GPIO_D                      ((uint32_t)(&(PWR->PUCRD)))
#if defined (GPIOE)
#define LL_PWR_GPIO_E                      ((uint32_t)(&(PWR->PUCRE)))
#endif /* GPIOE */
#define LL_PWR_GPIO_F                      ((uint32_t)(&(PWR->PUCRF)))
/**
  * @}
  */

/** @defgroup PWR_LL_EC_GPIO_BIT GPIO BIT
  * @{
  */
#define LL_PWR_GPIO_BIT_0                  0x00000001U
#define LL_PWR_GPIO_BIT_1                  0x00000002U
#define LL_PWR_GPIO_BIT_2                  0x00000004U
#define LL_PWR_GPIO_BIT_3                  0x00000008U
#define LL_PWR_GPIO_BIT_4                  0x00000010U
#define LL_PWR_GPIO_BIT_5                  0x00000020U
#define LL_PWR_GPIO_BIT_6                  0x00000040U
#define LL_PWR_GPIO_BIT_7                  0x00000080U
#define LL_PWR_GPIO_BIT_8                  0x00000100U
#define LL_PWR_GPIO_BIT_9                  0x00000200U
#define LL_PWR_GPIO_BIT_10                 0x00000400U
#define LL_PWR_GPIO_BIT_11                 0x00000800U
#define LL_PWR_GPIO_BIT_12                 0x00001000U
#define LL_PWR_GPIO_BIT_13                 0x00002000U
#define LL_PWR_GPIO_BIT_14                 0x00004000U
#define LL_PWR_GPIO_BIT_15                 0x00008000U
/**
  * @}
  */

/**
  * @}
  */

/* Exported macro ------------------------------------------------------------*/
/** @defgroup PWR_LL_Exported_Macros PWR Exported Macros
  * @{
  */

/** @defgroup PWR_LL_EM_WRITE_READ Common Write and read registers Macros
  * @{
  */

/**
  * @brief  Write a value in PWR register
  * @param  __REG__ Register to be written
  * @param  __VALUE__ Value to be written in the register
  * @retval None
  */
#define LL_PWR_WriteReg(__REG__, __VALUE__) WRITE_REG(PWR->__REG__, (__VALUE__))

/**
  * @brief  Read a value in PWR register
  * @param  __REG__ Register to be read
  * @retval Register value
  */
#define LL_PWR_ReadReg(__REG__) READ_REG(PWR->__REG__)
/**
  * @}
  */

/**
  * @}
  */

/* Exported functions --------------------------------------------------------*/
/** @defgroup PWR_LL_Exported_Functions PWR Exported Functions
  * @{
  */

/** @defgroup PWR_LL_EF_Configuration Configuration
  * @{
  */

/**
  * @brief  Set Low-Power mode
  * @rmtoll CR1          LPMS          LL_PWR_SetPowerMode
  * @param  LowPowerMode This parameter can be one of the following values:
  *         @arg @ref LL_PWR_MODE_STOP0
  *         @arg @ref LL_PWR_MODE_STOP1
  *         @arg @ref LL_PWR_MODE_STOP2
  *         @arg @ref LL_PWR_MODE_STANDBY
  *         @arg @ref LL_PWR_MODE_SHUTDOWN
  * @retval None
  */
__STATIC_INLINE void LL_PWR_SetPowerMode(uint32_t LowPowerMode)
{
  MODIFY_REG(PWR->CR1, PWR_CR1_LPMS, LowPowerMode);
}

/**
  * @brief  Get Low-Power mode
  * @rmtoll CR1          LPMS          LL_PWR_GetPowerMode
  * @retval Returned value can be one of the following values:
  *         @arg @ref LL_PWR_MODE_STOP0
  *         @arg @ref LL_PWR_MODE_STOP1
  *         @arg @ref LL_PWR_MODE_STOP2
  *         @arg @ref LL_PWR_MODE_STANDBY
  *         @arg @ref LL_PWR_MODE_SHUTDOWN
  */
__STATIC_INLINE uint32_t LL_PWR_GetPowerMode(void)
{
  return (uint32_t)(READ_BIT(PWR->CR1, PWR_CR1_LPMS));
}

/**
  * @brief  Enable Flash Pwr Down Mode during Stop
  * @rmtoll CR1          FPD_STOP           LL_PWR_EnableFlashPWRDownModeDuringStop
  * @retval None
  */
__STATIC_INLINE void LL_PWR_EnableFlashPWRDownModeDuringStop(void)
{
  SET_BIT(PWR->CR1, PWR_CR1_FPD_STOP);
}

/**
  * @brief  Disable Flash Pwr Down Mode during Stop
  * @rmtoll CR1          FPD_STOP          LL_PWR_DisableFlashPWRDownModeDuringStop
  * @retval None
  */
__STATIC_INLINE void LL_PWR_DisableFlashPWRDownModeDuringStop(void)
{
  CLEAR_BIT(PWR->CR1, PWR_CR1_FPD_STOP);
}

/**
  * @brief  Check if Flash Pwr Down Mode during Stop is enabled
  * @rmtoll CR1          FPD_STOP           LL_PWR_IsEnabledFlashPWRDownModeDuringSTOP
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_PWR_IsEnabledFlashPWRDownModeDuringSTOP(void)
{
  return ((READ_BIT(PWR->CR1, PWR_CR1_FPD_STOP) == (PWR_CR1_FPD_STOP)) ? 1UL : 0UL);
}

/**
  * @brief  Enable Flash Pwr Down Mode during LP run
  * @rmtoll CR1          FPD_LPRUN           LL_PWR_EnableFlashPWRDownModeDuringLPRun
  * @retval None
  */
__STATIC_INLINE void LL_PWR_EnableFlashPWRDownModeDuringLPRun(void)
{
  SET_BIT(PWR->CR1, PWR_CR1_FPD_LPRUN);
}

/**
  * @brief  Disable Flash Pwr Down Mode during LP run
  * @rmtoll CR1          FPD_LPRUN          LL_PWR_DisableFlashPWRDownModeDuringLPRun
  * @retval None
  */
__STATIC_INLINE void LL_PWR_DisableFlashPWRDownModeDuringLPRun(void)
{
  CLEAR_BIT(PWR->CR1, PWR_CR1_FPD_LPRUN);
}

/**
  * @brief  Check if Flash Pwr Down Mode during LP run is enabled
  * @rmtoll CR1          FPD_LPRUN           LL_PWR_IsEnabledFlashPWRDownModeDuringLPRun
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_PWR_IsEnabledFlashPWRDownModeDuringLPRun(void)
{
  return ((READ_BIT(PWR->CR1, PWR_CR1_FPD_LPRUN) == (PWR_CR1_FPD_LPRUN)) ? 1UL : 0UL);
}

/**
  * @brief  Enable Flash Pwr Down Mode during LP Sleep
  * @rmtoll CR1          FPD_LPSLP           LL_PWR_EnableFlashPWRDownModeDuringSleeep
  * @retval None
  */
__STATIC_INLINE void LL_PWR_EnableFlashPWRDownModeDuringSleeep(void)
{
  SET_BIT(PWR->CR1, PWR_CR1_FPD_LPSLP);
}

/**
  * @brief  Disable Flash Pwr Down Mode during LP Sleep
  * @rmtoll CR1          FPD_LPSLP           LL_PWR_DisableFlashPWRDownModeDuringSleeep
  * @retval None
  */
__STATIC_INLINE void LL_PWR_DisableFlashPWRDownModeDuringSleeep(void)
{
  CLEAR_BIT(PWR->CR1, PWR_CR1_FPD_LPSLP);
}

/**
  * @brief  Check if Flash Pwr Down Mode is enabled during Sleep
  * @rmtoll CR1          FPD_LPSLP           LL_PWR_IsEnabledFlashPWRDownModeDuringSleeep
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_PWR_IsEnabledFlashPWRDownModeDuringSleeep(void)
{
  return ((READ_BIT(PWR->CR1, PWR_CR1_FPD_LPSLP) == (PWR_CR1_FPD_LPSLP)) ? 1UL : 0UL);
}

/**
  * @brief  Enable access to the backup domain
  * @rmtoll CR1          DBP           LL_PWR_EnableBkUpAccess
  * @retval None
  */
__STATIC_INLINE void LL_PWR_EnableBkUpAccess(void)
{
  SET_BIT(PWR->CR1, PWR_CR1_DBP);
}

/**
  * @brief  Disable access to the backup domain
  * @rmtoll CR1          DBP           LL_PWR_DisableBkUpAccess
  * @retval None
  */
__STATIC_INLINE void LL_PWR_DisableBkUpAccess(void)
{
  CLEAR_BIT(PWR->CR1, PWR_CR1_DBP);
}

/**
  * @brief  Check if the backup domain is enabled
  * @rmtoll CR1          DBP           LL_PWR_IsEnabledBkUpAccess
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_PWR_IsEnabledBkUpAccess(void)
{
  return ((READ_BIT(PWR->CR1, PWR_CR1_DBP) == (PWR_CR1_DBP)) ? 1UL : 0UL);
}

/**
  * @brief  Set the main internal regulator output voltage
  * @note   This configuration may be completed with LL_PWR_EnableRange1BoostMode() on STM32L4Rx/STM32L4Sx devices.
  * @rmtoll CR1          VOS           LL_PWR_SetRegulVoltageScaling
  * @param  VoltageScaling This parameter can be one of the following values:
  *         @arg @ref LL_PWR_REGU_VOLTAGE_SCALE1
  *         @arg @ref LL_PWR_REGU_VOLTAGE_SCALE2
  * @retval None
  */
__STATIC_INLINE void LL_PWR_SetRegulVoltageScaling(uint32_t VoltageScaling)
{
  MODIFY_REG(PWR->CR1, PWR_CR1_VOS, VoltageScaling);
}

/**
  * @brief  Get the main internal regulator output voltage
  * @rmtoll CR1          VOS           LL_PWR_GetRegulVoltageScaling
  * @retval Returned value can be one of the following values:
  *         @arg @ref LL_PWR_REGU_VOLTAGE_SCALE1
  *         @arg @ref LL_PWR_REGU_VOLTAGE_SCALE2
  */
__STATIC_INLINE uint32_t LL_PWR_GetRegulVoltageScaling(void)
{
  return (uint32_t)(READ_BIT(PWR->CR1, PWR_CR1_VOS));
}
/**
  * @brief  Switch the regulator from main mode to low-power mode
  * @rmtoll CR1          LPR           LL_PWR_EnableLowPowerRunMode
  * @retval None
  */
__STATIC_INLINE void LL_PWR_EnableLowPowerRunMode(void)
{
  SET_BIT(PWR->CR1, PWR_CR1_LPR);
}

/**
  * @brief  Switch the regulator from low-power mode to main mode
  * @rmtoll CR1          LPR           LL_PWR_DisableLowPowerRunMode
  * @retval None
  */
__STATIC_INLINE void LL_PWR_DisableLowPowerRunMode(void)
{
  CLEAR_BIT(PWR->CR1, PWR_CR1_LPR);
}

/**  * @brief  Switch from run main mode to run low-power mode.
  * @rmtoll CR1          LPR           LL_PWR_EnterLowPowerRunMode
  * @retval None
  */
__STATIC_INLINE void LL_PWR_EnterLowPowerRunMode(void)
{
  LL_PWR_EnableLowPowerRunMode();
}

/**
  * @brief  Switch from run main mode to low-power mode.
  * @rmtoll CR1          LPR           LL_PWR_ExitLowPowerRunMode
  * @retval None
  */
__STATIC_INLINE void LL_PWR_ExitLowPowerRunMode(void)
{
  LL_PWR_DisableLowPowerRunMode();
}

/**
  * @brief  Check if the regulator is in low-power mode
  * @rmtoll CR1          LPR           LL_PWR_IsEnabledLowPowerRunMode
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_PWR_IsEnabledLowPowerRunMode(void)
{
  return ((READ_BIT(PWR->CR1, PWR_CR1_LPR) == (PWR_CR1_LPR)) ? 1UL : 0UL);
}

/**
  * @brief  Enable Power Voltage Detector
  * @rmtoll CR2          PVDE          LL_PWR_EnablePVD
  * @retval None
  */
__STATIC_INLINE void LL_PWR_EnablePVD(void)
{
  SET_BIT(PWR->CR2, PWR_CR2_PVDE);
}

/**
  * @brief  Disable Power Voltage Detector
  * @rmtoll CR2          PVDE          LL_PWR_DisablePVD
  * @retval None
  */
__STATIC_INLINE void LL_PWR_DisablePVD(void)
{
  CLEAR_BIT(PWR->CR2, PWR_CR2_PVDE);
}

/**
  * @brief  Check if Power Voltage Detector is enabled
  * @rmtoll CR2          PVDE          LL_PWR_IsEnabledPVD
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_PWR_IsEnabledPVD(void)
{
  return ((READ_BIT(PWR->CR2, PWR_CR2_PVDE) == (PWR_CR2_PVDE)) ? 1UL : 0UL);
}

/**
  * @brief  Configure the voltage threshold detected by the Power Voltage Detector
  * @rmtoll CR2          PLS           LL_PWR_SetPVDLevel
  * @param  PVDLevel This parameter can be one of the following values:
  *         @arg @ref LL_PWR_PVDLEVEL_0
  *         @arg @ref LL_PWR_PVDLEVEL_1
  *         @arg @ref LL_PWR_PVDLEVEL_2
  *         @arg @ref LL_PWR_PVDLEVEL_3
  *         @arg @ref LL_PWR_PVDLEVEL_4
  *         @arg @ref LL_PWR_PVDLEVEL_5
  *         @arg @ref LL_PWR_PVDLEVEL_6
  *         @arg @ref LL_PWR_PVDLEVEL_7
  * @retval None
  */
__STATIC_INLINE void LL_PWR_SetPVDLevel(uint32_t PVDLevel)
{
  MODIFY_REG(PWR->CR2, PWR_CR2_PLS, PVDLevel);
}

/**
  * @brief  Get the voltage threshold detection
  * @rmtoll CR2          PLS           LL_PWR_GetPVDLevel
  * @retval Returned value can be one of the following values:
  *         @arg @ref LL_PWR_PVDLEVEL_0
  *         @arg @ref LL_PWR_PVDLEVEL_1
  *         @arg @ref LL_PWR_PVDLEVEL_2
  *         @arg @ref LL_PWR_PVDLEVEL_3
  *         @arg @ref LL_PWR_PVDLEVEL_4
  *         @arg @ref LL_PWR_PVDLEVEL_5
  *         @arg @ref LL_PWR_PVDLEVEL_6
  *         @arg @ref LL_PWR_PVDLEVEL_7
  */
__STATIC_INLINE uint32_t LL_PWR_GetPVDLevel(void)
{
  return (uint32_t)(READ_BIT(PWR->CR2, PWR_CR2_PLS));
}
/**
  * @brief  Enable the Power Voltage Monitoring on a peripheral
  * @rmtoll CR2          PVME1         LL_PWR_EnablePVM\n
  *         CR2          PVME2         LL_PWR_EnablePVM\n
  *         CR2          PVME3         LL_PWR_EnablePVM\n
  * @param  PeriphVoltage This parameter can be one of the following values:
  *         @arg @ref LL_PWR_PVM_VDDUSB_1_2V (*)
  *         @arg @ref LL_PWR_PVM_VDDA_1_62V
  *         @arg @ref LL_PWR_PVM_VDDA_2_2V
  *
  *         (*) value not defined in all devices
  * @retval None
  */
__STATIC_INLINE void LL_PWR_EnablePVM(uint32_t PeriphVoltage)
{
  SET_BIT(PWR->CR2, PeriphVoltage);
}

/**
  * @brief  Disable the Power Voltage Monitoring on a peripheral
  * @rmtoll CR2          PVME1         LL_PWR_DisablePVM\n
  *         CR2          PVME2         LL_PWR_DisablePVM\n
  *         CR2          PVME3         LL_PWR_DisablePVM\n
  * @param  PeriphVoltage This parameter can be one of the following values:
  *         @arg @ref LL_PWR_PVM_VDDUSB_1_2V (*)
  *         @arg @ref LL_PWR_PVM_VDDA_1_62V
  *         @arg @ref LL_PWR_PVM_VDDA_2_2V
  *
  *         (*) value not defined in all devices
  * @retval None
  */
__STATIC_INLINE void LL_PWR_DisablePVM(uint32_t PeriphVoltage)
{
  CLEAR_BIT(PWR->CR2, PeriphVoltage);
}

/**
  * @brief  Check if Power Voltage Monitoring is enabled on a peripheral
  * @rmtoll CR2          PVME1         LL_PWR_IsEnabledPVM\n
  *         CR2          PVME2         LL_PWR_IsEnabledPVM\n
  *         CR2          PVME3         LL_PWR_IsEnabledPVM\n
  * @param  PeriphVoltage This parameter can be one of the following values:
  *         @arg @ref LL_PWR_PVM_VDDUSB_1_2V (*)
  *         @arg @ref LL_PWR_PVM_VDDA_1_62V
  *         @arg @ref LL_PWR_PVM_VDDA_2_2V
  *
  *         (*) value not defined in all devices
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_PWR_IsEnabledPVM(uint32_t PeriphVoltage)
{
  return ((READ_BIT(PWR->CR2, PeriphVoltage) == (PeriphVoltage)) ? 1UL : 0UL);
}

/**
  * @brief  Enable VDDUSB supply
  * @rmtoll CR2          USV           LL_PWR_EnableVddUSB
  * @retval None
  */
__STATIC_INLINE void LL_PWR_EnableVddUSB(void)
{
  SET_BIT(PWR->CR2, PWR_CR2_USV);
}

/**
  * @brief  Disable VDDUSB supply
  * @rmtoll CR2          USV           LL_PWR_DisableVddUSB
  * @retval None
  */
__STATIC_INLINE void LL_PWR_DisableVddUSB(void)
{
  CLEAR_BIT(PWR->CR2, PWR_CR2_USV);
}

/**
  * @brief  Check if VDDUSB supply is enabled
  * @rmtoll CR2          USV           LL_PWR_IsEnabledVddUSB
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_PWR_IsEnabledVddUSB(void)
{
  return ((READ_BIT(PWR->CR2, PWR_CR2_USV) == (PWR_CR2_USV)) ? 1UL : 0UL);
}

/**
  * @brief  Enable the WakeUp PINx functionality
  * @rmtoll CR3          EWUP1         LL_PWR_EnableWakeUpPin\n
  *         CR3          EWUP2         LL_PWR_EnableWakeUpPin\n
  *         CR3          EWUP3         LL_PWR_EnableWakeUpPin\n
  *         CR3          EWUP4         LL_PWR_EnableWakeUpPin\n
  *         CR3          EWUP5         LL_PWR_EnableWakeUpPin\n
  *         CR3          EWUP7         LL_PWR_EnableWakeUpPin\n
  * @param  WakeUpPin This parameter can be one of the following values:
  *         @arg @ref LL_PWR_WAKEUP_PIN1
  *         @arg @ref LL_PWR_WAKEUP_PIN2
  *         @arg @ref LL_PWR_WAKEUP_PIN3
  *         @arg @ref LL_PWR_WAKEUP_PIN4
  *         @arg @ref LL_PWR_WAKEUP_PIN5
  *         @arg @ref LL_PWR_WAKEUP_PIN7
  * @retval None
  */
__STATIC_INLINE void LL_PWR_EnableWakeUpPin(uint32_t WakeUpPin)
{
  SET_BIT(PWR->CR3, WakeUpPin);
}

/**
  * @brief  Disable the WakeUp PINx functionality
  * @rmtoll CR3          EWUP1         LL_PWR_DisableWakeUpPin\n
  *         CR3          EWUP2         LL_PWR_DisableWakeUpPin\n
  *         CR3          EWUP3         LL_PWR_DisableWakeUpPin\n
  *         CR3          EWUP4         LL_PWR_DisableWakeUpPin\n
  *         CR3          EWUP5         LL_PWR_DisableWakeUpPin\n
  *         CR3          EWUP7         LL_PWR_DisableWakeUpPin\n
  * @param  WakeUpPin This parameter can be one of the following values:
  *         @arg @ref LL_PWR_WAKEUP_PIN1
  *         @arg @ref LL_PWR_WAKEUP_PIN2
  *         @arg @ref LL_PWR_WAKEUP_PIN3
  *         @arg @ref LL_PWR_WAKEUP_PIN4
  *         @arg @ref LL_PWR_WAKEUP_PIN5
  *         @arg @ref LL_PWR_WAKEUP_PIN7
  * @retval None
  */
__STATIC_INLINE void LL_PWR_DisableWakeUpPin(uint32_t WakeUpPin)
{
  CLEAR_BIT(PWR->CR3, WakeUpPin);
}

/**
  * @brief  Check if the WakeUp PINx functionality is enabled
  * @rmtoll CR3          EWUP1         LL_PWR_IsEnabledWakeUpPin\n
  *         CR3          EWUP2         LL_PWR_IsEnabledWakeUpPin\n
  *         CR3          EWUP3         LL_PWR_IsEnabledWakeUpPin\n
  *         CR3          EWUP4         LL_PWR_IsEnabledWakeUpPin\n
  *         CR3          EWUP5         LL_PWR_IsEnabledWakeUpPin\n
  *         CR3          EWUP7         LL_PWR_IsEnabledWakeUpPin\n
  * @param  WakeUpPin This parameter can be one of the following values:
  *         @arg @ref LL_PWR_WAKEUP_PIN1
  *         @arg @ref LL_PWR_WAKEUP_PIN2
  *         @arg @ref LL_PWR_WAKEUP_PIN3
  *         @arg @ref LL_PWR_WAKEUP_PIN4
  *         @arg @ref LL_PWR_WAKEUP_PIN5
  *         @arg @ref LL_PWR_WAKEUP_PIN7
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_PWR_IsEnabledWakeUpPin(uint32_t WakeUpPin)
{
  return ((READ_BIT(PWR->CR3, WakeUpPin) == (WakeUpPin)) ? 1UL : 0UL);
}

/**
  * @brief  Enable SRAM full content retention in Standby mode
  * @rmtoll CR3          RRS           LL_PWR_EnableSRAMRetention
  * @retval None
  */
__STATIC_INLINE void LL_PWR_EnableSRAMRetention(void)
{
  MODIFY_REG(PWR->CR3, PWR_CR3_RRS, LL_PWR_FULL_SRAM_RETENTION);
}

/**
  * @brief  Disable SRAM content retention in Standby mode
  * @rmtoll CR3          RRS           LL_PWR_DisableSRAMRetention
  * @retval None
  */
__STATIC_INLINE void LL_PWR_DisableSRAMRetention(void)
{
  CLEAR_BIT(PWR->CR3, PWR_CR3_RRS);
}

/**
  * @brief  Check if SRAM full content retention in Standby mode is enabled
  * @rmtoll CR3          RRS           LL_PWR_IsEnabledSRAMRetention
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_PWR_IsEnabledSRAMRetention(void)
{
  return ((READ_BIT(PWR->CR3, PWR_CR3_RRS) == (LL_PWR_FULL_SRAM_RETENTION)) ? 1UL : 0UL);
}

/**
  * @brief  Set SRAM content retention in Standby mode
  * @rmtoll CR3          RRS          LL_PWR_SetSRAMContentRetention
  * @param  SRAM2Size This parameter can be one of the following values:
  *         @arg @ref LL_PWR_NO_SRAM_RETENTION
  *         @arg @ref LL_PWR_FULL_SRAM_RETENTION
  * @note  Setting LL_PWR_NO_SRAM_RETENTION is same as calling LL_PWR_DisableSRAMRetention()
  * @note  Setting LL_PWR_FULL_SRAM_RETENTION is same as calling LL_PWR_EnableSRAMRetention()
  * @retval None
  */
__STATIC_INLINE void LL_PWR_SetSRAMContentRetention(uint32_t SRAMSize)
{
  MODIFY_REG(PWR->CR3, PWR_CR3_RRS, SRAMSize);
}

/**
  * @brief  Get SRAM content retention in Standby mode
  * @rmtoll CR3          RRS          LL_PWR_GetSRAMContentRetention
  * @retval Returned value can be one of the following values:
  *         @arg @ref LL_PWR_NO_SRAM_RETENTION
  *         @arg @ref LL_PWR_FULL_SRAM_RETENTION
  */
__STATIC_INLINE uint32_t LL_PWR_GetSRAMContentRetention(void)
{
  return (uint32_t)(READ_BIT(PWR->CR3, PWR_CR3_RRS));
}

/**
  * @brief  Enable Ultra Low Power BORL, BORH and PVD for STOP2 and Standby modes
  * @rmtoll CR3          ENULP        LL_PWR_EnableBORPVD_ULP
  * @retval None
  */
__STATIC_INLINE void LL_PWR_EnableBORPVD_ULP(void)
{
  SET_BIT(PWR->CR3, PWR_CR3_ENULP);
}

/**
  * @brief  Disable Ultra Low Power BORL, BORH and PVD for STOP2 and Standby modes
  * @rmtoll CR3          ENULP        LL_PWR_DisableBORPVD_ULP
  * @retval None
  */
__STATIC_INLINE void LL_PWR_DisableBORPVD_ULP(void)
{
  CLEAR_BIT(PWR->CR3, PWR_CR3_ENULP);
}

/**
  * @brief  Check if Ultra Low Power BORL, BORH and PVD for STOP2 and Standby modes is enabled
  * @rmtoll CR3          ENULP        LL_PWR_IsEnabledBORPVD_ULP
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_PWR_IsEnabledBORPVD_ULP(void)
{
  return ((READ_BIT(PWR->CR3, PWR_CR3_ENULP) == (PWR_CR3_ENULP)) ? 1UL : 0UL);
}

/**
  * @brief  Enable pull-up and pull-down configuration
  * @rmtoll CR3          APC           LL_PWR_EnablePUPDCfg
  * @retval None
  */
__STATIC_INLINE void LL_PWR_EnablePUPDCfg(void)
{
  SET_BIT(PWR->CR3, PWR_CR3_APC);
}

/**
  * @brief  Disable pull-up and pull-down configuration
  * @rmtoll CR3          APC           LL_PWR_DisablePUPDCfg
  * @retval None
  */
__STATIC_INLINE void LL_PWR_DisablePUPDCfg(void)
{
  CLEAR_BIT(PWR->CR3, PWR_CR3_APC);
}

/**
  * @brief  Check if pull-up and pull-down configuration is enabled
  * @rmtoll CR3          APC           LL_PWR_IsEnabledPUPDCfg
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_PWR_IsEnabledPUPDCfg(void)
{
  return ((READ_BIT(PWR->CR3, PWR_CR3_APC) == (PWR_CR3_APC)) ? 1UL : 0UL);
}

/**
  * @brief  Enable Internal Wake-up line
  * @rmtoll CR3          EIWUL          LL_PWR_EnableInternWU
  * @retval None
  */
__STATIC_INLINE void LL_PWR_EnableInternWU(void)
{
  SET_BIT(PWR->CR3, PWR_CR3_EIWUL);
}

/**
  * @brief  Disable Internal Wake-up line
  * @rmtoll CR3          EIWUL          LL_PWR_DisableInternWU
  * @retval None
  */
__STATIC_INLINE void LL_PWR_DisableInternWU(void)
{
  CLEAR_BIT(PWR->CR3, PWR_CR3_EIWUL);
}

/**
  * @brief  Check if Internal Wake-up line is enabled
  * @rmtoll CR3          EIWUL          LL_PWR_IsEnabledInternWU
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_PWR_IsEnabledInternWU(void)
{
  return ((READ_BIT(PWR->CR3, PWR_CR3_EIWUL) == (PWR_CR3_EIWUL)) ? 1UL : 0UL);
}

/**
  * @brief  Set the Wake-Up pin polarity low for the event detection
  * @rmtoll CR4          WP1           LL_PWR_SetWakeUpPinPolarityLow\n
  *         CR4          WP2           LL_PWR_SetWakeUpPinPolarityLow\n
  *         CR4          WP3           LL_PWR_SetWakeUpPinPolarityLow\n
  *         CR4          WP4           LL_PWR_SetWakeUpPinPolarityLow\n
  *         CR4          WP5           LL_PWR_SetWakeUpPinPolarityLow\n
  *         CR4          WP7           LL_PWR_SetWakeUpPinPolarityLow
  * @param  WakeUpPin This parameter can be one of the following values:
  *         @arg @ref LL_PWR_WAKEUP_PIN1
  *         @arg @ref LL_PWR_WAKEUP_PIN2
  *         @arg @ref LL_PWR_WAKEUP_PIN3
  *         @arg @ref LL_PWR_WAKEUP_PIN4
  *         @arg @ref LL_PWR_WAKEUP_PIN5
  *         @arg @ref LL_PWR_WAKEUP_PIN7
  * @retval None
  */
__STATIC_INLINE void LL_PWR_SetWakeUpPinPolarityLow(uint32_t WakeUpPin)
{
  SET_BIT(PWR->CR4, WakeUpPin);
}

/**
  * @brief  Set the Wake-Up pin polarity high for the event detection
  * @rmtoll CR4          WP1           LL_PWR_SetWakeUpPinPolarityHigh\n
  *         CR4          WP2           LL_PWR_SetWakeUpPinPolarityHigh\n
  *         CR4          WP3           LL_PWR_SetWakeUpPinPolarityHigh\n
  *         CR4          WP4           LL_PWR_SetWakeUpPinPolarityHigh\n
  *         CR4          WP5           LL_PWR_SetWakeUpPinPolarityHigh\n
  *         CR4          WP7           LL_PWR_SetWakeUpPinPolarityHigh\n
  * @param  WakeUpPin This parameter can be one of the following values:
  *         @arg @ref LL_PWR_WAKEUP_PIN1
  *         @arg @ref LL_PWR_WAKEUP_PIN2
  *         @arg @ref LL_PWR_WAKEUP_PIN3
  *         @arg @ref LL_PWR_WAKEUP_PIN4
  *         @arg @ref LL_PWR_WAKEUP_PIN5
  *         @arg @ref LL_PWR_WAKEUP_PIN7
  * @retval None
  */
__STATIC_INLINE void LL_PWR_SetWakeUpPinPolarityHigh(uint32_t WakeUpPin)
{
  CLEAR_BIT(PWR->CR4, WakeUpPin);
}

/**
  * @brief  Get the Wake-Up pin polarity for the event detection
  * @rmtoll CR4          WP1           LL_PWR_IsWakeUpPinPolarityLow\n
  *         CR4          WP2           LL_PWR_IsWakeUpPinPolarityLow\n
  *         CR4          WP3           LL_PWR_IsWakeUpPinPolarityLow\n
  *         CR4          WP4           LL_PWR_IsWakeUpPinPolarityLow\n
  *         CR4          WP5           LL_PWR_IsWakeUpPinPolarityLow\n
  *         CR4          WP7           LL_PWR_IsWakeUpPinPolarityLow\n
  * @param  WakeUpPin This parameter can be one of the following values:
  *         @arg @ref LL_PWR_WAKEUP_PIN1
  *         @arg @ref LL_PWR_WAKEUP_PIN2
  *         @arg @ref LL_PWR_WAKEUP_PIN3
  *         @arg @ref LL_PWR_WAKEUP_PIN4
  *         @arg @ref LL_PWR_WAKEUP_PIN5
  *         @arg @ref LL_PWR_WAKEUP_PIN7
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_PWR_IsWakeUpPinPolarityLow(uint32_t WakeUpPin)
{
  return ((READ_BIT(PWR->CR4, WakeUpPin) == (WakeUpPin)) ? 1UL : 0UL);
}

/**
  * @brief  Enable battery charging
  * @rmtoll CR4          VBE           LL_PWR_EnableBatteryCharging
  * @retval None
  */
__STATIC_INLINE void LL_PWR_EnableBatteryCharging(void)
{
  SET_BIT(PWR->CR4, PWR_CR4_VBE);
}

/**
  * @brief  Disable battery charging
  * @rmtoll CR4          VBE           LL_PWR_DisableBatteryCharging
  * @retval None
  */
__STATIC_INLINE void LL_PWR_DisableBatteryCharging(void)
{
  CLEAR_BIT(PWR->CR4, PWR_CR4_VBE);
}

/**
  * @brief  Check if battery charging is enabled
  * @rmtoll CR4          VBE           LL_PWR_IsEnabledBatteryCharging
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_PWR_IsEnabledBatteryCharging(void)
{
  return ((READ_BIT(PWR->CR4, PWR_CR4_VBE) == (PWR_CR4_VBE)) ? 1UL : 0UL);
}

/**
  * @brief  Set the resistor impedance
  * @rmtoll CR4          VBRS          LL_PWR_SetBattChargResistor
  * @param  Resistor This parameter can be one of the following values:
  *         @arg @ref LL_PWR_BATT_CHARG_RESISTOR_5K
  *         @arg @ref LL_PWR_BATT_CHARGRESISTOR_1_5K
  * @retval None
  */
__STATIC_INLINE void LL_PWR_SetBattChargResistor(uint32_t Resistor)
{
  MODIFY_REG(PWR->CR4, PWR_CR4_VBRS, Resistor);
}

/**
  * @brief  Get the resistor impedance
  * @rmtoll CR4          VBRS          LL_PWR_GetBattChargResistor
  * @retval Returned value can be one of the following values:
  *         @arg @ref LL_PWR_BATT_CHARG_RESISTOR_5K
  *         @arg @ref LL_PWR_BATT_CHARGRESISTOR_1_5K
  */
__STATIC_INLINE uint32_t LL_PWR_GetBattChargResistor(void)
{
  return (uint32_t)(READ_BIT(PWR->CR4, PWR_CR4_VBRS));
}

/**
  * @brief  Enable GPIO pull-up state in Standby and Shutdown modes
  * @rmtoll PUCRA        PU0-15        LL_PWR_EnableGPIOPullUp\n
  *         PUCRB        PU0-15        LL_PWR_EnableGPIOPullUp\n
  *         PUCRC        PU0-15        LL_PWR_EnableGPIOPullUp\n
  *         PUCRD        PU0-13        LL_PWR_EnableGPIOPullUp\n
  *         PUCRE        PU3,PU7-9     LL_PWR_EnableGPIOPullUp\n
  *         PUCRF        PU0-3         LL_PWR_EnableGPIOPullUp\n
  * @param  GPIO This parameter can be one of the following values:
  *         @arg @ref LL_PWR_GPIO_A
  *         @arg @ref LL_PWR_GPIO_B
  *         @arg @ref LL_PWR_GPIO_C
  *         @arg @ref LL_PWR_GPIO_D
  *         @arg @ref LL_PWR_GPIO_E
  *         @arg @ref LL_PWR_GPIO_F
  * @param  GPIONumber This parameter can be one of the following values:
  *         @arg @ref LL_PWR_GPIO_BIT_0
  *         @arg @ref LL_PWR_GPIO_BIT_1
  *         @arg @ref LL_PWR_GPIO_BIT_2
  *         @arg @ref LL_PWR_GPIO_BIT_3
  *         @arg @ref LL_PWR_GPIO_BIT_4
  *         @arg @ref LL_PWR_GPIO_BIT_5
  *         @arg @ref LL_PWR_GPIO_BIT_6
  *         @arg @ref LL_PWR_GPIO_BIT_7
  *         @arg @ref LL_PWR_GPIO_BIT_8
  *         @arg @ref LL_PWR_GPIO_BIT_9
  *         @arg @ref LL_PWR_GPIO_BIT_10
  *         @arg @ref LL_PWR_GPIO_BIT_11
  *         @arg @ref LL_PWR_GPIO_BIT_12
  *         @arg @ref LL_PWR_GPIO_BIT_13
  *         @arg @ref LL_PWR_GPIO_BIT_14
  *         @arg @ref LL_PWR_GPIO_BIT_15
  * @retval None
  */
__STATIC_INLINE void LL_PWR_EnableGPIOPullUp(uint32_t GPIO, uint32_t GPIONumber)
{
  SET_BIT(*((__IO uint32_t *)GPIO), GPIONumber);
}

/**
  * @brief  Disable GPIO pull-up state in Standby and Shutdown modes
  * @rmtoll PUCRA        PU0-15        LL_PWR_DisableGPIOPullUp\n
  *         PUCRB        PU0-15        LL_PWR_EnableGPIOPullUp\n
  *         PUCRC        PU0-15        LL_PWR_EnableGPIOPullUp\n
  *         PUCRD        PU0-13        LL_PWR_EnableGPIOPullUp\n
  *         PUCRE        PU3,PU7-9     LL_PWR_EnableGPIOPullUp\n
  *         PUCRF        PU0-3         LL_PWR_EnableGPIOPullUp\n
  * @param  GPIO This parameter can be one of the following values:
  *         @arg @ref LL_PWR_GPIO_A
  *         @arg @ref LL_PWR_GPIO_B
  *         @arg @ref LL_PWR_GPIO_C
  *         @arg @ref LL_PWR_GPIO_D
  *         @arg @ref LL_PWR_GPIO_E
  *         @arg @ref LL_PWR_GPIO_F
  * @param  GPIONumber This parameter can be one of the following values:
  *         @arg @ref LL_PWR_GPIO_BIT_0
  *         @arg @ref LL_PWR_GPIO_BIT_1
  *         @arg @ref LL_PWR_GPIO_BIT_2
  *         @arg @ref LL_PWR_GPIO_BIT_3
  *         @arg @ref LL_PWR_GPIO_BIT_4
  *         @arg @ref LL_PWR_GPIO_BIT_5
  *         @arg @ref LL_PWR_GPIO_BIT_6
  *         @arg @ref LL_PWR_GPIO_BIT_7
  *         @arg @ref LL_PWR_GPIO_BIT_8
  *         @arg @ref LL_PWR_GPIO_BIT_9
  *         @arg @ref LL_PWR_GPIO_BIT_10
  *         @arg @ref LL_PWR_GPIO_BIT_11
  *         @arg @ref LL_PWR_GPIO_BIT_12
  *         @arg @ref LL_PWR_GPIO_BIT_13
  *         @arg @ref LL_PWR_GPIO_BIT_14
  *         @arg @ref LL_PWR_GPIO_BIT_15
  * @retval None
  */
__STATIC_INLINE void LL_PWR_DisableGPIOPullUp(uint32_t GPIO, uint32_t GPIONumber)
{
  CLEAR_BIT(*((__IO uint32_t *)GPIO), GPIONumber);
}

/**
  * @brief  Check if GPIO pull-up state is enabled
  * @rmtoll PUCRA        PU0-15        LL_PWR_IsEnabledGPIOPullUp\n
  *         PUCRB        PU0-15        LL_PWR_EnableGPIOPullUp\n
  *         PUCRC        PU0-15        LL_PWR_EnableGPIOPullUp\n
  *         PUCRD        PU0-13        LL_PWR_EnableGPIOPullUp\n
  *         PUCRE        PU3,PU7-9     LL_PWR_EnableGPIOPullUp\n
  *         PUCRF        PU0-3         LL_PWR_EnableGPIOPullUp\n
  * @param  GPIO This parameter can be one of the following values:
  *         @arg @ref LL_PWR_GPIO_A
  *         @arg @ref LL_PWR_GPIO_B
  *         @arg @ref LL_PWR_GPIO_C
  *         @arg @ref LL_PWR_GPIO_D
  *         @arg @ref LL_PWR_GPIO_E
  *         @arg @ref LL_PWR_GPIO_F
  * @param  GPIONumber This parameter can be one of the following values:
  *         @arg @ref LL_PWR_GPIO_BIT_0
  *         @arg @ref LL_PWR_GPIO_BIT_1
  *         @arg @ref LL_PWR_GPIO_BIT_2
  *         @arg @ref LL_PWR_GPIO_BIT_3
  *         @arg @ref LL_PWR_GPIO_BIT_4
  *         @arg @ref LL_PWR_GPIO_BIT_5
  *         @arg @ref LL_PWR_GPIO_BIT_6
  *         @arg @ref LL_PWR_GPIO_BIT_7
  *         @arg @ref LL_PWR_GPIO_BIT_8
  *         @arg @ref LL_PWR_GPIO_BIT_9
  *         @arg @ref LL_PWR_GPIO_BIT_10
  *         @arg @ref LL_PWR_GPIO_BIT_11
  *         @arg @ref LL_PWR_GPIO_BIT_12
  *         @arg @ref LL_PWR_GPIO_BIT_13
  *         @arg @ref LL_PWR_GPIO_BIT_14
  *         @arg @ref LL_PWR_GPIO_BIT_15
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_PWR_IsEnabledGPIOPullUp(uint32_t GPIO, uint32_t GPIONumber)
{
  return ((READ_BIT(*((__IO uint32_t *)GPIO), GPIONumber) == (GPIONumber)) ? 1UL : 0UL);
}

/**
  * @brief  Enable GPIO pull-down state in Standby and Shutdown modes
  * @rmtoll PDCRA        PD0-15        LL_PWR_EnableGPIOPullDown\n
  *         PUCRB        PU0-15        LL_PWR_EnableGPIOPullUp\n
  *         PUCRC        PU0-15        LL_PWR_EnableGPIOPullUp\n
  *         PUCRD        PU0-13        LL_PWR_EnableGPIOPullUp\n
  *         PUCRE        PU3,PU7-9     LL_PWR_EnableGPIOPullUp\n
  *         PUCRF        PU0-3         LL_PWR_EnableGPIOPullUp\n
  * @param  GPIO This parameter can be one of the following values:
  *         @arg @ref LL_PWR_GPIO_A
  *         @arg @ref LL_PWR_GPIO_B
  *         @arg @ref LL_PWR_GPIO_C
  *         @arg @ref LL_PWR_GPIO_D
  *         @arg @ref LL_PWR_GPIO_E
  *         @arg @ref LL_PWR_GPIO_F
  * @param  GPIONumber This parameter can be one of the following values:
  *         @arg @ref LL_PWR_GPIO_BIT_0
  *         @arg @ref LL_PWR_GPIO_BIT_1
  *         @arg @ref LL_PWR_GPIO_BIT_2
  *         @arg @ref LL_PWR_GPIO_BIT_3
  *         @arg @ref LL_PWR_GPIO_BIT_4
  *         @arg @ref LL_PWR_GPIO_BIT_5
  *         @arg @ref LL_PWR_GPIO_BIT_6
  *         @arg @ref LL_PWR_GPIO_BIT_7
  *         @arg @ref LL_PWR_GPIO_BIT_8
  *         @arg @ref LL_PWR_GPIO_BIT_9
  *         @arg @ref LL_PWR_GPIO_BIT_10
  *         @arg @ref LL_PWR_GPIO_BIT_11
  *         @arg @ref LL_PWR_GPIO_BIT_12
  *         @arg @ref LL_PWR_GPIO_BIT_13
  *         @arg @ref LL_PWR_GPIO_BIT_14
  *         @arg @ref LL_PWR_GPIO_BIT_15
  * @retval None
  */
__STATIC_INLINE void LL_PWR_EnableGPIOPullDown(uint32_t GPIO, uint32_t GPIONumber)
{
  SET_BIT(*((__IO uint32_t *)(GPIO + 4U)), GPIONumber);
}

/**
  * @brief  Disable GPIO pull-down state in Standby and Shutdown modes
  * @rmtoll PDCRA        PD0-15        LL_PWR_DisableGPIOPullDown\n
  *         PUCRB        PU0-15        LL_PWR_EnableGPIOPullUp\n
  *         PUCRC        PU0-15        LL_PWR_EnableGPIOPullUp\n
  *         PUCRD        PU0-13        LL_PWR_EnableGPIOPullUp\n
  *         PUCRE        PU3,PU7-9     LL_PWR_EnableGPIOPullUp\n
  *         PUCRF        PU0-3         LL_PWR_EnableGPIOPullUp\n
  * @param  GPIO This parameter can be one of the following values:
  *         @arg @ref LL_PWR_GPIO_A
  *         @arg @ref LL_PWR_GPIO_B
  *         @arg @ref LL_PWR_GPIO_C
  *         @arg @ref LL_PWR_GPIO_D
  *         @arg @ref LL_PWR_GPIO_E
  *         @arg @ref LL_PWR_GPIO_F
  * @param  GPIONumber This parameter can be one of the following values:
  *         @arg @ref LL_PWR_GPIO_BIT_0
  *         @arg @ref LL_PWR_GPIO_BIT_1
  *         @arg @ref LL_PWR_GPIO_BIT_2
  *         @arg @ref LL_PWR_GPIO_BIT_3
  *         @arg @ref LL_PWR_GPIO_BIT_4
  *         @arg @ref LL_PWR_GPIO_BIT_5
  *         @arg @ref LL_PWR_GPIO_BIT_6
  *         @arg @ref LL_PWR_GPIO_BIT_7
  *         @arg @ref LL_PWR_GPIO_BIT_8
  *         @arg @ref LL_PWR_GPIO_BIT_9
  *         @arg @ref LL_PWR_GPIO_BIT_10
  *         @arg @ref LL_PWR_GPIO_BIT_11
  *         @arg @ref LL_PWR_GPIO_BIT_12
  *         @arg @ref LL_PWR_GPIO_BIT_13
  *         @arg @ref LL_PWR_GPIO_BIT_14
  *         @arg @ref LL_PWR_GPIO_BIT_15
  * @retval None
  */
__STATIC_INLINE void LL_PWR_DisableGPIOPullDown(uint32_t GPIO, uint32_t GPIONumber)
{
  CLEAR_BIT(*((__IO uint32_t *)(GPIO + 4U)), GPIONumber);
}

/**
  * @brief  Check if GPIO pull-down state is enabled
  * @rmtoll PDCRA        PD0-15        LL_PWR_IsEnabledGPIOPullDown\n
  *         PUCRB        PU0-15        LL_PWR_EnableGPIOPullUp\n
  *         PUCRC        PU0-15        LL_PWR_EnableGPIOPullUp\n
  *         PUCRD        PU0-13        LL_PWR_EnableGPIOPullUp\n
  *         PUCRE        PU3,PU7-9     LL_PWR_EnableGPIOPullUp\n
  *         PUCRF        PU0-3         LL_PWR_EnableGPIOPullUp\n
  * @param  GPIO This parameter can be one of the following values:
  *         @arg @ref LL_PWR_GPIO_A
  *         @arg @ref LL_PWR_GPIO_B
  *         @arg @ref LL_PWR_GPIO_C
  *         @arg @ref LL_PWR_GPIO_D
  *         @arg @ref LL_PWR_GPIO_E
  *         @arg @ref LL_PWR_GPIO_F
  * @param  GPIONumber This parameter can be one of the following values:
  *         @arg @ref LL_PWR_GPIO_BIT_0
  *         @arg @ref LL_PWR_GPIO_BIT_1
  *         @arg @ref LL_PWR_GPIO_BIT_2
  *         @arg @ref LL_PWR_GPIO_BIT_3
  *         @arg @ref LL_PWR_GPIO_BIT_4
  *         @arg @ref LL_PWR_GPIO_BIT_5
  *         @arg @ref LL_PWR_GPIO_BIT_6
  *         @arg @ref LL_PWR_GPIO_BIT_7
  *         @arg @ref LL_PWR_GPIO_BIT_8
  *         @arg @ref LL_PWR_GPIO_BIT_9
  *         @arg @ref LL_PWR_GPIO_BIT_10
  *         @arg @ref LL_PWR_GPIO_BIT_11
  *         @arg @ref LL_PWR_GPIO_BIT_12
  *         @arg @ref LL_PWR_GPIO_BIT_13
  *         @arg @ref LL_PWR_GPIO_BIT_14
  *         @arg @ref LL_PWR_GPIO_BIT_15
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_PWR_IsEnabledGPIOPullDown(uint32_t GPIO, uint32_t GPIONumber)
{
  return ((READ_BIT(*((__IO uint32_t *)(GPIO + 4U)), GPIONumber) == (GPIONumber)) ? 1UL : 0UL);
}
/**
  * @}
  */

/** @defgroup PWR_LL_EF_FLAG_Management FLAG_Management
  * @{
  */

/**
  * @brief  Get Wake-up Flag 1
  * @rmtoll SR1          WUF1          LL_PWR_IsActiveFlag_WU1
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_PWR_IsActiveFlag_WU1(void)
{
  return ((READ_BIT(PWR->SR1, PWR_SR1_WUF1) == (PWR_SR1_WUF1)) ? 1UL : 0UL);
}

/**
  * @brief  Get Wake-up Flag 2
  * @rmtoll SR1          WUF2          LL_PWR_IsActiveFlag_WU2
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_PWR_IsActiveFlag_WU2(void)
{
  return ((READ_BIT(PWR->SR1, PWR_SR1_WUF2) == (PWR_SR1_WUF2)) ? 1UL : 0UL);
}

/**
  * @brief  Get Wake-up Flag 3
  * @rmtoll SR1          WUF3          LL_PWR_IsActiveFlag_WU3
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_PWR_IsActiveFlag_WU3(void)
{
  return ((READ_BIT(PWR->SR1, PWR_SR1_WUF3) == (PWR_SR1_WUF3)) ? 1UL : 0UL);
}

/**
  * @brief  Get Wake-up Flag 4
  * @rmtoll SR1          WUF4          LL_PWR_IsActiveFlag_WU4
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_PWR_IsActiveFlag_WU4(void)
{
  return ((READ_BIT(PWR->SR1, PWR_SR1_WUF4) == (PWR_SR1_WUF4)) ? 1UL : 0UL);
}

/**
  * @brief  Get Wake-up Flag 5
  * @rmtoll SR1          WUF5          LL_PWR_IsActiveFlag_WU5
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_PWR_IsActiveFlag_WU5(void)
{
  return ((READ_BIT(PWR->SR1, PWR_SR1_WUF5) == (PWR_SR1_WUF5)) ? 1UL : 0UL);
}

/**
  * @brief  Get Wake-up Flag 7
  * @rmtoll SR1          WUF7          LL_PWR_IsActiveFlag_WU7
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_PWR_IsActiveFlag_WU7(void)
{
  return ((READ_BIT(PWR->SR1, PWR_SR1_WUF7) == (PWR_SR1_WUF7)) ? 1UL : 0UL);
}

/**
  * @brief  Get Stand-By Flag
  * @rmtoll SR1          SBF           LL_PWR_IsActiveFlag_SB
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_PWR_IsActiveFlag_SB(void)
{
  return ((READ_BIT(PWR->SR1, PWR_SR1_SBF) == (PWR_SR1_SBF)) ? 1UL : 0UL);
}

/**
  * @brief  Get Stop Flag
  * @rmtoll SR1          STOPF 0          LL_PWR_IsActiveFlag_Stop
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_PWR_IsActiveFlag_Stop0(void)
{
  return ((READ_BIT(PWR->SR1, LL_PWR_SR1_STOP0) == (LL_PWR_SR1_STOP0)) ? 1UL : 0UL);
}

/**
  * @brief  Get Stop Flag
  * @rmtoll SR1          STOPF 1         LL_PWR_IsActiveFlag_Stop
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_PWR_IsActiveFlag_Stop1(void)
{
  return ((READ_BIT(PWR->SR1, LL_PWR_SR1_STOP1) == (LL_PWR_SR1_STOP1)) ? 1UL : 0UL);
}
/**
  * @brief  Get Stop Flag
  * @rmtoll SR1          STOPF 2          LL_PWR_IsActiveFlag_Stop
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_PWR_IsActiveFlag_Stop2(void)
{
  return ((READ_BIT(PWR->SR1, LL_PWR_SR1_STOP2) == (LL_PWR_SR1_STOP2)) ? 1UL : 0UL);
}

/**
  * @brief  Get Internal Wake-up line Flag
  * @rmtoll SR1          WUFI          LL_PWR_IsActiveFlag_InternWU
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_PWR_IsActiveFlag_InternWU(void)
{
  return ((READ_BIT(PWR->SR1, PWR_SR1_WUFI) == (PWR_SR1_WUFI)) ? 1UL : 0UL);
}

/**
  * @brief  Indicate whether or not the flash is ready
  * @rmtoll SR2          FLASH_RDY        LL_PWR_IsActiveFlag_FLASH_RDY
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_PWR_IsActiveFlag_FLASH_RDY(void)
{
  return ((READ_BIT(PWR->SR2, PWR_SR2_FLASH_RDY) == (PWR_SR2_FLASH_RDY)) ? 1UL : 0UL);
}

/**
  * @brief  Indicate whether or not the low-power regulator is ready
  * @rmtoll SR2          REGLPS        LL_PWR_IsActiveFlag_REGLPS
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_PWR_IsActiveFlag_REGLPS(void)
{
  return ((READ_BIT(PWR->SR2, PWR_SR2_REGLPS) == (PWR_SR2_REGLPS)) ? 1UL : 0UL);
}

/**
  * @brief  Indicate whether the regulator is ready in main mode or is in low-power mode
  * @note   Take care, return value "0" means the regulator is ready. Return value "1" means the output voltage range is still changing.
  * @rmtoll SR2          REGLPF        LL_PWR_IsActiveFlag_REGLPF
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_PWR_IsActiveFlag_REGLPF(void)
{
  return ((READ_BIT(PWR->SR2, PWR_SR2_REGLPF) == (PWR_SR2_REGLPF)) ? 1UL : 0UL);
}

/**
  * @brief  Indicate whether the regulator is ready in the selected voltage range or if its output voltage is still changing to the required voltage level
  * @rmtoll SR2          VOSF          LL_PWR_IsActiveFlag_VOS
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_PWR_IsActiveFlag_VOS(void)
{
  return ((READ_BIT(PWR->SR2, PWR_SR2_VOSF) == (PWR_SR2_VOSF)) ? 1UL : 0UL);
}

/**
  * @brief  Indicate whether VDD voltage is below or above the selected PVD threshold
  * @rmtoll SR2          PVDO          LL_PWR_IsActiveFlag_PVDO
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_PWR_IsActiveFlag_PVDO(void)
{
  return ((READ_BIT(PWR->SR2, PWR_SR2_PVDO) == (PWR_SR2_PVDO)) ? 1UL : 0UL);
}

/**
  * @brief  Indicate whether VDDUSB voltage is below or above PVMO1 threshold
  * @rmtoll SR2          PVMO1         LL_PWR_IsActiveFlag_PVMO_1
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_PWR_IsActiveFlag_PVMO_1(void)
{
  return ((READ_BIT(PWR->SR2, PWR_SR2_PVMO1) == (PWR_SR2_PVMO1)) ? 1UL : 0UL);
}

/**
  * @brief  Indicate whether VDDA ADC voltage is below or above PVMO3 threshold
  * @rmtoll SR2          PVMO3         LL_PWR_IsActiveFlag_PVMO_3
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_PWR_IsActiveFlag_PVMO_3(void)
{
  return ((READ_BIT(PWR->SR2, PWR_SR2_PVMO3) == (PWR_SR2_PVMO3)) ? 1UL : 0UL);
}

/**
  * @brief  Indicate whether VDDA voltage is below or above PVMO4 threshold
  * @rmtoll SR2          PVMO4         LL_PWR_IsActiveFlag_PVMO_4
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_PWR_IsActiveFlag_PVMO_4(void)
{
  return ((READ_BIT(PWR->SR2, PWR_SR2_PVMO4) == (PWR_SR2_PVMO4)) ? 1UL : 0UL);
}

/**
  * @brief  Clear Wake-up Flag 1
  * @rmtoll SCR          CWUF1         LL_PWR_ClearFlag_WU1
  * @retval None
  */
__STATIC_INLINE void LL_PWR_ClearFlag_WU1(void)
{
  WRITE_REG(PWR->SCR, PWR_SCR_CWUF1);
}

/**
  * @brief  Clear Wake-up Flag 2
  * @rmtoll SCR          CWUF2         LL_PWR_ClearFlag_WU2
  * @retval None
  */
__STATIC_INLINE void LL_PWR_ClearFlag_WU2(void)
{
  WRITE_REG(PWR->SCR, PWR_SCR_CWUF2);
}

/**
  * @brief  Clear Wake-up Flag 3
  * @rmtoll SCR          CWUF3         LL_PWR_ClearFlag_WU3
  * @retval None
  */
__STATIC_INLINE void LL_PWR_ClearFlag_WU3(void)
{
  WRITE_REG(PWR->SCR, PWR_SCR_CWUF3);
}

/**
  * @brief  Clear Wake-up Flag 4
  * @rmtoll SCR          CWUF4         LL_PWR_ClearFlag_WU4
  * @retval None
  */
__STATIC_INLINE void LL_PWR_ClearFlag_WU4(void)
{
  WRITE_REG(PWR->SCR, PWR_SCR_CWUF4);
}

/**
  * @brief  Clear Wake-up Flag 5
  * @rmtoll SCR          CWUF5         LL_PWR_ClearFlag_WU5
  * @retval None
  */
__STATIC_INLINE void LL_PWR_ClearFlag_WU5(void)
{
  WRITE_REG(PWR->SCR, PWR_SCR_CWUF5);
}

/**
  * @brief  Clear Wake-up Flag 7
  * @rmtoll SCR          CWUF7         LL_PWR_ClearFlag_WU7
  * @retval None
  */
__STATIC_INLINE void LL_PWR_ClearFlag_WU7(void)
{
  WRITE_REG(PWR->SCR, PWR_SCR_CWUF7);
}

/**
  * @brief  Clear standby and stop Flags
  * @rmtoll SCR          CSBF          LL_PWR_ClearFlag_CSB
  * @retval None
  */
__STATIC_INLINE void LL_PWR_ClearFlag_CSB(void)
{
  WRITE_REG(PWR->SCR, PWR_SCR_CSBF);
}
/**
  * @}
  */

/**
  * @}
  */
#if defined(USE_FULL_LL_DRIVER)
/** @defgroup PWR_LL_EF_Init De-initialization function
  * @{
  */
ErrorStatus LL_PWR_DeInit(void);
/**
  * @}
  */
#endif /* USE_FULL_LL_DRIVER */

/** @defgroup PWR_LL_EF_Legacy_Functions Legacy functions name
  * @{
  */
/* Old functions name kept for legacy purpose, to be replaced by the          */
/* current functions name.                                                    */
#define LL_PWR_IsActiveFlag_VOSF  LL_PWR_IsActiveFlag_VOS
/**
  * @}
  */

/**
  * @}
  */

/**
  * @}
  */

#endif /* defined(PWR) */

/**
  * @}
  */

#ifdef __cplusplus
}
#endif

#endif /* STM32U0xx_LL_PWR_H */