int buttonPushCounter[4] = {0,0,0,0};   // counter for the number of button presses
int buttonState[4] = {0,0,0,0};         // current state of the button
int lastButtonState[4] = {0,0,0,0};     // previous state of the button

void setup() {
  pinMode(22, OUTPUT);
  pinMode(24, OUTPUT);
  pinMode(26, OUTPUT);
  pinMode(28, OUTPUT);
  pinMode(30, OUTPUT);
  pinMode(32, OUTPUT);
  pinMode(34, OUTPUT);
  pinMode(36, OUTPUT);
  pinMode(38, OUTPUT);
  pinMode(40, OUTPUT);
  pinMode(42, OUTPUT);
  pinMode(44, OUTPUT);
  
  pinMode(A0, INPUT);
  pinMode(A1, INPUT);
  pinMode(A2, INPUT);
  pinMode(A3, INPUT);
  pinMode(A4, INPUT);

  Serial.begin(9600);
  
}
void loop() {
  buttonState[0] = analogRead(A0);
  buttonState[1] = analogRead(A1);
  buttonState[2] = analogRead(A2);
  buttonState[3] = analogRead(A3);
  
  // compare the buttonState to its previous state
  if (buttonState[0] != lastButtonState[0]) {
    // if the state has changed, increment the counter
 
    if (buttonState[0] == 0) {
      // if the current state is HIGH then the button
      // went from off to on:
      buttonPushCounter[0]++;
      delay(250);
      Serial.print("number of button pushes:  ");
      Serial.println(buttonPushCounter[0]);     
    } 
    else {
      delay(100);
    }
  }

  // compare the buttonState to its previous state
  if (buttonState[1] != lastButtonState[1]) {
    // if the state has changed, increment the counter
 
    if (buttonState[1] == 0) {
      // if the current state is HIGH then the button
      // went from off to on:
      buttonPushCounter[1]++;
      delay(250);
      Serial.print("number of button pushes:  ");
      Serial.println(buttonPushCounter[1]);     
    } 
    else {
      delay(100);
    }
  }

  if (buttonState[2] != lastButtonState[2]) {
    // if the state has changed, increment the counter
 
    if (buttonState[2] == 0) {
      // if the current state is HIGH then the button
      // went from off to on:
      buttonPushCounter[2]++;
      delay(250);
      Serial.print("number of button pushes:  ");
      Serial.println(buttonPushCounter[2]);     
    } 
    else {
      delay(100);
    }
  }

  if (buttonState[3] != lastButtonState[3]) {
    // if the state has changed, increment the counter
 
    if (buttonState[3] == 0) {
      // if the current state is HIGH then the button
      // went from off to on:
      buttonPushCounter[3]++;
      delay(250);
      Serial.print("number of button pushes:  ");
      Serial.println(buttonPushCounter[3]);     
    } 
    else {
      delay(100);
    }
  }





  
  // save the current state as the last state, 
  //for next time through the loop
  lastButtonState[0] = buttonState[0];
  lastButtonState[1] = buttonState[1];
  lastButtonState[2] = buttonState[2];
  lastButtonState[3] = buttonState[3];

  
  if (buttonPushCounter[0]%4 > 0){
    //Serial.println("on");
    digitalWrite(22, HIGH);
  }
  if (buttonPushCounter[0]%4 > 1){
    //Serial.println("on");
    digitalWrite(24, HIGH);
  }
  if (buttonPushCounter[0]%4 > 2){
    //Serial.println("on");
    digitalWrite(26, HIGH);
  }  
  else if (buttonPushCounter[0]%4 == 0){
    digitalWrite(22,LOW); 
    digitalWrite(24,LOW);
    digitalWrite(26,LOW); 
  }

  if (buttonPushCounter[1]%4 > 0){
    //Serial.println("on");
    digitalWrite(28, HIGH);
  }
  if (buttonPushCounter[1]%4 > 1){
    //Serial.println("on");
    digitalWrite(30, HIGH);
  }
  if (buttonPushCounter[1]%4 > 2){
    //Serial.println("on");
    digitalWrite(32, HIGH);
  }  
  else if (buttonPushCounter[1]%4 == 0){
    digitalWrite(28,LOW); 
    digitalWrite(30,LOW);
    digitalWrite(32,LOW); 
  }

  if (buttonPushCounter[2]%4 > 0){
    //Serial.println("on");
    digitalWrite(34, HIGH);
  }
  if (buttonPushCounter[2]%4 > 1){
    //Serial.println("on");
    digitalWrite(36, HIGH);
  }
  if (buttonPushCounter[2]%4 > 2){
    //Serial.println("on");
    digitalWrite(38, HIGH);
  }  
  else if (buttonPushCounter[0]%4 == 0){
    digitalWrite(34,LOW); 
    digitalWrite(36,LOW);
    digitalWrite(38,LOW); 
  }

  if (buttonPushCounter[3]%4 > 0){
    //Serial.println("on");
    digitalWrite(40, HIGH);
  }
  if (buttonPushCounter[3]%4 > 1){
    //Serial.println("on");
    digitalWrite(42, HIGH);
  }
  if (buttonPushCounter[3]%4 > 2){
    //Serial.println("on");
    digitalWrite(44, HIGH);
  }  
  else if (buttonPushCounter[0]%4 == 0){
    digitalWrite(40,LOW); 
    digitalWrite(42,LOW);
    digitalWrite(44,LOW); 
  }
}

