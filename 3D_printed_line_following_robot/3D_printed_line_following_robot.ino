
const int sensor1 = 34; //P34
const int sensor2 = 39; //SVN
const int sensor3 = 36; //SVP 

const int LmotorPWM = 32; //P32
const int RmotorPWM = 33; //P33

const int LmotorDirA = 19; // P19
const int LmotorDirB = 18; // P18
const int RmotorDirA = 14; // P14
const int RmotorDirB = 12; // P12

void setup() {
  Serial.begin(115200);   // Debugging 

  pinMode(sensor1, INPUT);
  pinMode(sensor2, INPUT);
  pinMode(sensor3, INPUT);

  pinMode(LmotorDirA, OUTPUT);
  pinMode(LmotorDirB, OUTPUT);
  pinMode(RmotorDirA, OUTPUT);
  pinMode(RmotorDirB, OUTPUT);
  pinMode(LmotorPWM, OUTPUT);
  pinMode(RmotorPWM, OUTPUT);

  digitalWrite(LmotorDirA, LOW);
  digitalWrite(LmotorDirB, LOW);
  digitalWrite(RmotorDirA, LOW);
  digitalWrite(RmotorDirB, LOW);

  digitalWrite(LmotorPWM, LOW);
  digitalWrite(RmotorPWM, LOW);

  setSpeed(90);
}

int lastDirection = 0;
unsigned long searchStart = 0;
bool isSearching = false;

void loop() {
  //Line following logic 
  bool sensor1Stat = digitalRead(sensor1);
  bool sensor2Stat = digitalRead(sensor2);
  bool sensor3Stat = digitalRead(sensor3);

  if (sensor2Stat) {
    forwards();
    lastDirection = 0;
    isSearching = false;
  } else if (sensor1Stat) {
    turnLeft();
    lastDirection = -1;
    isSearching = false;
  } else if (sensor3Stat) {
    turnRight();
    lastDirection = 1;
    isSearching = false;
  } else {  //Search for line for 1s if no sensors are detecting 
    if (!isSearching) {
      searchStart = millis();
      isSearching = true;
      search();
    }
    
    if (millis() - searchStart < 1000) {
      search();
    } else {  //Stop searching after 1s 
      stop();
    }
  }
}


// =========================
//  Motor control functions 
// =========================

void forwards() {
  digitalWrite(LmotorDirA, LOW);
  digitalWrite(LmotorDirB, HIGH);
  digitalWrite(RmotorDirA, LOW);
  digitalWrite(RmotorDirB, HIGH);
}

void turnRight() {
  digitalWrite(LmotorDirA, LOW);
  digitalWrite(LmotorDirB, HIGH);
  digitalWrite(RmotorDirA, HIGH);
  digitalWrite(RmotorDirB, LOW);
}

void turnLeft() {
  digitalWrite(LmotorDirA, HIGH);
  digitalWrite(LmotorDirB, LOW);
  digitalWrite(RmotorDirA, LOW);
  digitalWrite(RmotorDirB, HIGH);
}

void setSpeed(int pwm) {
  analogWrite(LmotorPWM, pwm);
  analogWrite(RmotorPWM, pwm);
}

void stop() {
  digitalWrite(LmotorDirA, LOW);
  digitalWrite(LmotorDirB, LOW);
  digitalWrite(RmotorDirA, LOW);
  digitalWrite(RmotorDirB, LOW);
}

void search() {
  if (lastDirection == -1) {
    turnLeft();
  } else if (lastDirection == 1) {
    turnRight();
  } else {
    turnLeft(); //Default search
  }
}


// =================================
//  Utility/test functions (unused)
// =================================

void speedRampUp(int maxSpeed) {
  for(int speed = 0; speed < maxSpeed; speed++) {
    analogWrite(LmotorPWM, speed);
    analogWrite(RmotorPWM, speed);
    delay(1);
  }
}

void setSpeedLeft(int pwm) {
  analogWrite(LmotorPWM, pwm);
}
void setSpeedRight(int pwm) {
  analogWrite(RmotorPWM, pwm);
}

void backwards() {
  digitalWrite(LmotorDirA, HIGH);
  digitalWrite(LmotorDirB, LOW);
  digitalWrite(RmotorDirA, HIGH);
  digitalWrite(RmotorDirB, LOW);
}