#include <stdio.h>
#include <stdbool.h>
#include <unistd.h>

#include "drv_gpio.h"

void app_main(void)
{
	stc_gpio_config_t io16 = {
		.ioNum = IO_0,
		.mode = IO_MODE_INPUT_OUTPUT,
	};
	drv_gpio_init(&io16);
	drv_gpio_set_level(io16.ioNum, 1);
    while (true) {
        printf("io16 level: %d\n", drv_gpio_get_level(io16.ioNum));
        sleep(1);
    }
}
