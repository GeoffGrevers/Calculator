// Filename PLL.c
// The initialisation / setup of the PLL and SysTick
// Last modified 29/11/2016 
// Created by James Collins & Geoffrey Grevers

// - - - - - - - - - - - - - - - - - - - - PRE-PROCESSOR DIRECTIVES - - - - - - - - - - - - - - - - - - 

#include "PLL.h"

// - - - - - - - - - - - - - - - - - - - - - SUBROUTINES SECTION - - - - - - - - - - - - - - - - - - - -

// Subroutine to initialise SysTick
// 
// Inputs: None
// Outputs: None
// Notes: None
void SysTick_Init(void){
  NVIC_ST_CTRL_R = 0;                   // disable SysTick during setup
  NVIC_ST_RELOAD_R = 0x00FFFFFF;        // maximum reload value
  NVIC_ST_CURRENT_R = 0;                // any write to current clears it             
  NVIC_ST_CTRL_R = 0x00000005;          // enable SysTick with core clock
}


// Subroutine to initialise PLL
// PLL configured for 80 MHz clock
// Inputs: None
// Outputs: None
// Notes: None
void PLL_Init(void){
  // 0) Use RCC2
  SYSCTL_RCC2_R |=  0x80000000;  		// USERCC2
  // 1) bypass PLL while initializing
  SYSCTL_RCC2_R |=  0x00000800;  		// BYPASS2, PLL bypass
  // 2) select the crystal value and oscillator source
  SYSCTL_RCC_R = (SYSCTL_RCC_R &~0x000007C0)   // clear XTAL field, bits 10-6
                 + 0x00000540;   		// 10101, configure for 16 MHz crystal
  SYSCTL_RCC2_R &= ~0x00000070;  		// configure for main oscillator source
  // 3) activate PLL by clearing PWRDN
  SYSCTL_RCC2_R &= ~0x00002000;
  // 4) set the desired system divider
  SYSCTL_RCC2_R |= 0x40000000;   		// use 400 MHz PLL
  SYSCTL_RCC2_R = (SYSCTL_RCC2_R&~ 0x1FC00000)  // clear system clock divider
                  + (4<<22);      	// change the left most number to configure clock
	
  // 5) wait for the PLL to lock by polling PLLLRIS
  while((SYSCTL_RIS_R&0x00000040)==0){};  // wait for PLLRIS bit
  // 6) enable use of PLL by clearing BYPASS
  SYSCTL_RCC2_R &= ~0x00000800;
}


// Subroutine to set the SysTick delay
// The delay parameter is in units of the 80 MHz core clock. (12.5 ns)
// Inputs: Delay parameter, set in terms of how many clock cycles there are within the chosen
//         delay time.
// Outputs: None
// Notes: None
void SysTick_Wait(unsigned long delay){
  NVIC_ST_RELOAD_R = delay-1;  					 // number of counts to wait
  NVIC_ST_CURRENT_R = 0;       					 // any value written to CURRENT clears
  while((NVIC_ST_CTRL_R&0x00010000)==0){ // wait for count flag
  }
}


