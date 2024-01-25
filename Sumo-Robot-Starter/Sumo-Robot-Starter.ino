/*
 Project: Sumo Robot Starter          Activity: mirobo.tech/arps
 Date:    January 18, 2024
 
 This is a starter program template to create a simple classroom Sumo robot
 using the mirobo.tech ARPS circuit and an Arduino UNO. Follow the
 instructions in the program code comments to complete the program.

 This program was designed to make classroom Sumo robots using the Robo-Sumo
 competitions rules on the mirobo site (https://mirobo.tech/robo-sumo-rules)
 and can easily be adapted for making other kinds of robots using ARPS.

 Find introductory ARPS learning activities here: https://mirobo.tech/arps
*/

// Define I/O pins used for human interface devices
const int SW2 = 0;      // Pushbuttons
const int SW3 = 1;
const int SW4 = 2;
const int SW5 = 3;

const int LED2 = 5;     // Top LEDs
const int LED3 = 6;
const int LED4 = 9;
const int LED5 = 10;

const int BEEPER = 11;  // Piezo beeper LS1

// Define I/O pins for special purpose interface devices
const int M1A = 5;      // Motor 1 - output A
const int M1B = 6;      // Motor 1 - output B
const int M2A = 9;      // Motor 2 - output A
const int M2B = 10;     // Motor 2 - output B

const int IR = 4;       // IR demodulator input

const int LED6 = 7;     // LED6 output and +5V supply for left floor/line sensors Q1 and Q2
const int LED7 = 8;     // LED7 output and +5V supply for right floor sensor Q3
const int Q1 = A0;      // Left floor/line sensor phototransistor
const int Q2 = A1;      // Right line sensor phototransistor
const int Q3 = A1;      // Right floor sensor phototransistor

const int H1 = 18;      // Header H1
const int H2 = 13;      // Header H2 (shared with SONAR and onboardLED)
const int TRIG = 13;    // Ultrasonic SONAR distance sensor TRIG(ger) output
const int H3 = 12;      // Header H3 (shared with SONAR)
const int ECHO = 12;    // Ultrasonic SONAR distance sensor ECHO input
const int H4 = 19;      // Header H4

const int VTMP = A2;    // ARPS temperature sensor Vout
const int VDIV = A3;    // ARPS voltage divider Vout

const int onboardLED = 13;  // On Arduino Uno (shared with H2 and SONAR TRIG)

// Define program constants
const int STARTUP = 0;  // Startup mode
const int SEARCH = 1;   // Search mode
const int ATTACK = 2;   // Attack mode
const int LIGHT = LOW;
const int DARK = HIGH;

// Define variables
int SW2state;           // Button state variables
int SW3state;
int SW4state;
int SW5state;
int mode;               // Current operating mode
int floorLeft;          // Left floor sensor state
int floorRight;         // Right floor sensor state

// Setup code runs once to configure I/O pins before running main loop
void setup() {
  pinMode(onboardLED,OUTPUT);
  pinMode(SW2,INPUT_PULLUP);
  pinMode(SW3,INPUT_PULLUP);
  pinMode(SW4,INPUT_PULLUP);
  pinMode(SW5,INPUT_PULLUP);
  pinMode(LED2,OUTPUT); // LEDs and motors share the same pins
  pinMode(LED3,OUTPUT);
  pinMode(LED4,OUTPUT);
  pinMode(LED5,OUTPUT);
  pinMode(BEEPER,OUTPUT);
  pinMode(IR,INPUT);
  pinMode(LED6,OUTPUT);
  pinMode(LED7,OUTPUT);
  pinMode(Q1,INPUT);
  pinMode(Q2,INPUT);    // Q2 and Q3 share the same pin
  pinMode(H1,INPUT);    // Define unused header pins as input
  pinMode(TRIG,OUTPUT); // H2/TRIG SONAR output (if installed)
  pinMode(ECHO,INPUT);  // H3/ECHO SONAR input
  pinMode(H4,INPUT);    // Define unused header pins as input
  pinMode(VTMP,INPUT);
  pinMode(VDIV,INPUT);

  // Set robot outputs and make a beep
  stop();               // Call stop function to keep the motors off
  tone(BEEPER,4000,100);  // Say hello!
  mode = STARTUP;       // Set startup mode
}

// Main loop code repeats forever
void loop() {
  // while() loops within loop() are like mini self-contained programs.
  // Switch between the while() loops by changing the mode variable.

  while(mode == STARTUP) {
    // Wait for a button to be pressed. If the button is pressed,
    // start a 5s countdown and then switch to SEARCH mode as shown:
    // mode = SEARCH;
  }

  while(mode == SEARCH) {
    // Use the SONAR to look for the opposing robot while monitoring
    // the floor sensors to stay in the Sumo ring. If an opposing
    // robot is within range, switch to ATTACK mode.
  }

  while(mode == ATTACK) {
    // Push the opposing robot out of the SUMO ring while monitoring
    // the floor sensors to stay in the ring. If the opposing robot is
    // no longer detected, switch to SEARCH mode.
  }
}

// Motor movement functions. Create a function for each direction that your
// robot should drive in. Can you come up with eight different possible
// movement directions, plus stop? Does your robot need all eight? If you
// create all of the different movement functions now, you will be able to
// easily adapt your robot for other types of tasks later.

// stop() function - Turns all motor outputs off
void stop() {
  digitalWrite(M1A,LOW);
  digitalWrite(M1B,LOW);
  digitalWrite(M2A,LOW);
  digitalWrite(M2B,LOW);
}

// fwd() function - Turns left and right motors on in opposite directions. Use
// this function to test your motors. If your robot does not move forward then
// either switch the wires of the backwards motor(s) on the ARPS screw terminal
// strip, or use the opposite HIGH and LOW output values in the code below:
void fwd() {
  digitalWrite(M1A,HIGH);
  digitalWrite(M1B,LOW);
  digitalWrite(M2A,LOW);
  digitalWrite(M2B,HIGH);
}

// Create a function similar to fwd(), above, for every other direction that
// you would like your robot to move in.

// Add other functions for your robot here as needed (e.g. a SONAR search
// function, a floor sensor function, or a remote-control function).
