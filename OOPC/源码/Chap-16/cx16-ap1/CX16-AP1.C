/*  cx16-ap1.c   */
#include "stdio.h"
#include "lw_oopc.h"

CLASS(BaseballTeam)
{
   void (*init)(void*);
   void (*setManager)(void*, char*);
   void (*setCoach)(void*, char*);
   void (*addPlayer)(void*, char*);
   void (*display)(void*);
   char *manager, *coach, *players[20];
   int i;
};

static void init(void* t)
       {
	 BaseballTeam* cthis = (BaseballTeam*) t;
	 cthis->i=0;
	 cthis->manager = NULL;
	 cthis->coach = NULL;
       }
static void setManager(void* t, char *manager_name)
       {
	 BaseballTeam* cthis = (BaseballTeam*) t;
	 cthis->manager = manager_name;
       }
static void setCoach(void*t, char *coach_name)
       {
	 BaseballTeam* cthis = (BaseballTeam*) t;
	 cthis->coach = coach_name;
       }
static void addPlayer(void* t, char *player_name )
       {
	  BaseballTeam* cthis = (BaseballTeam*) t;
	  cthis->players[cthis->i] = player_name;
          cthis->i++;
       }

void display(void*t)
       {
         int k;
	 BaseballTeam* cthis = (BaseballTeam*) t;
	 printf("%s\n", cthis->manager);
         printf("%s\n", cthis->coach);
	 for(k=0; k < cthis->i; k++ )
	     printf("%s\n", cthis->players[k]);
       }
CTOR(BaseballTeam)
    FUNCTION_SETTING(init, init);
    FUNCTION_SETTING(setManager, setManager);
    FUNCTION_SETTING(setCoach, setCoach);
    FUNCTION_SETTING(addPlayer, addPlayer);
    FUNCTION_SETTING(display, display);
END_CTOR

int main()
{
     BaseballTeam*  RedSock = BaseballTeamNew();
     RedSock->init(RedSock);
     RedSock->setManager(RedSock, "Jamis King");
     RedSock->setCoach(RedSock, "David Wang" );
     RedSock->addPlayer(RedSock, "Jim Lin" );
     RedSock->addPlayer(RedSock, "Alvin Kao" );
     RedSock->addPlayer(RedSock, "John Coppin" );
     RedSock->display(RedSock);
     getchar();
     return 0;

}