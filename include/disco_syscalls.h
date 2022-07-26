/**
 ******************************************************************************
 * @file        : disco_syscalls.h
 * @brief       : Implementation of I/O syscalls for gcc/newlib
 * @author      : Jacques Supcik <jacques.supcik@hefr.ch>
 * @date        : 26. July 2022
 ******************************************************************************
 * @copyright   : Copyright (c) 2022 HEIA-FR / ISC
 *                Haute école d'ingénierie et d'architecture de Fribourg
 *                Informatique et Systèmes de Communication
 * @attention   : SPDX-License-Identifier: MIT OR Apache-2.0
 ******************************************************************************
 * @details
 * This code implements the syscalls needed by gcc/newlib for input/output. It
 * main purpose is to enable console output using printf.
 ******************************************************************************
 */

#ifndef INCLUDE_DISCO_SYSCALLS_H_
#define INCLUDE_DISCO_SYSCALLS_H_

#ifdef __cplusplus
extern "C" {
#endif

void DiscoSyscallsInit();

#ifdef __cplusplus
}
#endif

#endif /* INCLUDE_DISCO_SYSCALLS_H_ */
