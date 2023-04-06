#include <Servo.h>

Servo myservo;

int trig = 3;
int echo = 4;
 
int led = 9;
int pos = 0;

const int buttonPin = 7;

void setup() {
  Serial.begin(9600);
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);
  pinMode(led, OUTPUT);
  pinMode(buttonPin, INPUT);
  myservo.attach(11);
}
 
void loop() {
  digitalWrite(trig, LOW);
  digitalWrite(echo, LOW);
  delayMicroseconds(2);
  digitalWrite(trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig, LOW);

  int buttonState = digitalRead(buttonPin);
  unsigned long duration = pulseIn(echo, HIGH);
  float distance = duration / 29.0 / 2.0;
  Serial.print(distance);
  Serial.println("cm");

  if (distance < 20) {
    myservo.write(90);  
    delay(20);
    digitalWrite(led, HIGH);
    while (buttonState == HIGH){
      myservo.write(0);
      digitalWrite(led, LOW);
      delay(3000);
      break;
    }
  }
  else {
    myservo.write(0);  
    delay(20);
    digitalWrite(led, LOW);
  }
  delay(200);
}