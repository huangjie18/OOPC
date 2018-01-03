/* cx15-ic.h */
#ifndef IC_H
#define IC_H
INTERFACE(ICell)
{
   void (*init)(void*);
   void (*SetLinkToNext)(void*, ICell*);
   int (*GetPower)(void*) ;
};
#endif
