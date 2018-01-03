/* EX27-03.C (BLINKY.C)  */
#include <REG51F.H>
#define LW_OOPC_STATIC
#include "lw_oopc_kc.h"

void wait (void)  {              
       ;                              
}

CLASS(LED)
{
	void (*run)();
};

	static void run(){
    unsigned int i;  unsigned char j;      
	for (j=0x01; j< 0x80; j<<=1)  {   
       P1 = j;                         
       for (i = 0; i < 10000; i++)  {  
            wait ();                      
        }
    }
    for (j=0x80; j> 0x01; j>>=1)  {  
       P1 = j;                         
       for (i = 0; i < 10000; i++)  { 
          wait ();                      
      }	   
	}
}

CTOR(LED)
   FUNCTION_SETTING(run, run)
END_CTOR
/* -------------------------------------- */
	char NUMB[10] = {0xC0, 0xf9, 0xa4, 0xb0, 0x99, 0x92, 0x83, 0xf8, 0x80, 0x98}; 
	static void show(){
    unsigned int x, i;              
	for (x=0; x < 10; x++)  {   
        P0 = NUMB[x];                         
        for (i = 0; i < 10000; i++)  {  
            wait ();                      
        }
    }
 }
/* --------------------------------------- */
	void main (void)  {
    LED le; 
    LEDSetting(&le); 	 
		              
    while (1) {                       
       le.run();
	   show();
	}
}
