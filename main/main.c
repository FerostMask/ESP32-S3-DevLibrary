#include <stdio.h>
#include <stdbool.h>
#include <unistd.h>

#include "driver/spi_master.h"
#include "driver/gpio.h"

#define MACR_LCD_SPI_HOST   SPI2_HOST   // SPI模块号
#define MACR_LCD_MOSI_IO    2
#define MACR_LCD_MISO_IO    7
#define MACR_LCD_SCLK_IO    8
#define MACR_LCD_BUFF_SZ    64
#define MACR_LCD_DMA_CH     SPI_DMA_DISABLED
#define MACR_LCD_FREQ       SPI_MASTER_FREQ_10M
#define MACR_LCD_SPI_MODE   0
#define MACR_LCD_CS_IO      4
#define MACR_LCD_QUEUE_SZ   1

// 初始化外设模块
spi_bus_config_t bus_cfg = {
    .mosi_io_num = MACR_LCD_MOSI_IO,
    .miso_io_num = MACR_LCD_MISO_IO,
    .sclk_io_num = MACR_LCD_SCLK_IO,
    .quadwp_io_num = -1,
    .quadhd_io_num = -1,
    .max_transfer_sz = MACR_LCD_BUFF_SZ,
};

// 初始化SPI设备
spi_device_interface_config_t dev_cfg = {
    .clock_speed_hz = MACR_LCD_FREQ,
    .mode = MACR_LCD_SPI_MODE,
    .spics_io_num = MACR_LCD_CS_IO,
    .queue_size = MACR_LCD_QUEUE_SZ,
};
spi_device_handle_t lcd;

void spi_write(spi_device_handle_t lcd, int spics_io_num, char *data, int len)
{
    spi_transaction_t trans = {0};

    if(len <= 0)
    {
        // do nothing
    }
    else
    {
        gpio_set_level(spics_io_num, 0);
        
        trans.length = len * 8; // 按位传输
        trans.tx_buffer = data,
        trans.user = (void*)1;
        spi_device_polling_transmit(lcd, &trans);

        gpio_set_level(spics_io_num, 0);
    }
}

void spi_read(spi_device_handle_t lcd, int spics_io_num, char *data, int len)
{
    spi_transaction_t trans = {0};

    if(len <= 0)
    {
        // do nothing
    }
    else if(len <= 4)
    {
        gpio_set_level(spics_io_num, 0);
        
        trans.length = len * 8; // 按位传输
        trans.flags = SPI_TRANS_USE_RXDATA;
        trans.user = (void*)1;
        spi_device_polling_transmit(lcd, &trans);

        gpio_set_level(spics_io_num, 0);

        for(int i = 0; i < len; i++)
        {
        	data[i] = trans.rx_data[i];
        }
    }
    else
    {

    }
}

void dev_lcd_st7789v_initialize(spi_bus_config_t *bus_cfg, spi_device_interface_config_t *dev_cfg, spi_device_handle_t *lcd)
{
    spi_bus_initialize(MACR_LCD_SPI_HOST, bus_cfg, MACR_LCD_DMA_CH);
    spi_bus_add_device(MACR_LCD_SPI_HOST, dev_cfg, lcd);

    // 设置CS管脚输出
    gpio_pad_select_gpio(dev_cfg->spics_io_num);
    gpio_set_direction(dev_cfg->spics_io_num, GPIO_MODE_OUTPUT);
    gpio_set_level(dev_cfg->spics_io_num, 1);
}

void app_main(void)
{
    int16_t read_data = 100;
    dev_lcd_st7789v_initialize(&bus_cfg, &dev_cfg, &lcd);
    while (true) {
        printf("Hello from app_main!\n");
        spi_write(lcd, dev_cfg.spics_io_num, "ab", 2);
        spi_read(lcd, dev_cfg.spics_io_num, &read_data, 2);
        printf("data read: %d", read_data);
        sleep(1);
    }
}
