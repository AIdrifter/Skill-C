#define TAG_NAME "[BUG_TAG]"
#include <stdarg.h>




typedef enum{
    false=0,
    true,
} bool;

typedef enum{
    char_type=1,
    int32_type,
    uint32_type,
} dump_type;

void DEBUG_PRINT(unsigned int level,char *fmt,...);
void DUMP_DATA(char *description, void *buffer, unsigned int len, dump_type type );

void dbgtext_va(const char *, va_list ap) ;
void dbgtext( const char *, ... ) ;
void dbghdrclass( int level, int codeline, const char *func);
void dbghdr( int level, const char *location, const char *func);


/*
#define DEBUG_PRINT(fmt, ...) \
            do { if (DEBUG) fprintf(stderr, "%s:%d:%s(): " fmt, __FILE__, \
                                                    __LINE__, __func__, __VA_ARGS__); } while (0)
*/

#define DEBUG_PRINT( level, body ) \
  (void)((dbghdrclass( level, __LINE__, __func__ )) \
       && (dbgtext body) )

