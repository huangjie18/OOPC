/* cx08-ca2.c */
/* Static functions */
#include <stdio.h>
#define  PI  3.1416

static float area( float r )
{	return (PI*r*r);  }

float cylinder( float h, float r)
{	return (h * area( r ) );  }

