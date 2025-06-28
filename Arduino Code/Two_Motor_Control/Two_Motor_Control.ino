#include <ODriveUART.h>

// ODrive A on Serial2 (TX=16, RX=17)
HardwareSerial& odriveA_serial = Serial2;
ODriveUART odriveA(odriveA_serial);

// ODrive B on Serial3 (TX=14, RX=15)
HardwareSerial& odriveB_serial = Serial3;
ODriveUART odriveB(odriveB_serial);

const int baudrate = 19200;  // Match ODrive UART settings
int target_velocity = 0;

void setup() {
  Serial.begin(115200);  // Debug Serial Monitor
  odriveA_serial.begin(baudrate);
  odriveB_serial.begin(baudrate);

  delay(1000);

  Serial.println("Connecting to both ODrives...");

  // Wait for ODrive A
  while (odriveA.getState() == AXIS_STATE_UNDEFINED) {
    Serial.println("Waiting for ODrive A...");
    delay(100);
  }

  // Wait for ODrive B
  while (odriveB.getState() == AXIS_STATE_UNDEFINED) {
    Serial.println("Waiting for ODrive B...");
    delay(100);
  }

  Serial.println("Both ODrives Found!");

  // Enable Closed Loop Control
  while (odriveA.getState() != AXIS_STATE_CLOSED_LOOP_CONTROL) {
    odriveA.clearErrors();
    odriveA.setState(AXIS_STATE_CLOSED_LOOP_CONTROL);
    Serial.println("ina");
    delay(10);
  }

  while (odriveB.getState() != AXIS_STATE_CLOSED_LOOP_CONTROL) {
    odriveB.clearErrors();
    odriveB.setState(AXIS_STATE_CLOSED_LOOP_CONTROL);
    Serial.println("inb");
    delay(10);
  }

  Serial.println("Both ODrives ready in Closed Loop!");
}

void loop() {
  // Take speed input from Serial Monitor
  if (Serial.available()) {
    target_velocity = Serial.parseInt();  // Example: type 60 in serial monitor
  }

  // Send same velocity to both ODrives
  odriveA.setVelocity(-target_velocity);
  odriveB.setVelocity(target_velocity);

  // Optional: Print feedback from both motors
  ODriveFeedback feedbackA = odriveA.getFeedback();
  ODriveFeedback feedbackB = odriveB.getFeedback();

  Serial.print("Target Vel: ");
  Serial.print(target_velocity);
  Serial.print(" | A Vel: ");
  Serial.print(feedbackA.vel);
  Serial.print(" | B Vel: ");
  Serial.println(feedbackB.vel);

  delay(5);
}
