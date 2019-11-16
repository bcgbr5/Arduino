//Viral Science www.youtube.com/c/viralscience
//Push Button Relay Control
int pbuttonPin = 2;
int relayPin = 10;
int pbuttonPin2 = 3;
int relayPin2 = 11;

int val = 0; 
int lightON = 0;
int pushed = 0;

int val2 = 0; 
int lightON2 = 0;
int pushed2 = 0;

void setup() {
  Serial.begin(9600);
  pinMode(pbuttonPin, INPUT_PULLUP); 
  pinMode(relayPin, OUTPUT);
   pinMode(pbuttonPin2, INPUT_PULLUP); 
  pinMode(relayPin2, OUTPUT);

}

void loop() {
  val = digitalRead(pbuttonPin);
  val2 = digitalRead(pbuttonPin2);

  
//Relay 1
  if(val == HIGH && lightON == LOW){

    pushed = 1-pushed;
    delay(100);
  }    
  lightON = val;

      if(pushed == HIGH){
        Serial.println("Light ON");
        digitalWrite(relayPin, LOW); 
       
      }else{
        Serial.println("Light OFF");
        digitalWrite(relayPin, HIGH);
   
      }   
  


//Relay 2

 
  if(val2 == HIGH && lightON2 == LOW){

    pushed2 = 1-pushed2;
    delay(100);
  }    

  lightON2 = val2;

      if(pushed2 == HIGH){
        Serial.println("Light ON");
        digitalWrite(relayPin2, LOW); 
       
      }else{
        Serial.println("Light OFF");
        digitalWrite(relayPin2, HIGH);
   
      }       


  delay(100);
}
