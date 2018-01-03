/* cx22-ap4.c  */
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
   void (*change_state)(void*);
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
	 cthis->change_state(cthis);
    }
static void withdraw(void* t, double a)
    {
	 Account* cthis = (Account*)t;
	 cthis->amount -= a;
	 cthis->change_state(cthis);
    }
static void change_state(void*t)
       {
         Account* cthis = (Account*)t;
         if(cthis->state == 'N' ) 
             { if( cthis->amount < 0 ) 
                { 
                  cthis->state = 'O';
                  cthis->message(cthis);
                } 
             }
         else 
            { 
              if( cthis->amount >= 0 ) 
                  cthis->state = 'N';
            } 
       }

static void message(void*t)
    {  Account* cthis = (Account*)t;
       printf("Over(%6.2f)\n", cthis->amount);
    }
CTOR(Account)
  FUNCTION_SETTING(IA.init, init);
  FUNCTION_SETTING(IA.deposit, deposit);
  FUNCTION_SETTING(IA.withdraw, withdraw);
  FUNCTION_SETTING(change_state, change_state);
  FUNCTION_SETTING(message, message);
END_CTOR

void main()
   {
     Account* acc = (Account*)AccountNew();
     acc->init(acc);
     acc->deposit(acc, 100);
     acc->withdraw(acc, 150);
     acc->withdraw(acc, 30);
     getchar();
	 return 0;
}
