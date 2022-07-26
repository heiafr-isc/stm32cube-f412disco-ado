/**
 ******************************************************************************
 * @file        : error_handler.h
 * @brief       : Error Handler
 * @author      : Jacques Supcik <jacques.supcik@hefr.ch>
 * @date        : 26. July 2022
 ******************************************************************************
 * @copyright   : Copyright (c) 2022 HEIA-FR / ISC
 *                Haute école d'ingénierie et d'architecture de Fribourg
 *                Informatique et Systèmes de Communication
 * @attention   : SPDX-License-Identifier: MIT OR Apache-2.0
 ******************************************************************************
 * @details
 * This code implements the error handler by blinking the red LED
 ******************************************************************************
 */

#ifndef INCLUDE_ERROR_HANDLER_H_
#define INCLUDE_ERROR_HANDLER_H_

#ifdef __cplusplus
extern "C" {
#endif

void ErrorHandler(void);

#ifdef __cplusplus
}
#endif

#endif /* INCLUDE_ERROR_HANDLER_H_ */
