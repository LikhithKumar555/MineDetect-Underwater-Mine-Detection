/*
   -- New project --
   
   This source code of graphical user interface 
   has been generated automatically by RemoteXY editor.
   To compile this code using RemoteXY library 3.1.10 or later version 
   download by link http://remotexy.com/en/library/
   To connect using RemoteXY mobile app by link http://remotexy.com/en/download/                   
     - for ANDROID 4.13.1 or later version;
     - for iOS 1.10.1 or later version;
    
   This source code is free software; you can redistribute it and/or
   modify it under the terms of the GNU Lesser General Public
   License as published by the Free Software Foundation; either
   version 2.1 of the License, or (at your option) any later version.    
*/

//////////////////////////////////////////////
//        RemoteXY include library          //
//////////////////////////////////////////////

// you can enable debug logging to Serial at 115200
//#define REMOTEXY__DEBUGLOG    

// RemoteXY select connection mode and include library 
#define REMOTEXY_MODE__ESP8266WIFI_LIB_POINT
#include <ESP8266WiFi.h>


// RemoteXY connection settings 
#define REMOTEXY_WIFI_SSID "YOUR_WIFI_SSID"
#define REMOTEXY_WIFI_PASSWORD "YOUR_WIFI_PASSWORD"
#define REMOTEXY_SERVER_PORT 6377


#include <RemoteXY.h>

// RemoteXY configurate  
#pragma pack(push, 1)
uint8_t RemoteXY_CONF[] =   // 69 bytes
  { 255,2,0,0,0,62,0,17,0,0,0,31,2,106,200,200,84,1,1,4,
  0,4,11,56,12,36,19,244,25,106,48,2,26,4,11,232,13,252,157,245,
  25,106,48,2,26,129,232,14,71,29,10,1,7,12,36,76,0,129,0,7,
  16,29,181,3,8,12,36,82,0 };
  
// this structure defines all the variables and events of your control interface 
struct {

    // input variables
  int8_t slider_01; // =-100..100 slider position
  int8_t slider_02; // =-100..100 slider position

    // other variable
  uint8_t connect_flag;  // =1 if wire connected, else =0

} RemoteXY;
#pragma pack(pop)
 
/////////////////////////////////////////////
//           END RemoteXY include          //
/////////////////////////////////////////////



#include<Servo.h>
Servo servo1;
Servo servo2;

 #define motor1 D7
 #define motor2 D8
 int servo1_pos = 90; // Initial position for servo1
int servo2_pos = 90; // Initial position for servo2


void setup() 
{
  RemoteXY_Init (); 
  servo2.attach(motor1);
  servo1.attach(motor2);
  RemoteXY.slider_01 = 0;
  RemoteXY.slider_02 = 0;
  
  // TODO you setup code
  
}

void loop()
{
  RemoteXY_Handler();

  // Map the slider values to servo speed
  int ms1 = map(RemoteXY.slider_01, -100, 100, 1000, 2000); // Adjust the range for speed reduction
  int ms2 = map(RemoteXY.slider_02, -100, 100, 2000, 1000); // Adjust the range for speed reduction

  servo1.writeMicroseconds(ms1);
  servo2.writeMicroseconds(ms2);


}
