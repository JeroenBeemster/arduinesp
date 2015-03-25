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
#ifdef __cplusplus
  extern "C"{
#endif

#include "webserver.h"

#include "ets_sys.h"
#include "os_type.h"
#include "osapi.h"
#include "mem.h"
#include "user_interface.h"
#include "espconn.h"
#include "c_types.h" 



LOCAL MyfuncDef MyWebServerCPublicFunctionPtr;
LOCAL char MyResponse[250] = "";

void ICACHE_FLASH_ATTR
wifi_begin(const char ssid[32], const char pass[64])
{
  struct station_config stationConf; 
 
  char current_ssid[32];
  char current_pass[64];
  //Set station mode 
  wifi_set_opmode( 0x1 ); 
  
  wifi_station_get_config (&stationConf);
  os_memcpy(current_ssid, &stationConf.ssid, 32); 
  os_memcpy(current_pass, &stationConf.password, 64); // wow is this really the case
  if((strcmp(ssid,current_ssid) != 0) || (strcmp(pass,current_pass) != 0)) {  // set only config if changed  
	  
	//Set ap settings 
	os_memcpy(&stationConf.ssid, ssid, 32); 
	os_memcpy(&stationConf.password, pass, 64); 
	wifi_station_set_config(&stationConf); 
  }
}

/******************************************************************************
 * FunctionName : webserver_recv
 * Description  : Processing the received data from the server
 * Parameters   : arg -- Additional argument to pass to the callback function
 *                pusrdata -- The received data (or NULL when the connection has been closed!)
 *                length -- The length of received data
 * Returns      : none
*******************************************************************************/
LOCAL void ICACHE_FLASH_ATTR
webserver_recv(void *arg, char *pusrdata, unsigned short length)
{
	os_printf("incoming request\r\n");

	//os_printf(pusrdata);
    struct espconn *ptrespconn = arg;


	(*MyWebServerCPublicFunctionPtr)(pusrdata);	
	os_printf(MyResponse);  
    os_printf("lengte%d",os_strlen(MyResponse))	;
	espconn_sent(ptrespconn, MyResponse, os_strlen(MyResponse));
	
	
}


/******************************************************************************
 * FunctionName : webserver_recon
 * Description  : the connection has been err, reconnection
 * Parameters   : arg -- Additional argument to pass to the callback function
 * Returns      : none
*******************************************************************************/
LOCAL ICACHE_FLASH_ATTR
void webserver_recon(void *arg, sint8 err)
{
    struct espconn *pesp_conn = arg;

    os_printf("webserver's %d.%d.%d.%d:%d err %d reconnect\n", pesp_conn->proto.tcp->remote_ip[0],
    		pesp_conn->proto.tcp->remote_ip[1],pesp_conn->proto.tcp->remote_ip[2],
    		pesp_conn->proto.tcp->remote_ip[3],pesp_conn->proto.tcp->remote_port, err);
}

/******************************************************************************
 * FunctionName : webserver_discon
 * Description  : 
 * Parameters   : arg -- Additional argument to pass to the callback function
 * Returns      : none
*******************************************************************************/
LOCAL ICACHE_FLASH_ATTR
void webserver_discon(void *arg)
{
    struct espconn *pesp_conn = arg;

    os_printf("webserver's %d.%d.%d.%d:%d disconnect\n", pesp_conn->proto.tcp->remote_ip[0],
        		pesp_conn->proto.tcp->remote_ip[1],pesp_conn->proto.tcp->remote_ip[2],
        		pesp_conn->proto.tcp->remote_ip[3],pesp_conn->proto.tcp->remote_port);
}

/******************************************************************************
 * FunctionName : webserver_listen
 * Description  : server listened a connection successfully
 * Parameters   : arg -- Additional argument to pass to the callback function
 * Returns      : none
*******************************************************************************/
LOCAL void ICACHE_FLASH_ATTR
webserver_listen(void *arg)
{
    struct espconn *pesp_conn = arg;

    espconn_regist_recvcb(pesp_conn, webserver_recv);
    espconn_regist_reconcb(pesp_conn, webserver_recon);
    espconn_regist_disconcb(pesp_conn, webserver_discon);
}


/******************************************************************************
* FunctionName : user_webserver_init
* Description  : parameter initialize as a server
* Parameters   : port -- server port
* Returns      : none
*******************************************************************************/

//void (*WebServerCPublicFunctionPtr)(char[],const char []);

void ICACHE_FLASH_ATTR
 webserver_init(uint32 port)
 {
	LOCAL struct espconn esp_conn;
    LOCAL esp_tcp esptcp;

    esp_conn.type = ESPCONN_TCP;
    esp_conn.state = ESPCONN_NONE;
    esp_conn.proto.tcp = &esptcp;
    esp_conn.proto.tcp->local_port = port;
    espconn_regist_connectcb(&esp_conn, webserver_listen);

    espconn_accept(&esp_conn);

 }
 
void ICACHE_FLASH_ATTR
 setWebserverPointer(MyfuncDef aWebServerCPublicFunctionPtr) {
	 MyWebServerCPublicFunctionPtr = aWebServerCPublicFunctionPtr;
 }

void ICACHE_FLASH_ATTR
 setResponse(char aResponse[250]) {
	 
	 strncpy(MyResponse, aResponse, 250);
	 
 }
 
void dummywebserver() {
	
} 
 
 #ifdef __cplusplus
  }
#endif
