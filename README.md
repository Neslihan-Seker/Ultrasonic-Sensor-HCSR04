# Ultrasonic-Sensor-HCSR04
Ultrasonic sensor interfacing with PIC16F877A | HC SR04 sensor | CCS C


# PIC16F877A LCD HCSR04 Distance Measurement
This project utilizes a PIC16F877A microcontroller, an LCD module, and an HC-SR04 ultrasonic distance sensor to measure and display distances.

## Hardware Setup

# LCD Module Connections

#define LCD_RS_PIN     PIN_D0
#define LCD_RW_PIN     PIN_D1
#define LCD_ENABLE_PIN PIN_D2
#define LCD_DATA4      PIN_D3
#define LCD_DATA5      PIN_D4
#define LCD_DATA6      PIN_D5
#define LCD_DATA7      PIN_D6

## PIC Microcontroller Configuration

#include <16F877A.h>
#fuses HS,NOWDT,NOPROTECT,NOLVP
#use delay(clock = 8000000)
#include <lcd.c>
#use fast_io(B)


## Program Logic

- Initializes the LCD module.
- Configures Timer1 for distance measurement.
- Enters a continuous loop for distance measurement.
- Triggers the HC-SR04 sensor, measures the time it takes for the echo signal to return.
- Checks for timeout or out-of-range conditions.
- Displays the distance on the LCD module.

## Pin Configuration

- PIN_B0: Trigger pin for the HC-SR04 sensor.
- PIN_B1: Echo pin for the HC-SR04 sensor.

## Usage
- Connect the LCD module and HC-SR04 sensor to the specified pins on the PIC16F877A.
- Upload the provided code to the microcontroller.
- Run the simulation in Proteus.
