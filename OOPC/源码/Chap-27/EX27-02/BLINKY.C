/*  EX27-02.C (BLINKY.C)  */
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
    unsigned int i;   unsigned char j;      
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
/* ----------------------------------------------- */
void main (void)  {
    LED le; 
    LEDSetting(&le);	 
    while (1) {                       
       le.run();
	}
}
