## 🧰 Hardware Components

| Component                    | Description                                                                 |
|-----------------------------|-----------------------------------------------------------------------------|
| **ODESK v4.2**              | BLDC Motor Driver (Hardware clone of ODrive v3.6)                          |
| **STM32F405RGT6**           | Microcontroller on the ODESC board                                         |
| **BLDC Motor**              | Brushless DC motor with 3-phase wires (used for testing & control)         |
| **AMT102V Encoder**         | Incremental rotary encoder (CPR = 8192), with index pulse                  |
| **Arduino Mega 2560**       | Used for UART control and serial feedback                                  |
| **Jumper Wires (Male-Female)** | For encoder to ODESC, ODESC to Arduino UART connections                 |
| **Power Supply (24V DC)**   | To power the ODESC and motor                                                |
| **USB Cable (Micro-USB)**   | To connect ODESC to PC for flashing and calibration                        |
| **Windows PC**              | For firmware flashing, configuration, calibration, and monitoring          |

---

## 🖥️ Software & Tools

| Tool / Library / Software         | Purpose                                                                     |
|----------------------------------|------------------------------------------------------------------------------|
| **ODrive Firmware (v0.5.x)**     | Controls motor driver logic on the ODESC board                               |
| **ODrive Python Tool (odrivetool)** | Used for calibration, control, and debugging over USB                     |
| **Python 3.10+**                 | Required for running `odrivetool` and scripting                              |
| **Arduino IDE**                 | Writing and uploading UART control code to Arduino                           |
| **ODriveUART Library**          | Arduino library for sending commands to ODrive via UART                      |
| **dfu-util (v0.9)**             | Used for flashing firmware to the ODESC over USB DFU                         |
| **Zadig**                       | USB driver installer for ODESC (WinUSB driver for USB communication)         |
| **STM32CubeProgrammer** *(Optional)* | Alternative firmware flashing tool from STMicroelectronics             |
| **GNU Arm Embedded Toolchain**  | Required for building custom firmware (if needed)                            |
| **Serial Monitor / PuTTY**      | For viewing real-time UART output and debugging                              |
