/* EX12-light-r.h  */

#include "lw_oopc_kc.h"

CLASS(LightR) {
    char state;
	void (*init)(char, LightR*);
    void (*ev_Y)(LightR*);
	void (*ev_RG)(LightR*);
	void (*goto_R)();
	void (*goto_Y)();
	void (*goto_G)();
    };
				   

				   