// C++ code
//
int GreenPort = 10;
int YellowPort = 9;
int RedPort = 8;
int timeSleepGREEN = 7000; 
int timeSleepYELLOW = 2000;
int timeSleepRED = 15000;

void setup()
{
 pinMode(GreenPort, OUTPUT);
 pinMode(YellowPort, OUTPUT);
 pinMode(RedPort, OUTPUT);
}
void pisca(int porta, int time){
  digitalWrite(porta,HIGH);
  delay(time);
  digitalWrite(porta,LOW);

}

void loop()
{
  pisca(GreenPort,timeSleepGREEN);
  pisca(YellowPort ,timeSleepYELLOW);
  pisca(RedPort ,timeSleepRED);	
}
