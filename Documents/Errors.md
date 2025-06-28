## ❗ All Errors Faced in Terminal + Their Meanings

### 1. `AxisError.ENCODER_FAILED`
axis0
axis: Error(s):
AxisError.ENCODER_FAILED

**Meaning**: ODrive failed to get a valid encoder signal.  
**Possible Causes**:
- Encoder not wired properly (check A, B, Z channels and GND/VCC).
- Encoder CPR or signal type mismatch.
- No encoder movement during calibration.

---

### 2. `EncoderError.CPR_POLEPAIRS_MISMATCH`
encoder: Error(s):
EncoderError.CPR_POLEPAIRS_MISMATCH

**Meaning**: The configured encoder CPR and motor pole pairs don’t match the physical motor behavior.  
**Possible Causes**:
- Incorrect value for `.encoder.config.cpr` or `.motor.config.pole_pairs`.
- Wrong wiring order or loose encoder connection.
- Slippage between motor shaft and encoder.

---

### 3. `AxisError.MOTOR_FAILED`
axis: Error(s):
AxisError.MOTOR_FAILED

**Meaning**: General motor failure error raised when a critical error occurs in the motor subsystem.  
**Note**: Usually accompanied by motor errors like the ones below.

---

### 4. `MotorError.CURRENT_SENSE_SATURATION`
motor: Error(s):
MotorError.CURRENT_SENSE_SATURATION

**Meaning**: The motor tried to draw more current than it could safely measure.  
**Possible Causes**:
- Very low phase resistance or inductance.
- Current limit too high.
- Poor tuning during motor calibration.
- Faulty driver circuitry or hardware damage.

---

### 5. `MotorError.CURRENT_LIMIT_VIOLATION`
motor: Error(s):
MotorError.CURRENT_LIMIT_VIOLATION

**Meaning**: The motor exceeded the defined `.motor.config.current_lim` value.  
**Possible Causes**:
- Load too high (too much torque required).
- Motor stalling or starting abruptly.
- Acceleration too high.
- Velocity command spike.

---

### 6. `MotorError.PHASE_INDUCTANCE_OUT_OF_RANGE`
motor: Error(s):
MotorError.PHASE_INDUCTANCE_OUT_OF_RANGE

**Meaning**: ODrive couldn't measure the motor's inductance correctly during calibration.  
**Possible Causes**:
- Very low-inductance motor (common in small or high-RPM motors).
- Unstable power supply.
- Wires not securely connected.
- ODrive version or firmware bug.

---

### 7. `AxisError.INVALID_STATE`
axis: Error(s):
AxisError.INVALID_STATE

**Meaning**: You tried to put the motor into an invalid or unsafe state.  
**Example**: Trying to enter `AXIS_STATE_CLOSED_LOOP_CONTROL` before calibration is complete.  
**Fix**:
- Ensure both motor and encoder are calibrated (`pre_calibrated = True`) before entering closed-loop mode.

---

### 8. `AxisError.WATCHDOG_TIMER_EXPIRED`
axis: Error(s):
AxisError.WATCHDOG_TIMER_EXPIRED

**Meaning**: ODrive stopped the motor because it didn’t receive control commands for too long.  
**Cause**:
- Arduino or PC stopped sending commands.
- `odrive.config.watchdog_timeout` enabled but not fed continuously.

**Fix**:
- Regularly send commands from Arduino, **or**
- Disable the watchdog:
```python
odrv0.config.enable_watchdog = False  
odrv0.save_configuration()  
odrv0.reboot()


9. system: not found
system: not found
Meaning: No error in the system-level subsystem. This is just an info message, not an error.

✅ Summary of Fixes You Did
Error	Fix Applied
CPR_POLEPAIRS_MISMATCH	Corrected CPR and pole pairs
ENCODER_FAILED	Checked wiring, re-calibrated
CURRENT_SENSE_SATURATION	Reduced velocity or current limit
WATCHDOG_TIMER_EXPIRED	Regular velocity commands sent from Arduino
INVALID_STATE	Ensured calibration before state transitions
CURRENT_LIMIT_VIOLATION	Increased current_lim, added velocity ramp
PHASE_INDUCTANCE_OUT_OF_RANGE	Rechecked wiring, ensured power supply stability

