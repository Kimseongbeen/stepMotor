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
  switch (_step)
  {
    case 0:
      digitalWrite(Pin1, HIGH);
      digitalWrite(Pin2, LOW);
      digitalWrite(Pin3, LOW);
      digitalWrite(Pin4, LOW);
      
      digitalWrite(Pin5, LOW);
      digitalWrite(Pin6, LOW); 
      digitalWrite(Pin7, LOW);
      digitalWrite(Pin8, HIGH);
      break;
    case 1:
      digitalWrite(Pin1, LOW);
      digitalWrite(Pin2, HIGH);
      digitalWrite(Pin3, LOW);
      digitalWrite(Pin4, LOW);
      
      digitalWrite(Pin5, LOW);
      digitalWrite(Pin6, LOW);
      digitalWrite(Pin7, HIGH);
      digitalWrite(Pin8, LOW);
      break;
    case 2:
      digitalWrite(Pin1, LOW);
      digitalWrite(Pin2, LOW);
      digitalWrite(Pin3, HIGH);
      digitalWrite(Pin4, LOW);
      
      digitalWrite(Pin5, LOW);
      digitalWrite(Pin6, HIGH);
      digitalWrite(Pin7, LOW);
      digitalWrite(Pin8, LOW);
      break;
    case 3:
      digitalWrite(Pin1, LOW);
      digitalWrite(Pin2, LOW);
      digitalWrite(Pin3, LOW);
      digitalWrite(Pin4, HIGH);
      
      digitalWrite(Pin5, HIGH);
      digitalWrite(Pin6, LOW);
      digitalWrite(Pin7, LOW);
      digitalWrite(Pin8, LOW);
      break;
    default:
      digitalWrite(Pin1, LOW);
      digitalWrite(Pin2, LOW);
      digitalWrite(Pin3, LOW);
      digitalWrite(Pin4, LOW);
      
      digitalWrite(Pin5, LOW);
      digitalWrite(Pin6, LOW);
      digitalWrite(Pin7, LOW);
      digitalWrite(Pin8, LOW);
      break;
  }

  if (dir)
  {
    _step++;
  }
  else
  {
    _step--;
  }

  if (_step > 3)
  {
    _step = 0;
  }

  if (_step < 0)
  {
    _step = 3;
  }
 //700까지는 돌아가나 토크가 매우 약함, delay(1000) = 1초, delayMicroseconds(1000) = delay(1)
  delayMicroseconds(2000); // Adjust the delay time as needed
}
