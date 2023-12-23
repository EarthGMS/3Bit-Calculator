//Pins used in the project
int AddSwitch = 2;
int MultiplySwitch = 3;

//Modes for doing math operations
bool AddMode;
bool MultiplyMode

void setup() {
  pinMode(AddSwitch, INPUT);
  pinMode(MultiplySwitch, INPUT);
}

void loop() {

  //Check the mode selection
  if (digitalRead(AddSwitch) == 1){
    AddMode = true;
  }
  else{
    AddMode = false;
  }
  if (digitalRead(MultiplySwitch) == 1){
    MultiplyMode = true;
  }
  else{
    MultiplyMode = false;
  }
  if (MultiplyMode == true && AddMode == true){
    //Tells LCD light to send an error message
  }

}
