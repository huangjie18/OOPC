/* EX33-handler.h */
#include "EX33-ifs.h"

CLASS(Handler)
{
   void (*init)(Handler*);
   void (*start)();
   IFlyState  *fs;
};


					