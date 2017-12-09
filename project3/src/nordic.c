/***************************************************************************************************
 *
 * @author  Preshit Harlikar, Shivam Khandelwal
 * @file nordic.c
 * @brief This file includes functions to communicate and configure nrf module.
 * @date December 03, 2017
 *
 * long description - The nordic.c file includes functions to -
 *                      1) nrf_read_register()
 *                      2) nrf_write_register()
 *                      3) nrf_read_status()
 *                      4) nrf_read_config()
 *                      5) nrf_write_config()
 *                      6) nrf_read_rf_setup()
 *                      7) nrf_write_rf_setup()
 *                      8) nrf_read_rf_ch()
 *                      9) nrf_read_TX_ADDR()
 *                     10) nrf_write_TX_ADDR()
 *                     11) nrf_read_fifo_status()
 *                     12) nrf_flush_rx_fifo()
 *                     13) nrf_flush_tx_fifo()
 *
 ***************************************************************************************************/

#include "nordic.h"

/********************************** nrf_read_register() **********************************************************
 *
 * @name   -  nrf_read_register()
 * @brief  -  function to initialize GPIO for nrf module.
 * @param  -  none
 *
 * long description - This function initializes GPIO for nrf module
 *
 * @return -  void
 *
 ********************************************************************************************************/

/************************************ nrf_read_register() function definition ***********************************/

uint8_t nrf_read_register(uint8_t reg)
{
	uint8_t a;
	SPI_write_byte(R_REGISTER|reg);			//sending read command
	delay();
	SPI_read_byte();
	SPI_write_byte(0xFF);					//sending dummy value
	delay();
	a=SPI_read_byte();						//reading value from register
	return a;
}

/********************************** nrf_write_register() **********************************************************
 *
 * @name   -  nrf_write_register()
 * @brief  -  function to initialize GPIO for nrf module.
 * @param  -  none
 *
 * long description - This function initializes GPIO for nrf module
 *
 * @return -  void
 *
 ********************************************************************************************************/

/************************************ nrf_write_register() function definition ***********************************/

void nrf_write_register(uint8_t reg, uint8_t value)
{
	SPI_write_byte(W_REGISTER|reg);			//sending write command
	delay();
	SPI_read_byte();
	SPI_write_byte(value);					//sending value to be written
	delay();
	SPI_read_byte();
}

/********************************** nrf_read_status() **********************************************************
 *
 * @name   -  nrf_read_status()
 * @brief  -  function to initialize GPIO for nrf module.
 * @param  -  none
 *
 * long description - This function initializes GPIO for nrf module
 *
 * @return -  void
 *
 ********************************************************************************************************/

/************************************ nrf_read_status() function definition ***********************************/

uint8_t nrf_read_status()
{
	uint8_t a;
	nrf_chip_enable();						//chip enable
	a = nrf_read_register(STATUS_REG);		//read value of status register and return value in a
	nrf_chip_disable();						//chip disable
	return a;
}

/********************************** nrf_read_config() **********************************************************
 *
 * @name   -  nrf_read_config()
 * @brief  -  function to initialize GPIO for nrf module.
 * @param  -  none
 *
 * long description - This function initializes GPIO for nrf module
 *
 * @return -  void
 *
 ********************************************************************************************************/

/************************************ nrf_read_config() function definition ***********************************/

uint8_t nrf_read_config()
{
	uint8_t a;
	nrf_chip_enable();						//chip enable
	a = nrf_read_register(CONFIG_REG);		//read value of config register and return value in a
	nrf_chip_disable();
	return a;
}

/********************************** nrf_write_config() **********************************************************
 *
 * @name   -  nrf_write_config()
 * @brief  -  function to initialize GPIO for nrf module.
 * @param  -  none
 *
 * long description - This function initializes GPIO for nrf module
 *
 * @return -  void
 *
 ********************************************************************************************************/

/************************************ nrf_write_config() function definition ***********************************/

void nrf_write_config(uint8_t config)
{
	nrf_chip_enable();						//chip enable
	nrf_write_register(CONFIG_REG,config); 	//send config register address and value to be written in the register
	nrf_chip_disable();						//chip disable
}

/********************************** nrf_read_rf_setup() **********************************************************
 *
 * @name   -  nrf_read_rf_setup()
 * @brief  -  function to initialize GPIO for nrf module.
 * @param  -  none
 *
 * long description - This function initializes GPIO for nrf module
 *
 * @return -  void
 *
 ********************************************************************************************************/

/************************************ nrf_read_rf_setup() function definition ***********************************/

uint8_t nrf_read_rf_setup()
{
	uint8_t a;
	nrf_chip_enable();						//chip enable
	a = nrf_read_register(RF_SETUP_REG);	//read value of rf setup register and return value in a
	nrf_chip_disable();						//chip disable
	return a;
}

/********************************** nrf_write_rf_setup() **********************************************************
 *
 * @name   -  nrf_write_rf_setup()
 * @brief  -  function to initialize GPIO for nrf module.
 * @param  -  none
 *
 * long description - This function initializes GPIO for nrf module
 *
 * @return -  void
 *
 ********************************************************************************************************/

/************************************ nrf_write_rf_setup() function definition ***********************************/

