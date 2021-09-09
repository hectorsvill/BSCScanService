/* Mini_Servo_robot_arm
 * by: @hectorsvill
 * 
 * Components:
 *  - 4 x SG90 Servo
 *  - 5v-9v power suply module
 *  - arduino nano
 */

#include <Servo.h>

#define delayTime 50
#define servoCount 4
#define servo0Pin 7
#define servo1Pin 8
#define servo2Pin 9
#define servo3Pin 10
#define servo0MaxPos 175
#define servo1MaxPos 100
#define servo2MaxPos 130
#define servo3MaxPos 180

Servo servo0;
Servo servo1;
Servo servo2;
Servo servo3;

Servo servoList[] = {servo0, servo1, servo2, servo3};
int serMaxPosList[] = {servo0MaxPos, servo1MaxPos, servo2MaxPos, servo3MaxPos};

void setup() {
  Serial.begin(9600);
  servo0.attach(servo0Pin);
  servo1.attach(servo1Pin);
  servo2.attach(servo2Pin);
  servo3.attach(servo3Pin);
  delay(1000);
}

void loop() {
  int ran = random(0, servoCount);
  readServoPositions();
  Serial.println(ran);
  Servo servo = servoList[ran];
  goToZero(servo);
  swingServo(servo, random(15,serMaxPosList[ran]));
}

int *readServoPositions() {
  int arr[4] = {};
  
  for (int i = 0; i < servoCount; i++) {
    arr[i] = servoList[i].read();
  }
  
  String str = "Servo 0:" + String(arr[0]) + " Servo 1:" + String(arr[1]) + " Servo 2:" + String(arr[2]) + " Servo 3:" + String(arr[3]);
  Serial.println(str);
  return arr;
}

void swingServo(Servo servo, int maxPosition) {
  for (int i = 0; i <  maxPosition; i+=5) {
    servo.write(i);
//    Serial.println(i);
    delay(delayTime);
  }

  for (int i = maxPosition; i >= 0; i-=5) {
    servo.write(i);
//    Serial.println(i);
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
//    Serial.println(str);
    
    if (pinPosition < 0) {
      pinPosition = 0;
    }
    
    delay(delayTime);
  }
}
