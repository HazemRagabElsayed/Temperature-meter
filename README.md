# Temperature-meter
this project is a temperature sensor that turns a certain temperature into a certain Analog Electrical Signal (Voltage) this signal enters ADC (Analog to Digital Converter) where it is turned into binary digits (0s and 1s) these digits represent decimal numbers (0,1,2,3,4,5,6,...etc) which can be understood by microcontroller then it can be displayed on LCD


## Devices used:

-Atmega32 (where we put our code to do specific functions)

-LM35 (temperature sensor that turns each 1 degree celsius into  10 mV)

-LCD 16x2 (for displaying Temperature in Celsius)

-10 uf capacitor (as it is mentioned in datasheet of Atmega32)

-DC VOLTMETER (for measuring output of LM35)

## tools used:
-Proteus 8 Professional

-Atmel Studio 6.0

-Extreme Burner

## note:
-there is a video provided in code folder

-Each range of decimal numbers represent a certain voltage which results in a shift in accuracy as in ADC there are a number of levels which is determined by number of bits that is outputted from ADC
for example 10-bit ADC has a number of levels equal to 1024 as it equals 2^10

-I used internal reference voltage (2.56 V) of ADC which made the accuracy high 

-each step contains certain range of decimal values that represents a certain voltage

-step = (reference voltage)/(number of levels) -> which means smaller steps give higher accuracy
