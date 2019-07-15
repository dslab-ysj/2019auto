/****************************************************************************
* Copyright 2019 DS LAB All Rights Reserved.
*
* Filename: 7.ex_Temp_UNO_.ino
* Author: sj.yang
* Release date: 2019/07/15
* Version: 1.0
****************************************************************************/
int ADC_PORT_Temp = 0;
int PIN_Temp = 0;

void setup()
{
  Serial.begin(115200);
  Serial.println();
  Serial.println("HexT Temp. Sensor Test");
}

void loop()
{
  float ValTemp = analogRead(PIN_Temp);
  ValTemp = ValTemp * 500/1023-50;
  Serial.print("Current Temp :");
  Serial.print(ValTemp,2);
  Serial.println(" C");
  delay(1000);
}
