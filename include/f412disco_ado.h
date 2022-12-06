/**
 ******************************************************************************
 * @file        : f412disco_ado.h
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

#ifndef INCLUDE_F412DISCO_ADO_H_
#define INCLUDE_F412DISCO_ADO_H_

#include "disco_syscalls.h"
#include "stm32412g_discovery.h"
#include "stm32f4xx_hal.h"
#include "system_clock.h"

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief Initialises the board
 * @details
 * This function initialises the board used for the ADO lecture.
 * It does the following:
 *
 * - Initializes the Hardware Abstraction Layer
 * - Initializes the system clock
 * - Initializes the syscalls for printf ant orher IO functions
 * - Initializes the 4 LEDs (green, orange, red and blue)
 *
 * @returns None
 */
void DiscoAdoInit();

#ifdef __cplusplus
}
#endif

#endif /* INCLUDE_F412DISCO_ADO_H_ */
