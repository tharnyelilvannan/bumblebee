#include <Arduino.h>
#include <SparkFun_TB6612.h>

// US1 initializations
#define RIGHT_ECHO 8 // echo value back 
#define RIGHT_TRIG 9 // triggers sound output
int right_duration; // duration it takes for pulse echo off object and come back
float right_distance; // distance to object

// US2 initializations
#define LEFT_ECHO 13
#define LEFT_TRIG 12
int left_duration;
float left_distance;


// IR initializations
#define IR_INPUT 7 // input pin for IR sensor
int IR_isObstacle = HIGH; // for IR sensor, high means yes

// motor initializationso
#define AIN1 2
#define BIN1 4
#define AIN2 3
#define BIN2 5
#define PWMA 10
#define PWMB 11
#define STBY 6
const int offsetA = 1;
const int offsetB = 1;
Motor left_motor = Motor(AIN1, AIN2, PWMA, offsetA, STBY);
Motor right_motor = Motor(BIN1, BIN2, PWMB, offsetB, STBY);

void setup() {

  Serial.begin(9600);

  // initialize IR
  pinMode(IR_INPUT, INPUT);

  // initialize US1
  pinMode(RIGHT_TRIG, OUTPUT);
  pinMode(RIGHT_ECHO, INPUT);

  // initialize US2
  pinMode(LEFT_TRIG, OUTPUT);
  pinMode(LEFT_ECHO, INPUT);

  // ensure trigger is set to low at first
  digitalWrite(RIGHT_TRIG, LOW);
  digitalWrite(LEFT_TRIG, LOW);

}

void loop() {

  // IR
  IR_isObstacle = digitalRead(IR_INPUT);

  if (IR_isObstacle == LOW) {

    Serial.println("White surface.");

  }
  else {

    Serial.println("Black surface.");

  }

  delay(200);

  // US1
  digitalWrite(RIGHT_TRIG, HIGH); // pulse trigger
  delayMicroseconds(10); 
  digitalWrite(RIGHT_TRIG, LOW);
  right_duration = pulseIn(RIGHT_ECHO, HIGH); // read echo

  if (right_duration >= 38000) {

    Serial.print("Out of range"); 

  }
  else {

    // calculate distance to object
    right_distance = right_duration / 58; 
    Serial.print(right_distance); 
    Serial.println(" cm");

  }

  delay(1000); 

  // US2
  digitalWrite(LEFT_TRIG, HIGH); // pulse trigger
  delayMicroseconds(10); 
  digitalWrite(LEFT_TRIG, LOW);
  left_duration = pulseIn(LEFT_ECHO, HIGH); // read echo

  if (left_duration >= 38000) {

    Serial.print("Out of range"); 

  }
  else {

    // calculate distance to object
    left_distance = left_duration / 58; 
    Serial.println(left_duration);
    Serial.print(left_distance); 
    Serial.println(" cm");

  }

  delay(1000); 

}
