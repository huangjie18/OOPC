/* EX33-handler.h */
#include "EX33-evs.h"

CLASS(Handler)
{
	void (*init)(Handler*);
	void (*change_state)(Handler*);
	char state;
	IEvState *list[2], *es_obj;
};

