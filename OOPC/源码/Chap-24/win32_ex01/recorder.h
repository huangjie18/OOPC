/*  recorder.h   */
#ifndef RECORDER_H
#define RECORDER_H
#include "lw_oopc.h"
#include "WavPlay.h"
#include "WavRec.h"

CLASS(Recorder)
{
    WavPlay* wp;
	WavRec* wr;
  	int m_state;
  	void (*init)(void*);
	void (*play_WaveFile)(void*);
    void (*prepare_rec)(void*);
	void (*start_rec)(void*);
	void (*close_rec)(void*);
};
#endif