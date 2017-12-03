/*
 * main.c
 *
 *  Created on: Dec 1, 2017
 *      Author: Preshit
 */

#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include "spi.h"
#include "nordic.h"
#include "gpio.h"

int main()
{
	GPIO_nrf_init();						//initialize gpio pins for SPI and NRF module
	SPI_init();								//initialize SPI
	GPIO_led_init();						//initialize led pins
	config_reg_test();						//test function for config register
	status_reg_test();						//test function for status register
	tx_addr_reg_test();						//test function for tx_addr register
	rf_setup_test();						//test function for rf_setup register
	rf_ch_reg_test();						//test function for rf_ch register
	fifo_status_reg_test();					//test function for fifo_status register
	return 0;
}

void config_reg_test()
{
	nrf_write_config(0x74);
	uint8_t config;
	config = nrf_read_config();
	if(config==0x74)
	{
		RED_LED_TOGGLE;
	}
	SPI_flush();
}

void status_reg_test()
{
	uint8_t status = nrf_read_status();
	SPI_flush();
}

void tx_addr_test()
{
	uint8_t write[5]={0x23,0x21,0x24,0x26,0x27};
	nrf_write_TX_ADDR(write);
	uint8_t read[5];
	nrf_read_TX_ADDR(read);
	uint8_t i=0;
	while(i<5)
	{
		if(*(read+i)==*(write+i))
		{
			RED_LED_TOGGLE;

		}
		else
		{
			GREEN_LED_TOGGLE;
		}
		i++;
	}
	SPI_flush();
}

void rf_setup_test()
{
	nrf_write_rf_setup(0x74);
	uint8_t setup;
	setup = nrf_read_rf_setup();
	if(setup==0x74)
	{
		RED_LED_TOGGLE;
	}
	SPI_flush();
}

void rf_ch_reg_test()
{
	nrf_write_rf_ch(0x74);
	uint8_t channel;
	channel = nrf_write_rf_ch();
	if(channel==0x74)
	{
		RED_LED_TOGGLE;
	}
	SPI_flush();
}

void fifo_status_reg_test()
{
	uint8_t fifo = nrf_read_fifo_status();
	SPI_flush();
}
