/* EX29-ap-2.c (BLINKY.c) */
#define LW_OOPC_STATIC
#include "ex29-light.h"

extern TLightSetting(TLight*);

void main()  {
      TLight light;
      TLightSetting(&light);
	  
	  light.init(&light);
	  while(1) {
	     light.run(&light);
		 }
   }
