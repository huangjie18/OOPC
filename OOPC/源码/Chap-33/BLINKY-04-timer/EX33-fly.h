/* EX17-fly.h */

CLASS(Flying)
{
   IMPLEMENTS(IFlyState);
   void (*init)(Flying*);
   STATE st;
};



