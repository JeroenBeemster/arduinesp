/*
  HardwareSerial.cpp - Hardware serial library for Wiring
  Copyright (c) 2006 Nicholas Zambetti.  All right reserved.

  This library is free software; you can redistribute it and/or
  modify it under the terms of the GNU Lesser General Public
  License as published by the Free Software Foundation; either
  version 2.1 of the License, or (at your option) any later version.

  This library is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
  Lesser General Public License for more details.

  You should have received a copy of the GNU Lesser General Public
  License along with this library; if not, write to the Free Software
  Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
  
  Modified 23 November 2006 by David A. Mellis
  Modified 28 September 2010 by Mark Sproul
  Modified 14 August 2012 by Alarus
  Modified 3 December 2013 by Matthijs Kooijman
    -----------------------------------------------------------------------------
  Modified 22 March 2015 Jeroen Beemster for ESP8266
*/


 
#ifdef __cplusplus
extern "C" {
#endif

#include "HardwareSerial.h"
#include "osapi.h"



HardwareSerial::HardwareSerial() {
    
}

void HardwareSerial::begin(unsigned long baud)
{
/*
	//Enable TxD pin
	PIN_PULLUP_DIS(PERIPHS_IO_MUX_U0TXD_U);
	PIN_FUNC_SELECT(PERIPHS_IO_MUX_U0TXD_U, FUNC_U0TXD);

	//Set baud rate and other serial parameters to 115200,n,8,1
	
	uart_div_modify(0, UART_CLK_FREQ / baud);
	
	WRITE_PERI_REG(UART_CONF0(0),
			(STICK_PARITY_DIS) | (ONE_STOP_BIT << UART_STOP_BIT_NUM_S) | (EIGHT_BITS << UART_BIT_NUM_S));

	//Reset tx & rx fifo
	SET_PERI_REG_MASK(UART_CONF0(0), UART_RXFIFO_RST | UART_TXFIFO_RST);
	CLEAR_PERI_REG_MASK(UART_CONF0(0), UART_RXFIFO_RST | UART_TXFIFO_RST);
	//Clear pending interrupts
	WRITE_PERI_REG(UART_INT_CLR(0), 0xffff);
*/
}

#ifdef __cplusplus
}
#endif

HardwareSerial Serial = HardwareSerial();