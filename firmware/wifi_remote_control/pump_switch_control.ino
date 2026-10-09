/*
   -- New project --
   
   This source code of graphical user interface 
   has been generated automatically by RemoteXY editor.
   To compile this code using RemoteXY library 3.1.10 or later version 
   download by link http://remotexy.com/en/library/
   To connect using RemoteXY mobile app by link http://remotexy.com/en/download/                   
     - for ANDROID 4.13.11 or later version;
     - for iOS 1.10.3 or later version;
    
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
#include <Servo.h>

Servo pump;
#define PIN_SWITCH_01 D0
#define PIN_PUMP D1

// RemoteXY configurate  
#pragma pack(push, 1)
uint8_t RemoteXY_CONF[] =   // 42 bytes
  { 255,1,0,0,0,35,0,17,0,0,0,31,2,106,200,200,84,1,1,1,
  0,2,42,43,23,52,79,18,44,22,1,2,26,31,31,79,78,0,79,70,
  70,0 };
  
// this structure defines all the variables and events of your control interface 
struct {

    // input variables
  uint8_t switch_01; // =1 if switch ON and =0 if OFF

    // other variable
  uint8_t connect_flag;  // =1 if wire connected, else =0

} RemoteXY;
#pragma pack(pop)
 
/////////////////////////////////////////////
//           END RemoteXY include          //
/////////////////////////////////////////////

void setup() 
{
  RemoteXY_Init (); 
  
  pinMode (PIN_SWITCH_01, OUTPUT);
  pinMode (PIN_PUMP, OUTPUT);

  // Initialize the pump servo
  pump.attach(PIN_PUMP);
  
  // TODO you setup code
  
}

void loop() 
{ 
  RemoteXY_Handler ();
  
  digitalWrite(PIN_SWITCH_01, (RemoteXY.switch_01==0)?LOW:HIGH);
  
  // Control the pump motor
  if (RemoteXY.switch_01 == 1) {
    pump.write(180); // Turn the pump motor ON
  } else {
    pump.write(0);   // Turn the pump motor OFF
  }

  // TODO you loop code
  // use the RemoteXY structure for data transfer
  // do not call delay(), use instead RemoteXY_delay() 
}
