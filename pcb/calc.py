# Calculations for Kratos pack

# --- LTC4231 ---
"""
Position of resistors
R1  - IN  - UVL
R2  - UVL - UVH
R3  - UVH - OV
R4  - OV  - GNDSW
"""
# Inputs

# Undervoltage rising threshold
V_UVON  = 6

# Undervoltage falling threshold
V_UVOFF = 5.9

# Overvoltage falling threshold
V_OVOFF = 10.0

# Maximal input voltage
input_voltage = 8.4

# Total resistance of settings resitors
resistance_total = 2000000

# Maximal continuous current
overcurrent_threshold = 5

## Based on SOA, output mosfet must witstand MOSFET P_DISS for time longer then OC timer charge
## Write down time of SOA for P_DISS of selected MOSFET in !seconds!
SOA_time = 0.0003

# Constants

## Voltage on sensing resistor which trips over current
sense_voltage_slow = 0.05

## Worst case calculations for overcurrent
sense_voltage_fast = 0.08
sense_voltage_fast_min = 0.065
sense_voltage_fast_max = 0.09

# Calculations
R4 = (0.795/V_OVOFF) * resistance_total
R3 = ((V_OVOFF/V_UVON) - 1) * R4
R2 = ((V_UVON/V_UVOFF) - 1) * (V_OVOFF/V_UVON) * R4
R1 = ((V_OVOFF/0.795) - 1) * R4 - R3 - R2

I_leakage = input_voltage/(R1 + R2 + R3 + R4)

R_sense = sense_voltage_slow/overcurrent_threshold

I_limit_fast = sense_voltage_fast / R_sense

I_limit_min = sense_voltage_fast_min/R_sense

I_limit_max = sense_voltage_fast_max/R_sense

R_sense_power = R_sense * I_limit_fast * I_limit_fast

C_L_charge = (0.0001 * input_voltage) / I_limit_min

P_DISS = input_voltage * I_limit_max

OC_trip_time = (SOA_time - C_L_charge)/4 + C_L_charge

C_T = OC_trip_time/input_voltage

# Outputs
print("   --- LTC4321 ---")
print("R4 value = {}k".format(round(R4/1000)))
print("R3 value = {}k".format(round(R3/1000)))
print("R2 value = {}k".format(round(R2/1000)))
print("R1 value = {}k".format(round(R1/1000)))

print("Divider leakage = {} uA".format(I_leakage*1000000))
print("Sensing resistor = {} mR".format(R_sense*1000))
print("Sensing resistor power dissipation = {} W".format(R_sense_power))

print("Worst case current = {} A".format(I_limit_max))
print("OC timer charge = {} ms".format(round(C_L_charge*1000,2)))
print("MOSFET P_DISS = {} W".format(round(P_DISS,2)))

if SOA_time < 2*C_L_charge:
    print("MOSFET is not able to withstand that much power for long enough to trip OC protection")

print("Time to OC protection activation = {} ms".format(round(OC_trip_time*1000,2)))
print("C_T value = {} nF".format(round(C_T*1000000,2)))


# INA199

# Inputs

# Sense resistor value
sense_resistor = 0.01

# Maximal current in Ampers
maximal_current = 5

# Supply voltage
supply_voltage = 3.3

# Available gains for CSAmp
gains = [50,100,200]

# Resolution of ADc in bits
ADC_bits = 12

# Calculations
voltage_drop = sense_resistor * maximal_current

power_on_sense = sense_resistor * maximal_current * maximal_current

for gain in gains:
    if voltage_drop * gain < supply_voltage:
        higher_gain = gain
    else:
        break

maximal_readable_current = supply_voltage / sense_resistor / higher_gain

minimal_adc_voltage = supply_voltage / 2**ADC_bits
minimal_current = minimal_adc_voltage / sense_resistor / higher_gain

# Outputs
print("\n   --- INA199 ---")
print("Voltage drop = {} mV".format(voltage_drop*1000))
print("Sensing resistor power dissipation = {} W".format(power_on_sense))
print("Higher usable gain = {}".format(higher_gain))
print("Maximal readable current = {} A".format(maximal_readable_current))
print("Minimal readable current = {} mA".format(round(minimal_current*1000,2)))

# INA199

# Inputs
maximal_input_current = 2.4

cell_voltage = 4.2

balance_current = 0.1

NTC_at_T1 = 32500.0
NTC_at_T5 = 2490.0

# Constants
K_ILIM = 1110

R_DSON_QCBX = 1

# Temperature point 1 for termistor
T1 = 0
# Temperature point 5 for termistor
T5 = 60

# Voltage of temperature level in fraction of REGN voltage
V_T1 = 0.7325
V_T5 = 0.3437

maximum_balance_current = 0.4

# Calculations
R_ILIM = K_ILIM / maximal_input_current

input_current_to_voltage = 0.8 * R_ILIM / K_ILIM

balance_resistor = (cell_voltage / balance_current) - R_DSON_QCBX

balance_resistor_power = balance_resistor * balance_current**2

RT2 = (NTC_at_T1*NTC_at_T5 * ((1.0/V_T5)-(1.0/V_T1))) / ((NTC_at_T1 * ((1.0/V_T1) - 1))-(NTC_at_T5 * ((1.0/V_T5) - 1)))

RT1 = ((1.0/V_T1) - 1) / ( (1.0 / RT2) + (1.0/NTC_at_T1) )

# Outputs
print("\n   --- BQ25887 ---")
print("ILIM resistor value = {} R".format(round(R_ILIM)))
print("1A input results to {} V on ILIM pin".format(round(input_current_to_voltage,2)))

print("Balance resistor = {} R".format(round(balance_resistor,2)))
print("Sensing resistor power dissipation = {} W".format(power_on_sense))

print("RT2 = {} k".format(round(RT2/1000,2)))
print("RT1 = {} k".format(round(RT1/1000,2)))
