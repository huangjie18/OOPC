/* cx22-ap5.c  */
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
   void (*state_action)(void*);
   void (*message_O)(void*);
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
    }
static void withdraw(void* t, double a)
    {
	 Account* cthis = (Account*)t;
	 if( (cthis->amount - a) < 0 )
             { cthis->state='O';
               cthis->state_action(cthis);
               cthis->state = 'N';
              }
          else
             { cthis->amount -= a;
               cthis->state_action(cthis);
             }
       }
static void message_O(void*t)
    {  Account* cthis = (Account*)t;
       printf("Over(%6.2f)\n", cthis->amount);
    }
static void message_N()
    {
       printf("Welcome\n");
    }
static void state_action(void*t)
       {
         Account* cthis = (Account*)t;
         switch( cthis->state )
           {
             case 'O':
	       cthis->message_O(cthis);
               break;
             case 'N':
               message_N();
               break;
           };
       }

CTOR(Account)
  FUNCTION_SETTING(IA.init, init);
  FUNCTION_SETTING(IA.deposit, deposit);
  FUNCTION_SETTING(IA.withdraw, withdraw);
  FUNCTION_SETTING(state_action, state_action);
  FUNCTION_SETTING(message_O, message_O);
END_CTOR
 
void main()
   {
     Account* acc = (Account*)AccountNew();
     acc->init(acc);
     acc->deposit(acc, 100.5);
     acc->withdraw(acc, 50.5);
     acc->withdraw(acc, 50.6);
     getchar();
	 return 0;
}
