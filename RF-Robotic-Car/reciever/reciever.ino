#include <RCSwitch.h> // This is the RC-Switch library

RCSwitch mySwitch = RCSwitch(); 

// L298N Motor 1 
const int ENA = 9;  // Enable A (PWM for speed)
const int IN1 = 5;  // Input 1
const int IN2 = 6;  // Input 2

// L298N Motor 2
const int ENB = 10; // Enable B (PWM for speed)
const int IN3 = 7;  // Input 3
const int IN4 = 8;  // Input 4

// LED Pins
const int FORWARD_LED = 3;
const int BACKWARD_LED = 4;

// Define the same unique codes as in the Transmitter
// Must be the same 
const unsigned long CODE_STOP = 100000;
const unsigned long CODE_FORWARD = 100001;
const unsigned long CODE_BACKWARD = 100002;
const unsigned long CODE_LEFT = 100003;
const unsigned long CODE_RIGHT = 100004;
const unsigned long CODE_PIVOT_LEFT = 100005;
const unsigned long CODE_PIVOT_RIGHT = 100006;

// Motor speed (adjust as needed, 0-255)
const int DEFAULT_SPEED = 180; 

// Our set-up Function
void setup() {
  Serial.begin(9600);
  // Receiver Data Pin (usually D2 for interrupt 0)
  // Connect MX-RM-5V DATA pin to Arduino UNO Digital Pin 2
  
  mySwitch.enableReceive(0);
  mySwitch.setProtocol(1);
  mySwitch.setPulseLength(180); // protocol and pulse length here too 

  // Set motor control pins as outputs
  pinMode(ENA, OUTPUT);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(ENB, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);

  // Set LED pins as outputs
  pinMode(FORWARD_LED, OUTPUT);
  pinMode(BACKWARD_LED, OUTPUT);

  // Initially stop motors and LEDs // the resting point
  stopMotors();
  digitalWrite(FORWARD_LED, LOW);
  digitalWrite(BACKWARD_LED, LOW);
}

// Here is the loop, main function
void loop() {
  if (mySwitch.available()) {
    unsigned long receivedValue = mySwitch.getReceivedValue();
    int receivedBitLength = mySwitch.getReceivedBitlength();
    int receivedDelay = mySwitch.getReceivedDelay();
    int receivedProtocol = mySwitch.getReceivedProtocol();

    Serial.print("Received: ");
    Serial.print(receivedValue);
    Serial.print(" / ");
    Serial.print(receivedBitLength);
    Serial.print("bit / Delay: ");
    Serial.print(receivedDelay);
    Serial.print("us / Protocol: ");
    Serial.println(receivedProtocol);

    // Logic for Movements
    if (receivedValue == CODE_FORWARD) {
      moveForward(DEFAULT_SPEED);
      digitalWrite(FORWARD_LED, HIGH);
      digitalWrite(BACKWARD_LED, LOW);
    } else if (receivedValue == CODE_BACKWARD) {
      moveBackward(DEFAULT_SPEED);
      digitalWrite(FORWARD_LED, LOW);
      digitalWrite(BACKWARD_LED, HIGH);
    } else if (receivedValue == CODE_LEFT) {
      turnLeft(DEFAULT_SPEED); 
      digitalWrite(FORWARD_LED, HIGH); 
      digitalWrite(BACKWARD_LED, LOW);
    } else if (receivedValue == CODE_RIGHT) {
      turnRight(DEFAULT_SPEED);
      digitalWrite(FORWARD_LED, HIGH);
      digitalWrite(BACKWARD_LED, LOW);
    } else if (receivedValue == CODE_PIVOT_LEFT) {
      pivotLeft(DEFAULT_SPEED);
      digitalWrite(FORWARD_LED, LOW); 
      digitalWrite(BACKWARD_LED, LOW);
    } else if (receivedValue == CODE_PIVOT_RIGHT) {
      pivotRight(DEFAULT_SPEED);
      digitalWrite(FORWARD_LED, LOW);
      digitalWrite(BACKWARD_LED, LOW);
    } else if (receivedValue == CODE_STOP) {
      stopMotors();
      digitalWrite(FORWARD_LED, HIGH); 
      digitalWrite(BACKWARD_LED, LOW);
    }

    mySwitch.resetAvailable();
  }
}

// A helper function to control a single motor // Needed
void setMotor(int in1, int in2, int ena, int dir1, int dir2, int speed) {
  digitalWrite(in1, dir1);
  digitalWrite(in2, dir2);
  analogWrite(ena, speed);
}
