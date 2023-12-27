/*
THE 3-BIT CALCULATOR PROJECT
MEMBER : PONGSAPAT B.
DATE STARTED : 11 DEC 2023 
DATE FINISHED : TBD
PURPOSE : FOR EDUCATIONAL PURPOSE ON DEMONSTRATION ON ADDING AND SUBTRACTING NUMBERS IN BINARY
*/

//Pins used in the project
int AddSwitch = 2;
int MultiplySwitch = 3;

//Modes for doing math operations
bool AddMode;
bool MultiplyMode;
int Base10Count;
int Base10Divide;
int BinaryResult[4];

void setup() {
  pinMode(AddSwitch, INPUT);
  pinMode(MultiplySwitch, INPUT);
  pinMode(2, INPUT);
  pinMode(3, INPUT);
  pinMode(4, INPUT);
  pinMode(5, INPUT);
  pinMode(6, INPUT);
  pinMode(7, INPUT);
  Serial.begin(9600);
}

void loop() {
  Base10Count = 0;
  Base10Divide = 0;
  //Start

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
  for (int i = 2; i < 8; i++){
    if (digitalRead(i) == 1){
     Base10Count += pow(2.0, i - 2.0); 
     Base10Divide = Base10Count;
    }
    else{
      continue;
    }
  }
  for (int i = 0; i < 4; i++){
    if (Base10Divide >= 0){
      BinaryResult[i] = Base10Divide % 2;
      Base10Divide %= 2;
    }
    else{
      break;
    }
  }
  //Tells LCD about the result
  Serial.println(Base10Count);
  //End
}
