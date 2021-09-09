/*
 * 
 * Components:
 *  - 5 x SG90 Servo
 *  - PCA9685 16 Channel 12 Bit PWM Servo Motor Driver
 * 
 */

#include <Servo.h>
#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>


#define SERVO_FREQ 50 // Analog servos run at ~50 Hz updates
#define SERVOMIN  110
#define SERVOMAX  510
#define SERVOCOUNT 5
Servo servo1;
Adafruit_PWMServoDriver pwmServoDriver = Adafruit_PWMServoDriver();

int delayTime = 500;
int servoPin = 9;
int servoPosition=0;
int servoMaxPosition = 180;
int servo1MaxPosition = 170;
int servo2MaxPosition = 140;
int servo3MaxPosition = 130;

// our servo # counter
uint8_t servonum = 0;

void setup() {
  Serial.begin(9600);
  servo1.attach(servoPin);
//
//  pwmServoDriver.begin();
//  pwmServoDriver.setOscillatorFrequency(27000000);
//  pwmServoDriver.setPWMFreq(SERVO_FREQ);  // Analog servos run at ~50 Hz updates
  delay(10);
}

void loop() {
  goToZero(servo1);
  servo1.write(servoMaxPosition);
  delay(delayTime);
  
//  Serial.println(servonum);
//  pwmServoDriver.setPWM(0, 0, SERVOMIN + random(10, 30));
//  delay(1000);

//  int maxPosition = servoMaxPosition;
//  
//  for (int i = 0; i <  maxPosition; i+=1) {
////    servo1.write(i);
//    pwmServoDriver.setPWM(0, 0, angleToPulse(i));
//    Serial.println(i);
//    delay(delayTime);
//  }
//
//  for (int i = maxPosition; i >= 0; i-=1) {
////    servo1.write(i);
//    pwmServoDriver.setPWM(0, 0, angleToPulse(i));
//    Serial.println(i);
//    delay(delayTime);
//  }
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

void goToZero(Servo servo) {
  
  
  while (servo.read() > 0) {
    int pinPosition = servo.read();
    pinPosition -= 5;
    servo.write(pinPosition);
    String str = "goToZero at position: " + String(pinPosition);
    Serial.println(str);
    delay(100);
    if (pinPosition < 0) {
      pinPosition = 0;
    }
  }
}

int angleToPulse(int angle) {
  int pulse = map(angle, 0, 180,SERVOMIN, SERVOMAX);
  String infoStr = "angle" + String(angle) + "pulse" + String(pulse);
  Serial.println(infoStr);
  return pulse; 
}
