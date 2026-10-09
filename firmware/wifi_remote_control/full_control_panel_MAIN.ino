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

// RemoteXY configurate  
#pragma pack(push, 1)
uint8_t RemoteXY_CONF[] =   // 114 bytes
  { 255,5,0,0,0,107,0,17,0,0,0,31,2,106,200,200,84,1,1,7,
  0,2,42,43,23,52,82,1,37,17,1,2,26,31,31,79,78,0,79,70,
  70,0,4,3,38,7,86,8,247,22,101,48,2,26,4,5,239,12,214,176,
  248,23,101,48,2,26,4,23,36,7,86,43,1,17,72,16,2,26,4,24,
  7,9,171,142,2,17,72,16,2,26,129,240,26,71,29,32,8,7,12,36,
  76,0,129,12,24,16,29,166,10,8,12,36,82,0 };
  
// this structure defines all the variables and events of your control interface 
struct {

    // input variables
  uint8_t switch_01; // =1 if switch ON and =0 if OFF
  int8_t slider_01; // =-100..100 slider position
  int8_t slider_02; // =-100..100 slider position
  int8_t slider_03; // =0..100 slider position
  int8_t slider_04; // =0..100 slider position

    // other variable
  uint8_t connect_flag;  // =1 if wire connected, else =0

} RemoteXY;
#pragma pack(pop)
 
/////////////////////////////////////////////
//           END RemoteXY include          //
/////////////////////////////////////////////

#define PIN_SWITCH_01 D0


#include<Servo.h>
Servo servo1;
Servo servo2;
Servo bushmotor1;
Servo bushmotor2;
Servo pump;

#define PIN_PUMP D1
#define motor1 D7
#define motor2 D8
#define motor1_pin D4
#define motor2_pin D3

void setup() {
  RemoteXY_Init();
  servo2.attach(motor1);
  servo1.attach(motor2);
  bushmotor1.attach(motor1_pin);
  bushmotor2.attach(motor2_pin);
  pump.attach(PIN_PUMP);

  pinMode(PIN_SWITCH_01, OUTPUT);
  pinMode(PIN_PUMP, OUTPUT);
}

void loop() {
  RemoteXY_Handler();

  // Control the switch
  digitalWrite(PIN_SWITCH_01, RemoteXY.switch_01 ? HIGH : LOW);

  // Control the pump motor
  pump.write(RemoteXY.switch_01 ? 180 : 0);

  // Map the slider values to servo speed
  int ms1 = map(RemoteXY.slider_01, -100, 100, 1000, 2000);
  int ms2 = map(RemoteXY.slider_02, -100, 100, 2000, 1000);

  // Map the slider values to motor speed
  int motor1_speed = map(RemoteXY.slider_03, 0, 100, 1000, 2000);
  int motor2_speed = map(RemoteXY.slider_04, 0, 100, 1000, 2000);
  servo1.writeMicroseconds(ms1);
  servo2.writeMicroseconds(ms2);
  bushmotor1.writeMicroseconds(motor1_speed);
  bushmotor2.writeMicroseconds(motor2_speed);
}