/* cx22-ap3.c  */
#include <stdio.h>
#include "lw_oopc.h"

INTERFACE(IA)
{
 void (*init)(void*);
 void (*deposit)(void*, double);
 void (*withdraw)(void*, double);
};

CLASS(Account)
{
   IMPLEMENTS(IA);
   double amount;
   char state;
   void (*message)(void*);
};

static void init(void* t)
       {
	   Account* cthis = (Account*)t;
	   cthis->amount = 0;
	   cthis->state='N';
       }

static void deposit(void*t, double a)
       {
	 Account* cthis = (Account*)t;
	 cthis->amount += a;
	 if(cthis->amount > 0 )
	    cthis->state='N';
        }
static void withdraw(void* t, double a)
       {
	 Account* cthis = (Account*)t;
	 cthis->amount = cthis->amount - a;
	 if(cthis->amount < 0 )
	    { cthis->state='O';
	      cthis->message(cthis);
	    }
        }
static void message(void*t)
       {  Account* cthis = (Account*)t;
	  printf("You owe the bank $%6.2f\n", -1 * cthis->amount);
       }
CTOR(Account)
  FUNCTION_SETTING(IA.init, init);
  FUNCTION_SETTING(IA.deposit, deposit);
  FUNCTION_SETTING(IA.withdraw, withdraw);
  FUNCTION_SETTING(message, message);
END_CTOR

void main()
   {
     Account* acc = (Account*)AccountNew();
     acc->init(acc);
     acc->deposit(acc, 100);
     acc->withdraw(acc, 150);
     getchar();
	 return 0;
}
