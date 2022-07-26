/**
 ******************************************************************************
 * @file        : error_handler.c
 * @brief       : Error Handler
 * @author      : Jacques Supcik <jacques.supcik@hefr.ch>
 * @date        : 26. July 2022
 ******************************************************************************
 * @copyright   : Copyright (c) 2022 
 *                Haute école d'ingénierie et d'architecture de Fribourg
 * @attention   : SPDX-License-Identifier: MIT OR Apache-2.0
 ******************************************************************************
 * @details
 * This code implements the error handler by blinking the red LED
 ******************************************************************************
 */

#include "error_handler.h"

#include "stm32412g_discovery.h"
#include "stm32f4xx_hal.h"

static void busy_wait(uint64_t n) {
    for (int i = 0; i < n; i++) {
        asm("nop");
    }
}

/**
 * @brief Blinks the Red LED to signa Error
 * @returns None
 */
/**
 * A simple busy wait function.
 *
 * @param delay The number of microseconds to wait.
 *
 * @returns None
 */
void Error_Handler(void) {
    __disable_irq();
    BSP_LED_Init(LED_RED);
    BSP_LED_On(LED_RED);
    while (1) {
        busy_wait(2000000);
        BSP_LED_Toggle(LED_RED);
    }
}
