#include <stdio.h>
#include <stdbool.h>
#include <unistd.h>

#include "drv_gpio.h"

#include "driver/rmt.h"

static const rmt_item32_t morse_esp[] = {
	// E : dot
	{{{ 3, 1, 9, 0 }}}, // 1
	{{{ 3, 1, 9, 0 }}}, // 1
    {{{ 3, 1, 9, 0 }}}, // 1aRD
    {{{ 3, 1, 9, 0 }}}, // 1
    {{{ 3, 1, 9, 0 }}}, // 1
    {{{ 3, 1, 9, 0 }}}, // 1
    {{{ 3, 1, 9, 0 }}}, // 1
    {{{ 3, 1, 9, 0 }}}, // 1
    {{{ 3, 1, 9, 0 }}}, // 1
    {{{ 3, 1, 9, 0 }}}, // 1
    {{{ 6, 1, 6, 0 }}}, // 1
    {{{ 6, 1, 6, 0 }}}, // 1
    {{{ 6, 1, 6, 0 }}}, // 1
    {{{ 6, 1, 6, 0 }}}, // 1
    {{{ 6, 1, 6, 0 }}}, // 1
    {{{ 6, 1, 6, 0 }}}, // 1
    {{{ 6, 1, 6, 0 }}}, // 1
    {{{ 6, 1, 6, 0 }}}, // 1
    {{{ 6, 1, 6, 0 }}}, // 1
    {{{ 6, 1, 6, 0 }}}, // 1
    {{{ 6, 1, 6, 0 }}}, // 1
    {{{ 6, 1, 6, 0 }}}, // 1
    {{{ 6, 1, 6, 0 }}}, // 1
    {{{ 6, 1, 6, 0 }}}, // 1
	// RMT end marker
	{{{ 0, 1, 0, 0 }}}
};

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

void app_main(void)
{
    rmt_tx_init();
    while (true) {
        printf("Hello from app_main!\n");
        sleep(1);
        rmt_write_items(RMT_CHANNEL_0, morse_esp, sizeof(morse_esp) / sizeof(morse_esp[0]), true);
    }
}