void nrf_write_rf_setup(uint8_t config)
{
	nrf_chip_enable();						//chip enable
	nrf_write_register(RF_SETUP_REG,config);//send rf setup register address and value to be written in the register
	nrf_chip_disable();						//chip disable
}

/********************************** nrf_read_rf_ch() **********************************************************
 *
 * @name   -  nrf_read_rf_ch()
 * @brief  -  function to initialize GPIO for nrf module.
 * @param  -  none
 *
 * long description - This function initializes GPIO for nrf module
 *
 * @return -  void
 *
 ********************************************************************************************************/

/************************************ nrf_read_rf_ch() function definition ***********************************/

uint8_t nrf_read_rf_ch()
{
	uint8_t a;
	nrf_chip_enable();						//chip enable
	a = nrf_read_register(RF_CH_REG);		//read value of rf ch register and return value in a
	nrf_chip_disable();						//chip disable
	return a;
}

/********************************** nrf_write_rf_ch() **********************************************************
 *
 * @name   -  nrf_write_rf_ch()
 * @brief  -  function to initialize GPIO for nrf module.
 * @param  -  none
 *
 * long description - This function initializes GPIO for nrf module
 *
 * @return -  void
 *
 ********************************************************************************************************/

/************************************ nrf_write_rf_ch() function definition ***********************************/

void nrf_write_rf_ch(uint8_t channel)
{
	nrf_chip_enable();						//chip enable
	nrf_write_register(RF_CH_REG,channel);	//send rf ch register address and value to be written in the register
	nrf_chip_disable();						//chip disable
}

/********************************** nrf_read_TX_ADDR() **********************************************************
 *
 * @name   -  nrf_read_TX_ADDR()
 * @brief  -  function to initialize GPIO for nrf module.
 * @param  -  none
 *
 * long description - This function initializes GPIO for nrf module
 *
 * @return -  void
 *
 ********************************************************************************************************/

/************************************ nrf_read_TX_ADDR() function definition ***********************************/

void nrf_read_TX_ADDR(uint8_t *address)
{
	uint8_t i;
	nrf_chip_enable();						//chip enable
	SPI_write_byte(R_REGISTER|TX_ADDR);		//sending read command in tx_addr register
	delay();
	SPI_read_byte();
	for(i=0;i<5;i++)
	{
		SPI_write_byte(0xFF);				//sending dummy value
		delay();
		*(address+i) = SPI_read_byte();		//reading value from register and storing it in a pointer
	}
	nrf_chip_disable();						//chip disable
}

/********************************** nrf_write_TX_ADDR() **********************************************************
 *
 * @name   -  nrf_write_TX_ADDR()
 * @brief  -  function to initialize GPIO for nrf module.
 * @param  -  none
 *
 * long description - This function initializes GPIO for nrf module
 *
 * @return -  void
 *
 ********************************************************************************************************/

/************************************ nrf_write_TX_ADDR() function definition ***********************************/

void nrf_write_TX_ADDR(uint8_t *tx_addr)
{
	uint8_t i=0;
	nrf_chip_enable();						//chip enable
	SPI_write_byte(W_REGISTER|TX_ADDR);		//sending write command in tx_addr register
	delay();
	SPI_read_byte();
	for(i=0;i<5;i++)
	{
		SPI_write_byte(*(tx_addr+i));		//writing value in tx_addr register
		delay();
		SPI_read_byte();
	}
	nrf_chip_disable();						//chip disable
}

/********************************** nrf_read_fifo_status() **********************************************************
 *
 * @name   -  nrf_read_fifo_status()
 * @brief  -  function to initialize GPIO for nrf module.
 * @param  -  none
 *
 * long description - This function initializes GPIO for nrf module
 *
 * @return -  void
 *
 ********************************************************************************************************/

/************************************ nrf_read_fifo_status() function definition ***********************************/

uint8_t nrf_read_fifo_status()
{
	uint8_t a;
	nrf_chip_enable();						//chip enable
	a= nrf_read_register(FIFO_STATUS_REG);	//read value of fifo status register and return value in a
	nrf_chip_disable();						//chip disable
	return a;
}

/********************************** nrf_flush_rx_fifo() **********************************************************
 *
 * @name   -  nrf_flush_rx_fifo()
 * @brief  -  function to initialize GPIO for nrf module.
 * @param  -  none
 *
 * long description - This function initializes GPIO for nrf module
 *
 * @return -  void
 *
 ********************************************************************************************************/

/************************************ nrf_flush_rx_fifo() function definition ***********************************/

void nrf_flush_rx_fifo()
{
	nrf_chip_enable();						//chip enable
	SPI_write_byte(FLUSH_RX);				//writing flush_rx command
	SPI_read_byte();
	nrf_chip_disable();						//chip disable
}

/********************************** nrf_flush_tx_fifo() **********************************************************
 *
 * @name   -  nrf_flush_tx_fifo()
 * @brief  -  function to initialize GPIO for nrf module.
 * @param  -  none
 *
 * long description - This function initializes GPIO for nrf module
 *
 * @return -  void
 *
 ********************************************************************************************************/

/************************************ nrf_flush_tx_fifo() function definition ***********************************/

void nrf_flush_tx_fifo()
{
	nrf_chip_enable();						//chip enable
	SPI_write_byte(FLUSH_TX);				//writing flush_tx command
	SPI_read_byte();
	nrf_chip_disable();						//chip disable
}
