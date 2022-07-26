/**
 ******************************************************************************
 * @file        : system_clock.h
 * @brief       : Configure System Clock to 100MHz
 * @author      : Jacques Supcik <jacques.supcik@hefr.ch>
 * @date        : 26. July 2022
 ******************************************************************************
 * @copyright   : Copyright (c) 2022 HEIA-FR / ISC
 *                Haute école d'ingénierie et d'architecture de Fribourg
 *                Informatique et Systèmes de Communication
 * @attention   : SPDX-License-Identifier: MIT OR Apache-2.0
 ******************************************************************************
 * @details
 * Configure the system clock to 100MHz using the 8MHz HSE Clock
 ******************************************************************************
 */

#ifndef INCLUDE_SYSTEM_CLOCK_H_
#define INCLUDE_SYSTEM_CLOCK_H_

#ifdef __cplusplus
extern "C" {
#endif

extern void SystemClock_Config();

#ifdef __cplusplus
}
#endif

#endif /* INCLUDE_SYSTEM_CLOCK_H_ */
