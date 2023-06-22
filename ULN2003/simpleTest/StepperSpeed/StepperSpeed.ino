#include <Stepper.h>

// 스텝 모터의 한 회전 당 스텝 수 정의
#define STEPS_PER_MOTOR_REVOLUTION 32  
#define STEPS_PER_OUTPUT_REVOLUTION 32  // 이 값은 모터에 따라 다릅니다.

// ULN2003A 드라이버 모듈의 핀 정의
#define IN1  19
#define IN2  18
#define IN3  5
#define IN4  17

// Stepper 라이브러리 설정
Stepper stepper(STEPS_PER_MOTOR_REVOLUTION, IN1, IN3, IN2, IN4);

void setup() {
  // 회전 속도 설정 (rpm)
  stepper.setSpeed(120);
}

void loop() {
  // 한 바퀴 회전
  stepper.step(STEPS_PER_OUTPUT_REVOLUTION);
  delay(1000);

  // 반대 방향으로 한 바퀴 회전
  stepper.step(-STEPS_PER_OUTPUT_REVOLUTION);
  delay(1000);
}
