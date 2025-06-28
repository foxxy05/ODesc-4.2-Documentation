#include <ODriveUART.h>

// Use Serial1 on Arduino Mega (TX = pin 18, RX = pin 19)
HardwareSerial& odrive_serial = Serial2;
int baudrate = 19200;  // Match with odrive.config.uart_baudrate
int target_velocity =0;
ODriveUART odrive(odrive_serial);

void setup() {
  odrive_serial.begin(baudrate);
  Serial.begin(115200); // Debug to Serial Monitor

  delay(100);

  Serial.println("Waiting for ODrive...");
  while (odrive.getState() == AXIS_STATE_UNDEFINED) {
    delay(100);
  }

  Serial.println("ODrive Found!");
  Serial.print("Bus Voltage: ");
  Serial.println(odrive.getParameterAsFloat("vbus_voltage"));

  // Put into closed loop control
  while (odrive.getState() != AXIS_STATE_CLOSED_LOOP_CONTROL) {
    odrive.clearErrors();
    odrive.setState(AXIS_STATE_CLOSED_LOOP_CONTROL);
    delay(10);
  }

  Serial.println("ODrive ready in closed loop!");
}

void loop() {
  if(Serial.available()){
    target_velocity = Serial.parseInt();
  }
  // float target_velocity = 20.0; // counts/sec
  odrive.setVelocity(target_velocity);

  ODriveFeedback feedback = odrive.getFeedback();
  Serial.print("Vel Cmd: ");
  Serial.print(target_velocity);
  Serial.print(" | Actual Vel: ");
  Serial.print(feedback.vel);
  Serial.print(" | Pos: ");
  Serial.println(feedback.pos);

  delay(5);
}
