/****************************************************************************
* Copyright 2019 DS LAB All Rights Reserved.
*
* Filename: 1.ex_LED(UNO).ino
* Author: sj.yang
* Release date: 2019/07/15
* Version: 1.0
****************************************************************************/
int PORT_LED = 0;
int PIN_RED = 2;
int PIN_GRE = 4;

void setup()
{
  pinMode(PIN_RED, OUTPUT);
  pinMode(PIN_GRE, OUTPUT);
}

void loop()
{
  digitalWrite(PIN_RED, HIGH);
  digitalWrite(PIN_GRE, LOW);
  delay(1000);
  
  digitalWrite(PIN_RED, LOW);
  digitalWrite(PIN_GRE, HIGH);  
  delay(1000);
}
