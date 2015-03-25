// Example using standard C library (in this case from expressif
// By adding extern "C" { ... } surround the #include, you may use then
// This library can be found in your arduino directory like :
// C:\Program Files (x86)\Arduino\hardware\arduino\esp8266\tools\esp_iot_sdk_v0.9.5\include
// Documentation about this library can be found somewhere here: 
// C:\Program Files (x86)\Arduino\hardware\arduino\esp8266\tools\esp_iot_sdk_v0.9.5\document\English\
// Be aware that this directory will change to the latest version of SDK 
// Jeroen Beemster 14 March 2015

#ifdef __cplusplus
  extern "C"{
#endif

#include "user_interface.h"

#ifdef __cplusplus
  }
#endif


void setup() {
  system_print_meminfo();
}

void loop() {

}
