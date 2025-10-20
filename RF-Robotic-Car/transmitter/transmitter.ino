#include <RCSwitch.h> // Include the RC-Switch library

RCSwitch mySwitch = RCSwitch(); 

// Joystick Pins
const int VRX_PIN = A0;
const int VRY_PIN = A1;
const int SW_PIN = 2; // This pin can be use for Buzzers for horns or leds to simulate horns

// Dead zone for joystick to prevent drift when centered
const int JOYSTICK_DEADZONE = 50;

// Define unique codes for different movements
// You can choose any distinct long integer values
const unsigned long CODE_STOP = 100000;
const unsigned long CODE_FORWARD = 100001;
const unsigned long CODE_BACKWARD = 100002;
const unsigned long CODE_LEFT = 100003;
const unsigned long CODE_RIGHT = 100004;
const unsigned long CODE_PIVOT_LEFT = 100005;
const unsigned long CODE_PIVOT_RIGHT = 100006;

// Our set-up Function
void setup() {
  Serial.begin(9600);
  // The TX pin for RCSwitch is often D10, but can be changed.
  // Connect FS1000A DATA pin to Arduino Nano Digital Pin 10
  mySwitch.enableTransmit(10); // Transmit on Digital Pin 10 (or adjust as needed)
  mySwitch.setProtocol(1); 
  mySwitch.setPulseLength(180); // protocol and pulse length here

  pinMode(SW_PIN, INPUT_PULLUP);
}

void loop() {
  int xValue = analogRead(VRX_PIN); 
  int yValue = analogRead(VRY_PIN); 
  int swState = digitalRead(SW_PIN); 

  unsigned long codeToSend = CODE_STOP;

  // Y value for the forward movements
  if (yValue < (512 - JOYSTICK_DEADZONE)) { // Forward
    if (xValue < (512 - JOYSTICK_DEADZONE)) { // Turn Left while moving forward
      codeToSend = CODE_LEFT; 
    } else if (xValue > (512 + JOYSTICK_DEADZONE)) { // Turn Right while moving forward
      codeToSend = CODE_RIGHT; 
    } else { // Straight Forward
      codeToSend = CODE_FORWARD;
    }  // X value for the backard movements
  } else if (yValue > (512 + JOYSTICK_DEADZONE)) { // Backward
    if (xValue < (512 - JOYSTICK_DEADZONE)) { // Turn Left while moving backward
      codeToSend = CODE_LEFT; 
    } else if (xValue > (512 + JOYSTICK_DEADZONE)) { // Turn Right while moving backward
      codeToSend = CODE_RIGHT;
    } else {                            // Straight Backward
      codeToSend = CODE_BACKWARD;
    }
  } else { 
    if (xValue < (512 - JOYSTICK_DEADZONE)) { // Pivot Left
      codeToSend = CODE_PIVOT_LEFT;
    } else if (xValue > (512 + JOYSTICK_DEADZONE)) { // Pivot Right
      codeToSend = CODE_PIVOT_RIGHT;
    } else { 
      codeToSend = CODE_STOP;
    }
  }

  // Send the determined code
  mySwitch.send(codeToSend, 24); // 24 is a common bit length for these modules

  Serial.print("Sent code: ");
  Serial.println(codeToSend);

  delay(100); // Adjust delay for desired responsiveness and transmission rate
}