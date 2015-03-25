/*
  webserver.h - Hardware serial library for Wiring
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
#ifndef __WEBSERVER_H__
#define __WEBSERVER_H__

#include "os_type.h"


#define SERVER_PORT 80
#define SERVER_SSL_PORT 443

#define URLSize 10

typedef enum Result_Resp {
    RespFail = 0,
    RespSuc,
} Result_Resp;

typedef enum ProtocolType {
    GET = 0,
    POST,
} ProtocolType;

typedef enum _ParmType {
    SWITCH_STATUS = 0,
    INFOMATION,
    WIFI,
    SCAN,
	REBOOT,
    DEEP_SLEEP,
    LIGHT_STATUS,
    CONNECT_STATUS,
    USER_BIN
} ParmType;

typedef struct URL_Frame {
    enum ProtocolType Type;
    char pSelect[URLSize];
    char pCommand[URLSize];
    char pFilename[URLSize];
} URL_Frame;

typedef struct _rst_parm {
    ParmType parmtype;
    struct espconn *pespconn;
} rst_parm;

typedef void (*MyfuncDef)(char[]);

void wifi_begin(const char ssid[32], const char pass[64]);
void webserver_init(uint32 port);
void setWebserverPointer(MyfuncDef aWebServerCPublicFunctionPtr);
void setResponse(char aResponse[250]);
void dummywebserver();
#endif
