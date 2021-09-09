/*
 * 
 * Components:
 *  - 5 x SG90 Servo
 *  - (not in use)PCA9685 16 Channel 12 Bit PWM Servo Motor Driver
 * 
 */

#include <Servo.h>
#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>


#define SERVO_FREQ 50 // Analog servos run at ~50 Hz updates
#define SERVOMIN  110
#define SERVOMAX  510
#define SERVOCOUNT 5

#define delayTime 200
#define servoCount 5
#define servo0Pin 9
#define servo1Pin 10
#define servo0MaxPositioon 175
#define servo1MaxPosition 130
#define servo2MaxPosition 140
#define servo3MaxPosition 130
#define servo4MaxPostion 130
#define servo5MaxPosition 160

Servo servo0;
Servo servo1;

//Adafruit_PWMServoDriver pwmServoDriver = Adafruit_PWMServoDriver();

void setup() {
  Serial.begin(9600);
  servo0.attach(9);
  servo1.attach(10);
//
//  pwmServoDriver.begin();
//  pwmServoDriver.setOscillatorFrequency(27000000);
//  pwmServoDriver.setPWMFreq(SERVO_FREQ);  // Analog servos run at ~50 Hz updates
  delay(10);
}

void loop() {
  goToZero(servo1);
  swingServo(servo1, servo1MaxPosition);
  goToZero(servo1);
  swingServo(servo0, servo1MaxPosition);
//  pwmServoDriver.setPWM(0, 0, SERVOMIN + random(10, 30));
//  delay(1000);

}

void swingServo(Servo servo, int maxPosition) {
  for (int i = 0; i <  maxPosition; i+=5) {
    servo.write(i);
    Serial.println(i);
    delay(delayTime);
  }

  for (int i = maxPosition; i >= 0; i-=5) {
    servo.write(i);
    Serial.println(i);
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

void goToZero(Servo servo) { 
  while (servo.read() > 0) {
    int pinPosition = servo.read();
    pinPosition -= 5;
    servo.write(pinPosition);
    String str = "goToZero at position: " + String(pinPosition);
    Serial.println(str);
    delay(delayTime);
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
