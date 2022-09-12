/**
 * @file:   gpio.h
 * @brief:  GPIO相关功能接口
 * @author: 吉平.「集」
 * @date::  2022-09-11
 */

#ifndef EASY_DRIVER_GPIO_H_
#define EASY_DRIVER_GPIO_H_

//?------------------------------------------------------------------------------
//? Includes

#include "drv_gpio_type.h"
#include "hal/gpio_ll.h"

//?------------------------------------------------------------------------------
//? Definitions

typedef struct
{
    en_gpio_num_t ioNum;
    en_gpio_mode_t mode;
    en_gpio_pull_mode_t pullMode;
} stc_gpio_config_t;
//?------------------------------------------------------------------------------
//? Function declarations
void drv_gpio_set_level(en_gpio_num_t ioNum, uint32_t level);
int drv_gpio_get_level(en_gpio_num_t ioNum);
void drv_gpio_init(const stc_gpio_config_t * const config);

#endif

//?------------------------------------------------------------------------------
//? End of file
