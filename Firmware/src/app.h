#ifndef SYSTEM_H
#define SYSTEM_H

#include <xc.h>


// CONFIG
#pragma config WDTE = ON        // Watchdog Timer (WDT enabled)
#pragma config CP = OFF         // Code Protect (Code protection off)
#pragma config MCLRE = ON       // Master Clear Enable (GP3/MCLR pin function  is MCLR)


#define _XTAL_FREQ 4000000


#define reset()  asm("RESET");
#define wait_20ms()   __delay_ms(20);
#define wait_short()  __delay_ms(150);


void init(void) {
    // Watchdog timer
    OPTION = 0b11111110;  // Prescaler assigned to the WDT and set to 1:64
}

#endif
