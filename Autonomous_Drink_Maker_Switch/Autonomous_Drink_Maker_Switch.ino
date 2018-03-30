int buttonPushCounter[5] = {0,0,0,0,0};   // counter for the number of button presses
int buttonState[5] = {0,0,0,0,0};         // current state of the button
int lastButtonState[5] = {0,0,0,0,0};     // previous state of the button
//Declare pin functions on Arduino
#define stp 48
#define dir 3
#define MS1 52
#define MS2 5
#define MS3 6
#define EN  50

//Declare variables for functions
char user_input;
int x;
int y;
int state;
int tnt = 0;

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
  pinMode(47, OUTPUT);
  
  pinMode(A0, INPUT);
  pinMode(A1, INPUT);
  pinMode(A2, INPUT);
  pinMode(A3, INPUT);
  pinMode(A4, INPUT);

  pinMode(stp, OUTPUT);
  pinMode(dir, OUTPUT);
  pinMode(MS1, OUTPUT);
  pinMode(MS2, OUTPUT);
  pinMode(MS3, OUTPUT);
  pinMode(EN, OUTPUT);
  resetBEDPins(); //Set step, direction, microstep and enable pins to default states
  Serial.begin(9600);
  
}
void loop() {
  buttonState[0] = analogRead(A0);
  buttonState[1] = analogRead(A1);
  buttonState[2] = analogRead(A2);
  buttonState[3] = analogRead(A3);
  buttonState[4] = analogRead(A4);

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
  }

  // compare the buttonState to its previous state
  if (buttonState[1] != lastButtonState[1]) {
    // if the state has changed, increment the counter
 
    if (buttonState[1] == 0) {
      // if the current state is HIGH then the button
      // went from off to on:
      buttonPushCounter[1]++;
      delay(100);
      Serial.print("number of button pushes:  ");
      Serial.println(buttonPushCounter[1]);     
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
  }

  if (buttonState[3] != lastButtonState[3]) {
    // if the state has changed, increment the counter
 
      // if the current state is HIGH then the button
      // went from off to on:
      buttonPushCounter[3]++;
      delay(250);
      Serial.print("number of button pushes:  ");
      Serial.println(buttonPushCounter[3]);     
    } 
  }

  if (buttonState[4] != lastButtonState[4]) {
    // if the state has changed, increment the counter
 
    if (buttonState[4] == 0) {
      // if the current state is HIGH then the button
      // went from off to on:
      buttonPushCounter[4]++;
      delay(250);
      Serial.print("number of button pushes:  ");
      Serial.println(buttonPushCounter[4]);     
    } 
  }

  
  // save the current state as the last state, 
  //for next time through the loop
  lastButtonState[0] = buttonState[0];
  lastButtonState[1] = buttonState[1];
  lastButtonState[2] = buttonState[2];
  lastButtonState[3] = buttonState[3];
  lastButtonState[4] = buttonState[4];

  
  if (buttonPushCounter[0]%4 > 0){
    //Serial.println("on");
    digitalWrite(22, HIGH);
  }
  if (buttonPushCounter[0]%4 > 1){
    //Serial.println("on");
    digitalWrite(26, HIGH);
  }
  if (buttonPushCounter[0]%4 > 2){
    //Serial.println("on");
    digitalWrite(34, HIGH);
  }  
  else if (buttonPushCounter[0]%4 == 0){
    digitalWrite(22,LOW); 
    digitalWrite(26,LOW);
    digitalWrite(34,LOW); 
  }

  if (buttonPushCounter[1]%4 > 0){
    //Serial.println("on");
    digitalWrite(24, HIGH);
  }
  if (buttonPushCounter[1]%4 > 1){
    //Serial.println("on");
    digitalWrite(28, HIGH);
  }
  if (buttonPushCounter[1]%4 > 2){
    //Serial.println("on");
    digitalWrite(36, HIGH);
  }  
  else if (buttonPushCounter[1]%4 == 0){
    digitalWrite(24,LOW); 
    digitalWrite(28,LOW);
    digitalWrite(36,LOW); 
  }

  if (buttonPushCounter[2]%4 > 0){
    Serial.println("on34");
    digitalWrite(30, HIGH);
  }
  if (buttonPushCounter[2]%4 > 1){
    //Serial.println("on");
    digitalWrite(47, HIGH);
  }
  if (buttonPushCounter[2]%4 > 2){
    //Serial.println("on");
    digitalWrite(38, HIGH);
  }  
  else if (buttonPushCounter[2]%4 == 0){
    //Serial.println("off34");
    digitalWrite(30,LOW); 
    digitalWrite(47,LOW);
    digitalWrite(38,LOW); 
  }

  if (buttonPushCounter[3]%4 > 0){
    //Serial.println("on");
    digitalWrite(32, HIGH);
  }
  if (buttonPushCounter[3]%4 > 1){
    //Serial.println("on");
    digitalWrite(42, HIGH);
  }
  if (buttonPushCounter[3]%4 > 2){
    //Serial.println("on");
    digitalWrite(40, HIGH);
  }  
  else if (buttonPushCounter[3]%4 == 0){
    digitalWrite(32,LOW); 
    digitalWrite(42,LOW);
    digitalWrite(40,LOW); 
  }

  if (buttonPushCounter[4] == 1){
    Serial.println("make_drink");

        
    //SmallStepMode();
    ReverseStep();


    buttonPushCounter[0] = 0;
    buttonPushCounter[1] = 0;
    buttonPushCounter[2] = 0;
    buttonPushCounter[3] = 0;
    buttonPushCounter[4] = 0;
    buttonPushCounter[5] = 0;
  }
}


