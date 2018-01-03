/* DoorSwitch.c   */
#include "stdio.h"
#include "switch.h"

static void swDown()
	{  printf("SW is Down\n");  }
static void swUp()
	{  printf("SW is Up\n");  }

CTOR(DoorSwitch)
	FUNCTION_SETTING(swDown, swDown)
	FUNCTION_SETTING(swUp, swUp)
END_CTOR

