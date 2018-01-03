/* cx22-ap6.c  */
#include <stdio.h>
#include "lw_oopc.h"

INTERFACE(IA)
{
 void (*init)(void*);
 void (*open)(void*);
 void (*close)(void*);
 void (*withdraw)(void*, double);
};

CLASS(Account)
{
   IMPLEMENTS(IA);
   double amount;
   int state;
   int psw;
};

static void init(void* t)
       {
	   Account* cthis = (Account*)t;
	   cthis->amount = 1000.525;
	   cthis->state = 0;
       }

static void open(void*t)
    {
	 Account* cthis = (Account*)t;
	 cthis->state = 1;
    }
static void close(void*t)
    {
	 Account* cthis = (Account*)t;
	 cthis->state = 0;
    }
static void withdraw(void* t, double a)
    {
	 Account* cthis = (Account*)t;
	 if( cthis->state == 1 )
             { printf("welcome.\n");
               cthis->amount -= a;
             }
           else
               printf("account is not open!\n");
       }

CTOR(Account)
  FUNCTION_SETTING(IA.init, init);
  FUNCTION_SETTING(IA.open, open);
  FUNCTION_SETTING(IA.close, close);
  FUNCTION_SETTING(IA.withdraw, withdraw);
END_CTOR

void main()
   {
     IA* acc = (IA*)AccountNew();
     acc->init(acc);
     acc->withdraw(acc, 1.0);
	 acc->open(acc);
     acc->withdraw(acc, 200.0);
     acc->close(acc);
     acc->withdraw(acc, 500.0);
     getchar();
	 return 0;
}
