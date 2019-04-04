// Filename main.h
// Header file containing preprocessor directives and declarations
// Last modified 5/11/2016
// Created by James Collins & Geoffrey Grevers


// - - - - - - - - - - - - - - - - - - - - PRE-PROCESSOR DIRECTIVES - - - - - - - - - - - - - - - - - - 

#include "LCD.h"
#include "Keypad.h"
#include "Port_Init.h"
#include "PLL.h"
#include <stdio.h> // for sprintf

#define ADD 0
#define SUBTRACT 1
#define MULTIPLY 2
#define DIVIDE 3

// - - - - - - - - - - - - - - - - - - - - - DECLARATIONS SECTION - - - - - - - - - - - - - - - - - - -

// - Global Variables
float answer;
int operation = 4;
int array_Counter = 0;
int i;   // used as increment variables
char decodekey;
char buffer[16];
int number_flag = 0;
int operation_flag = 0;


// - Function Prototypes
float calculate(float a, float b, int operation);
float button_Press_Array[16] = {0};
void display_Error();
void display_Reset();
void key_Press();






