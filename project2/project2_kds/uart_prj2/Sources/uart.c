/*
 * uart.c
 *
 *  Created on: 24-Oct-2017
 *      Author: defaultuser0
 */

#include "uart.h"
#include "circbuf.h"
#include "project2.h"

CB_status UART_configure()
{
	SIM->SCGC5 |= SIM_SCGC5_PORTA_MASK;
	SIM->SCGC4 |= SIM_SCGC4_UART0_MASK;

	PORTA_PCR1 |= PORT_PCR_MUX(2);
	PORTA_PCR2 |= PORT_PCR_MUX(2);

	SIM->SOPT2 &= ~(SIM_SOPT2_PLLFLLSEL_MASK);
	SIM->SOPT2 |= SIM_SOPT2_PLLFLLSEL(1);
	SIM->SOPT2 |= SIM_SOPT2_UART0SRC(1);

	uint16_t baud_rate = BAUD_RATE;
	UART0_BDL = (uint8_t)(baud_rate & UART0_BDL_SBR_MASK) ;
	UART0_BDH = (uint8_t)((baud_rate>>8) & UART0_BDH_SBR_MASK);

	UART0_C1 = 0x00;
	UART0_C3 = 0x00;
	UART0_S1 = 0x00;
	UART0_C4 = UART0_C4_OSR(15);

	UART0_C2 &= ~(UART0_C2_RE_MASK | UART0_C2_TE_MASK);
	UART0_C2 |=  (UART0_C2_RE_MASK | UART0_C2_TE_MASK);
	UART0_C2 |= UART0_C2_RIE_MASK;

	NVIC_EnableIRQ(UART0_IRQn);

	return SUCCESS;
}

CB_status UART_send(uint8_t *data0)
{
	UART0_D = *data0;
	return SUCCESS;
}

CB_status UART_send_n(uint8_t *data0, uint8_t length)
{
	uint8_t i = 0;

	for(i=0;i<length;i++)
	{
		//while(((UART0_S1)&(UART0_S1_TDRE_MASK)) != (UART0_S1_TDRE_MASK));
		UART0_D = *(data0 + i);
	}
	return SUCCESS;
}

CB_status UART_receive(uint8_t *data0)
{
	*(data0) = UART0_D;
	return RX_SUCCESS;
}

CB_status UART_receive_n(uint8_t *data0, uint8_t length)
{
	uint8_t i = 0;

		for(i=0;i<length;i++)
		{
			*(data0 + length) = UART0_D;
		}

	return RX_SUCCESS;
}

CB_status UART0_IRQHandler()
{

	if((UART0_S1 & UART0_S1_TDRE_MASK) && (!CB_is_empty(&Tx_Buffer))){
		CB_buffer_remove_item(&Tx_Buffer, &Tx_Data);
		UART_send(&Tx_Data);
		if(CB_is_empty(&Tx_Buffer)){
			UART0_C2 &= ~UART0_C2_TIE_MASK;
		}
		return TX_IRQ;
	}

	if((UART0_S1 & UART0_S1_RDRF_MASK ) && (!CB_is_full(&Rx_Buffer))){
		UART_receive(&Rx_Data);
		CB_buffer_add_item(&Rx_Buffer, &Rx_Data);
		if(CB_is_full(&Rx_Buffer)){
			UART0_C2 &= ~UART0_C2_RIE_MASK;
		}
		return RX_IRQ;
	}
}


