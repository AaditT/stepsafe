/******************************************************************************

Hardware hookup:
  Arduino --------------- MMA8452Q Breakout
    3.3V  ---------------     3.3V
    GND   ---------------     GND
  SDA (A4) --\/330 Ohm\/--    SDA
  SCL (A5) --\/330 Ohm\/--    SCL

******************************************************************************/
#include <Wire.h>
#include <SparkFun_MMA8452Q.h>

MMA8452Q accel;

void setup()
{
  Serial.begin(9600);
  accel.init();
}

int risk20 = 0;
int risk40 = 0;
int risk60 = 0;
int risk80 = 0;
int risk100 = 0;
int totalRisk;
int riskAv;

void loop()
{
  if (accel.available())
  {
    accel.read();
    if (0.85 < accel.cz && accel.cz <= 1) {
      Serial.println("0% Danger!");
    } else if (0.68 < accel.cz && accel.cz <= 0.85) {
      Serial.println("20% Danger!");
      risk20++;
    } else if (0.51 < accel.cz && accel.cz <= 0.68) {
      Serial.println("40% Danger!");
      risk40++;
    } else if (0.34 < accel.cz && accel.cz <= 0.51) {
      Serial.println("60% Danger!");
      risk60++;
    } else if (17 < accel.cz && accel.cz <= 0.34) {
      Serial.println("80% Danger!");
      risk80++;
    } else if (0 < accel.cz && accel.cz <= 0.17) {
      Serial.println("100% Danger!");
      risk100++;
    }  
  }
}

int riskAverage()
{
  totalRisk = risk20 + risk40 + risk60 + risk80 + risk100;
  risk20 = 20 * risk20;
  risk40 = 40 * risk40;
  risk60 = 60 * risk60;
  risk80 = 80 * risk80;
  risk100 = 100 * risk100;
  riskAv = (risk20 + risk40 + risk60 + risk80 + risk100)/totalRisk;
  return riskAv;
}
