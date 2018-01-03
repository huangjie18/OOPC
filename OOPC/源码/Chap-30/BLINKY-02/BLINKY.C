/* EX30-ap-2.c (BLINKY.c)  */
#include <REG51F.H>
#include <stdio.h>

#define LW_OOPC_STATIC
#include "EX30-ctrl.h"

extern CTRLSetting(CTRL*);

void main()  {
      CTRL ctrl;
      CTRLSetting(&ctrl);
	  
	  ctrl.init(&ctrl);
	  ctrl.run(&ctrl);
	}

				   