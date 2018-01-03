/* EX12-light-l.h  */

#include "lw_oopc_kc.h"

CLASS(LightL)
    {
    char state;
	void (*init)(char, LightL*);
    void (*ev_Y)(LightL*);
	void (*ev_RG)(LightL*);
	void (*goto_R)();
	void (*goto_Y)();
	void (*goto_G)();
    };
				   

				   