/*
 * spi.c
 *
 *  Created on: Nov 21, 2017
 *      Author: Preshit
 */

#include "spi.h"
#include "gpio.h"

void SPI_init(void)
{
	SIM->SCGC4 |= SIM_SCGC4_SPI0_MASK;  				//enable clock for SPI_0

	SPI0->BR = (SPI_BR_SPPR(0x01) | SPI_BR_SPR(0x00));	//baud rate

	SPI0->C1 = 0x50;
}

uint8_t SPI_status()
{
	return SPI0->S; 									//return SPI status
}

void SPI_write_byte(uint8_t byte)
{
	while (!(SPI0->S & 0x20)); 							//check whether transfer buffer is empty
	SPI0->D = byte;										//write data
}

uint8_t SPI_read_byte()
{
	uint8_t byte;
	while (!(SPI0->S & 0x80)); 							//check whether receive buffer is full
	byte = SPI0->D; 									//read data
	return byte; 										//return data
}

void SPI_send_packet(uint8_t *p, uint8_t length)
{
	uint8_t i = 0;
	for(i=0;i<length;i++)
	{
		while (!(SPI0->S & 0x20));  					//check whether transfer buffer is empty
		SPI0->D = *(p+i); 								//write data
	}
}

void SPI_flush()
{
	SPI0->C1= SPI0->C1 & 0xBF; 							//SPI module disable
	SPI_init();											//reinitialize SPI
}

