/* cx19-ap1.c  */
#include "stdio.h"
#include "lw_oopc.h"

CLASS(Book)
   {
     void (*set)(void*, char*, char*, char*);
     char book_no[14];
     char title[20];
     char author[15];
};

static void set(void* t, char no[], char ti[], char a[] )
      {
        Book* cthis = (Book*)t;
        strcpy(cthis->book_no, no);
	strcpy(cthis->title, ti);
        strcpy(cthis->author, a);
      }
CTOR(Book)
  FUNCTION_SETTING(set, set)
END_CTOR

int main()
{
    Book *book = (Book*)BookNew();
    book->set(book, "0-201-54709-0", "OOPC", "Alvin Kao");
    printf("course title = %s\n", book->title);
    getchar();
    return 0;
}