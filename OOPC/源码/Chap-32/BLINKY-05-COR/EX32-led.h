/* EX32-led.h   */
#include "lw_oopc_kc.h"
#include "ex32-il.h"

CLASS(LED_P0)
{
	IMPLEMENTS(IL);
	void (*init)(LED_P0*);
	IL* next;
};

CLASS(LED_P1)
{
	IMPLEMENTS(IL);
	void (*init)(LED_P1*);
	IL* next;
};

CLASS(LED_P2)
{
	IMPLEMENTS(IL);
	void (*init)(LED_P2*);
	IL* next;
};