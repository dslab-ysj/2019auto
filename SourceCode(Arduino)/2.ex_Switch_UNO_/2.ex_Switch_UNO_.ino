/****************************************************************************
* Copyright 2019 DS LAB All Rights Reserved.
*
* Filename: 2.ex_Switch_UNO_.ino
* Author: sj.yang
* Release date: 2019/07/15
* Version: 1.0
****************************************************************************/
int PORT_LED = 0;
int PORT_SWI = 1;

int PIN_RED = 2;
int PIN_GRE = 4;

int PIN_SWL = 7;
int PIN_SWR = 8;

void setup()
{
  pinMode(PIN_SWL, INPUT);
  pinMode(PIN_SWR, INPUT);
  pinMode(PIN_RED, OUTPUT);
  pinMode(PIN_GRE, OUTPUT);
}

void loop()
{
  digitalWrite(PIN_RED,digitalRead(PIN_SWL));
  digitalWrite(PIN_GRE,digitalRead(PIN_SWR));
}
