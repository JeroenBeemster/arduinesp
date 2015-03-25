/*
  wifi.h - Hardware serial library for Wiring
  Copyright (c) 2015 Jeroen Beemster.  All right reserved.

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

#ifndef wifi_h
#define wifi_h


#ifdef __cplusplus
extern "C" {
#endif

#include "Print.h"
#include "webserver.h"


class ESP8266wifi 
{
  public:
  inline ESP8266wifi();
  void begin(const char ssid[32], const char pass[64]);  
  void server(MyfuncDef ServerRespondPtr,unsigned long port);
  void print(const char c[]);   // OK, if you came to here. This should be the same as hardwareserial with inline write. 
  void println(const char c[]); //  Sorry, that this is not there yet. Something for you to develop? 
  void send();
  
};

#ifdef __cplusplus
}
#endif

#endif

extern ESP8266wifi wifi;
