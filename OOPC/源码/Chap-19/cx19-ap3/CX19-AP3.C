/* cx19-ap3.c  */
#include "stdio.h"
#include "lw_oopc.h"

CLASS(Author)
   {
     void (*init)(void*, char*, char*);
     char* (*get_name)(void*);
     char* (*get_tel_no)(void*);
     char name[14];
     char telphone[20];
   };

static void init(void* t, char na[], char tel[] )
      {
        Author* cthis = (Author*)t;
        strcpy(cthis->name, na);
        strcpy(cthis->telphone, tel);
      }
static char* get_name(void* t)
      {
        Author* cthis = (Author*)t;
        return cthis->name;
      }
static char* get_tel_no(void* t)
      {
        Author* cthis = (Author*)t;
        return cthis->telphone;
      }
CTOR(Author)
   FUNCTION_SETTING(init, init)
   FUNCTION_SETTING(get_name, get_name)
   FUNCTION_SETTING(get_tel_no, get_tel_no)
END_CTOR

/*  ----------------------------  */
CLASS(Book)
   {
     void (*set)(void*, char*, char*);
     void (*setAuthor)(void*, Author*);
     void (*print)(void*);
     char book_no[14];
     char title[20];
     Author* author;
};

static void set(void* t, char no[], char ti[])
      {
        Book* cthis = (Book*)t;
        strcpy(cthis->book_no, no);
	strcpy(cthis->title, ti);
       }
static void setAuthor(void* t, Author* pau)
      {
        Book* cthis = (Book*)t;
	cthis->author = pau;
      }
static void print(void* t)
{
     Book* cthis = (Book*)t;
     Author* pau;
     printf("book_no: %s,  title: %s\n",
	     cthis->book_no, cthis->title);
     pau = cthis->author;
     printf("author_na: %s, author_tel: %s\n",
	     pau->get_name(pau), pau->get_tel_no(pau));
    }

CTOR(Book)
  FUNCTION_SETTING(set, set)
  FUNCTION_SETTING(setAuthor, setAuthor)
  FUNCTION_SETTING(print, print)
END_CTOR

int main()
{
    Author *mike = (Author*)AuthorNew();    
    Book *book1 = (Book*)BookNew();
    Book *book2 = (Book*)BookNew();

    mike->init(mike, "Alvin Kao", "2622-7777");
    book1->set(book1, "0-201-54709-0", "OOPC");
    book2->set(book2, "0-183-156667", "Ajax");
    
    book1->setAuthor(book1, mike);
    book2->setAuthor(book2, mike);
    book1->print(book1);
    printf("\n");
    book2->print(book2);
    getchar();
    return 0;
}