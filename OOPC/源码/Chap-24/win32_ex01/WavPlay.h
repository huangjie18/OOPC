/*  wavplay.h   */
#ifndef WAVPLAY_H
#define WAVPLAY_H
#include "lw_oopc.h"

CLASS(WavPlay)
{
    char* m_buffer;
	int m_file_size;

    void (*init)(void*);
    void (*play_File)(void*);
};
#endif

