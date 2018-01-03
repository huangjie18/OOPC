/* EX31-led.h */
#ifndef LED_H
#define LED_H
#include "ex31-ip.h"

CLASS(LED)
{
    void (*load_data)(LED *t); 
	void (*show_data)(LED *t); 
    IPort *scan_port, *data_port;
	int digits[4];   
};
#endif




