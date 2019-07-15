/****************************************************************************
* Copyright 2019 DS LAB All Rights Reserved.
*
* Filename: 5.ex_IR_UNO_.ino
* Author: sj.yang
* Release date: 2019/07/15
* Version: 1.0
****************************************************************************/
int ADC_PORT_IR = 0;
int PIN_IR = 0;

void setup()
{
  Serial.begin(115200);
  Serial.println();
  Serial.println("HexT IR Sensor Test");
}

void loop()
{
  int ValADC = analogRead(PIN_IR);
  Serial.print("ADC Value of IR Sensor :");
  Serial.println(ValADC);
  delay(1000);
}
