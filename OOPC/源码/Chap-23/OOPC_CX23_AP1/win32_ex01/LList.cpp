/* llist.cpp   */
#include "stdafx.h"
#include "stdio.h"
#include "llist.h"

CLASS(ListNode)
{
	void* pItem;
	ListNode* next;
};
CTOR(ListNode)
END_CTOR

/* ----------------------------------  */
CLASS(LList)
{
   IMPLEMENTS(IColl);
   ListNode *head, *tail, *current;
};

void init(void*);
void clear(void*);
void add(void*, void*);
void top(void*);
void* next(void*);
void* get(void*, int);
int is_empty(void*);

CTOR(LList);
   FUNCTION_SETTING(IColl.init, init)
   FUNCTION_SETTING(IColl.clear, clear)
   FUNCTION_SETTING(IColl.add, add)
   FUNCTION_SETTING(IColl.top, top)
   FUNCTION_SETTING(IColl.next, next)
   FUNCTION_SETTING(IColl.get, get)
   FUNCTION_SETTING(IColl.is_empty, is_empty);
END_CTOR

static void init(void* t)
{
	LList* cthis = (LList*)t;
	cthis->head = NULL;
    cthis->tail = NULL;
	cthis->current = NULL;
}

static void clear(void* t)
{
   LList* cthis = (LList*)t;
   ListNode *px, *py;
   px = cthis->head;
   while(px != NULL)
   {
     py = px;
	 px = px->next;
	 free(py->pItem);
	 free(py);
   }
	cthis->head = NULL;
    cthis->tail = NULL;
	cthis->current = NULL;
}

static void add(void* t, void* pi)
{
  LList* cthis = (LList*) t;
  ListNode* pn = (ListNode*)ListNodeNew();
  pn->next = NULL;
  pn->pItem = pi;
  if(cthis->head == NULL)
  {
    cthis->tail = pn;
    cthis->head = pn;
	cthis->current = pn;
  }
  else
  {
    cthis->tail->next = pn;
	cthis->tail = pn;
	cthis->current = pn;
  }
}

static void top(void* t)
{
   LList* cthis = (LList*) t;
   cthis->current = NULL;
}

static void* next(void* t)
{
   LList* cthis = (LList*) t;
   if(cthis->current == NULL)
   {
	   if(cthis->head == NULL) return NULL;
	   else
	   {
		   cthis->current = cthis->head;
		   return cthis->current->pItem;
	   }
   }
   else
   {
	   cthis->current = cthis->current->next;
	   if(cthis->current == NULL) return NULL;
	   else return cthis->current->pItem;
   }
}

static void* get(void* t, int k)
{
   LList* cthis = (LList*) t;
   int i;
   ListNode* pn;
   if(cthis->head == NULL) return NULL;
   pn = cthis->head;
   for(i=0; i<k; i++)
   {
     pn = pn->next;
     if(pn == NULL) return NULL;
    }
    return pn->pItem;
 }

static int is_empty(void* t)
{
   LList* cthis = (LList*) t;
   if(cthis->head == NULL) return 1;
   else return 0;
 }

