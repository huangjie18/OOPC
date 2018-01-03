/*  wavrec.h   */
#ifndef WAVREC_H
#define WAVREC_H
#include "lw_oopc.h"

CLASS(WavRec)
{
   /* char* m_buffer;
	int m_file_size;*/

    void (*init)(void*);
	void (*prepare)(void*);
	void (*start)(void*);
	void (*close)(void*);
};
#endif

