/*  scribble.c    */
#include "StdAfx.h" 
#include "stdio.h"
#include "llist.h"
#include "dwPoint.h"
#include "painter.h"
#include "scribble.h"

extern void* LListNew();
extern void* dwPointNew();
extern void* PainterNew();

/*    -----------------------------------    */
static void init(void *t)
{
    Scribble* cthis = (Scribble*)t;
    cthis->poList = (INTERFACE(IColl)*) LListNew();
	(cthis->poList)->init(cthis->poList);
    cthis->pa = (Painter*)PainterNew();
   	(cthis->pa)->init(cthis->pa);
}

static void begin_record(void *t)
{  
    Scribble* cthis = (Scribble*)t;
    INTERFACE(IColl)* list = cthis->poList;
    dwPoint* po;
	cthis->m_state = 1;
    po = (dwPoint*)dwPointNew();
 	po->set_initial_time(po,(long)GetTickCount());
	free(po);
    if( ! list->is_empty(list))
	    list->clear(list);
}

static void record(void *t, int x, int y, int ty, long color)
{
      Scribble* cthis = (Scribble*)t;
      INTERFACE(IColl)* list = cthis->poList;
      dwPoint* po;
      if(cthis->m_state != 1)	return;
	  po = (dwPoint*)dwPointNew();
      po->init(po, x, y, ty, color);
      list->add(list, po);
}

static void stop(void* t)
{
    Scribble* cthis = (Scribble*)t;
	if(cthis->m_state != 1) return;
	else cthis->m_state = 2;
}
static void re_draw(void* t)
{
	Scribble* cthis = (Scribble*)t;
    Painter* pa = cthis->pa;
	if(cthis->m_state != 1 && cthis->m_state != 2) return;
	cthis->m_state = 2;
	pa->draw(pa, cthis->poList);
 }
static void save_drawing(void* t)
    {
	Scribble* cthis = (Scribble*)t;
    INTERFACE(IColl)* list = cthis->poList;
    struct dwpo
	{
	  long time_span;
	  int x, y;
	  char t, cc;
	};

	  struct dwpo po;
	  dwPoint* point;
	  FILE *fd;
	  fd = fopen("c:\\scribble.dat","wb");
      list->top(list);
	  point = (dwPoint*)list->next(list);
	  while(point != NULL)
       {
         po.x = point->m_x;
	     po.y = point->m_y;
         po.t = (char)point->m_type;
		 if(point->m_color == (long)RGB(255,0,0)) po.cc = 0;
	 else if(point->m_color == (long)RGB(0,255,0)) po.cc = 1;
	 else if(point->m_color == (long)RGB(0,0,255)) po.cc = 2;
	 else if(point->m_color == (long)RGB(0,0,0)) po.cc = 3;
	     po.time_span = point->m_timeSpan;
         fwrite(&po, sizeof(struct dwpo), 1, fd);
         point = (dwPoint*)list->next(list);
	   }
	   fclose(fd);
   }

      /*-----------------------------------*/
static void load_drawing(void* t)
      {
        Scribble* cthis = (Scribble*)t;
        INTERFACE(IColl)* list = cthis->poList;
        struct dwpo
	     {
	   long time_span;
	       int x, y;
	       char t, cc;
	     };
        struct dwpo po;
	    long col;
	    FILE *fd;
	    dwPoint* new_point;
	    fd = fopen("c:\\scribble.dat","rb");


        list->clear(list);
        while(1)
		{
			fread(&po, sizeof(struct dwpo), 1, fd);
			if( feof(fd) )
		       break;
			else
			{
            if(po.cc == 0) col = RGB(255,0,0);
            else if(po.cc == 1) col = RGB(0,255,0);
            else if(po.cc == 2) col = RGB(0,0, 255);
            else if(po.cc == 3) col = RGB(0,0,0);
		   /* MessageBox(NULL,_T("failed!!"),NULL, MB_OK | MB_ICONINFORMATION);*/

            new_point = (dwPoint*)dwPointNew();
            new_point->m_x = po.x;
			new_point->m_y = po.y;
			new_point->m_type = (int)po.t;
			new_point->m_color = col;
			new_point->m_timeSpan = po.time_span;

            list->add(list, new_point);
            }
		}
		fclose(fd);
		cthis->m_state = 2; /* Stop  */
      } /* Save */

CTOR(Scribble)
   FUNCTION_SETTING(init, init)
   FUNCTION_SETTING(begin_record, begin_record)
   FUNCTION_SETTING(record, record)
   FUNCTION_SETTING(stop, stop)
   FUNCTION_SETTING(re_draw, re_draw)
   FUNCTION_SETTING(save_drawing, save_drawing)
   FUNCTION_SETTING(load_drawing, load_drawing)
END_CTOR

