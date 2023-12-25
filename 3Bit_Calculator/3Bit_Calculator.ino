//Pins used in the project
int AddSwitch = 2;
int MultiplySwitch = 3;

//Modes for doing math operations
bool AddMode;
bool MultiplyMode;
int Base10Count;
int Base10Divide;
int[] BinaryResult;

void setup() {
  pinMode(AddSwitch, INPUT);
  pinMode(MultiplySwitch, INPUT);
  pinMode(0, INPUT);
  pinMode(1, INPUT);
  pinMode(2, INPUT);
  pinMode(3, INPUT);
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
    //Tells LCD light to send an error message and break the entire script
  }

  //Check the pins
  for (int i = 0, i < 4, i++){
    if (digitalRead(i) == 1){
     Base10Count += 2^i; 
     Base10Divide = Base10Count;
    }
  }
  for (int i = 0){
    if (Base10Divide >= 0){
      BinaryResult[i] = Base10Divide % 2;
      Base10Divide %= 2;
    }
  }
}
