# 1.1
- Battery output is moved from SNS to VBAT pin of charger according to problem described in Errata sheet
    - This should make device more reliable during longer current consumption higher then 2A
    - Capacitor connected to SNS pins is changed for 47uF/16V in 1206 package
- Footprint of resistors and capacitors was exchanged for smaller versions
- Remove resistor in series with RESET line which is not required in order to save some space
- Fix under-voltage protection by inverting signal of under-voltage supervisor with MOSFET
- Fix MCU detection of USB connection, CP2102 is directly connected to VBUS

# 1.0
- Initial release
