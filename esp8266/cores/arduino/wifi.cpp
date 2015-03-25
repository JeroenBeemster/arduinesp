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

#ifdef __cplusplus
	extern "C" {
#endif

#include "wifi.h"

#include <osapi.h>
#include "webserver.h" 
#include "os_type.h"
#include "espmissingincludes.h"
#include "ip_addr.h"
#include "espconn.h"

char response_data[200] ;

ESP8266wifi::ESP8266wifi()
{
	os_memset(response_data, 0, 200);
}

void ESP8266wifi::begin(const char ssid[32], const char pass[64]) {
	wifi_begin(ssid,pass);
}

void ESP8266wifi::server(MyfuncDef ServerRespondPtr,unsigned long port) {

	setWebserverPointer(ServerRespondPtr);
	webserver_init(port);
}

void ESP8266wifi::print(const char c[]) {
	os_sprintf(response_data,"%s%s",response_data, c);	
}

void ESP8266wifi::println(const char c[]) {
	  os_sprintf(response_data,"%s%s",response_data, c);
	  os_sprintf(response_data,"%s%s",response_data, "\r\n");

}

void ESP8266wifi::send() {
  char fulldata[250];
  os_memset(fulldata,0,250);
  

  os_sprintf(fulldata,"HTTP/1.0 200 OK\r\nContent-Length: %d\r\nServer: ArduinoESP8266\r\n\r\n",os_strlen(response_data)); 
  os_sprintf(fulldata,"%s%s",fulldata, response_data);

  int length = os_strlen(fulldata);
  os_sprintf(fulldata + length, "\n");
	
  setResponse(fulldata);
  os_memset(response_data, 0, 200);    
}

#ifdef __cplusplus
}
#endif

ESP8266wifi wifi = ESP8266wifi();

