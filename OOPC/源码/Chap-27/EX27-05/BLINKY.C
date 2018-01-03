/* EX27-05.C (BLINKY.C) */
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
/* ---------------------------------------------*/
	static void run(){
    unsigned int i;              
    unsigned char j;      
	 
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

CLASS(SEG)
{
	void (*show)();
};

	static void show(){
    unsigned int x, i;              
	 
	for (x=0; x < 10; x++)  {   
        P0 = NUMB[x];                         
        for (i = 0; i < 10000; i++)  {  
            wait ();                      
        }
    }
 }

CTOR(SEG)
	FUNCTION_SETTING(show, show)
END_CTOR
/* --------------------------------------- */
CLASS(Controller)
{
    void (*doing)();
};

static void doing()
{
	LED le;            SEG sg; 
    LEDSetting(&le);   SEGSetting(&sg);	 
		              
    while (1) {                       
       le.run();
	   sg.show();
	}
}

CTOR(Controller)
	FUNCTION_SETTING(doing, doing);
END_CTOR
/* ---------------------------------------- */
void main (void)  {
   Controller ctrl;
   ControllerSetting(&ctrl);
   ctrl.doing();
}
