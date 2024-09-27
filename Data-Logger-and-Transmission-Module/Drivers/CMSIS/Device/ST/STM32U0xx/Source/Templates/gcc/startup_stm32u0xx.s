/**
 ******************************************************************************
 * @file      startup_stm32u08cxx.s
 * @author    Auto-generated by STM32CubeIDE
 * @brief     STM32U083xx device vector table for GCC toolchain.
 *            This module performs:
 *                - Set the initial SP
 *                - Set the initial PC == Reset_Handler,
 *                - Set the vector table entries with the exceptions ISR address
 *                - Branches to main in the C library (which eventually
 *                  calls main()).
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

.syntax unified
.cpu cortex-m0plus
.fpu softvfp
.thumb

.global g_pfnVectors
.global Default_Handler

/* start address for the initialization values of the .data section.
defined in linker script */
.word _sidata
/* start address for the .data section. defined in linker script */
.word _sdata
/* end address for the .data section. defined in linker script */
.word _edata
/* start address for the .bss section. defined in linker script */
.word _sbss
/* end address for the .bss section. defined in linker script */
.word _ebss

/**
 * @brief  This is the code that gets called when the processor first
 *          starts execution following a reset event. Only the absolutely
 *          necessary set is performed, after which the application
 *          supplied main() routine is called.
 * @param  None
 * @retval : None
*/

  .section .text.Reset_Handler
  .weak Reset_Handler
  .type Reset_Handler, %function
Reset_Handler:
  ldr   r0, =_estack
  mov   sp, r0          /* set stack pointer */
/* Call the clock system initialization function.*/
  bl  SystemInit

/* Copy the data segment initializers from flash to SRAM */
  ldr r0, =_sdata
  ldr r1, =_edata
  ldr r2, =_sidata
  movs r3, #0
  b LoopCopyDataInit

CopyDataInit:
  ldr r4, [r2, r3]
  str r4, [r0, r3]
  adds r3, r3, #4

LoopCopyDataInit:
  adds r4, r0, r3
  cmp r4, r1
  bcc CopyDataInit

/* Zero fill the bss segment. */
  ldr r2, =_sbss
  ldr r4, =_ebss
  movs r3, #0
  b LoopFillZerobss

FillZerobss:
  str  r3, [r2]
  adds r2, r2, #4

LoopFillZerobss:
  cmp r2, r4
  bcc FillZerobss

/* Call static constructors */
  bl __libc_init_array
/* Call the application's entry point.*/
  bl main

LoopForever:
  b LoopForever

  .size Reset_Handler, .-Reset_Handler

/**
 * @brief  This is the code that gets called when the processor receives an
 *         unexpected interrupt.  This simply enters an infinite loop, preserving
 *         the system state for examination by a debugger.
 *
 * @param  None
 * @retval : None
*/
  .section .text.Default_Handler,"ax",%progbits
Default_Handler:
Infinite_Loop:
  b Infinite_Loop
  .size Default_Handler, .-Default_Handler

/******************************************************************************
*
* The STM32U083RCxx vector table.  Note that the proper constructs
* must be placed on this to ensure that it ends up at physical address
* 0x0000.0000.
*
******************************************************************************/
  .section .isr_vector,"a",%progbits
  .type g_pfnVectors, %object
  .size g_pfnVectors, .-g_pfnVectors

