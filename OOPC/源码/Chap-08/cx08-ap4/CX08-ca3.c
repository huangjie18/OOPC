/* cx08-ca3.c */
/* static function */
#include <stdio.h>

float area( float x )
{	return (x * x);   }

float volume( float h, float x )
{	return (h * area( x ) ); }


