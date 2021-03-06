int buttonPushCounter = 4;   // counter for the number of button presses
int buttonState = 0;         // current state of the button
int lastButtonState = 0;     // previous state of the button

void setup() {
  pinMode(22, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(A0, INPUT);

  int a[4] = {0,0,0,0};

  Serial.begin(9600);
  
}
void loop() {
  // read the pushbutton input pin:
  buttonState = analogRead(A0);
  //Serial.println(buttonState);
  
  // compare the buttonState to its previous state
  if (buttonState != lastButtonState) {
    // if the state has changed, increment the counter
    if (buttonState == 0) {
      // if the current state is HIGH then the button
      // went from off to on:
      buttonPushCounter--;
      delay(100);
      Serial.println("on");
      Serial.print("number of button pushes:  ");
      Serial.println(buttonPushCounter);
    } 
    else {
      delay(100);
    }
  }
  // save the current state as the last state, 
  //for next time through the loop
  lastButtonState = buttonState;


  if (buttonPushCounter == 1 || buttonPushCounter == 2 || buttonPushCounter == 3) {
    digitalWrite(22, HIGH);   
  }
  
  if (buttonPushCounter == 1 || buttonPushCounter == 2){
    digitalWrite(11, HIGH);
  }
  
  if (buttonPushCounter == 1){
    digitalWrite(9, HIGH);
  }
  
  if (buttonPushCounter == 0) {             
    digitalWrite(22, LOW); 
    digitalWrite(11, LOW);
    digitalWrite(9, LOW);
    buttonPushCounter = 4;
  }         
}

