/*
 * spi.h
 *
 *  Created on: Nov 21, 2017
 *      Author: Preshit
 */

#ifndef SOURCES_SPI_H_
#define SOURCES_SPI_H_

#include<stdio.h>
#include<stdlib.h>
#include<stdint.h>
#include "MKL25Z4.h"
#include "gpio.h"

void SPI_init();
uint8_t SPI_status();
void SPI_write_byte(uint8_t byte);
uint8_t SPI_read_byte();
void SPI_send_packet(uint8_t *p, uint8_t length);
void SPI_flush();

#endif /* SOURCES_SPI_H_ */
