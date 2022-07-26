#include "stm32412g_discovery.h"
#include "stm32f4xx_hal.h"
#include "system_clock.h"

#include "unity.h"

void setUp(void) {
}

void tearDown(void) {
}

void BasicTest() {}

int main(void) {
    HAL_Init();
    SystemClock_Config();
    HAL_Delay(2000);

    UNITY_BEGIN();  // Mandatory call to initialize test framework
    RUN_TEST(BasicTest);
    UNITY_END();  // Mandatory call to finalize test framework

    while (1) {
        asm("nop");
    }
}