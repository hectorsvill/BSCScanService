
#include <Servo.h>

int delayTime = 50;
int servoPin = 9;
int servoPosition=0;

int servoMaxPosition = 60;

int servo1MaxPosition = 170;
int servo2MaxPosition = 140;
int servo3MaxPosition = 130;

Servo servo1;

void setup() {
  Serial.begin(9600);
  servo1.attach(servoPin);
}

void loop() {
//  servo1.write(0);
  int maxPosition = servoMaxPosition;
  
  for (int i = 0; i <  maxPosition; i+=1) {
    servo1.write(i);
    Serial.println(i);
    delay(delayTime);
  }

  for (int i = maxPosition; i >= 0; i-=1) {
    servo1.write(i);
    Serial.println(i);
    delay(delayTime);
  }
}

void randomPosition() {
  int num = random(0, 170);
  Serial.println(num);
  servo1.write(num);  
  delay(250);
}
void checkServoRadius() {
  servo1.write(0);
  if (servo1.read()  < servoMaxPosition) {
    servo1.write(servoPosition);
    servoPosition += 10;
    delay(delayTime);
  } 
}
