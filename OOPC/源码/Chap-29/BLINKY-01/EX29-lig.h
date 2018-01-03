/* EX11-light.h  */
#include "lw_oopc_kc.h"

CLASS(TLight)
    {
        char state;
		void (*init)(TLight*);
        void (*run)(TLight*);
		void (*goto_R)();
		void (*goto_Y)();
		void (*goto_G)();
    };



				   