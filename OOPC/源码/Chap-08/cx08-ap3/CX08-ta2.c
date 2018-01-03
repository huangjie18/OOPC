/* cx08-ta2.c */
/* External storage class */
#include <stdio.h>
#include <string.h>

extern char *ps;
void update()
{
	char bb[10];
	bb[0] = ps[3];
	bb[1] = ps[2];
	bb[2] = ps[1]; 
	bb[3] = ps[0];
	bb[4] = '\0';
	puts(bb);
}

