/**
 ******************************************************************************
 * @file        : test_main.c
 * @brief       : Basic tests
 * @author      : Jacques Supcik <jacques.supcik@hefr.ch>
 * @date        : 26. July 2022
 ******************************************************************************
 * @copyright   : Copyright (c) 2022 HEIA-FR / ISC
 *                Haute école d'ingénierie et d'architecture de Fribourg
 *                Informatique et Systèmes de Communication
 * @attention   : SPDX-License-Identifier: MIT OR Apache-2.0
 ******************************************************************************
 * @details
 * Basic tests
 ******************************************************************************
 */

#include "stm32412g_discovery.h"
#include "stm32f4xx_hal.h"
#include "system_clock.h"
#include "unity.h"

void setUp(void) {}

void tearDown(void) {}

void BasicTest() {}

int main(void) {
    HAL_Init();
    SystemClock_Config();
    HAL_Delay(2000);  // Mandatory waiting for 2 seconds...
    UNITY_BEGIN();    // Mandatory call to initialize test framework
    RUN_TEST(BasicTest);
    UNITY_END();  // Mandatory call to finalize test framework

    while (1) {
        asm("nop");
    }
}
