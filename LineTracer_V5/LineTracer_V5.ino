/* Actuator : NP01D-48
 *  Motor Driver : SZH-MDBL-010
 *                    |  IN1  |  IN2  |  IN3  |  IN4  |
 * ------------------------------------------------------
 * Motor A | Forward  | 1/pwm |   0   |       |       |
 * (LEFT)  | Backward |   0   | 1/pwm |       |       |
 *         | Standby  |   0   |   0   |       |       |
 *         | Brake    |   1   |   1   |       |       |
 * ------------------------------------------------------
 * Motor B | Forward  |       |       | 1/pwm |   0   |
 * (RIGHT) | Backward |       |       |   0   | 1/pwm |
 *         | Standby  |       |       |   0   |   0   |
 *         | Brake    |       |       |   1   |   1   |
*/

/*
 * PORT   | PINs  | BOARD 
 * ------------------------------------------------------
 * GPIO 0 | D2,D4 | HexT Switch
 * GPIO 1 | D7,D8 | HexT LED
 * ADC  0 | A0,A1 | HexT IR Sensor(L)
 * ADC  1 | A2,A3 | HexT IR Sensor(R)
*/

/*
 * Pin |      Role       |
 * -----------------------
 *  2  | Switch Input(L) |
 *  3  |      NONE       |
 *  4  | Switch Input(R) |
 *  5  |  Motor IN 1 (L) |
 *  6  |  Motor IN 2 (L) |
 *  7  |     LED RED     |
 *  8  |    LED GREEN    |
 *  9  |  Motor IN 3 (R) |
 *  10 |  Motor IN 4 (R) |
 *  A0 |  IR Sensor (L)  |
 *  A1 |      NONE       |
 *  A2 |  IR Sensor (R)  |
 *  A3 |      NONE       |
 */

int SW_L = 2;
int SW_R = 4;
int Motor_A_Forward = 5;  // IN1
int Motor_A_Backward = 6; // IN2
int LED_RED = 7;
int LED_GRE = 8;
int Motor_B_Forward = 9;  // IN3
int Motor_B_Backward = 10; // IN4
int IR_L = A0;
int IR_R = A2;

int SPEED = 120;

void GoForward()
{
  analogWrite(Motor_A_Forward,SPEED);
  analogWrite(Motor_A_Backward,LOW);
  analogWrite(Motor_B_Forward,LOW);
  analogWrite(Motor_B_Backward,SPEED);
}
void GoBackward()
{
  analogWrite(Motor_A_Forward,LOW);
  analogWrite(Motor_A_Backward,SPEED);
  analogWrite(Motor_B_Forward,SPEED);
  analogWrite(Motor_B_Backward,LOW);
}

void TurnRight()
{
  analogWrite(Motor_A_Forward,SPEED);
  analogWrite(Motor_A_Backward,LOW);
  analogWrite(Motor_B_Forward,SPEED-20);
  analogWrite(Motor_B_Backward,LOW);
}

void TurnLeft()
{
  analogWrite(Motor_A_Forward,LOW);
  analogWrite(Motor_A_Backward,SPEED-20);
  analogWrite(Motor_B_Forward,LOW);
  analogWrite(Motor_B_Backward,SPEED);
}
void MotorStop()
{
  digitalWrite(Motor_A_Forward,HIGH);
  digitalWrite(Motor_A_Backward,HIGH);
  digitalWrite(Motor_B_Forward,HIGH);
  digitalWrite(Motor_B_Backward,HIGH);
}

void setup() 
{
  pinMode(SW_L,INPUT); // digital pin 2
  pinMode(SW_R,INPUT); // digital pin 4
  pinMode(LED_RED,OUTPUT); // digital pin 7
  pinMode(LED_GRE,OUTPUT); // digital pin 8
  pinMode(Motor_A_Forward,OUTPUT);  // digital pin 5 (PWM)
  pinMode(Motor_A_Backward,OUTPUT); // digital pin 6 (PWM)
  pinMode(Motor_B_Forward,OUTPUT);  // digital pin 9 (PWM)
  pinMode(Motor_B_Backward,OUTPUT); // digital pin 10(PWM)
  pinMode(IR_L, INPUT); // analog pin a0
  pinMode(IR_R, INPUT); // analog pin a1

  MotorStop();
}

void loop() 
{
  digitalWrite(LED_RED,HIGH);
  digitalWrite(LED_GRE,LOW);
  MotorStop();
  while(!digitalRead(SW_R));
 
  digitalWrite(LED_RED,LOW);
  digitalWrite(LED_GRE,HIGH);
  while(!digitalRead(SW_L))
  {
    int LineVal=300;
    int LeftSensor = analogRead(IR_L); 
    int RightSensor = analogRead(IR_R); 

    if (LeftSensor<LineVal && RightSensor>LineVal) TurnLeft();
    else if(LeftSensor>LineVal && RightSensor<LineVal) TurnRight();
    else if (LeftSensor>LineVal && RightSensor<LineVal) GoForward();
    else {MotorStop();}
  }
}
