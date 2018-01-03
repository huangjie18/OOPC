/*  WavPlay.c    */
#include "StdAfx.h" 
#include "stdio.h"
#include <MMSystem.h>
#include "wavplay.h"

#define OFFSET_FORMATTAG			20
#define OFFSET_CHANNELS				22
#define OFFSET_SAMPLESPERSEC		24
#define OFFSET_AVGBYTESPERSEC		28
#define OFFSET_BLOCKALIGN			32
#define OFFSET_BITSPERSAMPLE		34
#define OFFSET_WAVEDATA				44
#define HEADER_SIZE	                OFFSET_WAVEDATA

//-----------------------------------------
static void CALLBACK VoicePlayProc(HWAVEOUT hwo, UINT uMsg, DWORD dwInstance, DWORD dwParam1, DWORD dwParam2)
{
	switch(uMsg)
	{
	case WOM_OPEN:
		break;
	case WOM_DONE:
		{
			WAVEHDR *whdr = (WAVEHDR*)dwParam1;
			if(whdr->dwUser)
				waveOutWrite(hwo, whdr, sizeof(WAVEHDR));
			else
			{
				waveOutUnprepareHeader(hwo, whdr, sizeof(WAVEHDR));
				delete whdr;
			}
		}
		break;
	case WOM_CLOSE:
		break;
	}
}
//---------------------------------------------------------------------
static void init(void *t)
{   WavPlay* cthis = (WavPlay*)t;  }

// play wave data from c:\\SymSound.wav rather than Linter DB
static void play_File(void*t)
{
    char* buffer;
	int file_size;
	WAVEFORMATEX m_Format;
	HWAVEOUT m_hPlay;

	// load wave data from c:\\SymSound.wav to buffer[]
	FILE *pf = fopen("c:\\SymSound.wav", "rb");
    if(!pf)
	{  //MessageBox(NULL, "File not found", NULL, NULL);
        return;
	}
    fseek(pf, 0, SEEK_END);
    file_size = ftell(pf);
    fseek(pf, 0, SEEK_SET);
    buffer = new char [file_size];
    fread(buffer, 1, file_size, pf);
    fclose(pf);

	// play the wave data in buffer[]
	m_Format.wFormatTag         = *((WORD* )(buffer + OFFSET_FORMATTAG     ));
    m_Format.nChannels          = *((WORD* )(buffer + OFFSET_CHANNELS      ));
    m_Format.nSamplesPerSec     = *((DWORD*)(buffer + OFFSET_SAMPLESPERSEC ));
    m_Format.nAvgBytesPerSec    = *((DWORD*)(buffer + OFFSET_AVGBYTESPERSEC));
    m_Format.nBlockAlign        = *((WORD* )(buffer + OFFSET_BLOCKALIGN    ));
    m_Format.wBitsPerSample     = *((WORD* )(buffer + OFFSET_BITSPERSAMPLE ));


	WAVEHDR *wHdr = new WAVEHDR;
	ZeroMemory((void*)wHdr, sizeof(WAVEHDR));

	wHdr->lpData = buffer + HEADER_SIZE;
	wHdr->dwBufferLength = file_size - HEADER_SIZE;
	wHdr->dwUser = (DWORD)false;

	// Find a waveOut device and open it
	for(UINT devid = 0; devid < waveOutGetNumDevs(); devid++)
	{
		if(devid == waveOutGetNumDevs())
			// Error, no free devices found
			return ;
		if(waveOutOpen(&m_hPlay, WAVE_MAPPER, &m_Format, (DWORD)VoicePlayProc, 0, CALLBACK_FUNCTION) == MMSYSERR_NOERROR)
			// Usable device found, stop searching
			break;
	}

	if(waveOutPrepareHeader(m_hPlay, wHdr, sizeof(WAVEHDR)) != MMSYSERR_NOERROR)
		return;
	if(waveOutWrite(m_hPlay, wHdr, sizeof(WAVEHDR)) != MMSYSERR_NOERROR)
		return;
	return;
}
//--------------------------------------------
CTOR(WavPlay)
   FUNCTION_SETTING(init, init)
   FUNCTION_SETTING(play_File, play_File)
END_CTOR