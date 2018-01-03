/* EX33-handler.h */
#include "EX33-ifs.h"

CLASS(Handler)
{
	void (*init)(Handler*);
	void (*run)(Handler*);
	IFlyState* array[4];
	char state;
};


					