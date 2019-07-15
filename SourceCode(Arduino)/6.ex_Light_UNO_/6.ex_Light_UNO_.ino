/****************************************************************************
* Copyright 2019 DS LAB All Rights Reserved.
*
* Filename: 6.ex_Light_UNO_.ino
* Author: sj.yang
* Release date: 2019/07/15
* Version: 1.0
****************************************************************************/
int ADC_PORT_Light = 0;
int PIN_Light = 2;

void setup()
{
  Serial.begin(115200);
  Serial.println();
  Serial.println("HexT Light Sensor Test");
}

void loop()
{
  int ValADC = analogRead(PIN_Light);
  Serial.print("ADC Value of Light Sensor :");
  Serial.println(ValADC);
  delay(1000);
}
