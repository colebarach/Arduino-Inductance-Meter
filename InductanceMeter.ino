// Capacitance Meter
//   Author - Cole Barach
//   Date Created - 22.07.11
//   Date Updated - 22.07.11
//   Usage - Connect an inductor in parallel with a capacitor to form a LC circuit.
//     The input to this circuit will be the Wave Pin, which will stimulate the circuit
//     at a variable frequency, the frecuency at which the inductor's voltage is highest
//     indicates its inductance.

// Includes
#include <TimerOne.h>

// Pinout
const int potentiometerPin = A0;
const int wavePin          = 9;

// Potentiometer Config
long frequencyHigh = 300;
long frequencyLow  = 200;

void setup() {
  Serial.begin(9600);
  Timer1.initialize(1000000/480);
  
  pinMode(potentiometerPin, INPUT);
  pinMode(wavePin,          OUTPUT);
}

void loop() {
  long potentiometer = analogRead(potentiometerPin)*(frequencyHigh-frequencyLow);
  long frequency = potentiometer/1024.0f + frequencyLow;
  int period = 1000000/frequency;

  Timer1.pwm(wavePin,512,period);
  
  Serial.println("");
  Serial.print(frequency);
  Serial.print("Hz : ");
  Serial.print(period);
  Serial.print(" us");
}
