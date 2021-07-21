#include <xc.h>

void io_setup() {

#if defined(_10F200) || defined(_10F202) || defined(_10F204) || defined(_10F206)
    GP2 = 0;                // turn off GP2
    TRISGPIO = 0b11111011;  // GP2 is output
#else
    LATAbits.LATA2 = 0;    // turn off RA2
    TRISAbits.TRISA2 = 0;  // RA2 is output
#endif

}
