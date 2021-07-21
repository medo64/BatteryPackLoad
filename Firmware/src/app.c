#include <stdbool.h>
#include "app.h"
#include "io.h"

void main(void) {
    init();
    io_setup();

    // initial twinkle - total of two short bursts including one from the loop
    CLRWDT();
    io_out_powerOn(); wait_20ms();
    io_out_powerOff(); wait_short();

    // loop
    while(true) {
        // pulse
        io_out_powerOn();
        wait_20ms();
        io_out_powerOff();

        wait_8s();
    }
}
