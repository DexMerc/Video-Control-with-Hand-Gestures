const int ledPin = 13; // Pin for Led
const int trigger1 = 4; //Input pin of 1st Sesnor
const int echo1 = 5; //Output pin of 1st Sesnor
const int trigger2 = 6; //Input pin of 2nd Sesnor
const int echo2 = 7;//Output pin of 2nd Sensor

float distL = 0;
float distR = 0;
float dist = 0;
float time_taken = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(ledPin, OUTPUT);
  pinMode(trigger1, OUTPUT);
  pinMode(echo1, INPUT);
  pinMode(trigger2, OUTPUT);
  pinMode(echo2, INPUT);
  }


float distance(int trigger, int echo)
//function to calculate the distance between hands and sensors
{
  digitalWrite(trigger, LOW);
  delayMicroseconds(2);
  digitalWrite(trigger, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigger, LOW);
  
  time_taken = pulseIn(echo, HIGH);
  dist= time_taken*0.034/2;
  if (dist>50)  // to avoid too far distance bugs
    dist = 51;
  return dist;
}

void loop() {
  // put your main code here, to run repeatedly:
  distL =  distance(trigger1,echo1); //distance of left sensor
  distR =  distance(trigger2,echo2); //distance of right sensor
  
  
  //Play/Pause
  if ((distL >37 && distR>37) && (distL <50 && distR<50)) //Detect both hands
    {
      Serial.println("Play/Pause"); 
      delay (450); //to accidentaly Play/Pause again
    }
  
  distL =  distance(trigger1,echo1); //distance of left sensor
  distR =  distance(trigger2,echo2); //distance of right sensor

  //Control Modes
  //Lock Left - Control Mode
  if (distL>=15 && distL<=20)
  {
    delay(100); //Hand Hold Time
    distL =  distance(trigger1,echo1); //distance of left sensor
    if (distL>=15 && distL<=20)
    {
      Serial.println("Left Locked");
      digitalWrite(ledPin, HIGH);
      while(distL<=48)
      {
        distL =  distance(trigger1,echo1); //distance of left sensor
        if (distL<12) //Hand pushed in 
        {Serial.println ("Vup"); delay (250);}
        if (distL>20) //Hand pulled out
        {Serial.println ("Vdown"); delay (250);}
      }
      digitalWrite(ledPin, LOW);
    }
  }
  
  //Lock Right - Control Mode
  if (distR>=15 && distR<=20)
  {
    delay(100); //Hand Hold Time
    distR =  distance(trigger2,echo2); //distance of right sensor
    if (distR>=15 && distR<=20)
    {
      Serial.println("Right Locked");
      digitalWrite(ledPin, HIGH);
      while(distR<=48)
      {
        distR =  distance(trigger2,echo2); //distance of right sensor
        if (distR<10) //Right hand pushed in
        {Serial.println ("Rewind"); delay (250);}
        if (distR>20) //Right hand pulled out
        {Serial.println ("Forward"); delay (250);}
      }
      digitalWrite(ledPin, LOW);
    }
  }
  delay(150);
}
