
const int sensor1 = 34; //P34
const int sensor2 = 39; //SUN
const int sensor3 = 36; //SVP 

const int LmotorPWM = 32; //P32
const int RmotorPWM = 33; //P33

const int LmotorDirA = 19; // P19
const int LmotorDirB = 18; // P18
const int RmotorDirA = 14; // P14
const int RmotorDirB = 12; // P12

void setup() {
  Serial.begin(115200);

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
  while (!Serial.available()) { //Line following test code to run without Serial input 
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


  //Serial Input handling logic for testing
  String input = Serial.readStringUntil('\n');
  input.trim();

  if (input == "Backwards") {
    backwards();
  } else if (input == "Straight") {
    forwards();
  } else if (input == "Stop") {
    stop();
  } else if (input == "Slow") {
    slow();
  } else if (input == "Medium") {
    medium();
  } else if (input == "Fast") {
    fast();
  } else if (input == "Sensor Status") {
    Serial.print("Sensor 1: ");
    Serial.println(digitalRead(sensor1));
    Serial.print("Sensor 2: ");
    Serial.println(digitalRead(sensor2));
    Serial.print("Sensor 3: ");
    Serial.println(digitalRead(sensor3));
  }
}

//Motor control functions 

void forwards() {
  digitalWrite(LmotorDirA, LOW);
  digitalWrite(LmotorDirB, HIGH);
  digitalWrite(RmotorDirA, LOW);
  digitalWrite(RmotorDirB, HIGH);
}

void backwards() {
  digitalWrite(LmotorDirA, HIGH);
  digitalWrite(LmotorDirB, LOW);
  digitalWrite(RmotorDirA, HIGH);
  digitalWrite(RmotorDirB, LOW);
}

void stop() {
  digitalWrite(LmotorDirA, LOW);
  digitalWrite(LmotorDirB, LOW);
  digitalWrite(RmotorDirA, LOW);
  digitalWrite(RmotorDirB, LOW);
}

void slow() {
  analogWrite(LmotorPWM, 90);
  analogWrite(RmotorPWM, 90);
}

void medium() {
  analogWrite(LmotorPWM, 150);
  analogWrite(RmotorPWM, 150);
}

void fast() {
  analogWrite(LmotorPWM, 255);
  analogWrite(RmotorPWM, 255);
}

void setSpeedLeft(int pwm) {
  analogWrite(LmotorPWM, pwm);
}
void setSpeedRight(int pwm) {
  analogWrite(RmotorPWM, pwm);
}

void setSpeed(int pwm) {
  analogWrite(LmotorPWM, pwm);
  analogWrite(RmotorPWM, pwm);
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

void search() {
  if (lastDirection == -1) {
    turnLeft();
  }
  if (lastDirection == 1) {
    turnRight();
  } else {
    turnLeft(); //Default search
  }
}

void speedRampUp(int max) {
  for(int speed = 0; speed < max; speed++) {
    analogWrite(LmotorPWM, speed);
    analogWrite(RmotorPWM, speed);
    delay(1);
  }
}