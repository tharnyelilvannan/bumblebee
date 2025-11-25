int ECHO = 8; // echo value back 
int TRIG = 9; // triggers sound output
int duration; // duration it takes for pulse echo off object and come back
float distance; // distance to object
int IR_LED = 13; // LED on IR sensor
int IR_INPUT = 7; // input pin for IR sensor
int IR_isObstacle = HIGH; // for IR sensor, high means yes

void setup() {

  Serial.begin(9600);

  // initialize IR
  pinMode(IR, INPUT);
  pinMode(LED, OUTPUT);

  // initialize US
  pinMode(TRIG, OUTPUT);
  pinMode(ECHO, INPUT);

  // ensure trigger is set to low at first
  digitalWrite(TRIG, LOW);

}

void loop() {

  // IR
  IR_isObstacle = digitalRead(IR_INPUT);

  if (IR_isObstacle == LOW)
  {
    Serial.println("White surface.");
    digitalWrite(IR_LED, HIGH);
  }
  else
  {
    Serial.println("Black surface.");
    digitalWrite(IR_LED, LOW);
  }

  delay(200);

  // US
   
  digitalWrite(TRIG, HIGH); // pulse trigger
  delayMicroseconds(10); 
  digitalWrite(TRIG, LOW);
  duration = pulseIn(ECHO, HIGH); // read echo

  if (duration >= 38000) {

    Serial.print("Out of range"); 

  }
  else
  {
    // calculate distance to object
    distance = duration / 58; 
    Serial.print(distance); 
    Serial.println(" cm");

  }

  delay(1000); 

}
