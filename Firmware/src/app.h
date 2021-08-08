#ifndef SYSTEM_H
#define SYSTEM_H

#include <xc.h>


#if defined(_10F200) || defined(_10F202) || defined(_10F204) || defined(_10F206)

    // CONFIG
    #pragma config WDTE = OFF       // Watchdog Timer (WDT enabled)
    #pragma config CP = OFF         // Code Protect (Code protection off)
    #pragma config MCLRE = ON       // Master Clear Enable (GP3/MCLR pin function  is MCLR)

#elif defined(_10F220) || defined(_10F222)

    // CONFIG
    #pragma config IOSCFS = 4MHZ    // Internal Oscillator Frequency Select bit (4 MHz)
    #pragma config MCPU = OFF       // Master Clear Pull-up Enable bit (Pull-up disabled)
    #pragma config WDTE = OFF       // Watchdog Timer Enable bit (WDT enabled)
    #pragma config CP = OFF         // Code protection bit (Code protection off)
    #pragma config MCLRE = ON       // GP3/MCLR Pin Function Select bit (GP3/MCLR pin function is MCLR)

    #define _XTAL_FREQ 4000000

#elif defined(_10F320) || defined(_10F322)

    // CONFIG
    #pragma config FOSC = INTOSC    // Oscillator Selection bits (INTOSC oscillator: CLKIN function disabled)
    #pragma config BOREN = ON       // Brown-out Reset Enable (Brown-out Reset enabled)
    #pragma config WDTE = OFF       // Watchdog Timer Disable (WDT disabled)
    #pragma config PWRTE = ON       // Power-up Timer Enable bit (PWRT enabled)
    #pragma config MCLRE = ON       // MCLR Pin Function Select bit (MCLR pin function is MCLR)
    #pragma config CP = OFF         // Code Protection bit (Program memory code protection is disabled)
    #pragma config LVP = ON         // Low-Voltage Programming Enable (Low-voltage programming enabled)
    #pragma config LPBOR = ON       // Brown-out Reset Selection bits (BOR enabled)
    #pragma config BORV = LO        // Brown-out Reset Voltage Selection (Brown-out Reset Voltage (Vbor), low trip point selected.)
    #pragma config WRT = OFF        // Flash Memory Self-Write Protection (Write protection off)

    #define _XTAL_FREQ 31000

#else

    #error "Only PIC10F20x PIC10F22x, and PIC10F32x devices are supported"

#endif


#define wait_20ms()   CLRWDT(); __delay_ms(20);
#define wait_short()  CLRWDT(); __delay_ms(150);
#define wait_10s()    __delay_ms(10000);


void init(void) {

#if defined(_10F200) || defined(_10F202) || defined(_10F204) || defined(_10F206) || defined(_10F220) || defined(_10F222)
    OPTION = 0b11011111;  // disabled T0CKI
#elif defined(_10F320) || defined(_10F322)
    OSCCONbits.IRCF = 0b000;  // 31 kHz (LFINTOSC)
#endif

}

#endif
