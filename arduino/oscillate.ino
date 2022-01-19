/*
 * this program is to control the peristlatic pump to oscillate fluids back and forth on command from a switch
 */

//Input the Frequency. Do not exceed 2. Note that this is not accurate in Hz, to verify the speed of the pump, manually check the RPM. 

float frequency = 2; //2 to 1.66 to 1.33 to 1

//**********************************************************************************************************************************************************************
float loopTime = (639.6/frequency-287.8); 
float delayTime = loopTime/2; 
unsigned long timeElapsed = 0;
int stp = 6;
int dir = 7;
int initialized = 0;
int power = 1;
int onSwitch = 0;
int sensor = 3;
int powerSwitch = 2;
int sensorRead = 0;
int directionSwitch = 4;
int dirSensor = 5;
int dirSensorRead = 0;
int previousDir = 0;

int valve = 8;
long j = 0;
int valveState = 1;

long previousMillis = 0;
long interval = 2000;
int a = 60;

// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital pin 13 as an output.
  pinMode(stp, OUTPUT);
  pinMode(dir,OUTPUT);
  pinMode(powerSwitch,OUTPUT);
  pinMode(directionSwitch, OUTPUT);
  pinMode(dirSensor,INPUT);
  pinMode(sensor, INPUT);
  pinMode(valve,OUTPUT);
  digitalWrite(dir,HIGH);
  digitalWrite(powerSwitch,HIGH);
  digitalWrite(directionSwitch,HIGH);
  digitalWrite(valve,HIGH);
  
  Serial.begin(250000);
  while (!Serial) {
    ;
  }
}

// the loop function runs over and over again forever
void loop() {

  takeReading();

  
}

void takeReading()
{
  sensorRead = digitalRead(sensor);
   if(sensorRead == HIGH)
  {
    onSwitch = 1;
  }
  else
  {
    onSwitch = 0;
    initialized = 0;
  }

  dirSensorRead = digitalRead(dirSensor);
  if (dirSensorRead != previousDir)
  {
    initialized = 0;
  }
  previousDir = dirSensorRead;
  if(dirSensorRead == HIGH)
  {
    //digitalWrite(dir,HIGH);
    for (int j = 0; j<6; j++) //change direction 6 times
    {
      for (int i = 1000; i > 0; i--) //run 1000 steps in one direction
      {
        digitalWrite(stp, HIGH);   // turn the LED on (HIGH is the voltage level)
        delayMicroseconds(200);              // wait for a second
        digitalWrite(stp, LOW);    // turn the LED off by making the voltage LOW
        delayMicroseconds(200);              // wait for a second
      }
      digitalWrite(dir,!digitalRead(dir));
    }
    
    while (dirSensorRead == HIGH)
    {
      dirSensorRead = digitalRead(dirSensor);
    }
  }
  else
  {
    //digitalWrite(dir,LOW);
  }

  
}
