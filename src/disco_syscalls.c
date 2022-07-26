/**
 ******************************************************************************
 * @file        : disco_syscalls.c
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

#include "disco_syscalls.h"

#include <errno.h>
#include <sys/stat.h>

#include "stdio.h"
#include "stm32412g_discovery.h"
#include "stm32f4xx_hal.h"

#define STDIN_FILENO 0
#define STDOUT_FILENO 1
#define STDERR_FILENO 2

static UART_HandleTypeDef huart2;

/**
 * @brief Initializes the console (USART2) used for the syscalls
 * @returns None
 */
void Disco_Syscalls_Init() {
    huart2.Instance          = USART2;
    huart2.Init.BaudRate     = 115200;
    huart2.Init.WordLength   = UART_WORDLENGTH_8B;
    huart2.Init.StopBits     = UART_STOPBITS_1;
    huart2.Init.Parity       = UART_PARITY_NONE;
    huart2.Init.Mode         = UART_MODE_TX_RX;
    huart2.Init.HwFlowCtl    = UART_HWCONTROL_NONE;
    huart2.Init.OverSampling = UART_OVERSAMPLING_16;

    // I know it looks weird, but you really have to use COM1 for USART2!
    BSP_COM_Init(COM1, &huart2);

    // Disable I/O buffering for STDOUT stream, so that
    // chars are sent out as soon as they are printed.
    setvbuf(stdout, NULL, _IONBF, 0);
}

int _isatty(int fd) {
    if (fd < STDIN_FILENO || fd > STDERR_FILENO) {
        errno = EBADF;
        return 0;
    }
    return 1;
}

int _write(int fd, char* ptr, int len) {
    if (fd != STDOUT_FILENO && fd != STDERR_FILENO) {
        errno = EBADF;
        return -1;
    }
    uint8_t cr   = '\r';
    uint8_t prev = 0;
    for (int i = 0; i < len; i++) {
        uint8_t ch = (uint8_t)(ptr[i]);
        // Insert a CR before LF if not already sent
        if (ch == '\n' && prev != cr) {
            if (HAL_UART_Transmit(&huart2, &cr, 1, HAL_MAX_DELAY) != HAL_OK) {
                return EIO;
            }
        }
        prev = ch;
        if (HAL_UART_Transmit(&huart2, &ch, 1, HAL_MAX_DELAY) != HAL_OK) {
            return EIO;
        }
    }
    return len;
}

int _close(int fd) {
    if (fd < STDIN_FILENO || fd > STDERR_FILENO) {
        errno = EBADF;
        return -1;
    }
    return 0;
}

int _lseek(int fd, int ptr, int dir) {
    (void)fd;
    (void)ptr;
    (void)dir;

    errno = EBADF;
    return -1;
}

int _read(int fd, char* ptr, int len) {
    if (fd != STDIN_FILENO) {
        errno = EBADF;
        return -1;
    }
    return (HAL_UART_Receive(&huart2, (uint8_t*)ptr, 1, HAL_MAX_DELAY) == HAL_OK) ? 1 : EIO;
}

int _fstat(int fd, struct stat* st) {
    if (fd < STDIN_FILENO || fd > STDERR_FILENO) {
        errno = EBADF;
        return 0;
    }
    st->st_mode = S_IFCHR;
    return 0;
}
