#ifndef SYSTEM_H
#define SYSTEM_H

#include <xc.h>


#if defined(_10F200) || defined(_10F202) || defined(_10F204) || defined(_10F206)

    // CONFIG
    #pragma config WDTE = ON        // Watchdog Timer (WDT enabled)
    #pragma config CP = OFF         // Code Protect (Code protection off)
    #pragma config MCLRE = ON       // Master Clear Enable (GP3/MCLR pin function  is MCLR)

    #define _XTAL_FREQ 4000000

    #define wait_20ms()   __delay_ms(20);
    #define wait_short()  __delay_ms(150);
    #define wait_8s()     for (int i = 0; i < 7; i++) { CLRWDT(); SLEEP(); NOP(); }

#elif defined(_10F320) || defined(_10F322)

    // CONFIG
    #pragma config FOSC = INTOSC    // Oscillator Selection bits (INTOSC oscillator: CLKIN function disabled)
    #pragma config BOREN = ON       // Brown-out Reset Enable (Brown-out Reset enabled)
    #pragma config WDTE = ON        // Watchdog Timer Enable (WDT enabled)
    #pragma config PWRTE = ON       // Power-up Timer Enable bit (PWRT enabled)
    #pragma config MCLRE = ON       // MCLR Pin Function Select bit (MCLR pin function is MCLR)
    #pragma config CP = OFF         // Code Protection bit (Program memory code protection is disabled)
    #pragma config LVP = ON         // Low-Voltage Programming Enable (Low-voltage programming enabled)
    #pragma config LPBOR = ON       // Brown-out Reset Selection bits (BOR enabled)
    #pragma config BORV = LO        // Brown-out Reset Voltage Selection (Brown-out Reset Voltage (Vbor), low trip point selected.)
    #pragma config WRT = OFF        // Flash Memory Self-Write Protection (Write protection off)

    #define _XTAL_FREQ 4000000

    #define wait_20ms()   __delay_ms(20);
    #define wait_short()  __delay_ms(150);
    #define wait_8s()     CLRWDT(); SLEEP(); NOP();

#else

    #error "Only PIC10F20x and PIC10F32x devices are supported"

#endif

void init(void) {

#if defined(_10F200) || defined(_10F202) || defined(_10F204) || defined(_10F206)
    // Watchdog timer
    OPTION = 0b11111110;  // Prescaler assigned to the WDT and set to 1:64
#else
    WDTCONbits.SWDTEN = 1;       // WDT turned on
    WDTCONbits.WDTPS = 0b01101;  // 8s interval
#endif

}

#endif
