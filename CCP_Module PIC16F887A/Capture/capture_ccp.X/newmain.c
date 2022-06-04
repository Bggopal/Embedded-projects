/*
 * File:   newmain.c
 * Author: Guga
 */


// 'C' source line config statements

// CONFIG
#pragma config FOSC = HS        // Oscillator Selection bits (HS oscillator)
#pragma config WDTE = OFF       // Watchdog Timer Enable bit (WDT disabled)
#pragma config PWRTE = OFF      // Power-up Timer Enable bit (PWRT disabled)
#pragma config BOREN = ON       // Brown-out Reset Enable bit (BOR enabled)
#pragma config LVP = OFF        // Low-Voltage (Single-Supply) In-Circuit Serial Programming Enable bit (RB3 is digital I/O, HV on MCLR must be used for programming)
#pragma config CPD = OFF        // Data EEPROM Memory Code Protection bit (Data EEPROM code protection off)
#pragma config WRT = OFF        // Flash Program Memory Write Enable bits (Write protection off; all program memory may be written to by EECON control)
#pragma config CP = OFF         // Flash Program Memory Code Protection bit (Code protection off)

// #pragma config statements should precede project file includes.
// Use project enums instead of #define for ON and OFF.

#include <xc.h>

#define _XTAL_FREQ 20000000 //Specify the XTAL crystall FREQ


void main(void)
{
   //--[ Configure The IO Ports ]--
  // Set The Output Port For The Capture Operation (CCPR1 register)
  TRISB = 0x00;
  PORTB = 0x00; // Initial State
  // Set The Output Port For The TMR1 Module (TMR1 register)
  TRISD = 0x00;
  PORTD = 0x00; // Initial State
  //--[ Configure The Timer1 Module To Operate In Counter Mode ]--
  TMR1 = 0;
  T1CKPS0 = 0;
  T1CKPS1 = 0;
  TMR1CS = 1;
  T1OSCEN = 1;
  T1SYNC = 0;
  TMR1ON = 1;
  //--[ Configure The CCP1 Module To Operate in Capture Mode ]--
  CCP1M0 = 1;
  CCP1M1 = 0;
  CCP1M2 = 1;
  CCP1M3 = 0;
  // Enable CCP1 Interrupt
  CCP1IE = 1;
  PEIE = 1;
  GIE = 1;
  // Create The Main Loop Of The System
  while (1)
  {
    // Read & Print Out The TMR1 Counts
    PORTD = TMR1;
  }
  return;
}
 
// Write The ISR Handler
void __interrupt() isr(void)
{
  if (CCP1IF)
  {
    // If Capture Event Occurs, Write the CCPR1 register's value to PORTB
    PORTB = CCPR1;
    CCP1IF = 0;
  }
}
 