/*	Author: lab
 *  Partner(s) Name: 
 *	Lab Section:
 *	Assignment: Lab #  Exercise #
 *	Exercise Description: [optional - include for your own benefit]
 *
 *	I acknowledge all content contained herein, excluding template or example
 *	code, is my own original work.
 */
#include <avr/io.h>
#ifdef _SIMULATE_
#include "simAVRHeader.h"
#endif

enum LED_STATES{START,ON,OFF} Led_State;

unsigned char button = 0x00;
unsigned tmpB = 0x00;
void State_Machine(){
	switch(Led_State){
	
		button = PINA & 0x01;
		
		case START:
		Led_State = OFF;
		break;	
		
		case OFF:
		if(button == 0x01){
		Led_State = ON;
		}
		else{
		Led_State = OFF;
		}	
		break;

		case ON:
		if(button == 0x01){
			Led_State = ON;
		}
		else{
			Led_State = OFF;
		}
		break;

		default:
		Led_State = START;
		break;
	}//transitions

	switch(Led_State){ //actions
		case OFF:
		tmpB = 0x01;
		PORTB = tmpB;
		break;
		
		case ON:
		tmpB = 0x02;
		PORTB = tmpB;
		break;

		default:
		break;
	}
}
int main(void) {
    /* Insert DDR and PORT initializations */

DDRA = 0x00; PORTA = 0xFF; // Configure port A's  pins as inputs
	DDRB = 0xFF; PORTB = 0x00;
    /* Insert your solution below */
	PORTB = 0x01;
	Led_State = START;
    while (1) {
	State_Machine();
    }
    return 1;
}
