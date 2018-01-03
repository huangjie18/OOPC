/*  lw_oopc_kc.h */ 
/* 这就MISOO团队所设计的C宏 */
#ifndef _LW_OOPC_H
#define _LW_OOPC_H
#include <stdlib.h>

#define CLASS(type)\
typedef struct type type; \
struct type

#define IMPLEMENTS(type) struct type type
#define INTERFACE(type) \
typedef struct type type; \
struct type
#endif
/*     end     */

