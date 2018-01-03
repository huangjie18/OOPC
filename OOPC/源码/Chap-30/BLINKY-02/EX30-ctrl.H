/* EX30-ctrl.h  */
#include "ex30-light-r.h"
#include "ex30-light-l.h"

CLASS(CTRL)
    {
        char state;
		LightR lg_right;
		LightL lg_left;
		void (*init)(CTRL*);
        void (*run)(CTRL*);
		void (*goto_LW)(CTRL*);
		void (*goto_SW)(CTRL*);
    };



				   