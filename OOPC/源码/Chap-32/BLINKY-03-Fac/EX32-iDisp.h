/* ex16-idisp.h */
#ifndef _IDISP_H
#define	_IDISP_H

INTERFACE(IDisplay)
{
	void (*init)(void*);
	void (*display)(void*);
};
#endif
