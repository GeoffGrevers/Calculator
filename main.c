// Filename main.c
// main.c filed for calculator project
// Last modified 29/11/2016 
// Created by James Collins & Geoffrey Grevers

// - - - - - - - - - - - - - - - - - - - - PRE-PROCESSOR DIRECTIVES - - - - - - - - - - - - - - - - - - 

#include "main.h"

// - - - - - - - - - - - - - - - - - - - - - SUBROUTINES SECTION - - - - - - - - - - - - - - - - - - - -

int main(void)  {
	
	PortA_Init();
	PortB_Init(); 
	PortD_Init();
	PortE_Init();
	SysTick_Init();
	PLL_Init();
	lcd_Init();

	while(1) {
		
		decodekey = decode_Key_Press(read_Keypad());
		key_Press();
		SysTick_Wait(80000000); 					// delay to prevent multiple button presses		
	}	
}


// Subroutine to calculate key press'
// 
// Inputs: A input, Operation input and B input
// Outputs: Answer to input calculation
// Notes: None
float calculate(float a, float b, int operation) {
	
	if (operation == ADD) {
		return (a + b);
	}
	else if (operation == SUBTRACT) {
		return (a - b);
	}
	else if (operation == MULTIPLY) {
		return (a * b);
	}
	else if (operation == DIVIDE) {
		return (a / b);
	}
	else{
		return 0;
	}
}


// Subroutine to store key press' in button press array, then increment the array counter
// 
// Inputs: None 
// Outputs: None
// Notes: None
void key_Press(){
	
	if(decodekey == 'E'){		
				// do nothing	
	}
	else if(decodekey == 'C'){		
			display_Reset();          // call reset function
	}
	else if(decodekey == '+'){			
			lcd_Write_Data(decodekey); 											// print key to LCD
			button_Press_Array[array_Counter] = decodekey;  // store operation characheter in array
			operation = 0;                                  // addition defined as 0 in preprocessor directives
			operation_flag++;                               // increment operation flag
			number_flag = 0;                                
			array_Counter++;                                // increment array counter to next element in array
			if(operation_flag > 1) {                        // more than one digit number entered will reult in an error
				display_Error();
			}
	}
	else if(decodekey == '-'){
			lcd_Write_Data(decodekey);                      
			button_Press_Array[array_Counter] = decodekey; 
			operation = 1;
			operation_flag++;
			number_flag = 0;
			array_Counter++;
			if(operation_flag > 1) {
				display_Error();
			}
	}
	else if(decodekey == 'x'){	
			lcd_Write_Data(decodekey);
			button_Press_Array[array_Counter] = decodekey; 
			operation = 2;
			operation_flag++;
			number_flag = 0;
			array_Counter++;
			if(operation_flag > 1) {
				display_Error();
			}
	}
	else if(decodekey == '/'){	
			lcd_Write_Data(decodekey);
			button_Press_Array[array_Counter] = decodekey; 
			operation = 3;
			operation_flag++;
			number_flag = 0;
			array_Counter++;
			if(operation_flag > 1) {
				display_Error();
			}		
	}
	else if(decodekey == '='){
			lcd_Write_Data(decodekey);                        // print equal charachter to LCD
			button_Press_Array[array_Counter] = decodekey;    // store operation in array
			answer = calculate(button_Press_Array[0],button_Press_Array[2],operation); // pass calculation array into answer function
			sprintf(buffer,"%.2f",answer);                    // answer will be of type string
			lcd_Write_String(buffer);                         // write string to LCD
			operation_flag= 0;
			number_flag = 0;
			array_Counter++;
			if(operation_flag > 1) {
				display_Error();
			}
	}
	else {
			lcd_Write_Data(decodekey); 													 // print key to LCD
			button_Press_Array[array_Counter] = decodekey - '0'; // converts char value into decimal, decode key -48
			operation_flag = 0;
			number_flag++;
			array_Counter++;
			if(number_flag > 1) {
				display_Error();
			}
	}
}


// Subroutine to display error when 2 digits are pressed
// 
// Inputs: None
// Outputs: None
// Notes: None
void display_Error(){
	
	display_Reset(); 
	lcd_Write_String("Error");
	SysTick_Wait(0xFFFFFFFF);
	SysTick_Wait(0xFFFFFFFF);
	SysTick_Wait(0xFFFFFFFF);
	SysTick_Wait(0xFFFFFFFF);
	SysTick_Wait(0xFFFFFFFF);
	display_Reset();	
}


// Subroutine to reset and clear the display
// 
// Inputs: None
// Outputs: None
// Notes: None
void display_Reset(){
	
	lcd_Clear_Screen();
	operation = 4;
	operation_flag = 0;             // reset operation flag
	number_flag = 0;                // reset number flag
	array_Counter = 0;              // reset array counter
	
	for(i=0;i<16;i++){
			button_Press_Array[i] = 0;	// empties and clears calculation array
	}
	answer = 0;
	
}
