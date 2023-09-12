#include <SoftwareSerial.h>

// Bluetooth module's TX and RX pins
SoftwareSerial bluetooth(0, 1); // RX, TX

// Relay module control pins
const int relay1Pin = 2;
const int relay2Pin = 3;
// Add more relay pins as needed

void setup() {
  // Set relay pins as OUTPUT
  pinMode(relay1Pin, OUTPUT);
  pinMode(relay2Pin, OUTPUT);
  // Add more relay pins as needed

  // Start serial communication with Bluetooth module
  bluetooth.begin(9600);
}

void loop() {
  if (bluetooth.available() > 0) {
    char command = bluetooth.read();
    processCommand(command);
  }
}

void processCommand(char command) {
  // Process the command received from the smartphone via Bluetooth
  // You can define your own commands to control specific appliances
  
  switch (command) {
    case '1':
      digitalWrite(relay1Pin, HIGH); // Turn ON relay 1 (Control appliance 1)
      break;
    case '2':
      digitalWrite(relay1Pin, LOW); // Turn OFF relay 1
      break;
    case '3':
      digitalWrite(relay2Pin, HIGH); // Turn ON relay 2 (Control appliance 2)
      break;
    case '4':
      digitalWrite(relay2Pin, LOW); // Turn OFF relay 2
      break;
    // Add more cases for additional appliances if needed
    default:
      // Invalid command received, do nothing
      break;
  }
}
