int PinBlue = 4; // blue R = PC3 (B,P,Y,O) 0100,0001,0010, 1000 / 0100,1000,0010,0001
int PinPink = 6; // pink = PC0     0001,0100,1000,0010
int PinYello = 7; // yellow = PC1
int PinOrange = 8; // orange = PC4
 int delaytime = 2;
   
void setup()
{
  pinMode(PinBlue, OUTPUT);
  pinMode(PinPink, OUTPUT);
  pinMode(PinYello, OUTPUT);
  pinMode(PinOrange, OUTPUT);
}

void loop()
{
  portC(0x08); // pin1 = 0, pin2 = 1, pin3 = 0, pin4 = 0 0001
  delay(delaytime);

  portC(0x04); // pin1 = 0, pin2 = 0, pin3 = 0, pin4 = 1 0010
  delay(delaytime);

  portC(0x02); // pin1 = 0, pin2 = 0, pin3 = 1, pin4 = 0 0100
  delay(delaytime);

  portC(0x01); // pin1 = 0, pin2 = 0, pin3 = 0, pin4 = 1 1000
  delay(delaytime);
    
//  portC(0x02); // pin1 = 0, pin2 = 1, pin3 = 0, pin4 = 0 0100
//  delay(100);
//
//  portC(0x08); // pin1 = 0, pin2 = 0, pin3 = 0, pin4 = 1
//  delay(100);
//
//  portC(0x04); // pin1 = 0, pin2 = 0, pin3 = 1, pin4 = 0
//  delay(100);
//
//  portC(0x01); // pin1 = 0, pin2 = 0, pin3 = 0, pin4 = 1
//  delay(100);

}

void portC(byte x)
{
  byte pinByte = x;
  digitalWrite(PinBlue, (pinByte & 0x01));
  digitalWrite(PinPink, (pinByte & 0x02));
  digitalWrite(PinYello, (pinByte & 0x04));
  digitalWrite(PinOrange, (pinByte & 0x08));
}
