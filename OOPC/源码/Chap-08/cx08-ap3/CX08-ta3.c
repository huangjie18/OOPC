/*  cx08-ta3.cpp  */
/*  External Variable  */

#include <stdio.h>
#include <string.h>
#include <ctype.h>

int upr, lwr;
extern char *ps;

void count()
{
	char *pk;
	upr = lwr = 0;
	pk = ps;
	while( *pk != '\0' )
		if( islower( *pk++ ) )  lwr++;
		else                    upr++;
}

