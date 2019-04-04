// Filename LCD.h
// Header file containing preprocessor directives and declarations
// Last modified 22/11/2016
// Created by James Collins & Geoffrey Grevers

// - - - - - - - - - - - - - - - - - - - - PRE-PROCESSOR DIRECTIVES - - - - - - - - - - - - - - - - - - 

#define LCD_EN (*((volatile unsigned long *)  0x40004040 )) // PA4
#define LCD_RS (*((volatile unsigned long *)  0x40004020 )) // PA3
#define LCD_DB (*((volatile unsigned long *)  0x400050F0 )) // PB2-5 - DB4-DB7

// - - - - - - - - - - - - - - - - - - - - - DECLARATIONS SECTION - - - - - - - - - - - - - - - - - - -

// - Global Variables

// - Function Prototypes
void lcd_Init(void);
void lcd_EN_Pulse(void);
void lcd_Write_Cmd(unsigned char c);
void lcd_Setup(void);
void lcd_Clear_Screen(void);
void lcd_Goto(unsigned char address);
void lcd_Write_Data(unsigned char d);
void lcd_Write_String(char *string);
