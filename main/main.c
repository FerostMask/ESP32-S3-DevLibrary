#include <stdio.h>
#include <stdbool.h>
#include <unistd.h>

#include "drv_gpio.h"

#include "driver/rmt.h"

void rmt_tx_init(void)
{
    rmt_config_t rmt =
    {
    	.channel = RMT_CHANNEL_0,
		.clk_div = 8,
		.gpio_num = IO_38,
		.mem_block_num = 1,
		.rmt_mode = RMT_MODE_TX,

		.tx_config.carrier_en = false,
		.tx_config.idle_output_en = true,
		.tx_config.idle_level = RMT_IDLE_LEVEL_LOW,
		.tx_config.loop_en = false,
    };

    rmt_config(&rmt);
    rmt_driver_install(RMT_CHANNEL_0, 0, 0);
}

/**
 * @brief:   设置SK6812灯珠颜色
 * @param:   color: 颜色的RGB值
 * @return:  none
 * @example: sk6812_set_color(0xFFFFFF); // 设置灯珠为白色
 * @author:  吉平.「集」
 * @date:    2022-09-17
 */
#define COLOR_ENCODING_GREEN_LSB_INDEX  7
#define COLOR_ENCODING_RED_LSB_INDEX    15
#define COLOR_ENCODING_BLUE_LSB_INDEX   23
void sk6812_set_color(uint32_t color)
{
    uint8_t red = (color >> 16) & 0xFF;
    uint8_t green = (color >> 8) & 0xFF;
    uint8_t blue = color & 0xFF;
    rmt_item32_t color_encoding[] = {
		{{{ 3, 1, 9, 0 }}}, // G7
		{{{ 3, 1, 9, 0 }}}, // G6
		{{{ 3, 1, 9, 0 }}}, // G5
		{{{ 3, 1, 9, 0 }}}, // G4
		{{{ 3, 1, 9, 0 }}}, // G3
		{{{ 3, 1, 9, 0 }}}, // G2
		{{{ 3, 1, 9, 0 }}}, // G1
		{{{ 3, 1, 9, 0 }}}, // G0
		{{{ 3, 1, 9, 0 }}}, // R7
		{{{ 3, 1, 9, 0 }}}, // R6
		{{{ 3, 1, 9, 0 }}}, // R5
		{{{ 3, 1, 9, 0 }}}, // R4
		{{{ 3, 1, 9, 0 }}}, // R3
		{{{ 3, 1, 9, 0 }}}, // R2
		{{{ 3, 1, 9, 0 }}}, // R1
		{{{ 3, 1, 9, 0 }}}, // R0
		{{{ 3, 1, 9, 0 }}}, // B7
		{{{ 3, 1, 9, 0 }}}, // B6
		{{{ 3, 1, 9, 0 }}}, // B5
		{{{ 3, 1, 9, 0 }}}, // B4
		{{{ 3, 1, 9, 0 }}}, // B3
		{{{ 3, 1, 9, 0 }}}, // B2
		{{{ 3, 1, 9, 0 }}}, // B1
		{{{ 3, 1, 9, 0 }}}, // B0
		// RMT end marker
		{{{ 0, 1, 0, 0 }}}
    };
    rmt_item32_t bit_one = {{{6, 1, 6, 0}}};

    // Set Red
    for(int i = 7; i >= 0; i--)
    {
        if((red >> i) & 0x01)
        {
            color_encoding[COLOR_ENCODING_RED_LSB_INDEX - i] = bit_one;
        }
    }

    // Set Green
    for(int i = 7; i >= 0; i--)
    {
        if((green >> i) & 0x01)
        {
            color_encoding[COLOR_ENCODING_GREEN_LSB_INDEX - i] = bit_one;
        }
    }

    // Set Blue
    for(int i = 7; i >= 0; i--)
    {
        if((blue >> i) & 0x01)
        {
            color_encoding[COLOR_ENCODING_BLUE_LSB_INDEX - i] = bit_one;
        }
    }

    rmt_write_items(RMT_CHANNEL_0, color_encoding, sizeof(color_encoding) / sizeof(color_encoding[0]), true);
}

void app_main(void)
{
	uint32_t color_code = 0;
    rmt_tx_init();
    while (true) {
        usleep(20000);
        sk6812_set_color(0xffb5c5);
        ++color_code;
        if(color_code > 0xFFFFFF)
        {
        	color_code = 0;
        }
    }
}
