// Filename LCD.h
// Header file containing preprocessor directives and declarations
// Last modified 22/11/2016
// Created by James Collins & Geoffrey Grevers

// - - - - - - - - - - - - - - - - - - - - PRE-PROCESSOR DIRECTIVES - - - - - - - - - - - - - - - - - - 

#define SYSCTL_RCGC2_R            (*((volatile unsigned long *)  0x400FE108 )) 

// - PORT A
#define GPIO_PORTA_DATA_R         (*((volatile unsigned long *)  0x400043FC ))
#define GPIO_PORTA_DIR_R          (*((volatile unsigned long *)  0x40004400 ))
#define GPIO_PORTA_AFSEL_R        (*((volatile unsigned long *)  0x40004420 ))
#define GPIO_PORTA_PUR_R          (*((volatile unsigned long *)  0x40004510 ))
#define GPIO_PORTA_DEN_R          (*((volatile unsigned long *)  0x4000451C ))
#define GPIO_PORTA_CR_R           (*((volatile unsigned long *)  0x40004524 ))
#define GPIO_PORTA_AMSEL_R        (*((volatile unsigned long *)  0x40004528 ))
#define GPIO_PORTA_PCTL_R         (*((volatile unsigned long *)  0x4000452C ))
	
// - PORT B
#define GPIO_PORTB_DATA_R 				(*((volatile unsigned long *)  0x400053FC ))
#define GPIO_PORTB_DIR_R   				(*((volatile unsigned long *)  0x40005400 ))
#define GPIO_PORTB_AFSEL_R 				(*((volatile unsigned long *)  0x40005420 ))
#define GPIO_PORTB_PUR_R 					(*((volatile unsigned long *)  0x40005510 ))
#define GPIO_PORTB_DEN_R          (*((volatile unsigned long *)  0x4000551C ))
#define GPIO_PORTB_CR_R 					(*((volatile unsigned long *)  0x40005524 ))
#define GPIO_PORTB_AMSEL_R        (*((volatile unsigned long *)  0x40005528 ))
#define GPIO_PORTB_PCTL_R         (*((volatile unsigned long *)  0x4000552C ))

// - PORT D
#define GPIO_PORTD_DATA_R   			(*((volatile unsigned long *)  0x400073FC ))
#define GPIO_PORTD_DIR_R     			(*((volatile unsigned long *)  0x40007400 ))
#define GPIO_PORTD_AFSEL_R   			(*((volatile unsigned long *)  0x40007420 ))
#define GPIO_PORTD_PUR_R     			(*((volatile unsigned long *)  0x40007510 ))
#define GPIO_PORTD_DEN_R     			(*((volatile unsigned long *)  0x4000751C ))
#define GPIO_PORTD_CR_R     			(*((volatile unsigned long *)  0x40007524 ))
#define GPIO_PORTD_AMSEL_R 				(*((volatile unsigned long *)  0x40007528 ))
#define GPIO_PORTD_PCTL_R   			(*((volatile unsigned long *)  0x4000752C ))
#define GPIO_PORTD_LOCK_R   			(*((volatile unsigned long *)  0x40007520 ))
	
// - PORT E
#define GPIO_PORTE_DATA_R  				(*((volatile unsigned long *)  0x400243FC ))
#define GPIO_PORTE_DIR_R     			(*((volatile unsigned long *)  0x40024400 ))
#define GPIO_PORTE_AFSEL_R   			(*((volatile unsigned long *)  0x40024420 ))
#define GPIO_PORTE_PUR_R     			(*((volatile unsigned long *)  0x40024510 ))
#define GPIO_PORTE_DEN_R     			(*((volatile unsigned long *)  0x4002451C ))
#define GPIO_PORTE_CR_R     			(*((volatile unsigned long *)  0x40024524 ))
#define GPIO_PORTE_AMSEL_R   			(*((volatile unsigned long *)  0x40024528 ))
#define GPIO_PORTE_PCTL_R   			(*((volatile unsigned long *)  0x4002452C ))

	

// - - - - - - - - - - - - - - - - - - - - - DECLARATIONS SECTION - - - - - - - - - - - - - - - - - - -

// - Global Variables

// - Function Prototypes
void PortA_Init(void); // LCD
void PortB_Init(void); // LCD

void PortD_Init(void); // Keypad
void PortE_Init(void); // Keypad




