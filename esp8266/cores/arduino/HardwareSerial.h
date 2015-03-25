/*
  HardwareSerial.h - Hardware serial library for Wiring
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

  Modified 28 September 2010 by Mark Sproul
  Modified 14 August 2012 by Alarus
  Modified 3 December 2013 by Matthijs Kooijman
  -----------------------------------------------------------------------------
  Modified 22 March 2015 Jeroen Beemster for ESP8266
*/

#ifndef HardwareSerial_h
#define HardwareSerial_h

//#include "os_type.h"

#ifdef __cplusplus
extern "C" {
#endif

#include "Print.h"

// Define config for Serial.begin(baud, config);
//#define SERIAL_8N1 0x06

class HardwareSerial : public Print
{
  public:
    inline HardwareSerial();
    void begin(unsigned long baud);
	
};



#ifdef __cplusplus
}

#endif
extern HardwareSerial Serial;
#endif
