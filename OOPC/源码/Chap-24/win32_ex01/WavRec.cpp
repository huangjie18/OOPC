/*  WavRec.c    */
#include "StdAfx.h" 
#include "stdio.h"
#include <io.h>
#include <fcntl.h>
#include <stdlib.h>
#include <sys\stat.h>
#include <MMSystem.h>
#include "wavrec.h"

#define OFFSET_FORMATTAG			20
#define OFFSET_CHANNELS				22
#define OFFSET_SAMPLESPERSEC		24
#define OFFSET_AVGBYTESPERSEC		28
#define OFFSET_BLOCKALIGN			32
#define OFFSET_BITSPERSAMPLE		34
#define OFFSET_WAVEDATA				44
#define HEADER_SIZE	                OFFSET_WAVEDATA

typedef struct
{
   char R1;
   char I2;
   char F3;
   char F4;
   unsigned long WAVElen;
   struct
   {
      char W1;
      char A2;
      char V3;
      char E4;
      char f5;
      char m6;
      char t7;
      char space;
      unsigned long fmtlen;
      struct
      {
         unsigned short FormatTag;
         unsigned short Channels;
         unsigned long SamplesPerSec;
         unsigned long AvgBytesPerSec;
         unsigned short BlockAlign;
         unsigned short BitsPerSample; /* format specific for PCM */
      } fmt;
      char d8;
      char a9;
      char t10;
      char a11;
      unsigned long datalen;
      /* from here you insert your PCM data */
   } WAVE;
} RIFF;

long total_len  = 0;
HWAVEIN m_hwIn;
WAVEFORMATEX m_format;
WAVEHDR m_wHdr;  
RIFF header;
int  hfile;
int  xfile;

//-----------------------------------------
static void ProcessHeader(WAVEHDR * pvr)
{
	write(hfile, pvr->lpData, pvr->dwBytesRecorded);  // Writting buffer data to wave file
    total_len +=  pvr->dwBytesRecorded;
	if(waveInAddBuffer(m_hwIn, pvr, sizeof(WAVEHDR)) != 0)
	     MessageBox(NULL, _T("waveInAddBuffer error!"), _T(""), MB_OK | MB_ICONINFORMATION);
}

static void CALLBACK waveInProc(HWAVEIN hwi,UINT uMsg,DWORD dwInstance,DWORD dwParam1,DWORD dwParam2)
{
	WAVEHDR *pHdr=NULL;
	switch(uMsg)
	{
		case WIM_CLOSE:
			break;

		case WIM_DATA:
			{
			//	VoiceRec *pvr=(VoiceRec*)dwInstance;
				ProcessHeader((WAVEHDR *)dwParam1);
			}
			break;

		case WIM_OPEN:
			break;

		default:
			break;
	}
}


