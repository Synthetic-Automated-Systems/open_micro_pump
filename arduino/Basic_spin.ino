//A minimal program to use the arduino and easydriver motor controller to spin the stepper motor in one direction. 
//The speed can be controlled by controlling the delay length in the main loop, but this is a pretty crude controller for the pump. 
//designed to work with the electrical schematic included. 


#define stp 6
#define dir 7

void setup() {
pinMode(stp, OUTPUT);
pinMode(dir, OUTPUT);
}

//Main loop
void loop() {
digitalWrite(stp,HIGH); //Trigger one step forward
delay(.1);
digitalWrite(stp,LOW); //Pull step pin low so it can be triggered again
delay(1);
  
}
