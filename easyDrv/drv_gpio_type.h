/**
 * @file:   drv_gpio_type.h
 * @brief:  GPIO管脚类型定义
 * @author: 吉平.「集」
 * @date::  2022-09-11
 */

#ifndef EASY_DRIVER_GPIO_TYPE_H_
#define EASY_DRIVER_GPIO_TYPE_H_

//?------------------------------------------------------------------------------
//? Includes
#include "esp_bit_defs.h"
//?------------------------------------------------------------------------------
//? Definitions
/**
 * @brief: GPIO端口号
 */
typedef enum {
    IO_NC = -1,    /*!< Use to signal not connected to S/W */
    IO_0 = 0,     /*!< GPIO0, input and output */
    IO_1 = 1,     /*!< GPIO1, input and output */
    IO_2 = 2,     /*!< GPIO2, input and output */
    IO_3 = 3,     /*!< GPIO3, input and output */
    IO_4 = 4,     /*!< GPIO4, input and output */
    IO_5 = 5,     /*!< GPIO5, input and output */
    IO_6 = 6,     /*!< GPIO6, input and output */
    IO_7 = 7,     /*!< GPIO7, input and output */
    IO_8 = 8,     /*!< GPIO8, input and output */
    IO_9 = 9,     /*!< GPIO9, input and output */
    IO_10 = 10,   /*!< GPIO10, input and output */
    IO_11 = 11,   /*!< GPIO11, input and output */
    IO_12 = 12,   /*!< GPIO12, input and output */
    IO_13 = 13,   /*!< GPIO13, input and output */
    IO_14 = 14,   /*!< GPIO14, input and output */
    IO_15 = 15,   /*!< GPIO15, input and output */
    IO_16 = 16,   /*!< GPIO16, input and output */
    IO_17 = 17,   /*!< GPIO17, input and output */
    IO_18 = 18,   /*!< GPIO18, input and output */
    IO_19 = 19,   /*!< GPIO19, input and output */
    IO_20 = 20,   /*!< GPIO20, input and output */
    IO_21 = 21,   /*!< GPIO21, input and output */
    IO_26 = 26,   /*!< GPIO26, input and output */
    IO_27 = 27,   /*!< GPIO27, input and output */
    IO_28 = 28,   /*!< GPIO28, input and output */
    IO_29 = 29,   /*!< GPIO29, input and output */
    IO_30 = 30,   /*!< GPIO30, input and output */
    IO_31 = 31,   /*!< GPIO31, input and output */
    IO_32 = 32,   /*!< GPIO32, input and output */
    IO_33 = 33,   /*!< GPIO33, input and output */
    IO_34 = 34,   /*!< GPIO34, input and output */
    IO_35 = 35,   /*!< GPIO35, input and output */
    IO_36 = 36,   /*!< GPIO36, input and output */
    IO_37 = 37,   /*!< GPIO37, input and output */
    IO_38 = 38,   /*!< GPIO38, input and output */
    IO_39 = 39,   /*!< GPIO39, input and output */
    IO_40 = 40,   /*!< GPIO40, input and output */
    IO_41 = 41,   /*!< GPIO41, input and output */
    IO_42 = 42,   /*!< GPIO42, input and output */
    IO_43 = 43,   /*!< GPIO43, input and output */
    IO_44 = 44,   /*!< GPIO44, input and output */
    IO_45 = 45,   /*!< GPIO45, input and output */
    IO_46 = 46,   /*!< GPIO46, input and output */
    IO_47 = 47,   /*!< GPIO47, input and output */
    IO_48 = 48,   /*!< GPIO48, input and output */
    IO_MAX,
/** @endcond */
} en_gpio_num_t;

/**
 * @brief: GPIO模式
 */
/** @cond */
#define MACR_GPIO_MODE_DISABLE         (0)
#define MACR_GPIO_MODE_INPUT           (BIT0)    ///< bit mask for input
#define MACR_GPIO_MODE_OUTPUT          (BIT1)    ///< bit mask for output
#define MACR_GPIO_MODE_OD              (BIT2)    ///< bit mask for OD mode
/** @endcond */
typedef enum
{
    IO_MODE_DISABLE = MACR_GPIO_MODE_DISABLE,                                                           //< 关闭输入输出
    IO_MODE_INPUT = MACR_GPIO_MODE_INPUT,                                                               //< 输入模式
    IO_MODE_OUTPUT = MACR_GPIO_MODE_OUTPUT,                                                             //< 输出模式（推挽）
    IO_MODE_OUTPUT_OD = ((MACR_GPIO_MODE_OUTPUT) | (MACR_GPIO_MODE_OD)),                                //< 输出模式（开漏）
    IO_MODE_INPUT_OUTPUT_OD = ((MACR_GPIO_MODE_INPUT) | (MACR_GPIO_MODE_OUTPUT) | (MACR_GPIO_MODE_OD)), //< 输入输出模式（开漏）
    IO_MODE_INPUT_OUTPUT = ((MACR_GPIO_MODE_INPUT) | (MACR_GPIO_MODE_OUTPUT)),                          //< 输入输出模式（推挽）
} en_gpio_mode_t;

//?------------------------------------------------------------------------------
//? Function declarations

#endif

//?------------------------------------------------------------------------------
//? End of file
