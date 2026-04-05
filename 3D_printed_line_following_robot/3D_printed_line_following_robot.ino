
const int sensor = 4; //D2 


void setup() {
  Serial.begin(9600);

  pinMode(sensor, INPUT);
}

void loop() {
  if (digitalRead(sensor) == HIGH) {
    Serial.println("No object");
  } else {
    Serial.println("Object");
  }
  delay(500);
}
