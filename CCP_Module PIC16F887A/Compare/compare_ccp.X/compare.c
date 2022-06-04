/*
 * File:   compare.c
 * Author: Gopika
 *
 * Created on 15 December, 2021, 5:36 PM
 */
#pragma config FOSC = HS        // Oscillator Selection bits (HS oscillator)
#pragma config WDTE = OFF       // Watchdog Timer Enable bit (WDT disabled)
#pragma config PWRTE = OFF      // Power-up Timer Enable bit (PWRT disabled)
#pragma config BOREN = ON       // Brown-out Reset Enable bit (BOR enabled)
#pragma config LVP = OFF        // Low-Voltage (Single-Supply) In-Circuit Serial Programming Enable bit (RB3 is digital I/O, HV on MCLR must be used for programming)
#pragma config CPD = OFF        // Data EEPROM Memory Code Protection bit (Data EEPROM code protection off)
#pragma config WRT = OFF        // Flash Program Memory Write Enable bits (Write protection off; all program memory may be written to by EECON control)
#pragma config CP = OFF         // Flash Program Memory Code Protection bit (Code protection off)

#define _XTAL_FREQ 10000000 //Specify the XTAL crystall FREQ 

#include <xc.h>

void main(void)
{
    PORTC = 0;
    TRISC = 0;
    CCP1CON = 11;
    CCP1IE = 1;
    GIE = 1;
    PEIE = 1;
    CCPR1H = 0xC3;
    CCPR1L = 0x50;
    //CCPR1 = 0xC350 = 50000
    T1CON = 0x01; //Prescaler 1:1, start Timer 1
    while(1){
    //Do whatever else is required
    }
}

void __interrupt() isr(void)
{
  if (CCP1IF)
  {
        RC0 = ~RC0;
        CCP1IF = 0;
    }
}