g_pfnVectors:
  .word _estack
  .word Reset_Handler
  .word NMI_Handler
  .word HardFault_Handler
  .word	0
  .word	0
  .word	0
  .word	0
  .word	0
  .word	0
  .word	0
  .word	SVC_Handler
  .word	0
  .word	0
  .word	PendSV_Handler
  .word	SysTick_Handler
  .word	WWDG_IRQHandler               /* Window watchdog interrupt                                                       */
  .word	PVD_PVM_IRQHandler            /* PVD/PVM1/PVM2/PVM3 interrupt (combined with EXTI lines 16 and 19 and 20 and 21) */
  .word	RTC_TAMP_IRQHandler           /* RTC and TAMP interrupts(combined EXTI lines 19 and 21)                          */
  .word	FLASH_ECC_IRQHandler          /* FLASH global interrupt                                                          */
  .word	RCC_CRS_IRQHandler            /* RCC and CRS global interrupt                                                    */
  .word	EXTI0_1_IRQHandler            /* EXTI lines 0 and 1 interrupt                                                    */
  .word	EXTI2_3_IRQHandler            /* EXTI lines 2 and 3 interrupt                                                    */
  .word	EXTI4_15_IRQHandler           /* EXTI lines 4 to 15 interrupt                                                    */
  .word	USB_IRQHandler                /* USB global interrupt (combined with EXTI line 33)                               */
  .word	DMA1_CHannel1_IRQHandler      /* DMA1 channel 1 interrupt                                                        */
  .word	DMA1_Channel2_3_IRQHandler    /* DMA1 channel 2 and 3 interrupts                                                 */
  .word	DMA1_Ch4_7_DMA2_Ch1_5_DMAMUX_OVR_IRQHandler /* DMA1 channel 4, 5, 6, 7, DMAMUX, DMA2 channel 1, 2, 3, 4, 5 interrupts          */
  .word	ADC_COMP_IRQHandler           /* ADC and COMP interrupts (ADC combined with EXTI lines 17 and 18)                */
  .word	TIM1_BRK_UP_TRG_COM_IRQHandler/* TIM1 break, update, trigger and commutation interrupts                          */
  .word	TIM1_CC_IRQHandler            /* TIM1 Capture Compare interrupt                                                  */
  .word	TIM2_IRQHandler               /* TIM2 global interrupt                                                           */
  .word	TIM3_IRQHandler               /* TIM3 global interrupt                                                           */
  .word	TIM6_DAC_LPTIM1_IRQHandler    /* TIM6, LPTIM1 and DAC global interrupt (combined with EXTI line 29)              */
  .word	TIM7_LPTIM2_IRQHandler        /* TIM7 and LPTIM2 global interrupt (combined with EXTI line 30)                   */
  .word	TIM15_LPTIM3_IRQHandler       /* TIM15 and LPTIM3 global interrupt (combined with EXTI line 29)                  */
  .word	TIM6_IRQHandler               /* TIM16 global interrupt                                                          */
  .word	TSC_IRQHandler                /* TSC global interrupt                                                            */
  .word	LCD_IRQHandler                /* LCD global interrupt (combined with EXTI line 32)                               */
  .word	I2C1_IRQHandler               /* I2C1 global interrupt (combined with EXTI line 23)                              */
  .word	I2C2_3_4_IRQHandler           /* I2C2/3/4 global interrupt                                                       */
  .word	SPI1_IRQHandler               /* SPI1 global interrupt                                                           */
  .word	SPI2_3_IRQHandler             /* SPI2/3 global interrupt                                                         */
  .word	USART1_IRQHandler             /* USART1 global interrupt (combined with EXTI line 25)                            */
  .word	USART2_LPUART2_IRQHandler     /* USART2 and LPUART2 global interrupt (combined with EXTI lines 26 and 35)        */
  .word	USART3_LPUART1_IRQHandler     /* USART3 and LPUART1 global interrupt (combined with EXTI lines 24 and 28)        */
  .word	USART4_LPUART3_IRQHandler     /* USART4 and LPUART3 global interrupt (combined with EXTI lines 20 and 34)        */
  .word	RNG_CRYP_IRQHandler           /* RNG and CRYPTO global interrupts                                                 */

