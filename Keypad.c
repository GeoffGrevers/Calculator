// Filename : Keypad.c
// The scanning and decoding of a 4*4 matrix keypad
// Last modified 22/11/2016 
// Created by James Collins & Geoffrey Grevers

// - - - - - - - - - - - - - - - - - - - - PRE-PROCESSOR DIRECTIVES - - - - - - - - - - - - - - - - - - 

#include "Keypad.h"
#include "Port_Init.h"

// - - - - - - - - - - - - - - - - - - - - - SUBROUTINES SECTION - - - - - - - - - - - - - - - - - - - -

// Subroutine to scan keypad
// Current increment of row set high, for every increment read columns checking for input
// Inputs: None
// Outputs: Location of keypress ( unsigned char )
// Notes: None
unsigned char read_Keypad(void){
		
		int r,c; 
		unsigned long input;

				for (r=0;r<4;r++) {      		// loop through rows
						rows=(0x01<<r);      		// every increment in r results in different row being high
						
					for (c=0;c<4;c++) {    		// for every row increment check all 4 columns
						input = (columns&0x0F); // read columns into input

						if(input&(0x01<<c)) {   // if key press is detected
							return (r*10) + c + 1;// map location to value
			}
		}
	} 
return 0; 
}


// Subroutine to decode the location of pressed key
// Inputs: Location of pressed key
// Outputs: Returns value of key
// Notes: None
char decode_Key_Press(unsigned char k){

	
	if (k==1){      // FIRST ROW
			return '1'; 
	}
  
	else if (k==2){
			return '2'; 
	}

	else if (k==3){ 
			return '3';
	}

	else if (k==4){
			return '+';
	}

	
	else if (k==11){ // SECOND ROW               
			return '4';
	}

	else if (k==12){
			return '5';
	}

	else if (k==13){
			return '6';
	}

	else if (k==14){
			return '-';
	}
	

	else if (k==21){ // THIRD ROW           
			return'7';
	}
	
	else if (k==22){
			return'8';
	}

	else if (k==23){
			return'9';
	}

	else if (k==24){
			return'C';
	}

	
	else if (k==31){ // FOURTH ROW
			return'x';
	}

	else if (k==32){
			return'0';
	}
		
	else if (k==33){
			return'/';
	}

	else if (k==34){
			return'=';
	}

	else {
			return 'E'; // error - no button pressed
	} 
}