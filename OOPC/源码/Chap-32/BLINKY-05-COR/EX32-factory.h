/*  EX32-factory.h */ 
#include "ex32-il.h"

CLASS(Factory)
{
   void (*init)(Factory*);
   IL* (*get_LED_LIST)(Factory*, int);
   IL *head;
};