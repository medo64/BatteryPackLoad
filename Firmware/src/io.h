#ifndef IO_H
#define IO_H

void io_setup(void);

#if defined(_10F200) || defined(_10F202) || defined(_10F204) || defined(_10F206)
    #define io_out_powerOn()   GP2 = 1
    #define io_out_powerOff()  GP2 = 0
#else
    #define io_out_powerOn()   LATAbits.LATA2 = 1
    #define io_out_powerOff()  LATAbits.LATA2 = 0
#endif


#endif
