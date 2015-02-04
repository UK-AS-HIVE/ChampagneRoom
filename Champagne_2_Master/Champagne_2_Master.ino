//For left Box.
int comm = 12;
int dirpin = 7;
int steppin = 8;
int switch1 = 3;
int switch2 = 2;
int mainSwitch = 4;
int mainLight = 5;
const double vi120[] = {35, 53, 39, 57, 88, 53, 41, 30, 42, 57, 40, 58, 58, 64, 64, 83, 84, 30, 39, 48, 38, 74, 37, 38, 71};
int trialIndex = 0;
long prevMillis = 0;
int runMe = 0;


void setup() {
  // put your setup code here, to run once:
  pinMode(switch1, INPUT);
  pinMode(switch2, INPUT);
  pinMode(dirpin, OUTPUT);
  pinMode(steppin, OUTPUT);
  pinMode(mainLight, OUTPUT);
  pinMode(mainSwitch, INPUT);
  pinMode(comm, OUTPUT);
  Serial.begin(9600);
  closeMeNoSafe();
}

void loop() {
  Serial.println(digitalRead(mainSwitch));
  if(digitalRead(mainSwitch) == 1){
    runMe = 1;
  }
  
  unsigned long currentMillis = millis();
  
  if(runMe == 1){

    if(prevMillis == 0){
      prevMillis = currentMillis;
    }
    //delay(vi120[trialIndex] * 1000);
    if(currentMillis - prevMillis > vi120[trialIndex] * 1000){
      prevMillis = currentMillis + 16000;
      Serial.write("sending\n");
      digitalWrite(comm, HIGH);
      delay(2);
      digitalWrite(comm, LOW);
      trial();
      trialIndex++;
    }
  
  }
}

void openMe(){
 digitalWrite(dirpin, LOW);
 while(digitalRead(switch1) == 0){
   if(digitalRead(mainSwitch) == 1){
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

//void trial(){
//  digitalWrite(mainLight, HIGH);
//  delay(8000);
//  digitalWrite(mainLight, LOW);
//  openMe();
//  delay(8000);
//  closeMe();  
//}

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
  
  
