/*This is a file I got from an ME buddy who needed some help.
The basic idea was that he would have a button that would
actuate a servo through a 180 degree revolution and then
return back to it's starting point and another that would
Actuate a relay. The issue was that he didn't have a great
idea of how the relay code worked and that we didn't have
any guarentee that he wouldn't need to flip the relay during
the servo cycle*/

/*These were the changes I made. I split the servo movment
into a series of smaller steps and allowed the code to poll
the relay control button once per cycle, so that its status
could be modified during the flip. I also tried to comment it
as well as I could so that it would make sense to him, which is
also why some of the variable names aren't neccisarily what
I would use, for example, angle below should probably be
currentAngle to make the intent of the code more clear.
I also didn't have a servo or relay to test with, so I was
reliant on him to actually test the code and confirm that
it did what it was supposed to and allowed sufficuent time
for the relay he was using to move, but I felt I made which
variables do what clear enough that he could make some changes
to it if he needed to */




/*Ryan Felter
  08-11-2019
  Brandon Greer
  12-11-2019
 Turns on a relay and servo with two different
 buttons, and lets is stay on until the button is pressed again */

#include <Servo.h>
/*Servo Setup*/
Servo servo;
int startingAngle = 0;//Starting angle for the servo
int angle = startingAngle;// Used to track current position of the servo
int maxAngle = 180;//max angle we want the servo to turn to
int angleStep = 10;//size of steps for the servo to move in degrees
int angleStepTime = 15;//the time it takes the servo to move one angleStep in milliseconds
bool servoButtonPressed = false;//Boolean used to track whether or not the button has been pressed
bool completedAngle = false;//Tracks whether or not the servo has completed it's positive revolution

int Button1 = 2;
int Relay = 7;
int servoButton = 4;
int stateLED = LOW;
int stateButton;
int previous = LOW;
long time = 0;
long debounce = 200;

void setup() {
  Serial.begin(9600);
  servo.attach(9);
  pinMode(servoButton, INPUT_PULLUP);
    Serial.println("Project Servo Button ");

  pinMode(Button1, INPUT);
  pinMode(Relay, OUTPUT);
}

void loop() {
  if(digitalRead(servoButton == HIGH && servoButtonPressed == false)){
    servoButtonPressed = true;
  }

  stateButton = digitalRead(Button1);
  if(stateButton == HIGH && previous == LOW && millis() - time > debounce) {
    if(stateLED == HIGH){
      stateLED = LOW;
    } else {
       stateLED = HIGH;
    }
    time = millis();
  }
  digitalWrite(Relay, stateLED);
  previous == stateButton;//why is this == ?

  //servo control code, we've split out like this instead of one loop so that every angleStepTime ms, the arduino will recheck the
  //relay button and change it if appropriate. We can split that up even more if we need faster response time.
  if(servoButtonPressed == true && completedAngle == false){
    if(angle+angleStep < maxAngle){//Move until the servo angle is one angleStep or less away from max angle
      angle += angleStep;
      servo.write(angle);
      delay(angleStepTime);
    }
    else if(angle+angleStep >= maxAngle){//once we're one angleStep away from max, just move to max and trip the boolean
      angle = maxAngle;
      servo.write(angle);
      completedAngle = true;
      delay(angleStepTime);
    }
  }
  else if(servoButtonPressed == true && completedAngle == true){
    if(angle-angleStep > startingAngle){//start moving in negative degrees until we're within one anglestep of our starting angle
      angle -= angleStep;
      servo.write(angle);
      delay(angleStepTime);
    }
    else if(angle+angleStep <= startingAngle){//move to starting angle and reset both booleans
      angle = startingAngle;
      servo.write(angle);
      completedAngle = false;
      delay(angleStepTime);
      servoButtonPressed = false;//right now this would allow us to press the button again if we wanted to actuate the servo again
    }

  }
}
