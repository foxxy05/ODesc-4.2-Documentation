## 🔥 Firmware Flashing Methods Used (DFU and STLink)

To run the ODrive firmware on the **ODESK v4.2** board (clone of ODrive v3.6), we used two firmware flashing methods depending on the board's bootloader state:

---

### ⚙️ Method 1: DFU Flashing (Via USB — No STLink Required)

#### ✅ When to Use:
- ODESC enters DFU mode on boot (e.g., **BOOT & RESET** button combo used).
- USB port is working and the board appears as **"STM32 BOOTLOADER"** in Device Manager.

#### 🧰 Tools Required:
- `dfu-util` (for Windows)
- Zadig
- Precompiled `firmware.hex` (generated from `firmware.elf` using `arm-none-eabi-objcopy`)

#### 🔌 Steps:

1. **Enter DFU Mode on ODESC**
    - Press and hold the **BOOT** button on the board.
    - Tap the **RESET** button once while holding **BOOT**.
    - Release the **BOOT** button.  
    → The board should now show up as **STM32 Bootloader** in Windows.

2. **Install USB DFU Driver**
    - Open **Zadig**
    - Go to `Options > List All Devices`
    - Select **STM32 Bootloader**
    - Choose **WinUSB** driver and click **Install Driver**

3. **Flash Using dfu-util**
    - Open Command Prompt in the folder with `dfu-util.exe` and `firmware.hex`:
      ```bash
      dfu-util.exe -d 0483:df11 -a 0 -s 0x08000000:leave -D firmware.hex
      ```
    - ✅ If successful, you’ll see: `File downloaded successfully`.

4. **Reconnect & Detect**
    - Unplug USB and reconnect.
    - Run `odrivetool` — the board should now show up as **ODrive v3.6**.

---

### 🔧 Method 2: STLink Flashing (Using External Debugger)

#### ✅ When to Use:
- DFU mode is broken or USB bootloader is not responding.
- You want to directly write firmware to the chip via **SWD** interface.

#### 🧰 Tools Required:
- **STLink V2** (cloned or genuine)
- **STM32CubeProgrammer**
- **Dupont wires** (for SWD connections)
- Precompiled `firmware.hex`

#### 🔌 Pin Connections:

| STLink Pin | ODESC Pin |
|------------|------------|
| SWDIO      | SWDIO      |
| SWCLK      | SWCLK      |
| GND        | GND        |
| 3.3V       | 3.3V       |

> 💡 *Make sure your ODESC is powered (via USB or external 5V) while flashing. Don’t power it from STLink if it's already externally powered.*

#### 🪛 Steps:

1. **Connect STLink to ODESC**
    - Match pins: SWDIO, SWCLK, GND, and 3.3V.

2. **Open STM32CubeProgrammer**
    - Select **STLink** as the interface.
    - Click **Connect**.

3. **Load Firmware**
    - Click **Open File** and select `firmware.hex`.
    - Set **Start Address** to `0x08000000`.
    - Click **Start Programming**.

4. **Reset the Board**
    - After flashing completes, **power cycle** the board.
    - Use `odrivetool` to detect and verify firmware.

---

### 🧠 Notes:

- To generate `.hex` from `.elf`:
  ```bash
  arm-none-eabi-objcopy -O ihex firmware.elf firmware.hex
Keep firmware size under 2MB for compatibility.

ODrive firmware was cloned from the official ODrive GitHub Repository.

If unsure about the flash, use STM32CubeProgrammer to erase the chip before re-flashing.