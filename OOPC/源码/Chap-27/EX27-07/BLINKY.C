/* EX27-07.C (BLINKY.C) */
#include <REG51F.H>
#define LW_OOPC_PURE_STATIC
#include "lw_oopc_kc.h"

static void wait (void)  {            /* wait function */
  ;                                   /* only to delay for LED flashes */
}

CLASS(LED)
{
  void (*run)();
};

static void running()
{
  unsigned int i;                    /* Delay var */
  unsigned char j;  
  for (j=0x01; j< 0x80; j<<=1)  {    /* Blink LED 0, 1, 2, 3, 4, 5, 6 */
      P1 = j;                        /* Output to LED Port */
      for (i = 0; i < 10000; i++)  { /* Delay for 10000 Counts */
       wait ();                      /* call wait function */
      }
    }
  for (j=0x80; j> 0x01; j>>=1)  {    /* Blink LED 6, 5, 4, 3, 2, 1 */
      P1 = j;                        /* Output to LED Port */
      for (i = 0; i < 10000; i++)  { /* Delay for 10000 Counts */
       wait ();                      /* call wait function */
      }
    }
}
/* --------------------------------*/
void main (void)  {
   LED le; 
   le.run = running;
   while(1) {
      le.run();  
   }
}
