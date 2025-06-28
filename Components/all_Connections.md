🧩 Hardware Connection Overview
🧠 System Summary
Motor Controller: ODESC v4.2 (ODrive v3.6 clone)

Microcontroller: Arduino MEGA 2560

Communication: UART using Serial2 (or Serial3)

Motor: BLDC motor (e.g. Racerstar BR2205)

Encoder: AMT102V (Incremental)

Power Supply: 24V DC, 10A (or higher)

ODrive Firmware: v0.5.1 or compatible clone firmware

🧵 1. ODESC to BLDC Motor
ODESC Motor Port	Motor Wire	Notes
M0 (or M1)	U	Phase A
M0 (or M1)	V	Phase B
M0 (or M1)	W	Phase C

⚠️ Don’t worry about motor wire order — calibration detects correct phasing.


🧭 2. ODESC to AMT102V Encoder
AMT102V Pin	ODESC Pin	Notes
VCC	3.3V	Not 5V! Only 3.3V supported on ODESC encoder input
GND	GND	Common ground
A	A	Channel A
B	B	Channel B
Z (Index)	Z	Optional but recommended
A/B/Z GND	GND	Shared with power GND


⚠️ Connect VCC to 3.3V only to avoid damaging ODESC.

Set encoder CPR:
odrv0.axis0.encoder.config.cpr = 8192


🔌 3. ODESC to Power Supply
Power Supply	ODESC Input	Notes
+24V	V+ / VM	Connect to main voltage terminal
GND	GND	Connect to power ground terminal


⚠️ Use a power supply that can handle your motor’s stall current.

Confirm voltage via:
odrv0.vbus_voltage


📡 4. ODESC to Arduino MEGA via UART
Arduino MEGA	ODESC Pins	Notes
TX (e.g., pin 16 = TX2)	RX (GPIO1)	Send commands to ODrive
RX (e.g., pin 17 = RX2)	TX (GPIO2)	Receive feedback from ODrive
GND	GND (ISOGND)	Shared ground is mandatory
5V	VCC (ISOVDD)	Powers ODESC’s isolated UART side


⚠️ Always connect ISOGND and ISOVDD if using UART.

If using Serial2 on Mega:

HardwareSerial& odrive_serial = Serial2; // pins 16 (TX2), 17 (RX2)
🧠 Optional: Multiple ODESC Boards
If using 2 motors (2 ODESCs):

Use Serial2 and Serial3 on Mega

Set UART baudrate to same (19200) on both ODESC boards:

odrv0.config.uart_baudrate = 19200
odrv1.config.uart_baudrate = 19200


📌 On Arduino MEGA:

Serial2 = pins 16 (TX2), 17 (RX2)
Serial3 = pins 14 (TX3), 15 (RX3)

