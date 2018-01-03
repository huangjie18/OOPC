/* EX18-pre.h */
CLASS(Preparing)
{
	IMPLEMENTS(IFlyState);
	void (*init)(Preparing*);
	STATE st;
};



