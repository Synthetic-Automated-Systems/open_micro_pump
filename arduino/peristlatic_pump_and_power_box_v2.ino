//This is a program for running the 3d peristaltic pump designed in the Ruder Lab at Pitt
//This program is designed to be used with the included power box with a direction switch, a power switch, and a potentiometer to sense the speed
//this program can run the pump at a speed set by the potentiometer, change direection, and turn on and off. 
//see the following section of code to see the arduino pins used for this.



#include <Timer.h>

//**********************************************************************************************************************************************************************
//this section of code sets the physical GPIO pins that are used. this must match the hardware setup. 
int stp = 6; //digital pin for outputting step commands
int dir = 7; //digital pin for outputting direction commands
int powerSensor = 3; //digital pin that will take readings from the power switch
int powerSwitchVcc = 2; //digital pin that is always high, to supply Vcc to the power switch (lazy workaround)
int directionSwitch = 4; //digital pin that is always high, to supply Vcc to the direction switch (lazy workaround)
int dirSensor = 5; //digital pin that senses the direction switch
int speedPot = 1; //analog pin that keeps track of the speed knob potentiometer

Timer t1, t2; //two timer objects to run commands at a fixed time interval

float delayTime = 100; //time between steps. changes with the speed sensor potentiometer
unsigned long timeElapsed = 0; //how long it's been since the program started running
int initialized = 0; //variabe that tells you whether of not you have done the acceleration routine for running at high speeds
int onSwitch = 0; //variable that shoud really be gotten rid of and replaced with powerSensorRead
int powerSensorRead = 0; //variable to hold the power sensor reading
int dirSensorRead = 0; //variable to hold readings from the direction sensor
int previousDir = 0; //variable that keeps track of which direction you were going last loop
int speedReading = 0; //variable to keep track of the speed
int previousSpeed = 0; //variable the keeps track of which speed you were going at last loop
float currentTime = 0; //counter that keeps track of the time
int analogReadTiming = 100; //time between readings of the analog potentiometer
int lastPowerRead = 0; //variable to keep track of the state of the power switch


// the setup function runs once when you press reset or power the board
void setup() {
  //set up the digital pins as input or output
  pinMode(stp, OUTPUT);
  pinMode(dir,OUTPUT);
  pinMode(powerSwitchVcc,OUTPUT);
  pinMode(directionSwitch, OUTPUT);
  pinMode(dirSensor,INPUT);
  pinMode(powerSensor, INPUT);

  digitalWrite(dir,HIGH);   //initialize value for direction
  digitalWrite(powerSwitchVcc,HIGH);  //set a digital pin always high for the power switch to use
  digitalWrite(directionSwitch,HIGH); //set a digital pin alwasy high for the direction switch to use
  
  Serial.begin(9600);
  while (!Serial) {
    ;
  }

  t1.every(analogReadTiming, speedSense,0); //read the speed sensor every *analogReadTiming* milliseconds
  t2.every(analogReadTiming, printReading,0); // print the diagnostic string to the terminal. comment out for faster operation
}

// the loop function runs over and over again forever
void loop() {

  //update the timers
  t1.update();
  t2.update();
  
  if (onSwitch == 1)
  {
    if (initialized == 0)
    {
      initialize();
    } 
    if (speedReading != 0)
    {
      digitalWrite(stp, HIGH);   // send a step 1
      delayMicroseconds(delayTime);              //delay for the right amount of time
      digitalWrite(stp, LOW);    // send a step 0, 
      delayMicroseconds(delayTime);              //delay for the right amount of time
    }
   
  }
  takeReading();
  //printReading(); //uncomment this if you want to print the diagnostic information every loop. not recommended for speed reasons. this slows the loop down. 
}

void takeReading() //a function to take readings from the switches
{
  powerSense();
  directionSense();  
}

void powerSense() //a function to sense the state of the power switch
{
    powerSensorRead = digitalRead(powerSensor); //read the power switch
   if(powerSensorRead == HIGH)
  {
    onSwitch = 1;
  }
  else
  {
    onSwitch = 0;
  }
  if (powerSensorRead != lastPowerRead) //if there has been a state transition from low to high on the power switch, set initialized to 0
  {
    if (powerSensorRead == HIGH)
    {
      initialized = 0;
    }
  }
  lastPowerRead = powerSensorRead; //update the last power reading
}

void directionSense() //a function to sense the direcetion switch state
{
   dirSensorRead = digitalRead(dirSensor); //read the direction switch. 
  if (dirSensorRead != previousDir) //run the initilization protocol of the direction switch has flipped.
  {
    initialized = 0;
  }
  previousDir = dirSensorRead; //keep track of the last state of teh direction switch
  if(dirSensorRead == HIGH)
  {
    digitalWrite(dir,HIGH);
  }
  else
  {
    digitalWrite(dir,LOW);
  }
}

void speedSense() //a function to sense the potentiometer and set the speed of the pump
{
  speedReading = analogRead(speedPot); //analog read the potentiometer
  if (abs(speedReading - previousSpeed) > 3) //this is an analog reading so there is a little wiggle room (3 bits out of 1024). if the change is less than 3 assume that no change has been made
  {
    initialized = 0;
  }
  previousSpeed = speedReading;
  delayTime = (20460/speedReading); //thisis the function to determine how long the loop runs for.
}

void printReading() //a function to print diagnostic information to the terminal
{
  currentTime = millis();
  String Output = String(String(onSwitch) + ", " + String(speedReading));
  Serial.println(Output);
}

void initialize() //a function that is used to accelerate the motor slowly, so that there is not a hardware problem with fast speeds. This is to compensate for the inertia of the rotor. 
{
  
 for (int i = 300; i > 0; i--) 
      {
        if(speedReading != 0)
        {
          digitalWrite(stp, HIGH);   // turn the LED on (HIGH is the voltage level)
          delayMicroseconds(delayTime+i);             //increase the delay each loop to help the pump accelerate
          digitalWrite(stp, LOW);    // turn the LED off by making the voltage LOW
          delayMicroseconds(delayTime+i);             // increase the delay each loop to help the pump accelerate
        }
      }
      initialized = 1; 
}





