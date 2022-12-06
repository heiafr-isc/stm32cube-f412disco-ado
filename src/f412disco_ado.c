/**
 ******************************************************************************
 * @file        : f412disco_ado.c
 * @brief       : Main include file for the ADO-STM32f412-Disco board
 * @author      : Jacques Supcik <jacques.supcik@hefr.ch>
 * @date        : 26. July 2022
 ******************************************************************************
 * @copyright   : Copyright (c) 2022 HEIA-FR / ISC
 *                Haute école d'ingénierie et d'architecture de Fribourg
 *                Informatique et Systèmes de Communication
 * @attention   : SPDX-License-Identifier: MIT OR Apache-2.0
 ******************************************************************************
 * @details
 * Main include file for the ADO-STM32f412-Disco board
 ******************************************************************************
 */

/** @addtogroup ADO
 * @{
 */

#include "f412disco_ado.h"

#include "disco_syscalls.h"
#include "stm32412g_discovery.h"
#include "stm32f4xx_hal.h"
#include "system_clock.h"

// cppcheck-suppress unusedFunction
void DiscoAdoInit() {
    HAL_Init();
    SystemClock_Config();
    DiscoSyscallsInit();
    BSP_LED_Init(LED_GREEN);
    BSP_LED_Init(LED_ORANGE);
    BSP_LED_Init(LED_RED);
    BSP_LED_Init(LED_BLUE);
}

/**
 * @}
 */