/*******************************************************************************
*
* Provide weak aliases for each Exception handler to the Default_Handler.
* As they are weak aliases, any function with the same name will override
* this definition.
*
*******************************************************************************/

	.weak	NMI_Handler
	.thumb_set NMI_Handler,Default_Handler

	.weak	HardFault_Handler
	.thumb_set HardFault_Handler,Default_Handler

	.weak	SVC_Handler
	.thumb_set SVC_Handler,Default_Handler

	.weak	PendSV_Handler
	.thumb_set PendSV_Handler,Default_Handler

	.weak	SysTick_Handler
	.thumb_set SysTick_Handler,Default_Handler

	.weak	WWDG_IRQHandler
	.thumb_set WWDG_IRQHandler,Default_Handler

	.weak	PVD_PVM_IRQHandler
	.thumb_set PVD_PVM_IRQHandler,Default_Handler

	.weak	RTC_TAMP_IRQHandler
	.thumb_set RTC_TAMP_IRQHandler,Default_Handler

	.weak	FLASH_ECC_IRQHandler
	.thumb_set FLASH_ECC_IRQHandler,Default_Handler

	.weak	RCC_CRS_IRQHandler
	.thumb_set RCC_CRS_IRQHandler,Default_Handler

	.weak	EXTI0_1_IRQHandler
	.thumb_set EXTI0_1_IRQHandler,Default_Handler

	.weak	EXTI2_3_IRQHandler
	.thumb_set EXTI2_3_IRQHandler,Default_Handler

	.weak	EXTI4_15_IRQHandler
	.thumb_set EXTI4_15_IRQHandler,Default_Handler

	.weak	USB_IRQHandler
	.thumb_set USB_IRQHandler,Default_Handler

	.weak	DMA1_CHannel1_IRQHandler
	.thumb_set DMA1_CHannel1_IRQHandler,Default_Handler

	.weak	DMA1_Channel2_3_IRQHandler
	.thumb_set DMA1_Channel2_3_IRQHandler,Default_Handler

	.weak	DMA1_Ch4_7_DMA2_Ch1_5_DMAMUX_OVR_IRQHandler
	.thumb_set DMA1_Ch4_7_DMA2_Ch1_5_DMAMUX_OVR_IRQHandler,Default_Handler

	.weak	ADC_COMP_IRQHandler
	.thumb_set ADC_COMP_IRQHandler,Default_Handler

	.weak	TIM1_BRK_UP_TRG_COM_IRQHandler
	.thumb_set TIM1_BRK_UP_TRG_COM_IRQHandler,Default_Handler

	.weak	TIM1_CC_IRQHandler
	.thumb_set TIM1_CC_IRQHandler,Default_Handler

	.weak	TIM2_IRQHandler
	.thumb_set TIM2_IRQHandler,Default_Handler

	.weak	TIM3_IRQHandler
	.thumb_set TIM3_IRQHandler,Default_Handler

	.weak	TIM6_DAC_LPTIM1_IRQHandler
	.thumb_set TIM6_DAC_LPTIM1_IRQHandler,Default_Handler

	.weak	TIM7_LPTIM2_IRQHandler
	.thumb_set TIM7_LPTIM2_IRQHandler,Default_Handler

	.weak	TIM15_LPTIM3_IRQHandler
	.thumb_set TIM15_LPTIM3_IRQHandler,Default_Handler

	.weak	TIM6_IRQHandler
	.thumb_set TIM6_IRQHandler,Default_Handler

	.weak	TSC_IRQHandler
	.thumb_set TSC_IRQHandler,Default_Handler

	.weak	LCD_IRQHandler
	.thumb_set LCD_IRQHandler,Default_Handler

	.weak	I2C1_IRQHandler
	.thumb_set I2C1_IRQHandler,Default_Handler

	.weak	I2C2_3_4_IRQHandler
	.thumb_set I2C2_3_4_IRQHandler,Default_Handler

	.weak	SPI1_IRQHandler
	.thumb_set SPI1_IRQHandler,Default_Handler

	.weak	SPI2_3_IRQHandler
	.thumb_set SPI2_3_IRQHandler,Default_Handler

	.weak	USART1_IRQHandler
	.thumb_set USART1_IRQHandler,Default_Handler

	.weak	USART2_LPUART2_IRQHandler
	.thumb_set USART2_LPUART2_IRQHandler,Default_Handler

	.weak	USART3_LPUART1_IRQHandler
	.thumb_set USART3_LPUART1_IRQHandler,Default_Handler

	.weak	USART4_LPUART3_IRQHandler
	.thumb_set USART4_LPUART3_IRQHandler,Default_Handler

	.weak	RNG_CRYP_IRQHandler
	.thumb_set RNG_CRYP_IRQHandler,Default_Handler

	.weak	SystemInit

/************************ (C) COPYRIGHT STMicroelectonics *****END OF FILE****/
