/* EX31-led.h */
#ifndef LED_H
#define LED_H

CLASS(LED)
{
    void (*data_port)(char);
    void (*scan_port)(char);
    void (*run)(LED*);
};
#endif




   