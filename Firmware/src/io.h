#ifndef IO_H
#define IO_H

void io_setup(void);

#define io_out_powerOn()   GP2 = 1
#define io_out_powerOff()  GP2 = 0

#endif
