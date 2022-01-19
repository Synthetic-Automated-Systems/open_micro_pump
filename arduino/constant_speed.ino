/*
 * this program is to control the peristaltic pump to run at a fixed speed, controlled by the frequency variable in the program. 
 */

//Input the Frequency. Do not exceed 2. (is not actually in Hz. To verify RMP, the speed should be manually tested by counting revolutions)

float frequency = 1.8; 


//**********************************************************************************************************************************************************************
float loopTime = (639.6/frequency-287.8); 
float delayTime = loopTime/2; 
unsigned long timeElapsed = 0;
int stp = 6;
int dir = 7;
int initialized = 0;
int power = 1;
int onSwitch = 0;
int sensor = 2;
int powerSwitch = 3;
int sensorRead = 0;
int directionSwitch = 5;
int dirSensor = 4;
int dirSensorRead = 0;
int previousDir = 0;

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
  
  Serial.begin(250000);
  while (!Serial) {
    ;
  }
}

// the loop function runs over and over again forever
void loop() {
  if (onSwitch == 1)
  {
    if (initialized == 0)
    {
      for (int i = 500; i > 0; i--) 
      {
        digitalWrite(stp, HIGH);   // turn the LED on (HIGH is the voltage level)
        delayMicroseconds(delayTime+i);              // wait for a second
        digitalWrite(stp, LOW);    // turn the LED off by making the voltage LOW
        delayMicroseconds(delayTime+i);              // wait for a second
      }
      initialized = 1;
    }
    
    digitalWrite(stp, HIGH);   // turn the LED on (HIGH is the voltage level)
    delayMicroseconds(delayTime);              // wait for a second
    digitalWrite(stp, LOW);    // turn the LED off by making the voltage LOW
    delayMicroseconds(delayTime);              // wait for a second
  }
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
    digitalWrite(dir,HIGH);
  }
  else
  {
    digitalWrite(dir,LOW);
  }
}
