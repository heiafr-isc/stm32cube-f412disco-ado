#include "f412disco_ado.h"

#include "disco_syscalls.h"
#include "stm32f4xx_hal.h"
#include "system_clock.h"
#include "stm32412g_discovery.h"

void Disco_ADO_init() {
    HAL_Init();
    SystemClock_Config();
    Disco_Syscalls_Init();
    BSP_LED_Init(LED_GREEN);
    BSP_LED_Init(LED_ORANGE);
    BSP_LED_Init(LED_RED);
    BSP_LED_Init(LED_BLUE);
}