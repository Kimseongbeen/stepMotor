#define STEP_DIR_PIN 13
#define STEP_STP_PIN 12
#define STEP_ENA_PIN 14

#define STEP_DELAY_MICROS 1000 // 스텝모터 스텝간 DELAY , 값이 작아질수록 모터는 빨라짐

unsigned long start_millis;

void setup()
{
  pinMode(STEP_DIR_PIN, OUTPUT);
  pinMode(STEP_STP_PIN, OUTPUT);
  pinMode(STEP_ENA_PIN, OUTPUT);
  digitalWrite(STEP_ENA_PIN, HIGH); // 모터 사용 안함
}

void loop()
{
  digitalWrite(STEP_ENA_PIN, LOW); // 모터 사용
  start_millis = millis();
  while ( (millis() - start_millis) < 1000 ) // 1초간 정방향 회전
  {
    digitalWrite(STEP_DIR_PIN, HIGH); // 방향 설정
    digitalWrite(STEP_STP_PIN, HIGH); // STEP 신호 전송
    digitalWrite(STEP_STP_PIN, LOW);
    delayMicroseconds(STEP_DELAY_MICROS);
  }
  start_millis = millis();
  while ( (millis() - start_millis) < 1000 ) // 1초간 역방향 회전
  {
    digitalWrite(STEP_DIR_PIN, LOW); // 방향 설정
    digitalWrite(STEP_STP_PIN, HIGH); // STEP 신호 전송
    digitalWrite(STEP_STP_PIN, LOW);
    delayMicroseconds(STEP_DELAY_MICROS);
  }
}
