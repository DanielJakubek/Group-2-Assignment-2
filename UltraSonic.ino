
// defines pins
const int trigPin = 6;
const int echoPin = 5;

// defines variables
long duration;
int distance;


void setup() 
{
  pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
  pinMode(echoPin, INPUT); // Sets the echoPin as an Input
  Serial.begin(9600);

}

void loop() 
{
  // Prints the distance on the Serial Monitor
  Serial.print("Distance: ");
  Serial.println(sonicLocation()); // prints distance to serial

}

//This function deals with getting a value from the ultrasonic sensor and 
//then returns that value as an int.
int sonicLocation()
{
  // Clears the trigPin
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  
  // Sets the trigPin on HIGH state for 10 micro seconds
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  
  // Reads the echoPin, returns the sound wave travel time in microseconds
  duration = pulseIn(echoPin, HIGH);
  // Calculating the distance
  distance= duration*0.034/2;
  
  //returns the int value
  return distance;
}
