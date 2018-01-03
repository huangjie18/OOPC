/* cx22-ap1.c  */
#include <stdio.h>
#include "cx22-lig.h"

int main()
{
	IL* lg = (IL*)LightNew();
	lg->init(lg);
	lg->turnOn(lg);
	lg->turnOn(lg);
	lg->turnOff(lg);
	getchar();
	return 0;
}
