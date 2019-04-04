// Filename LCD.c
// The initialisation and setup of the LCD screen with onboard driver / controller
// Last modified 29/11/2016 
// Created by James Collins & Geoffrey Grevers

// - - - - - - - - - - - - - - - - - - - - PRE-PROCESSOR DIRECTIVES - - - - - - - - - - - - - - - - - - 

#include "LCD.h"
#include "PLL.h"

// - - - - - - - - - - - - - - - - - - - - - SUBROUTINES SECTION - - - - - - - - - - - - - - - - - - - -

// Subroutine to initialise LCD and onboard driver
// 
// Inputs: None
// Outputs: Location of keypress ( unsigned char )
// Notes: None
void lcd_Init(void) {

		SysTick_Wait(1200000);  // 15ms delay
		SysTick_Wait(1200000);
		
		LCD_RS = 0x00; // set RS to 0, do not need to set LCD_RW to 0 as it is connected to ground
		
		LCD_DB = 0x0C;  // DB5 - DB4 set high 
		lcd_EN_Pulse();         // latch the commandby pulsing the EN line

		SysTick_Wait(328000);   // 4.1ms delay
		SysTick_Wait(400000);   // 5ms delay
		LCD_DB = 0x0C;          
		lcd_EN_Pulse();         // latch the commandby pulsing the EN line

		SysTick_Wait(8000);     // 100us delay
		SysTick_Wait(400000);   // 5ms delay
		LCD_DB = 0x0C;          
		lcd_EN_Pulse();         // latch the commandby pulsing the EN line
		
		SysTick_Wait(400000);   // 5ms delay
		LCD_DB = 0x08;          // send 0x08
		lcd_EN_Pulse();         // pulse EN
		SysTick_Wait(400000);   // 5ms delay
		
		lcd_Write_Cmd(0x28); // 0010 1000 setting data length, no. of lines and charachter font
		lcd_Write_Cmd(0x0F); // 0000 1111 cursor on, display on, blink on
		lcd_Write_Cmd(0x06); // 0000 0110 entry mode set, increment but do not shift
		lcd_Write_Cmd(0x01); // clear screen
}


// Subroutine to write commands to LCD
// 
// Inputs: c
// Outputs: None
// Notes: None
void lcd_Write_Cmd(unsigned char c) {

		LCD_RS = 0x00;            // set RS to zero , send instruction
	
		SysTick_Wait(3500);       // 43.75us delay
		LCD_DB = (c & 0xF0) >>2;  
		
	  lcd_EN_Pulse();           // pulse EN
		SysTick_Wait(400000);     // 5ms delay
		
	  LCD_DB = (c&0x0F) << 2;   
		lcd_EN_Pulse();           // pulse EN
		SysTick_Wait(400000);     // 5ms delay
}


// Subroutine to write data to LCD
// 
// Inputs: key press char value
// Outputs: None
// Notes: None
void lcd_Write_Data(unsigned char d) {

		LCD_RS = 0x08;            
		SysTick_Wait(3200);       // 40us delay
	  
		LCD_DB = (d & 0xF0) >>2;  // shift high nibble into PB5-2
	  lcd_EN_Pulse();           // pulse EN
	  SysTick_Wait(16000);     	// 200us delay
		
	  LCD_DB = (d & 0x0F) << 2; // shift low nibble into PB5-2
		lcd_EN_Pulse();           // pulse EN
		SysTick_Wait(16000);     	// 200us delay
	
		LCD_RS = 0x00;
}


// Subroutine to write string to LCD
// 
// Inputs: *string
// Outputs: None
// Notes: None
void lcd_Write_String(char *string){
	
	while(*string) {
		lcd_Write_Data(*string);
		string++;
	}
}


// Subroutine to clear LCD screen
// 
// Inputs: None
// Outputs: None
// Notes: None
void lcd_Clear_Screen(void){
 
		lcd_Write_Cmd(0x01);  // clear display
}


// Subroutine to go to LCD address
//
// Inputs: None
// Outputs: Address
// Notes: None
void lcd_Goto(unsigned char address){
	
	lcd_Write_Cmd ((0x80) | (address));    // 0x80 refers to setting CGRAM address
}


// Subroutine to pulse EN
// 
// Inputs: None
// Outputs: None
// Notes: None
void lcd_EN_Pulse (void) {

		LCD_EN =0x10; //set EN high for a pulse width of 450ns (minimum)
		SysTick_Wait(36); // delay of 450ns
		LCD_EN =0x00; // return EN line back to 0
}
