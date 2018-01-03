/*  recorder.c    */
#include "StdAfx.h" 
#include "stdio.h"
#include "recorder.h"
#include "WavPlay.h"
#include "WavRec.h"

extern void* WavPlayNew();
extern void* WavSaveNew();
extern void* WavRecNew();
/*    -----------------------------------    */
static void init(void *t)
{
	Recorder* cthis = (Recorder*)t;
    (cthis->wp) = (WavPlay*)WavPlayNew();
    (cthis->wp)->init(cthis->wp);
    (cthis->wr) = (WavRec*)WavRecNew();
    (cthis->wr)->init(cthis->wr);
  }

static void load_song_from_db(void* t)
      {
       // Recorder* cthis = (Recorder*)t;
	   // (cthis->wp)->load_from_db(cthis->wp);
       // cthis->m_state = 2; /* Stop  */
       // MessageBox(NULL,_T("Load OK"),NULL, MB_OK | MB_ICONINFORMATION);
}
static void play_WaveFile(void* t)  // play wave data in file
      {
        Recorder* cthis = (Recorder*)t;
        (cthis->wp)->play_File(cthis->wp);
      }
// writting wave file header 
static void prepare_rec(void* t)
      {
        Recorder* cthis = (Recorder*)t;
		(cthis->wr)->prepare(cthis->wr);
        cthis->m_state = 1; /* Stop  */
        //  MessageBox(NULL,_T("Copy OK"),NULL, MB_OK | MB_ICONINFORMATION);
}
static void start_rec(void* t)
      {
        Recorder* cthis = (Recorder*)t;
		(cthis->wr)->start(cthis->wr);
        cthis->m_state = 1; /* Stop  */
        // MessageBox(NULL,_T("Copy OK"),NULL, MB_OK | MB_ICONINFORMATION);
     }
static void close_rec(void* t)
      {
        Recorder* cthis = (Recorder*)t;
		(cthis->wr)->close(cthis->wr);
        cthis->m_state = 2; /* Stop  */
        //  MessageBox(NULL,_T("Copy OK"),NULL, MB_OK | MB_ICONINFORMATION);    
      }
CTOR(Recorder)
   FUNCTION_SETTING(init, init)
   FUNCTION_SETTING(play_WaveFile, play_WaveFile)
   FUNCTION_SETTING(prepare_rec, prepare_rec)
   FUNCTION_SETTING(start_rec, start_rec)
   FUNCTION_SETTING(close_rec, close_rec)
END_CTOR

