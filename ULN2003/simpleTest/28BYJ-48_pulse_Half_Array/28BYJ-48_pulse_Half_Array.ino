int Pin1 = 4; //blue R
int Pin2 = 6; //pink
int Pin3 = 7; //yellow
int Pin4 = 8; //orange
int Pin5 = 19; //blue L
int Pin6 = 18; //pink
int Pin7 = 5; //yellow
int Pin8 = 17; //orange
int _step = 0;
boolean dir = false; // false=clockwise, true=counter clockwise
//{pink,yellow,orange,blue}(i2r) > {blue,pink,yellow,orange}(google)
//0010,1000,0001,0100 > 0001,0100,1000,0010
//1000 0010 0100 0001 >
int pole1[] = {1, 0, 0, 0}; // pole5, 4 step values 1000
int pole2[] = {0, 1, 0, 0}; // pole6, 4 step values 0100
int pole3[] = {0, 0, 1, 0}; // pole7, 4 step values 0010
int pole4[] = {0, 0, 0, 1}; // pole8, 4 step values 0001

//int pole5[] = {1, 0, 0, 0}; // pole5, 4 step values 0001
//int pole6[] = {0, 1, 0, 0}; // pole6, 4 step values 0010
//int pole7[] = {0, 0, 1, 0}; // pole7, 4 step values 0100
//int pole8[] = {0, 0, 0, 1}; // pole8, 4 step values 1000
int pole5[] = {0, 0, 0, 1}; // pole5, 4 step values 0001
int pole6[] = {0, 0, 1, 0}; // pole6, 4 step values 0010
int pole7[] = {0, 1, 0, 0}; // pole7, 4 step values 0100
int pole8[] = {1, 0, 0, 0}; // pole8, 4 step values 1000
void setup()
{
  pinMode(Pin1, OUTPUT);
  pinMode(Pin2, OUTPUT);
  pinMode(Pin3, OUTPUT);
  pinMode(Pin4, OUTPUT);
  pinMode(Pin5, OUTPUT);
  pinMode(Pin6, OUTPUT);
  pinMode(Pin7, OUTPUT);
  pinMode(Pin8, OUTPUT);  
}

void loop()
{
  // 전진
  _step++;
  driveStepperR(_step);
  delayMicroseconds(1000); // Adjust the delay time as needed 
  driveStepperL(_step);
  delayMicroseconds(1000); // Adjust the delay time as needed
 if(_step>3){ 
   _step=0;
 } 
 if(_step<0){ 
   _step=3; 
 }
 //700까지는 돌아가나 토크가 매우 약함, delay(1000) = 1초, delayMicroseconds(1000) = delay(1)
    //delayMicroseconds(1200); // Adjust the delay time as needed
  //delayMicroseconds(1000); // Adjust the delay time as needed
}

void driveStepperR(int c)
{
     digitalWrite(Pin1, pole1[c]);  
     digitalWrite(Pin2, pole2[c]); 
     digitalWrite(Pin3, pole3[c]); 
     digitalWrite(Pin4, pole4[c]); 
}//driveStepper end here

void driveStepperL(int c)
{
     digitalWrite(Pin5, pole5[c]);  
     digitalWrite(Pin6, pole6[c]); 
     digitalWrite(Pin7, pole7[c]); 
     digitalWrite(Pin8, pole8[c]);  
}//driveStepper end here
