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


enum INC_States {Start,wait,plus,minus,both} INC_State;

unsigned char val;
unsigned char tmpA1;
unsigned char tmpA2;

void State_Machine(){//transitions
	switch(INC_State){
	tmpA1 = PINA & 0x01;
	tmpA2 = PINA & 0x02;
	
		case Start:
		INC_State = wait;
		break;

		case wait:
		break;

		case plus:
		break;

		case minus:
		break;

		case both:
		break;

		default:
		INC_State = Start;
		break;
	}
	switch(INC_State){
		case Start:
			PORTC = 7;
		break;
		case wait:
		break;
		case plus:
		if(PORTC < 9){
		PORTC = PORTC + 1;
		}
		break;
		case minus:
		if (PORTC > 0){
		PORTC = PORTC - 1;
		}
		break;
		case both:
		PORTC = 0;
		break;
		default:
		break;
	}
}


int main(void) {
    /* Insert DDR and PORT initializations */
DDRA = 0x00; PORTA = 0xFF; // Configure port A's  pins as inputs
	DDRC = 0xFF; PORTC = 0x00;
    /* Insert your solution below */
	PORTC = 7;
    while (1) {
	State_Machine();
    }
    return 1;
}
