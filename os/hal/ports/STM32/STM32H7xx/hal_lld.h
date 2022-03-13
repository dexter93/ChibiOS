/*
    ChibiOS - Copyright (C) 2006..2018 Giovanni Di Sirio

    Licensed under the Apache License, Version 2.0 (the "License");
    you may not use this file except in compliance with the License.
    You may obtain a copy of the License at

        http://www.apache.org/licenses/LICENSE-2.0

    Unless required by applicable law or agreed to in writing, software
    distributed under the License is distributed on an "AS IS" BASIS,
    WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
    See the License for the specific language governing permissions and
    limitations under the License.
*/

/**
 * @file    STM32H7xx/hal_lld.h
 * @brief   STM32H7xx HAL subsystem low level driver header.
 *
 * @addtogroup HAL
 * @{
 */

#ifndef HAL_LLD_H
#define HAL_LLD_H

#include "stm32_registry.h"

/*===========================================================================*/
/* Driver constants.                                                         */
/*===========================================================================*/

/**
 * @brief   Requires use of SPIv2 driver model.
 */
#define HAL_LLD_SELECT_SPI_V2           TRUE

/**
 * @brief   Sub-family identifier
 */
#if !defined(STM32H7XX) || defined(__DOXYGEN__)
#define STM32H7XX
#endif

/*===========================================================================*/
/* Driver pre-compile time settings.                                         */
/*===========================================================================*/

/**
 * @name    Configuration options (common)
 * @{
 */
/**
 * @brief   Disables the PWR/RCC initialization in the HAL.
 * @note    All the clock tree constants are calculated but the initialization
 *          is not performed.
 */
#if !defined(STM32_NO_INIT) || defined(__DOXYGEN__)
#define STM32_NO_INIT                       FALSE
#endif

/**
 * @brief   Target code for this HAL configuration.
 * @note    Core 1 is the Cortex-M7, core 2 is the Cortex-M4.
 */
#if !defined(STM32_TARGET_CORE) || defined(__DOXYGEN__)
#define STM32_TARGET_CORE                   1
#endif

/**
 * @brief   MPU region to be used for no-cache RAM area.
 */
#if !defined(STM32_NOCACHE_MPU_REGION) || defined(__DOXYGEN__)
#define STM32_NOCACHE_MPU_REGION            MPU_REGION_6
#endif

/**
 * @brief   Add no-cache attribute to SRAM1 and SRAM2.
 */
#if !defined(STM32_NOCACHE_SRAM1_SRAM2) || defined(__DOXYGEN__)
#define STM32_NOCACHE_SRAM1_SRAM2           FALSE
#endif

/**
 * @brief   Add no-cache attribute to SRAM3.
 */
#if !defined(STM32_NOCACHE_SRAM3) || defined(__DOXYGEN__)
#define STM32_NOCACHE_SRAM3                 FALSE
#endif
/** @} */

/*===========================================================================*/
/* Derived constants and error checks.                                       */
/*===========================================================================*/

/*===========================================================================*/
/* Driver data structures and types.                                         */
/*===========================================================================*/

/*===========================================================================*/
/* Driver macros.                                                            */
/*===========================================================================*/

/*===========================================================================*/
/* External declarations.                                                    */
/*===========================================================================*/

#if defined(STM32H723xx) || defined(STM32H733xx) ||                         \
    defined(STM32H725xx) || defined(STM32H735xx) ||                         \
    defined(__DOXYGEN__)
#include "hal_lld_type2.h"
#else
#include "hal_lld_type1.h"
#endif

/* Various helpers.*/
#include "nvic.h"
#include "cache.h"
#include "mpu_v7m.h"
#include "stm32_isr.h"
#include "stm32_mdma.h"
#include "stm32_dma.h"
#include "stm32_bdma.h"
#include "stm32_exti.h"
#include "stm32_rcc.h"
#include "stm32_tim.h"

#ifdef __cplusplus
extern "C" {
#endif
  void hal_lld_init(void);
  void stm32_clock_init(void);
#ifdef __cplusplus
}
#endif

#endif /* HAL_LLD_H */

/** @} */
