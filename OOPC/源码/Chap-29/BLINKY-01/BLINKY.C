/* EX29-ap-1.c (BLINKY.c)  */
#include <stdio.h>
#define LW_OOPC_STATIC
#include "ex29-lig.h"

extern void TLightSetting(TLight*);

void main()  {
      TLight light;
      TLightSetting(&light);
	  
	  light.init(&light);
	  while(1) {
	     light.run(&light);
		 }
   }
