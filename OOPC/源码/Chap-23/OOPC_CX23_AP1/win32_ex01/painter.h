/* painter.h   */
#ifndef PAINTER_H
#define PAINTER_H
#include "StdAfx.h"
#include "lw_oopc.h"
#include "llist.h"
//#pragma once

CLASS(Painter)
{
	INTERFACE(IColl)* m_pList;
	void (*init)(void*);
    void (*draw_line)(void*, int, int, int, int, long);
    void (*draw)(void*, INTERFACE(IColl)* );
	// void (*paint)(void*);
 };
#endif