//--------------------------------------------------------------
static void writeFileHeader()  // This is called by prepare()
{
   //header = new RIFF();
   header.R1 = 'R';
   header.I2 = 'I';
   header.F3 = 'F';
   header.F4 = 'F';
   header.WAVElen = 36; //sizeof(header.WAVE); /* + datalen */
                         //暂时而已，写完数据必须回来update
   header.WAVE.W1 = 'W';
   header.WAVE.A2 = 'A';
   header.WAVE.V3 = 'V';
   header.WAVE.E4 = 'E';
   header.WAVE.f5 = 'f';
   header.WAVE.m6 = 'm';
   header.WAVE.t7 = 't';
   header.WAVE.space = ' ';
   header.WAVE.fmtlen = 16;  //sizeof(header.WAVE.fmt);
   header.WAVE.fmt.FormatTag = WAVE_FORMAT_PCM;
   header.WAVE.d8 = 'd';
   header.WAVE.a9 = 'a';
   header.WAVE.t10 = 't';
   header.WAVE.a11 = 'a';
   header.WAVE.datalen = 0; /* we don't know yet *///暂时而已，写完数据必须回来update
   header.WAVE.fmt.BitsPerSample = m_format.wBitsPerSample;
   header.WAVE.fmt.Channels = m_format.nChannels ;
   header.WAVE.fmt.SamplesPerSec = m_format.nSamplesPerSec;
   header.WAVE.fmt.AvgBytesPerSec =m_format.nAvgBytesPerSec;
   header.WAVE.fmt.BlockAlign =m_format.nBlockAlign ;
   //===============================================================
   // Open Wave file named: c:\\SymSound.wav  
   hfile = open("c:\\SymSound.wav",O_CREAT | O_TRUNC | O_RDWR | O_BINARY, S_IWRITE);
   if(!hfile || hfile == -1) 
        MessageBox(NULL,_T("can not open .wav!"),_T(""), MB_OK | MB_ICONINFORMATION);
   // Write WaveFile Header      
   if(write(hfile, &header, sizeof(header)) != sizeof(header))
        MessageBox(NULL,_T("write header Err!"),_T(""), MB_OK | MB_ICONINFORMATION);
}
//--------------------------------------------------------------
static void prepare(void* t)
{
  // MessageBox(NULL,_T("000..."),_T(""), MB_OK | MB_ICONINFORMATION);
  int kk;
  MMRESULT ret=0;
  // Fill in the WAVEFORMATEX header.
  m_format.wFormatTag      = WAVE_FORMAT_PCM;
  m_format.nChannels       = 2; //channels;  1=mono, 2=stereo
  m_format.nSamplesPerSec  = 44100; // or 11025; 
  m_format.wBitsPerSample  = 16; //bitsPerSample;   16 for high quality, 8 for telephone-grade
  m_format.nBlockAlign     = m_format.nChannels * (m_format.wBitsPerSample / 8);
  m_format.cbSize          = 0; //sizeof(WAVEFORMATEX);
  m_format.nAvgBytesPerSec = m_format.nSamplesPerSec * m_format.nChannels * (m_format.wBitsPerSample / 8);
  //------------------------------------------------------
  writeFileHeader();
  //------------------------------------------------------
  ret=waveInOpen(&m_hwIn,WAVE_MAPPER,&m_format,(DWORD_PTR)waveInProc,(DWORD_PTR)NULL,CALLBACK_FUNCTION);
  if(ret!=MMSYSERR_NOERROR)
	{	MessageBox(NULL,_T("waveInOpen err ..."),_T(""), MB_OK | MB_ICONINFORMATION);
	    return;
	}
		//------------------------>> PrepareBuffers <<---------------------
        m_wHdr.lpData=(LPSTR)HeapAlloc(GetProcessHeap(),8,m_format.nAvgBytesPerSec*8);
		m_wHdr.dwBufferLength=m_format.nAvgBytesPerSec*8;
		m_wHdr.dwUser=0;

    	if(waveInPrepareHeader(m_hwIn,&m_wHdr, sizeof(WAVEHDR)) != 0)
		{
		  MessageBox(NULL,_T("waveInPrepareHeader error!"),_T(""), MB_OK | MB_ICONINFORMATION);
	      return;
	    }
		if( waveInAddBuffer(m_hwIn,&m_wHdr,sizeof(WAVEHDR)) != 0)
		{
		  MessageBox(NULL,_T("waveInAddBuffer error!"),_T(""), MB_OK | MB_ICONINFORMATION);
	      return;
		}
	return;
 }
//-------------------------------------------------
static void start(void*t)
{	
   	if (waveInStart(m_hwIn) != 0)
	{   MessageBox(NULL,_T("waveInStart error!"),_T(""), MB_OK | MB_ICONINFORMATION);
	    return;
	}
	return;
}
//--------------------------------------------------
static void close(void*t)
{
	//------>>	UnPrepareBuffers <<-----------------
    waveInStop(m_hwIn);
    //------->> Close Device <<---------------------
    DWORD curr_time, base_time, draw_time;
	// Waiting for thread finished 
    base_time = GetTickCount();
    do {    curr_time =  GetTickCount() - base_time; 	 }  
    while (curr_time < 300);
    if(m_wHdr.lpData)
		{
     		waveInUnprepareHeader(m_hwIn,&m_wHdr,sizeof(WAVEHDR));
	    	HeapFree(GetProcessHeap(),0,m_wHdr.lpData);
			ZeroMemory(&m_wHdr, sizeof(WAVEHDR));
		}
    waveInClose(m_hwIn);
   //====================================================
   header.WAVE.datalen += total_len;
   header.WAVElen += total_len;
   lseek(hfile,0,SEEK_SET);
   write(hfile, &header, sizeof(header));  // Update Wave File header
                                           // for recording the real data length
   lseek(hfile,0,SEEK_END);
   close(hfile);
   MessageBox(NULL,_T("SaveToFile OK"),_T(""), MB_OK | MB_ICONINFORMATION);
   //=================================================
   /* WavSave* ws = (WavSave*)WavSaveNew();
   ws->copy_from_file_to_db(ws);
   MessageBox(NULL,_T("SaveToDB OK"),_T(""), MB_OK | MB_ICONINFORMATION);*/
}

//---------------------------------------------------------------------
static void init(void *t)
{   WavRec* cthis = (WavRec*)t;  }

//--------------------------------------------
CTOR(WavRec)
   FUNCTION_SETTING(init, init)
   FUNCTION_SETTING(prepare, prepare)
   FUNCTION_SETTING(start, start)
   FUNCTION_SETTING(close, close)
END_CTOR