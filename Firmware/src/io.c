#include <xc.h>

void io_setup() {
    GP2 = 0;                // turn off GP2
    TRISGPIO = 0b11111011;  // GP2 is output
}
