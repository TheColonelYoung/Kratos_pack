# 1.2
- Disconnect ~SHDN of LTC4231 from voltage supervisor UVLO signal
- Enable MCU to control shutdown (~SHDN input) of LTC4231 by pin 22 of MCU (PD0)
- Fix MOSFET type which inverts voltage supervisor logic level
- Selectable power input for 3V3 rail (SNS of battery charger or VCC) ???
    - SNS is but unstable and noisy but work with USB connected and battery disconnected
    - VCC is stable but unavailable when battery is disconnected (debug friendly)
    - Selectable by jumper next to regulator
- Fix USB detection by changing ESD protection and reconnecting USB detection

# 1.1
- Battery output is moved from SNS to VBAT pin of charger according to problem described in Errata sheet
    - This should make device more reliable during longer current consumption higher then 2A
    - Capacitor connected to SNS pins is changed for 47uF/16V in 1206 package
- Footprint of resistors and capacitors was exchanged for smaller versions
- Remove resistor in series with RESET line which is not required in order to save some space
- Fix under-voltage protection by inverting signal of under-voltage supervisor with MOSFET
- Fix MCU detection of USB connection, CP2102 is directly connected to VBUS
- Intended connection from ILIM pin to MCU is removed to avoid confusion
- Fix layout of signalization

# 1.0
- Initial release
