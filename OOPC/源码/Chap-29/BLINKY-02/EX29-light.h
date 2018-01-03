/* EX29-light.h  */
#include "lw_oopc_kc.h"

CLASS(TLight)
    {
        char state;
        unsigned int wait_R, wait_Y, wait_G;
        void (*init)(TLight*);
        void (*run)(TLight*);
        void (*perform)(TLight*);
    };
   