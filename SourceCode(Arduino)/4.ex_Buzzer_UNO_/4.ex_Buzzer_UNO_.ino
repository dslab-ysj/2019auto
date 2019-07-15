/****************************************************************************
* Copyright 2019 DS LAB All Rights Reserved.
*
* Filename: 4.ex_Buzzer_UNO_.ino
* Author: sj.yang
* Release date: 2019/07/15
* Version: 1.0
****************************************************************************/
int BUZZER_PWM = 6;
int note[] = {2093,2349,2637,2793,3136,3520,3951,4186};

void setup()
{
  pinMode(BUZZER_PWM, OUTPUT);
}

void loop()
{
  for (int i=0; i < 8; i++)
  {
    tone(BUZZER_PWM,note[i],500);
    delay(750);
  }
}
