/*This is a file I got from an ME buddy who needed some help.
The basic idea was that he would have a button that would
actuate a servo through a 180 degree revolution and then
return back to it's starting point and another that would
Actuate a relay. The issue was that he didn't have a great
idea of how the relay code worked and that we didn't have
any guarentee that he wouldn't need to flip the relay during
the servo cycle*/


/*Ryan Felter
  08-11-2019
 Turns on a relay and servo with two different
 buttons, and lets is stay on until the button is pressed again */
#include <Servo.h>

Servo servo;

int angle = 90;
int angleStep = 10;

int Button1 = 2;
int Relay = 7;
int Button2 = 4;
int stateLED = LOW;
int stateButton;
int previous = LOW;
long time = 0;
long debounce = 200;

void setup() {
  Serial.begin(9600);
  servo.attach(9);
  pinMode(Button2, INPUT_PULLUP);
    Serial.println("Project Servo Button ");

  pinMode(Button1, INPUT);
  pinMode(Relay, OUTPUT);
}

void loop()
{
  {

  while(digitalRead(4) == LOW){

    servo.write(angle); // move the servo to desired angle
      Serial.print("Moved to: ");
      Serial.print(angle);   // print the angle
      Serial.println(" degree");
  delay(100); // waits for the servo to get there
  }// while
  }







 { stateButton = digitalRead(Button1);
  if(stateButton == HIGH && previous == LOW && millis() - time > debounce) {
    if(stateLED == HIGH){
      stateLED = LOW;
    } else {
       stateLED = HIGH;
    }
    time = millis();
  }
  digitalWrite(Relay, stateLED);
  previous == stateButton;
 }





}
