#include <IRremote.h>
#include <Servo.h>

// Pin Definitions
const int RemotePin = 8;
const int in1 = 3;
const int in2 = 5;
const int in3 = 6;
const int in4 = 9;
const int motorPin = 10;  // New motor control pin

// IR and Servo Setup
IRrecv irrecv(RemotePin);
decode_results results;
Servo motor;  // Create a servo object to control the new motor

void setup() {
  Serial.begin(9600);
  irrecv.enableIRIn();  // Start the IR receiver

  // Pin Modes for the 4 motors
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);

  // Setup new motor control
  motor.attach(motorPin);  // Attach the new motor to pin 10
  motor.write(90);  // Set motor to neutral/stop position
}

void loop() {
  if (irrecv.decode(&results)) {
    // IR Commands to control the motors
    if (results.value == 0xFF629D) {  // Press UP Button
      Forward();
    } 
    else if (results.value == 0xFFA857) {  // Press Down Button
      Backward();
    } 
    else if (results.value == 0xFF22DD) {  // Press Left Button
      Left();
    } 
    else if (results.value == 0xFFC23D) {  // Press Right Button
      Right();
    } 
    else if (results.value == 0xFF02FD) {  // Stop
      Stop();
    } 
    else if (results.value == 0xFFE01F) {  //  Button for controlling 1000 kHz motor
      controlMotor();  // Control the 1000 kHz motor
    }
    irrecv.resume();  // Get ready for the next IR command
  }
}

// Motor Control Functions
void Backward() {
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
}

void Forward() {
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
}

void Stop() {
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);
  motor.write(90);  // Stop the new motor
}

void Left() {
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
}

void Right() {
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);
}

void controlMotor() {
  // Example to control new motor via IR
  motor.write(180);  // Full speed in one direction
  
}
