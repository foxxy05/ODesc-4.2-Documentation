## 📄 Overview

This repository provides a complete, end-to-end guide for configuring and running a Brushless DC (BLDC) motor using the ODESC v4.2 motor driver board (a hardware-compatible clone of ODrive v3.6) with an Arduino Mega via UART communication. The project focuses on achieving precise velocity and position control using encoder feedback, calibrated through ODrive firmware, and controlled serially (or wirelessly) through Arduino. It is tailored for anyone looking to integrate low-cost ODrive clones into robotics or automation projects.

## ⚡ Quick Start

1. Flash the firmware using [guide](ODesc_Firmware/flashing_Methods.md).
2. Wire the motor, encoder, and Arduino as per [this](Components/all_Connections.md).
3. Upload [One_Motor_Control](Arduino Code/One_Motor_Control) or [Two_Motor_Control](Arduino Code/Two_Motor_Control) sketch to Arduino.
4. Run `odrivetool` to verify firmware and test calibration.

## 📚 Full Documentation Index

### 🧰 Components & Diagrams
- 🔩 [Hardware Components](Components/Components.md)
- 🧷 [All Wiring Connections](Components/all_Connections.md)
- 🖼️ [ODESK Wiring Diagram](Diagrams/ODESC_Wiring_Diagram.png)

### ⚙️ Firmware
- 💾 [Firmware Flashing Methods (DFU & STLink)](ODesc_Firmware/flashing_Methods.md)
- 🧠 [ODrive Firmware - HEX File](ODesc_Firmware/ODrive_4_2.hex)
- 🧠 [ODrive Firmware - BIN File](ODesc_Firmware/ODrive_4_2.bin)
- 🧠 [Working ODESC Firmware HEX](ODesc_Firmware/workign_odesc_firmware.hex)

### 💻 Arduino Code
- 🎮 [Single Motor Control Code](Arduino Code/One_Motor_Control)
  - `SingleMotorControl.ino`
- 🎮 [Dual Motor Control Code](Arduino Code/Two_Motor_Control)
  - `DualMotorControl.ino`

### 📟 Terminal & UART
- 📡 [ODrive UART & Terminal Commands](Documents/Terminal_Commands.md)

### 🧨 Error Handling
- ❗ [ODESC Errors & Fixes](Documents/Errors.md)


### 📌 Objective

- Establish closed-loop velocity and position control of a BLDC motor using encoder feedback.
- Flash official ODrive firmware to the ODESC v4.2 board.
- Calibrate the motor and encoder using `odrivetool`.
- Handle and fix common calibration and communication errors (e.g., MOTOR_FAILED, ENCODER_FAILED).
- Set up UART communication to control two motors simultaneously via Arduino Mega (Serial2 and Serial3).
- Control the motors using custom Arduino sketches.
- Fine-tune motor settings like ramp speeds, current limits, etc.

### 🔌 What’s Inside the Repository

- Step-by-step setup and calibration instructions using `odrivetool`.
- Arduino code for UART-based motor control.
- Python snippets for configuration and testing.
- Logs of error messages and their fixes.
- Precompiled `.hex` firmware and flashing instructions (optional).

### ✅ Final Outcome

By the end of this guide, you will be able to:

- Run two BLDC motors in closed-loop control using encoder feedback.
- Control motor velocity or position using UART commands from Arduino.
- Monitor and log real-time motor data like speed and position.

---

### EXTERNAL TOOLS
- [Zadig](https://zadig.akeo.ie/)
- [STM32CubeProgrammer](https://www.st.com/en/development-tools/stm32cubeprog.html)
- [ODrive GitHub Repo](https://github.com/madcowswe/ODrive)

