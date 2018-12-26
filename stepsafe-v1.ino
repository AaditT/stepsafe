/***
code modified from SparkFun
***/

/******************************************************************************
MMA8452Q_Basic.ino
SFE_MMA8452Q Library Basic Example Sketch
Jim Lindblom @ SparkFun Electronics
Original Creation Date: June 3, 2014
https://github.com/sparkfun/MMA8452_Accelerometer

This sketch uses the SparkFun_MMA8452Q library to initialize the
accelerometer, and stream values from it.

Hardware hookup:
  Arduino --------------- MMA8452Q Breakout
    3.3V  ---------------     3.3V
    GND   ---------------     GND
  SDA (A4) --\/330 Ohm\/--    SDA
  SCL (A5) --\/330 Ohm\/--    SCL

The MMA8452Q is a 3.3V max sensor, so you'll need to do some 
level-shifting between the Arduino and the breakout. Series
resistors on the SDA and SCL lines should do the trick.

Development environment specifics:
  IDE: Arduino 1.0.5
  Hardware Platform: Arduino Uno
  
  **Updated for Arduino 1.6.4 5/2015**

This code is beerware; if you see me (or any other SparkFun employee) at the
local, and you've found our code helpful, please buy us a round!

Distributed as-is; no warranty is given.
******************************************************************************/


#include <Wire.h>
#include <SparkFun_MMA8452Q.h>


MMA8452Q accel;

void setup()
{
  Serial.begin(9600);

  accel.init();

}

void loop()
{

  if (accel.available())
  {
    // First, use accel.read() to read the new variables:
    accel.read();
    if (accel.cz < 0.85) {
      Serial.println("Warning!");
    }    
  }
}
