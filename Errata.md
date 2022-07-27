# V1.0  

## Schema  
- Unconnected I_IN  
    - Output of battery charger on which could be measured voltage proportional to input current is unconnected due to space constraints  
    - This connection redundant, because current could be read from registers of battery charger IC  

- SNS is used as output instead of BAT  
    - This was designed due to built in resistor inside battery charger IC, because then could be calculated consumption of inner components of device as MCU, USB to UART converter  
    - But power limitation of this sense resistor could lead to IC damage when current of 2A is long-term exceeded  
    - Fixed in v1.1

## PCB  
- Voltage supervisor is not working  
    - Supervisor is active low but enable MOSFET is active high  
    - Partially solved by removing of supervisor  
    - Fixed in v1.1

- Enable MOSFET for supervisor is not working  
    - Is pulled high by supervisor or by pull-up resistor  
    - Solution: Remove resistor R31  
    - Must by supplemented by pulldown resistor (otherwise gate of MOSFET will float)  
    - New resistor can be placed instead of C19  
    - Fixed in v1.1

- Communication with MCU is not working  
    - Place only one resistor for CP2102 WAKEUP pin (preferably place only R15)  
    - Exchange R2 resistor value (47k -> 39k)  

- Signaling LED has incorrect layout  
    - Solution: Is possible to solder LED turned by 90° clockwise  
