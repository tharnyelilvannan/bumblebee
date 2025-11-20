int ECHO = 8; // echo value back 
int TRIG = 9; // triggers sound output
int duration; 
float distance;
float meter;
int LED = 13;
int IR = 7; // input pin for IR sensor
int isObstacle_IR = HIGH; // for IR sensor, high means yes

void setup() {
  Serial.begin(9600);

  pinMode(LED, OUTPUT);
  pinMode(IR, INPUT);
  pinMode(TRIG, OUTPUT);
  pinMode(ECHO, INPUT);

  digitalWrite(TRIG, LOW);


}

void loop() {

  // IR
  isObstacle_IR = digitalRead(IR);
  if (isObstacle_IR == LOW)
  {
    Serial.println("OBSTACLE!!, OBSTACLE!!");
    digitalWrite(LED, HIGH);
  }
  else
  {
    Serial.println("clear");
    digitalWrite(LED, LOW);
  }
  delay(200);

  // ULTRASONIC
   
  digitalWrite(TRIG, HIGH); 
  delayMicroseconds(10); 
  digitalWrite(TRIG, LOW); 
  duration = pulseIn(ECHO, HIGH);
  if(duration>=38000){
    Serial.print("Out range"); 
  }
  else
  {
    distance = duration/58; 
    Serial.print(distance); 
    Serial.print("cm");
    meter=distance/100;
    Serial.print("\t");
    Serial.print(meter);
    Serial.println("m");
  }
  delay(1000); 


}
