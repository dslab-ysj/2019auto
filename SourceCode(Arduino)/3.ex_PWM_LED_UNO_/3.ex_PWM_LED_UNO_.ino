/****************************************************************************
* Copyright 2019 DS LAB All Rights Reserved.
*
* Filename: 3.ex_PWM_LED_UNO_.ino
* Author: sj.yang
* Release date: 2019/07/15
* Version: 1.0
****************************************************************************/
#define MAX_PWM 255

int PORT_LED_PWM = 0;
int PIN_RED_PWM = 3;
int PIN_GRE_PWM = 5;

void setup()
{
  pinMode(PIN_RED_PWM, OUTPUT);
  pinMode(PIN_GRE_PWM, OUTPUT);
}

void loop()
{
  int i=0;
  
  for(i = 0; i < MAX_PWM; i++)
  { // 255번 * 20ms -> 약 5s
    analogWrite(PIN_RED_PWM,i);
    analogWrite(PIN_GRE_PWM,i);
    delay(20);   
  }
  for(i = MAX_PWM; i > 0; i--)
  {
    analogWrite(PIN_RED_PWM,i);
    analogWrite(PIN_GRE_PWM,i);
    delay(20);   
  }
}
