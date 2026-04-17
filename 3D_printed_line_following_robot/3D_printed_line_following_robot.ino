
const int sensor1 = 36; //SVP 
const int sensor2 = 39; //SUN
const int sensor3 = 34; //P34

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
}

void loop() {
  while (!Serial.available()) {}
  String input = Serial.readStringUntil('\n');
  input.trim();

  if (input == "Backwards") {
    digitalWrite(LmotorDirA, HIGH);
    digitalWrite(LmotorDirB, LOW);
    digitalWrite(RmotorDirA, HIGH);
    digitalWrite(RmotorDirB, LOW);
  } else if (input == "Straight") {
    digitalWrite(LmotorDirA, LOW);
    digitalWrite(LmotorDirB, HIGH);
    digitalWrite(RmotorDirA, LOW);
    digitalWrite(RmotorDirB, HIGH);
  } else if (input == "Stop") {
    digitalWrite(LmotorDirA, LOW);
    digitalWrite(LmotorDirB, LOW);
    digitalWrite(RmotorDirA, LOW);
    digitalWrite(RmotorDirB, LOW);
  } else if (input == "Slow") {
    analogWrite(LmotorPWM, 90);
    analogWrite(RmotorPWM, 90);
  } else if (input == "Medium") {
    analogWrite(LmotorPWM, 150);
    analogWrite(RmotorPWM, 150);
  } else if (input == "Fast") {
    analogWrite(LmotorPWM, 255);
    analogWrite(RmotorPWM, 255);
  } else if (input == "Sensor Status") {
    Serial.print("Sensor 1: ");
    Serial.println(digitalRead(sensor1));
    Serial.print("Sensor 2: ");
    Serial.println(digitalRead(sensor2));
    Serial.print("Sensor 3: ");
    Serial.println(digitalRead(sensor3));
  }
}
