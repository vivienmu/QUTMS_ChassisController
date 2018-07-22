
#define F_CPU 16000000

#include <avr/io.h>
#include <avr/interrupt.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <util/delay.h>
#include "MCP2515.h"
#include "uart.h"
#include "a2d.h"
#include "chassisInit.h"
#include "chassisInput.h"
#include "chassisUART.h"
#include "chassisLED.h"
#include "chassisCAN.h"
#include "chassisError.h"



// Variables used in the 1kHz CAN heartbeat loop
#define CAN_HEARTBEAT_TIME_INVERTERS (10)   // Defines the 10ms (100Hz) for the inverter trigger
#define CAN_HEARTBEAT_TIME_DATA (10)        // Defines the 10ms (100Hz) for the data trigger
#define CAN_HEARTBEAT_TIME_POWER (50)       // Defines the 50ms (20Hz) for the power trigger

#define CAN_HEARTBEAT_ERROR_DELAY (110)     // Milliseconds without return heartbeat, must be slightly larger than largest heartbeat time x2

#define INPUT_TIME_PEDAL_THROTTLE  (10)     // Defines the 10ms (100Hz) for the input send trigger
#define INPUT_TIME_PEDAL_BRAKE  (10)        // Defines the 10ms (100Hz) for the input send trigger
#define INPUT_TIME_TEMP (100)               // Defines the 100ms (10Hz) for the input send trigger

#define CAN_INPUT_SEND_DELAY (10)           // Defines the 200ms (5Hz) for the input send trigger

#define CAR_ARM_HV (1)                      // Used to set the car's armed state to high
#define CAR_DISARM_HV (0)                   // Used to set the car's armed state to low
extern uint8_t armedState;              // Stores the car's armed state
extern uint8_t ignitionState;           // Stores the car's ignition switch/button state

extern uint8_t shutdownState;           // Stores the car's current state of its shutdown circuity