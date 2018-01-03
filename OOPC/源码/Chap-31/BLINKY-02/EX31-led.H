/* EX15-led.h */
#ifndef LED_H
#define LED_H

CLASS(LED)
{
    void (*scan_port)(char);
	void (*data_port)(char);
    void (*load_data)(LED *t); 
	void (*show_digits)(LED *t); 
	int digits[4];   
};
#endif




