//initialize pins
const int pingPin[] = {2,3,4,5,6,7};

//initialize variables
long duration, cm;

void setup() 
{
  // initialize serial communication
  Serial.begin(9600);
}

void loop() 
{
	Serial.println(getLocation());
}

//return method that deals with converint the duration (in microseconds)
//to cm.
long durationToCentimeters(long duration) 
{
  return duration/29/2;
}

//Return method that deals with getting a value from the first sensor
long sensorOne()
{
  //Clears the trigPin
  pinMode(pingPin[0], OUTPUT);
  digitalWrite(pingPin[0], LOW);
  delayMicroseconds(2);

  //Sets the Pin on HIGH state for 5 micro seconds
  digitalWrite(pingPin[0], HIGH);
  delayMicroseconds(5);
  digitalWrite(pingPin[0], LOW);

  //this same pin is used for input 
  pinMode(pingPin[0], INPUT);
  duration = pulseIn(pingPin[0], HIGH);
	
  cm = durationToCentimeters(duration);
  
  if(cm<300)
  {
    return 1;
  }
  else
  {
    return 300;
  }
}

//Return method that deals with getting a value from the second sensor
long sensorTwo()
{
  //Clears the trigPin
  pinMode(pingPin[1], OUTPUT);
  digitalWrite(pingPin[1], LOW);
  delayMicroseconds(2);

  //Sets the Pin on HIGH state for 5 micro seconds
  digitalWrite(pingPin[1], HIGH);
  delayMicroseconds(5);
  digitalWrite(pingPin[1], LOW);

  //this same pin is used for input 
  pinMode(pingPin[1], INPUT);
  duration = pulseIn(pingPin[1], HIGH);
	
  cm = durationToCentimeters(duration);
  
  if(cm<300)
  {
    return 2;
  }
  else
  {
    return 300;
  }
}

//Return method that deals with getting a value from the third sensor
long sensorThree()
{
  //Clears the trigPin
  pinMode(pingPin[2], OUTPUT);
  digitalWrite(pingPin[2], LOW);
  delayMicroseconds(2);

  //Sets the Pin on HIGH state for 5 micro seconds
  digitalWrite(pingPin[2], HIGH);
  delayMicroseconds(5);
  digitalWrite(pingPin[2], LOW);

  //this same pin is used for input 
  pinMode(pingPin[2], INPUT);
  duration = pulseIn(pingPin[2], HIGH);
	
  cm = durationToCentimeters(duration);
  
  if(cm<300)
  {
    return 3;
  }
  else
  {
    return 300;
  }
}

//Return method that deals with getting a value from the fourth sensor
long sensorFour()
{
  //Clears the trigPin
  pinMode(pingPin[3], OUTPUT);
  digitalWrite(pingPin[3], LOW);
  delayMicroseconds(2);

  //Sets the Pin on HIGH state for 5 micro seconds
  digitalWrite(pingPin[3], HIGH);
  delayMicroseconds(5);
  digitalWrite(pingPin[3], LOW);

  //this same pin is used for input 
  pinMode(pingPin[3], INPUT);
  duration = pulseIn(pingPin[3], HIGH);
	
  cm = durationToCentimeters(duration);
  
  if(cm<300)
  {
    return 4;
  }
  else
  {
    return 300;
  }
}

//Return method that deals with getting a value from the fifth sensor
long sensorFive()
{
  //Clears the trigPin
  pinMode(pingPin[4], OUTPUT);
  digitalWrite(pingPin[4], LOW);
  delayMicroseconds(2);

  //Sets the Pin on HIGH state for 5 micro seconds
  digitalWrite(pingPin[4], HIGH);
  delayMicroseconds(5);
  digitalWrite(pingPin[4], LOW);

  //this same pin is used for input 
  pinMode(pingPin[4], INPUT);
  duration = pulseIn(pingPin[4], HIGH);
	
  cm = durationToCentimeters(duration);
  
  if(cm<300)
  {
    return 5;
  }
  else
  {
    return 300;
  }
}

//Return method that deals with getting a value from the sixth sensor
long sensorSix()
{
  //Clears the trigPin
  pinMode(pingPin[5], OUTPUT);
  digitalWrite(pingPin[5], LOW);
  delayMicroseconds(2);

  //Sets the Pin on HIGH state for 5 micro seconds
  digitalWrite(pingPin[5], HIGH);
  delayMicroseconds(5);
  digitalWrite(pingPin[5], LOW);

  //this same pin is used for input 
  pinMode(pingPin[5], INPUT);
  duration = pulseIn(pingPin[5], HIGH);
	
  cm = durationToCentimeters(duration);
  
  if(cm<300)
  {
    return 6;
  }
  else
  {
    return 300;
  }
}

long getLocation()
{
  if(sensorOne() == 1)
  {
    return 1;
  }
  else if(sensorTwo() == 2)
  {
    return 2;
  }
  else if(sensorThree() == 3)
  {
    return 3;
  }
  else if(sensorFour() == 4)
  {
    return 4;
  }
  else if(sensorFive() == 5)
  {
    return 5;
  }
  else if(sensorSix() == 6)
  {
    return 6;
  }
}
