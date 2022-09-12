/**
 * @file:   gpio.c
 * @brief:  GPIO相关功能接口实现
 * @author: 吉平.「集」
 * @date::  2022-09-11
 */
//?------------------------------------------------------------------------------
//? Includes
#include "hal/gpio_hal.h"
#include "drv_gpio.h"
#include "driver/gpio.h"
//?------------------------------------------------------------------------------
//? Definitions

// Get GPIO hardware instance with giving gpio num
#define DRV_GPIO_GET_HW(num) GPIO_LL_GET_HW(num)
#define MACR_IO_PORT_0 (0)
typedef struct {
    gpio_dev_t *dev;
    uint32_t version;
} stc_gpio_context_t;
stc_gpio_context_t _gpio_hw = {
    .dev = DRV_GPIO_GET_HW(MACR_IO_PORT_0)
};
stc_gpio_context_t *gpio_hw = &_gpio_hw;

//?------------------------------------------------------------------------------
//? Function declarations

//?------------------------------------------------------------------------------
//? Global variables

//?------------------------------------------------------------------------------
//? Functions

/**
 * @brief:   设置IO管脚电平
 * @param:   - ioNum: IO管脚编号
 *           - level: 设置电平 | 1: 高电平 | 0: 低电平
 * @return:  none
 * @example: drv_gpio_set_level(io16.ioNum, 1); // 设置IO16为高电平
 * @author:  吉平.「集」
 * @date:    2022-09-12
 */
void drv_gpio_set_level(en_gpio_num_t ioNum, uint32_t level)
{
    gpio_hal_set_level(gpio_hw, ioNum, level);
}

/**
 * @brief:   获取IO电平
 * @param:   ioNum: IO管脚编号
 * @return:  1: 高电平 | 0: 低电平
 * @example: level = drv_gpio_get_level(io16.ioNum); // 获取IO16电平
 * @author:  吉平.「集」
 * @date:    2022-09-12
 */
int drv_gpio_get_level(en_gpio_num_t ioNum)
{
    return gpio_hal_get_level(gpio_hw, ioNum);
}

/**
 * @brief:   GPIO初始化
 * @param:   config: GPIO配置结构体
 * @return:  none
 * @example: drv_gpio_init(&io16); // 初始化IO16
 * @author:  吉平.「集」
 * @date:    2022-09-12
 */
void drv_gpio_init(stc_gpio_config_t * const config)
{
    // 设置端口输入
    if(config->mode & MACR_GPIO_MODE_INPUT)
    {
        gpio_hal_input_enable(gpio_hw, config->ioNum);
    }
    else
    {
        gpio_hal_input_disable(gpio_hw, config->ioNum);
    }
    // 设置端口输出
    if(config->mode & MACR_GPIO_MODE_OUTPUT)
    {
        gpio_hal_output_enable(gpio_hw, config->ioNum);
    }
    else
    {
        gpio_hal_output_disable(gpio_hw, config->ioNum);
    }
    // 设置端口输出模式
    if(config->mode & MACR_GPIO_MODE_OD)
    {
        gpio_hal_od_enable(gpio_hw, config->ioNum);
    }
    else
    {
        gpio_hal_od_disable(gpio_hw, config->ioNum);
    }
    
}
//?------------------------------------------------------------------------------
//? End of file
