/**
 ******************************************************************************
 * @file        : test_main.c
 * @brief       : Basic tests
 * @author      : Jacques Supcik <jacques.supcik@hefr.ch>
 * @date        : 27. July 2022
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

#define LEDn 4
uint16_t led_pins[LEDn] = {
    LED1_PIN,
    LED2_PIN,
    LED3_PIN,
    LED4_PIN,
};

void setUp(void) {
    BSP_LED_Init(LED_GREEN);
    BSP_LED_Init(LED_ORANGE);
    BSP_LED_Init(LED_RED);
    BSP_LED_Init(LED_BLUE);
    BSP_LED_On(LED_BLUE);
}

void tearDown(void) {
    BSP_LED_DeInit(LED_GREEN);
    BSP_LED_DeInit(LED_ORANGE);
    BSP_LED_DeInit(LED_RED);
    BSP_LED_DeInit(LED_BLUE);
}

void test_led_state_high(void) {
    for (int i = 0; i < LEDn; i++) {
        HAL_GPIO_WritePin(LEDx_GPIO_PORT, led_pins[i], GPIO_PIN_SET);
        TEST_ASSERT_EQUAL(HAL_GPIO_ReadPin(LEDx_GPIO_PORT, led_pins[i]), GPIO_PIN_SET);
    }
    HAL_Delay(500);
}

void test_led_state_low(void) {
    for (int i = 0; i < LEDn; i++) {
        HAL_GPIO_WritePin(LEDx_GPIO_PORT, led_pins[i], GPIO_PIN_RESET);
        TEST_ASSERT_EQUAL(HAL_GPIO_ReadPin(LEDx_GPIO_PORT, led_pins[i]), GPIO_PIN_RESET);
    }
    HAL_Delay(500);
}

int main(void) {
    HAL_Init();
    SystemClock_Config();
    HAL_Delay(2000);  // Mandatory waiting for 2 seconds...
    UNITY_BEGIN();    // Mandatory call to initialize test framework
    for (int i = 0; i < 5; i++) {
        RUN_TEST(test_led_state_high);
        RUN_TEST(test_led_state_low);
    }
    UNITY_END();  // Mandatory call to finalize test framework

    while (1) {
        asm("nop");
    }
}
