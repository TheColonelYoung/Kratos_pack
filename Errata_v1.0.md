# PCB
- Voltage supervisor is not working
    - Supervisor is active low but enable mosfet is active high
    - Partially solved by removing of supervisor

- Enable mosfet for supervisor is not working
    - Is pulled high by supervisor or by pull-up resistor
    - Solution: Remove resistor R31
    - Must by supplemented by pulldown resistor (otherwise gate of mosfet will float)
    - New resistor can be placed instead of C19

- Communication with MCU is not working
    - Place only one resistor for CP2102 WAKEUP pin (preferably place only R15)
    - Exchange R2 resistor value (47k -> 39k)

- Signaling LED has incorrect layout
    - Solution: Is possible to solder LED turned by 90° clockwise
