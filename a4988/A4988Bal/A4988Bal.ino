// Define pin connections & motor's steps per revolution
const int dirPin = 35; //스테퍼 모터의 방향과
const int stepPin = 36; // 단계 신호를 제어하는 핀
const int stepsPerRevolution = 1200; //모터의 한 번 회전할 때의 단계 수 거리라고 생각하면 된다

void setup() {
  // Declare pins as Outputs
  pinMode(stepPin, OUTPUT);
  pinMode(dirPin, OUTPUT);
}
void loop() {
  // Set motor direction clockwise
  digitalWrite(dirPin, HIGH); //시계 반대 방향

  // Spin motor slowly
  for (int x = 0; x < stepsPerRevolution; x++) {
    digitalWrite(stepPin, HIGH);
    delayMicroseconds(500);
    digitalWrite(stepPin, LOW);
    delayMicroseconds(500);
  }
  delay(1000); // Wait a second

  // Set motor direction counterclockwise
  digitalWrite(dirPin, LOW); //시계 방향

  // Spin motor quickly
  for (int x = 0; x < stepsPerRevolution; x++) {
    digitalWrite(stepPin, HIGH);
    delayMicroseconds(4000);
    digitalWrite(stepPin, LOW);
    delayMicroseconds(4000); //숫자 높을수록 느림
  }
  delay(1000); // Wait a second
}
