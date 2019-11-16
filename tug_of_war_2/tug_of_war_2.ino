/* Turns on a relay and servo with two different buttons, and lets is stay on until the button is pressed again */
//
//int relayButton = 4;
//int Relay = 7;
//int stateLED = LOW;
//int stateButton;
//int previous = LOW;
//long time = 0;
//long debounce = 2000;
//
//int relayButton = 9;
//int relayPin = 2;
//int relayStatus;
//
//void setup() {
//  pinMode(relayButton, INPUT);
//  pinMode(relayPin, OUTPUT);
//  digitalWrite(relayPin, LOW);
//  relayStatus = LOW;
//}
//
//void loop() {
//
//  if(digitalRead(relayButton) == HIGH){
//    if(relayStatus == LOW){
//      digitalWrite(relayPin, HIGH);
//      relayStatus = HIGH;
//      
//    }
//    else{
//      digitalWrite(relayPin, LOW);
//      relayStatus = LOW;
//    }
//    
//  }
//  delay(500);
//}
/* sketch 1 
turn on a LED when the button is pressed
turn it off when the button is not pressed (or released)
*/
/* sketch 2 
turn on a LED when the button is pressed and let it on when the button is released
*/
int pinButton = 8; //the pin where we connect the button
int LED = 2; //the pin we connect the LED

void setup() {
  pinMode(pinButton, INPUT); //set the button pin as INPUT
  pinMode(LED, OUTPUT); //set the LED pin as OUTPUT
}

void loop() {
  int stateButton = digitalRead(pinButton); //read the state of the button
  if(stateButton == 1) { //if is pressed
     digitalWrite(LED, HIGH); //write 1 or HIGH to led pin
  }
}
