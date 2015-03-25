/*
  Print.h - Base class that provides print() and println()
  Copyright (c) 2008 David A. Mellis.  All right reserved.

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
  
  Modified 06 March 2014 by Jeroen J.P. Beemster for ESP8266
*/

#ifndef Print_h
#define Print_h

//#include <inttypes.h>
#include "os_type.h"
#include <stdio.h> // for size_t

//#include "WString.h"
#include "Printable.h"
	
#define DEC 10
#define HEX 16
#define OCT 8
#define BIN 2

class Print
{
	
  private:

    size_t printNumber(unsigned long, uint8_t);	
    size_t printFloat(double, uint8_t);

  public:
	
    //size_t print(const String &);
    size_t print(const char[]);
    size_t print(char);
    //size_t print(unsigned char, int = DEC);
    size_t print(int, int = DEC);
    size_t print(unsigned int, int = DEC);
    size_t print(long, int = DEC);
    size_t print(unsigned long, int = DEC);
	size_t print(double, int = 2);//  not supported, check http://embdev.net/topic/129076	
    //size_t print(const Printable&);

    //size_t println(const String &s);
    size_t println(const char[]);	
    size_t println(char);
    //size_t println(unsigned char, int = DEC);
    size_t println(int, int = DEC);
    size_t println(unsigned int, int = DEC);
    size_t println(long, int = DEC);
    size_t println(unsigned long, int = DEC);
    size_t println(double, int = 2); // not supported
    //size_t println(const Printable&);
    size_t println(void);
	
};

#endif
