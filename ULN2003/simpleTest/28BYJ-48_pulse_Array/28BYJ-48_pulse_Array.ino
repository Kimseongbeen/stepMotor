int Pin1 = 4; //blue
int Pin2 = 6; //pink
int Pin3 = 7; //yellow
int Pin4 = 8; //orange
int Pin5 = 19; //blue
int Pin6 = 18; //pink
int Pin7 = 5; //yellow
int Pin8 = 17; //orange
int _step = 0;
boolean dir = false; // false=clockwise, true=counter clockwise

int pole1[] ={0,0,0,0, 0,1,1,1, 0};//pole1, 8 step values
int pole2[] ={0,0,0,1, 1,1,0,0, 0};//pole2, 8 step values
int pole3[] ={0,1,1,1, 0,0,0,0, 0};//pole3, 8 step values
int pole4[] ={1,1,0,0, 0,0,0,1, 0};//pole4, 8 step values

int pole5[] ={1,1,0,0, 0,0,0,1, 0};//pole1, 8 step values
int pole6[] ={0,1,1,1, 0,0,0,0, 0};//pole2, 8 step values
int pole7[] ={0,0,0,1, 1,1,0,0, 0};//pole3, 8 step values
int pole8[] ={0,0,0,0, 0,1,1,1, 0};//pole4, 8 step values

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
  delayMicroseconds(400); // Adjust the delay time as needed
  //driveStepperL(_step);
  //delayMicroseconds(400); // Adjust the delay time as needed
 if(_step>7){ 
   _step=0;
 } 
 if(_step<0){ 
   _step=7; 
 }
 //700까지는 돌아가나 토크가 매우 약함, delay(1000) = 1초, delayMicroseconds(1000) = delay(1)
  //delayMicroseconds(800); // Adjust the delay time as needed
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
