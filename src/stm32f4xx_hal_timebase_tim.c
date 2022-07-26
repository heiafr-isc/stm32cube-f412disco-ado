/* USER CODE BEGIN Header */
/**
 ******************************************************************************
 * @file    stm32f4xx_hal_timebase_TIM.c
 * @brief   HAL time base based on the hardware TIM.
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

#include "stm32f4xx_hal.h"
#include "stm32f4xx_hal_tim.h"

// Period elapsed callback in non blocking mode
// This function is called  when TIM6 interrupt took place, inside
// HAL_TIM_IRQHandler(). It makes a direct call to HAL_IncTick() to increment
// a global variable "uwTick" used as application time base.
static void period_elapsed_callback(TIM_HandleTypeDef* htim) { HAL_IncTick(); }

TIM_HandleTypeDef htim6;

/**
 * @brief  This function configures the TIM6 as a time base source.
 *         The time source is configured  to have 1ms time base with a dedicated
 *         Tick interrupt priority.
 * @note   This function is called  automatically at the beginning of program after
 *         reset by HAL_Init() or at any time when clock is configured, by HAL_RCC_ClockConfig().
 * @param  TickPriority: Tick interrupt priority.
 * @retval HAL status
 */
// cppcheck-suppress unusedFunction
HAL_StatusTypeDef HAL_InitTick(uint32_t TickPriority) {
    RCC_ClkInitTypeDef clkconfig;
    uint32_t uwTimclock, uwAPB1Prescaler = 0U;

    uint32_t uwPrescalerValue = 0U;
    uint32_t pFLatency;
    HAL_StatusTypeDef status;

    /* Enable TIM6 clock */
    __HAL_RCC_TIM6_CLK_ENABLE();

    /* Get clock configuration */
    HAL_RCC_GetClockConfig(&clkconfig, &pFLatency);

    /* Get APB1 prescaler */
    uwAPB1Prescaler = clkconfig.APB1CLKDivider;
    /* Compute TIM6 clock */
    if (uwAPB1Prescaler == RCC_HCLK_DIV1) {
        uwTimclock = HAL_RCC_GetPCLK1Freq();
    } else {
        uwTimclock = 2UL * HAL_RCC_GetPCLK1Freq();
    }

    /* Compute the prescaler value to have TIM6 counter clock equal to 1MHz */
    uwPrescalerValue = (uint32_t)((uwTimclock / 1000000U) - 1U);

    /* Initialize TIM6 */
    htim6.Instance = TIM6;

    /* Initialize TIMx peripheral as follow:
    + Period = [(TIM6CLK/1000) - 1]. to have a (1/1000) s time base.
    + Prescaler = (uwTimclock/1000000 - 1) to have a 1MHz counter clock.
    + ClockDivision = 0
    + Counter direction = Up
    */
    htim6.Init.Period            = (1000000U / 1000U) - 1U;
    htim6.Init.Prescaler         = uwPrescalerValue;
    htim6.Init.ClockDivision     = 0;
    htim6.Init.CounterMode       = TIM_COUNTERMODE_UP;
    htim6.Init.AutoReloadPreload = TIM_AUTORELOAD_PRELOAD_DISABLE;

    status = HAL_TIM_Base_Init(&htim6);
    if (status != HAL_OK) {
        return status;
    }
    status =
        HAL_TIM_RegisterCallback(&htim6, HAL_TIM_PERIOD_ELAPSED_CB_ID, period_elapsed_callback);
    if (status != HAL_OK) {
        return status;
    }
    /* Start the TIM time Base generation in interrupt mode */
    status = HAL_TIM_Base_Start_IT(&htim6);
    if (status != HAL_OK) {
        return status;
    }
    /* Enable the TIM6 global Interrupt */
    HAL_NVIC_EnableIRQ(TIM6_IRQn);
    /* Configure the SysTick IRQ priority */
    if (TickPriority < (1UL << __NVIC_PRIO_BITS)) {
        /* Configure the TIM IRQ priority */
        HAL_NVIC_SetPriority(TIM6_IRQn, TickPriority, 0U);
        uwTickPrio = TickPriority;
    } else {
        status = HAL_ERROR;
    }

    return status;
}

/**
 * @brief  Suspend Tick increment.
 * @note   Disable the tick increment by disabling TIM6 update interrupt.
 * @param  None
 * @retval None
 */
// cppcheck-suppress unusedFunction
void HAL_SuspendTick(void) {
    // Disable TIM6 update Interrupt
    __HAL_TIM_DISABLE_IT(&htim6, TIM_IT_UPDATE);
}

/**
 * @brief  Resume Tick increment.
 * @note   Enable the tick increment by Enabling TIM6 update interrupt.
 * @param  None
 * @retval None
 */
// cppcheck-suppress unusedFunction
void HAL_ResumeTick(void) {
    // Enable TIM6 Update interrupt
    __HAL_TIM_ENABLE_IT(&htim6, TIM_IT_UPDATE);
}
