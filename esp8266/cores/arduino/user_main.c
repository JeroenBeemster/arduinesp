/*
  user_main.h - Hardware serial library for Wiring
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

#include "ets_sys.h"
#include "osapi.h"
#include "gpio.h"
#include "os_type.h"
#include "user_config.h"
#include "mem.h"


#define user_procTaskPrio        0 
#define user_procTaskQueueLen    1 
bool firsttime = true;
//os_event_t    user_procTaskQueue[user_procTaskQueueLen];

static volatile os_timer_t some_timer;

void myloop(void *arg) // in Arduino this is loop the main loop
//static void ICACHE_FLASH_ATTR myloop(os_event_t *events) 
{
	if(firsttime == true) {  // Show some info like dhcp server start. Starts after first time system_os_post
		os_delay_us(100000); 

		setup(); // 
	}
	firsttime = false; 
	
	loop();
	
	os_delay_us(10000); //otherwise too fast restart loop and in conflict with uart os_print.
	//system_os_post(user_procTaskPrio, 0, 0 ); // Put the same task (this task) in the queue 
    os_timer_disarm(&some_timer);
    os_timer_setfn(&some_timer, (os_timer_func_t *)myloop, NULL);
    os_timer_arm(&some_timer, 1000, 0);
	
}


void ICACHE_FLASH_ATTR
user_init()  // in arduino this is setup()
{
    // Initialize the GPIO subsystem.
    gpio_init();
    //uart_div_modify(115200); // Show some info like dhcp server start.  
	uart_div_modify(0, UART_CLK_FREQ / 115200);
	
	//system_os_task(myloop, user_procTaskPrio,user_procTaskQueue, user_procTaskQueueLen);
    //system_os_post(user_procTaskPrio, 0, 0 );	 // Put the first time the task in the queue 
	
	os_timer_disarm(&some_timer);
    os_timer_setfn(&some_timer, (os_timer_func_t *)myloop, NULL);

    //Arm the timer
    //&some_timer is the pointer
    //1000 is the fire time in ms
    //0 for once and 1 for repeating
    os_timer_arm(&some_timer, 1000, 0);

	
	
}

void dummy() { // remove this and the compiler will complain. :(
	dummywebserver(); 

}

#ifdef __cplusplus
  }
#endif
