/* cx16-ip.h */
#ifndef IP_H
#define IP_H

INTERFACE(IPower)
{
   void (*init)(void*);
   int (*GetPower)(void*) ;
};
#endif