// Include the AccelStepper Library
#include <AccelStepper.h>

// Define pin connections & motor's steps per revolution
const int dirPin = 35; //스테퍼 모터의 방향과
const int stepPin = 36; // 단계 신호를 제어하는 핀
const int stepsPerRevolution = 200; //모터의 한 번 회전할 때의 단계 수

// Define motor interface type
#define motorInterfaceType 1

// Creates an instance
AccelStepper myStepper(motorInterfaceType, stepPin, dirPin);
int AccelState = 0;
bool hasCompletedRoundTrip = false; // This variable will keep track of whether a round trip is completed

void setup() {
  // Declare pins as Outputs
  pinMode(stepPin, OUTPUT);
  pinMode(dirPin, OUTPUT);
  myStepper.setMaxSpeed(1000); //설정 기능에서 모터의 최대 허용 속도는 1000으로 설정됩니다(모터를 실행할 때 모터는 이 속도까지 가속됩니다).
  myStepper.setAcceleration(50); //목표위치로 이동하기위해 얼마나 빨리 가속할지 결정
  myStepper.setSpeed(200); // 초기 속도를 200단계/초
  myStepper.moveTo(200); //특정위치로 이동시키는데 사용
}
void loop() {
  if(AccelState ==0){
  // Set motor direction clockwise
  digitalWrite(dirPin, HIGH); //시계 방향

  // Spin motor slowly
  for (int x = 0; x < stepsPerRevolution; x++) {
    digitalWrite(stepPin, HIGH);
    delayMicroseconds(1000);
    digitalWrite(stepPin, LOW);
    delayMicroseconds(1000);
  }
  delay(100); // Wait a second

  // Set motor direction counterclockwise
  digitalWrite(dirPin, LOW); //시계 방향

  // Spin motor quickly
  for (int x = 0; x < stepsPerRevolution; x++) {
    digitalWrite(stepPin, HIGH);
    delayMicroseconds(500);
    digitalWrite(stepPin, LOW);
    delayMicroseconds(500);
  }
  AccelState = 1;
}
  if(AccelState == 1){
    // Change direction once the motor reaches target position
    if (myStepper.distanceToGo() == 0) { //목표 위치 도달
      myStepper.moveTo(-myStepper.currentPosition()); //방향 반대로 변경
      if (hasCompletedRoundTrip) {
        AccelState = 0;
        hasCompletedRoundTrip = false;  // Reset for the next round trip
      } else {
        hasCompletedRoundTrip = true;  // First half of the round trip completed
      }
    }
    // Move the motor one step
    myStepper.run();
  }
  delay(100); // Wait a second
}
