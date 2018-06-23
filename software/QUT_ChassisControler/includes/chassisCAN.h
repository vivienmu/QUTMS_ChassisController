/**
 * @file chassisShutDown
 * @author Jonn Dillon
 * @date 16/4/2018
 * @description Defines and outlines all varibles and definitions related to the CANBUS system
 **/

#include <stdlib.h>
#include <avr/io.h>

#define STATUS_REG 			GPIOR0
#define CAN1_DataWaiting	1
#define CAN2_DataWaiting	2
#define CAN3_DataWaiting	4
#define IGNITION			8

#define HEARTBEAT_INV_ID	0x0C000000
#define	HEARTBEAT_AMU_ID	0x0A000000
#define HEARTBEAT_PDM_ID	0x09000000
#define HEARTBEAT_WHEEL_ID	0x00400000

unsigned char CANreceiver = 0;
unsigned int radiator_cals_acewell_22k[27] = {801,	800, 799, 797, 791, 785, 767, 750, 734, 707, 689, 671, 637, 598, 581, 562, 529,
493, 464, 443, 359, 338, 317, 297, 278, 234, 204};
volatile int heartbeatTimer = 0;
char CANdiagnostics[10][20];
uint8_t tempBuffer[10];

#define CANselect PORTC &= ~1
#define CANdeselect	  PORTC |= 1