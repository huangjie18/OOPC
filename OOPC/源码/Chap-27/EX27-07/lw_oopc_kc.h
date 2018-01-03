/*  lw_oopc_kc.h */ 
#ifndef _LW_OOPC_H
#define _LW_OOPC_H
#include <stdlib.h>

#define CLASS(type)\
typedef struct type type; \
struct type

#ifndef LW_OOPC_PURE_STATIC
  #ifndef LW_OOPC_STATIC
    #ifndef LW_OOPC_DYNAMIC
      #define CTOR(type) \
      void* type##Setting(type*); \
      void* type##New() \
       { \
         struct type *t; \
         t = (struct type *)malloc(sizeof(struct type)); \
         return type##Setting(t); \
       } \
      void* type##Setting(type *t) \
      { 
    #else
      #define CTOR(type) \
      void* type##New() \
       { \
         struct type *t; \
         t = (struct type *)malloc(sizeof(struct type)); 
    #endif
  #else
    #define CTOR(type) \
    void* type##Setting(type *t) \
    { 
  #endif
#endif

#define END_CTOR return (void*)t;  }
#define FUNCTION_SETTING(f1, f2)  t->f1 = f2;
#define IMPLEMENTS(type) type type
#define INTERFACE(type) \
typedef struct type type; \
struct type
#endif
/*     end     */

