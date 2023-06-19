// Define pin connections & motor's steps per revolution
const int dirPin = 35; //스테퍼 모터의 방향과
const int stepPin = 36; // 단계 신호를 제어하는 핀
const int stepsPerRevolution = 200; //모터의 한 번 회전할 때의 단계 수
int customDelay, customDelayMapped; // 변수 정의
void setup() {
pinMode ( stepPin, OUTPUT ) ;
pinMode ( dirPin, OUTPUT ) ;
 
digitalWrite ( dirPin, HIGH ) ; // 모터가 특정 방향으로 이동하도록합니다.
}
void loop() {
 customDelayMapped = speedUp () ; // 사용자 정의 speedUp 함수에서 사용자 정의 지연 값을 가져옵니다.
// 모터의 속도가 의존하는 전위차계에 따라 사용자 지정 지연으로 풀을 만듭니다.
digitalWrite ( stepPin, HIGH ) ;
delayMicroseconds ( customDelayMapped ) ;
digitalWrite ( stepPin, LOW ) ;
delayMicroseconds ( customDelayMapped ) ;
}// 전위차계를 읽는 기능
int speedUp () {  
int customDelay = analogRead ( A0 ) ; // 전위차계를 읽습니다.
int newCustom = map( customDelay, 0, 1023, 300,4000 ) ; // 0에서 1023까지의 전위차계 읽기 값을 원하는 지연 값 (300에서 4000)으로 변환합니다.
return newCustom; 
}
