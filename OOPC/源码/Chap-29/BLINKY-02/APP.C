/* EX1-app.c  */
#include <REG51F.H>
#include <stdio.h>

#define LW_OOPC_STATIC
#include "ex11-light.h"

extern TLightSetting(TLight*);

void main()  {
      TLight light;
      TLightSetting(&light);
	  
	  light.init(&light);
	  while(1) {
	     light.run(&light);
		 }

   }

				   