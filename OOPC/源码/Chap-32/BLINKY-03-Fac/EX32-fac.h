/*  EX32-fac.h */ 
#include "ex32-idisp.h"

CLASS(Factory)
{
   IDisplay* (*get_object)();
};

