#define A     2
#define A_EN  3
#define B     4
#define B_EN  5
#define C     6
#define C_EN  7


void setup() {
  pinMode(A,OUTPUT);
  pinMode(A_EN,OUTPUT);
  pinMode(B,OUTPUT);
  pinMode(B_EN,OUTPUT);
  pinMode(C,OUTPUT);
  pinMode(C_EN,OUTPUT);

  digitalWrite(A_EN,LOW);
  digitalWrite(B_EN,LOW);
  digitalWrite(C_EN,LOW);
}

void loop() {
  digitalWrite(B_EN,LOW);
  digitalWrite(A,HIGH);
  digitalWrite(C,LOW);
  digitalWrite(A_EN,HIGH);
  digitalWrite(C_EN,HIGH);
  delay(30);

  digitalWrite(A_EN,LOW);  
  digitalWrite(B,HIGH);
  digitalWrite(C,LOW);
  digitalWrite(B_EN,HIGH);
  digitalWrite(C_EN,HIGH);
  delay(30);
  
  digitalWrite(C_EN,LOW);
  digitalWrite(A,LOW);
  digitalWrite(B,HIGH);
  digitalWrite(A_EN,HIGH);
  digitalWrite(B_EN,HIGH);
  delay(30);

  digitalWrite(B_EN,LOW);
  digitalWrite(A,LOW);
  digitalWrite(C,HIGH);
  digitalWrite(A_EN,HIGH);
  digitalWrite(C_EN,HIGH);
  delay(30);

  digitalWrite(A_EN,LOW);
  digitalWrite(B,LOW);
  digitalWrite(C,HIGH);
  digitalWrite(B_EN,HIGH);
  digitalWrite(C_EN,HIGH);
  delay(30);

  digitalWrite(C_EN,LOW);
  digitalWrite(A,HIGH);
  digitalWrite(B,LOW);
  digitalWrite(A_EN,HIGH);
  digitalWrite(B_EN,HIGH);
  delay(30);
        
}
