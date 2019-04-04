// Filename Keypad.h
// Header file containing preprocessor directives and declarations
// Last modified 22/11/2016
// Created by James Collins & Geoffrey Grevers

// - - - - - - - - - - - - - - - - - - - - PRE-PROCESSOR DIRECTIVES - - - - - - - - - - - - - - - - - - 

#define columns (*((volatile unsigned long*) 0x4002403C )) // - keypad port E
#define rows 		(*((volatile unsigned long*) 0x4000703C )) // - keypad port D
	
// - - - - - - - - - - - - - - - - - - - - - DECLARATIONS SECTION - - - - - - - - - - - - - - - - - - -

// - Global Variables

// - Function Prototypes

unsigned char read_Keypad(void);
char decode_Key_Press(unsigned char k);
