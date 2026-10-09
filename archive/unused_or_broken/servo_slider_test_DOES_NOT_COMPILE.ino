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
#define REMOTEXY_MODE__SOFTSERIAL
#include <SoftwareSerial.h>


// RemoteXY connection settings 
#define REMOTEXY_SERIAL_RX 2
#define REMOTEXY_SERIAL_TX 3
#define REMOTEXY_SERIAL_SPEED 9600
#define REMOTEXY_ACCESS_PASSWORD "YOUR_ACCESS_PASSWORD"


#include <RemoteXY.h>

// RemoteXY configurate  
#pragma pack(push, 1)
uint8_t RemoteXY_CONF[] =   // 33 bytes
  { 255,1,0,0,0,26,0,17,0,0,0,36,2,106,200,200,84,1,1,1,
  0,4,49,47,7,86,163,246,25,92,0,2,26 };
  
// this structure defines all the variables and events of your control interface 
struct {

    // input variables
  int8_t slider_01; // =0..100 slider position

    // other variable
  uint8_t connect_flag;  // =1 if wire connected, else =0

} RemoteXY;
#pragma pack(pop)
 
/////////////////////////////////////////////
//           END RemoteXY include          //
/////////////////////////////////////////////



#include <Servo.h>

Servo Servo1;
Servo Servo2;


void setup() {
  RemoteXY_Init ();
  Servo1.attach();
  Servo2.attach();
  RemoteXY.slider_01=50;

}


void loop() {
  RemoteXY_Handler ();
  int ms = RemoteXY.slider_01*20+500
  Servo1.writeMicroseconds(ms);
  Servo2.writeMicroseconds(ms);
}
