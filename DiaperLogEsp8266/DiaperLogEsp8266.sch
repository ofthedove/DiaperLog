EESchema Schematic File Version 4
LIBS:DiaperLogEsp8266-cache
EELAYER 29 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 1 1
Title ""
Date ""
Rev ""
Comp ""
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
$Comp
L ESP8266:NodeMCU_1.0_(ESP-12E) U?
U 1 1 6132C176
P 2550 3250
F 0 "U?" H 2550 4337 60  0000 C CNN
F 1 "NodeMCU_1.0_(ESP-12E)" H 2550 4231 60  0000 C CNN
F 2 "" H 1950 2400 60  0000 C CNN
F 3 "" H 1950 2400 60  0000 C CNN
	1    2550 3250
	1    0    0    -1  
$EndComp
$Comp
L Switch:SW_Push_Open SW?
U 1 1 6132FDFE
P 5500 1800
F 0 "SW?" H 5500 2015 50  0000 C CNN
F 1 "SW_Push_Open" H 5500 1924 50  0000 C CNN
F 2 "" H 5500 2000 50  0001 C CNN
F 3 "~" H 5500 2000 50  0001 C CNN
	1    5500 1800
	1    0    0    -1  
$EndComp
$Comp
L Switch:SW_Push_Open SW?
U 1 1 61330E01
P 5500 2200
F 0 "SW?" H 5500 2415 50  0000 C CNN
F 1 "SW_Push_Open" H 5500 2324 50  0000 C CNN
F 2 "" H 5500 2400 50  0001 C CNN
F 3 "~" H 5500 2400 50  0001 C CNN
	1    5500 2200
	1    0    0    -1  
$EndComp
$Comp
L Switch:SW_Push_Open SW?
U 1 1 613312CA
P 5500 2600
F 0 "SW?" H 5500 2815 50  0000 C CNN
F 1 "SW_Push_Open" H 5500 2724 50  0000 C CNN
F 2 "" H 5500 2800 50  0001 C CNN
F 3 "~" H 5500 2800 50  0001 C CNN
	1    5500 2600
	1    0    0    -1  
$EndComp
$Comp
L Device:LED_CRGB D?
U 1 1 613340AD
P 5550 4400
F 0 "D?" H 5550 3933 50  0000 C CNN
F 1 "LED_CRGB" H 5550 4024 50  0000 C CNN
F 2 "" H 5550 4350 50  0001 C CNN
F 3 "~" H 5550 4350 50  0001 C CNN
	1    5550 4400
	-1   0    0    1   
$EndComp
Text Label 3350 2650 0    50   ~ 0
BlueButton
Text Label 3350 2750 0    50   ~ 0
GreenButton
Text Label 3350 3250 0    50   ~ 0
RedButton
Text Label 3350 3350 0    50   ~ 0
RgbLedBlue
Text Label 3350 3450 0    50   ~ 0
RgbLedRed
Text Label 3350 2850 0    50   ~ 0
PeeLedPin
Text Label 3350 2950 0    50   ~ 0
PooLedPin
Text Label 3350 3950 0    50   ~ 0
LedVcc
Text Label 3350 3850 0    50   ~ 0
SwitchGnd
Text Label 3350 3150 0    50   ~ 0
RgbLedGnd
Text Label 5050 1800 2    50   ~ 0
BlueButton
Text Label 5050 2200 2    50   ~ 0
GreenButton
Text Label 5050 2600 2    50   ~ 0
RedButton
Text Label 5050 4200 2    50   ~ 0
RgbLedBlue
Text Label 5050 4600 2    50   ~ 0
RgbLedRed
Text Label 6350 4400 0    50   ~ 0
RgbLedGnd
Text Label 6000 2200 0    50   ~ 0
SwitchGnd
Wire Wire Line
	5700 2200 5900 2200
Wire Wire Line
	5700 1800 5900 1800
Wire Wire Line
	5900 1800 5900 2200
Connection ~ 5900 2200
Wire Wire Line
	5900 2200 6000 2200
Wire Wire Line
	5700 2600 5900 2600
Wire Wire Line
	5900 2600 5900 2200
Wire Wire Line
	5050 1800 5300 1800
Wire Wire Line
	5300 2200 5050 2200
Wire Wire Line
	5050 2600 5300 2600
Wire Wire Line
	5350 4200 5050 4200
Wire Wire Line
	5050 4600 5350 4600
Wire Wire Line
	5350 4400 5050 4400
NoConn ~ 5050 4400
$Comp
L Device:R R?
U 1 1 6132E93E
P 5050 3200
F 0 "R?" V 4843 3200 50  0000 C CNN
F 1 "R" V 4934 3200 50  0000 C CNN
F 2 "" V 4980 3200 50  0001 C CNN
F 3 "~" H 5050 3200 50  0001 C CNN
	1    5050 3200
	0    1    1    0   
$EndComp
Text Label 4750 3650 2    50   ~ 0
PooLedPin
Text Label 4750 3200 2    50   ~ 0
PeeLedPin
Wire Wire Line
	5650 3650 5900 3650
Wire Wire Line
	5900 3400 5900 3650
Wire Wire Line
	5900 3200 5900 3400
Connection ~ 5900 3400
Wire Wire Line
	5900 3400 6000 3400
Wire Wire Line
	5650 3200 5900 3200
Text Label 6000 3400 0    50   ~ 0
LedVcc
$Comp
L Device:LED D?
U 1 1 61333555
P 5500 3650
F 0 "D?" H 5493 3395 50  0000 C CNN
F 1 "LED" H 5493 3486 50  0000 C CNN
F 2 "" H 5500 3650 50  0001 C CNN
F 3 "~" H 5500 3650 50  0001 C CNN
	1    5500 3650
	-1   0    0    1   
$EndComp
$Comp
L Device:LED D?
U 1 1 61331785
P 5500 3200
F 0 "D?" H 5493 2945 50  0000 C CNN
F 1 "LED" H 5493 3036 50  0000 C CNN
F 2 "" H 5500 3200 50  0001 C CNN
F 3 "~" H 5500 3200 50  0001 C CNN
	1    5500 3200
	-1   0    0    1   
$EndComp
$Comp
L Device:R R?
U 1 1 61331E6C
P 5050 3650
F 0 "R?" V 4843 3650 50  0000 C CNN
F 1 "R" V 4934 3650 50  0000 C CNN
F 2 "" V 4980 3650 50  0001 C CNN
F 3 "~" H 5050 3650 50  0001 C CNN
	1    5050 3650
	0    1    1    0   
$EndComp
$Comp
L Device:R R?
U 1 1 6133276D
P 6050 4400
F 0 "R?" V 5843 4400 50  0000 C CNN
F 1 "R" V 5934 4400 50  0000 C CNN
F 2 "" V 5980 4400 50  0001 C CNN
F 3 "~" H 6050 4400 50  0001 C CNN
	1    6050 4400
	0    1    1    0   
$EndComp
Wire Wire Line
	6350 4400 6200 4400
Wire Wire Line
	5900 4400 5750 4400
Wire Wire Line
	5350 3650 5200 3650
Wire Wire Line
	5200 3200 5350 3200
Wire Wire Line
	4900 3200 4750 3200
Wire Wire Line
	4750 3650 4900 3650
$EndSCHEMATC
