/* EX33-FlyState.h */

CLASS(Preparing)
{
	IMPLEMENTS(IFlyState);
	Status st;
};

static void init(Status x){
	st = x;
}

Status get
