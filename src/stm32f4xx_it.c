/* USER CODE BEGIN Header */
/**
 ******************************************************************************
 * @file    stm32f4xx_it.c
 * @brief   Interrupt Service Routines.
 ******************************************************************************
 * @attention
 *
 * Copyright (c) 2022 STMicroelectronics.
 * All rights reserved.
 *
 * This software is licensed under terms that can be found in the LICENSE file
 * in the root directory of this software component.
 * If no LICENSE file comes with this software, it is provided AS-IS.
 *
 ******************************************************************************
 */

#include "stm32f4xx_it.h"

#include "stm32f4xx_hal.h"

extern TIM_HandleTypeDef htim6;

/******************************************************************************/
/*           Cortex-M4 Processor Interruption and Exception Handlers          */
/******************************************************************************/
/**
 * @brief This function handles Non maskable interrupt.
 */
// cppcheck-suppress unusedFunction
void NMI_Handler(void) {
    while (1) {
    }
}

/**
 * @brief This function handles Hard fault interrupt.
 */
// cppcheck-suppress unusedFunction
void HardFault_Handler(void) {
    while (1) {
    }
}

/**
 * @brief This function handles Memory management fault.
 */
// cppcheck-suppress unusedFunction
void MemManage_Handler(void) {
    while (1) {
    }
}

/**
 * @brief This function handles Pre-fetch fault, memory access fault.
 */
// cppcheck-suppress unusedFunction
void BusFault_Handler(void) {
    while (1) {
    }
}

/**
 * @brief This function handles Undefined instruction or illegal state.
 */
// cppcheck-suppress unusedFunction
void UsageFault_Handler(void) {
    while (1) {
    }
}

/**
 * @brief This function handles Debug monitor.
 */
// cppcheck-suppress unusedFunction
void DebugMon_Handler(void) {}

/******************************************************************************/
/* STM32F4xx Peripheral Interrupt Handlers                                    */
/* Add here the Interrupt Handlers for the used peripherals.                  */
/* For the available peripheral interrupt handler names,                      */
/* please refer to the startup file (startup_stm32f4xx.s).                    */
/******************************************************************************/

/**
 * @brief This function handles TIM6 global interrupt.
 */
// cppcheck-suppress unusedFunction
void TIM6_IRQHandler(void) { HAL_TIM_IRQHandler(&htim6); }
