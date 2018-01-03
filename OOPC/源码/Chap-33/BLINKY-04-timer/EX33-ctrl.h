/* EX33-ctrl.h */
#include "ex33-pre.h"
#include "ex33-fly.h"
#include "ex33-handler.h"
			 
CLASS(CTRL)
{
   void (*init)(CTRL*);
   void (*start)(CTRL*);
   Handler hObj;
   char state;
   Preparing pObj;
   Flying fObj;
};



