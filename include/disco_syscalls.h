/**
 ******************************************************************************
 * @file        : disco_syscalls.h
 * @brief       : Implementation of I/O syscalls for gcc/newlib
 * @author      : Jacques Supcik <jacques.supcik@hefr.ch>
 * @date        : 26. July 2022
 ******************************************************************************
 * @copyright   : Copyright (c) 2022 
 *                Haute école d'ingénierie et d'architecture de Fribourg
 * @attention   : SPDX-License-Identifier: MIT OR Apache-2.0
 ******************************************************************************
 * @details
 * This code implements the syscalls needed by gcc/newlib for input/output. It
 * main purpose is to enable console output using printf.
 ******************************************************************************
 */

#ifndef DISCO_SYSCALLS_H_
#define DISCO_SYSCALLS_H_

void Disco_Syscalls_Init();

#endif /* DISCO_SYSCALLS_H_ */
