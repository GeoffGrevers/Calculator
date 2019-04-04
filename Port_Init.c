// Filename Port_Init.c
// The initialisation of ports A,B,D and E
// Last modified 29/11/2016 
// Created by James Collins & Geoffrey Grevers

// - - - - - - - - - - - - - - - - - - - - PRE-PROCESSOR DIRECTIVES - - - - - - - - - - - - - - - - - - 

#include "Port_Init.h"

// - - - - - - - - - - - - - - - - - - - - - SUBROUTINES SECTION - - - - - - - - - - - - - - - - - - - -	

// Subroutine to initialise port A
// LCD_EN (PA4) and LCD_RS (PA3)
// Inputs: None
// Outputs: None
// Notes: None
void PortA_Init(void) { 
	
		volatile unsigned long delay;
		SYSCTL_RCGC2_R |= 0x01;  					 // activate the clock for port A 
		delay = SYSCTL_RCGC2_R;  					 // delay, wait for clock to start
	
		GPIO_PORTA_AMSEL_R &= ~0x18;       // disable analog on PA4-3
		GPIO_PORTA_PCTL_R &= ~0x000FF000;  // configure PA4-3 as GPIO
		GPIO_PORTA_DIR_R |= 0x18;          // PA4-3 set as outputs
		GPIO_PORTA_AFSEL_R &= ~0x18;       // disable alternative function
		GPIO_PORTA_DEN_R |= 0x18;          // enable digital I/O on PA4-3
}
	

// Subroutine to initialise port B, 
// LCD data pins (PB5-2)
// Inputs: None
// Outputs: None
// Notes: None
void PortB_Init(void) { 
	
		volatile unsigned long delay;
		SYSCTL_RCGC2_R |= 0x02; 					 // activate the clock for port B
		delay = SYSCTL_RCGC2_R;  					 // delay, wait for clock to start
	
		GPIO_PORTB_AMSEL_R &= ~0x3C;       // disable analog mode
		GPIO_PORTB_PCTL_R  &= ~0x00FFFF00; // configure PB5-2 as GPIO
		GPIO_PORTB_DIR_R |= 0x3C;          // PB5-2 set as outputs
		GPIO_PORTB_AFSEL_R &= ~0x3C;       // disable alternative function
		GPIO_PORTB_DEN_R |= 0x3C;          // enable digital I/O on PB5-2
}


// Subroutine to initialise port D
// Keypad rows
// Inputs: None
// Outputs: None
// Notes: None
void PortD_Init(void) { 
	
	 volatile unsigned long delay;
	 SYSCTL_RCGC2_R |= 0x08; 						 // activate the clock for port D
	 delay = SYSCTL_RCGC2_R;             // delay, wait for clock to start
	
	 GPIO_PORTD_LOCK_R = 0x4C4F434B;     // unlock port D
	 GPIO_PORTD_AMSEL_R &= ~0x0F;        // disable analog on PD0-3
	 GPIO_PORTD_PCTL_R &= ~0x0000FFFF;   // configure PD0-3 as GPIO
	 GPIO_PORTD_DIR_R |= 0x0F;         	 // set direction register PD0-3 (row) outputs
	 GPIO_PORTD_AFSEL_R &= ~0x0F;        // disable alternate function on PD0-3
	 GPIO_PORTD_DEN_R |= 0x0F;           // enable digital I/O on PE0-3 
	
}


// Subroutine to initialise port E
// Keypad columns
// Inputs: None
// Outputs: None
// Notes: None
void PortE_Init(void) { 
	
	 volatile unsigned long delay;
	 SYSCTL_RCGC2_R |= 0x10;             // activate the clock for port E 
	 delay = SYSCTL_RCGC2_R;             // wait for clock to start

	 GPIO_PORTE_AMSEL_R &= ~0x0F;        // disable analog on PE0-3
	 GPIO_PORTE_PCTL_R  &= ~0x0000FFFF;  // configure PE0-3 as GPIO
	 GPIO_PORTE_DIR_R &= ~0x0F;          // set direction register PE0-3 (column) inputs
	 GPIO_PORTE_AFSEL_R &= ~0x0F;        // disable alternate function on PE0-3
	 GPIO_PORTE_DEN_R |= 0x0F;           // enable digital I/O on PE0-3

}


	

	