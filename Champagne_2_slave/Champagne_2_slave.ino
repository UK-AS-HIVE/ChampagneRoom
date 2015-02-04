//For right Box.
int comm = 12;
int dirpin = 8;
int steppin = 7;
int switch1 = 3;
int switch2 = 2;
int mainSwitch = 4;
int mainLight = 5;
const double vi120[] = {35, 53, 39, 57, 88, 53, 41, 30, 42, 57, 40, 58, 58, 64, 64, 83, 84, 30, 39, 48, 38, 74, 37, 38, 71};
int trialIndex = 0;
long prevMillis = 0;


void setup() {
  // put your setup code here, to run once:
  pinMode(switch1, INPUT);
  pinMode(switch2, INPUT);
  pinMode(dirpin, OUTPUT);
  pinMode(steppin, OUTPUT);
  pinMode(mainLight, OUTPUT);
  pinMode(mainSwitch, INPUT);
  pinMode(comm, INPUT);
  Serial.begin(9600);
  closeMeNoSafe();
}

void loop() {
    if(digitalRead(comm) == 1){
      trial();
      trialIndex++;
    }
}

void openMe(){
 digitalWrite(dirpin, LOW);
 while(digitalRead(switch1) == 0){
   if(digitalRead(mainSwitch == 1)){
     digitalWrite(steppin, LOW);
     digitalWrite(steppin, HIGH);
     delayMicroseconds(150);
   }
 }
}

void closeMe(){
 digitalWrite(dirpin, HIGH);
 while(digitalRead(switch2) == 0){
   if(digitalRead(mainSwitch) == 1){
     digitalWrite(steppin, LOW);
     digitalWrite(steppin, HIGH);
     delayMicroseconds(150);
   }
 }
}

void closeMeNoSafe(){
 digitalWrite(dirpin, HIGH);
 while(digitalRead(switch2) == 0){
     digitalWrite(steppin, LOW);
     digitalWrite(steppin, HIGH);
     delayMicroseconds(150);
 }
}


void trial(){
  long baseTrialMillis = millis();
  digitalWrite(mainLight, HIGH);
  while(millis() - baseTrialMillis < 8000){
    Serial.println("1");
  }
  digitalWrite(mainLight, LOW);
  openMe();
  while(millis() - baseTrialMillis < 16000){
    Serial.println("2");
  }
  closeMe();
}
  
  