//Reset Big Easy Driver pins to default states
void resetBEDPins()
{
  digitalWrite(stp, LOW);
  digitalWrite(dir, LOW);
  digitalWrite(MS1, LOW);
  digitalWrite(MS2, LOW);
  digitalWrite(MS3, LOW);
  digitalWrite(EN, HIGH);
}

//Default microstep mode function
void StepForwardDefault()
{
  Serial.println("Moving forward at default step mode.");
  digitalWrite(dir, LOW); //Pull direction pin low to move "forward"
  for(x= 1; x<500; x++)  //Loop the forward stepping enough times for motion to be visible
  {
    digitalWrite(stp,HIGH); //Trigger one step forward
    delay(1);
    digitalWrite(stp,LOW); //Pull step pin low so it can be triggered again
    delay(1);
  }
  Serial.println("Enter new option");
  Serial.println();
}

//Default microstep mode function
void StepForward()
{
  Serial.println("Moving forward at default step mode.");
  digitalWrite(dir, LOW); //Pull direction pin low to move "forward"
  for(x= 1; x<2700; x++)  //Loop the forward stepping enough times for motion to be visible
  {
    digitalWrite(stp,HIGH); //Trigger one step forward
    delay(1);
    digitalWrite(stp,LOW); //Pull step pin low so it can be triggered again
    delay(1);
  }
  Serial.println("Enter new option");
  Serial.println();
}


void ReverseStep()
{
  Serial.println("Moving in reverse at default step mode.");
  digitalWrite(dir, HIGH); //Pull direction pin high to move in "reverse"
  for(x= 1; x<2700; x++)  //Loop the stepping enough times for motion to be visible
  {
    digitalWrite(stp,HIGH); //Trigger one step
    delay(1);
    digitalWrite(stp,LOW); //Pull step pin low so it can be triggered again
    delay(1);
  }
  Serial.println("Enter new option");
  Serial.println();
}



//Reverse default microstep mode function
void ReverseStepDefault()
{
  Serial.println("Moving in reverse at default step mode.");
  digitalWrite(dir, HIGH); //Pull direction pin high to move in "reverse"
  for(x= 1; x<500; x++)  //Loop the stepping enough times for motion to be visible
  {

    if (tnt == 1)
      {
         break;
      }
  
    digitalWrite(stp,HIGH); //Trigger one step
    delay(1);
    digitalWrite(stp,LOW); //Pull step pin low so it can be triggered again
    delay(1);
  }
  Serial.println("Enter new option");
  Serial.println();
}

// 1/16th microstep foward mode function
void SmallStepMode()
{
  Serial.println("Stepping at 1/16th microstep mode.");
  digitalWrite(dir, LOW); //Pull direction pin low to move "forward"
  digitalWrite(MS1, HIGH); //Pull MS1,MS2, and MS3 high to set logic to 1/16th microstep resolution
  digitalWrite(MS2, HIGH);
  digitalWrite(MS3, HIGH);
  for(x= 1; x<1000; x++)  //Loop the forward stepping enough times for motion to be visible
  {
    digitalWrite(stp,HIGH); //Trigger one step forward
    delay(1);
    digitalWrite(stp,LOW); //Pull step pin low so it can be triggered again
    delay(1);
  }
  Serial.println("Enter new option");
  Serial.println();
}

//Forward/reverse stepping function
void ForwardBackwardStep()
{
  Serial.println("Alternate between stepping forward and reverse.");
  for(x= 1; x<5; x++)  //Loop the forward stepping enough times for motion to be visible
  {
    //Read direction pin state and change it
    state=digitalRead(dir);
    if(state == HIGH)
    {
      digitalWrite(dir, LOW);
    }
    else if(state ==LOW)
    {
      digitalWrite(dir,HIGH);
    }
    
    for(y=1; y<1000; y++)
    {
      digitalWrite(stp,HIGH); //Trigger one step
      delay(1);
      digitalWrite(stp,LOW); //Pull step pin low so it can be triggered again
      delay(1);
    }
  }
  Serial.println("Enter new option");
  Serial.println();
}
