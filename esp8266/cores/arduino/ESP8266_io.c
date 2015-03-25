/*
  ESP8266_io.h - Main include file for the ArduinoESP8266 SDK
  Copyright (c) 2015.  All right reserved.

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
  -----------------------------------------------------------------------------
  Modified 22 March 2015 Jeroen Beemster for ESP8266
*/


#ifdef __cplusplus
  extern "C"{
#endif


#include "os_type.h"
#include "gpio.h"
#include "osapi.h"

void pinMode(uint8_t pin, uint8_t output ) {
	if (pin == 1) {
		PIN_FUNC_SELECT(PERIPHS_IO_MUX_U0TXD_U, FUNC_GPIO1);
	}
    GPIO_OUTPUT_SET(pin, output); 
}

void digitalWrite(uint8_t pin, uint8_t output) {
	GPIO_OUTPUT_SET(pin, output); 

}
int digitalRead(uint8_t pin) {
	return GPIO_INPUT_GET(pin);
}
/*int analogRead(uint8_t);
void analogReference(uint8_t mode);
void analogWrite(uint8_t, int);
*/
unsigned long millis(void) {
	return system_get_rtc_time(); 
}
/*
unsigned long micros(void);
*/
void delay(unsigned long interval) {
  os_delay_us(interval*1000);
}     

 
/*
void delayMicroseconds(unsigned int us);
unsigned long pulseIn(uint8_t pin, uint8_t state, unsigned long timeout);

void shiftOut(uint8_t dataPin, uint8_t clockPin, uint8_t bitOrder, uint8_t val);
uint8_t shiftIn(uint8_t dataPin, uint8_t clockPin, uint8_t bitOrder);

void attachInterrupt(uint8_t, void (*)(void), int mode);
void detachInterrupt(uint8_t);

*/




#ifdef __cplusplus
  }
#endif

