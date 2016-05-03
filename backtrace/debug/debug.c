#include "debug.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>


// Do not modify
#define NONE "\033[m"
#define RED "\033[0;32;31m"
#define LIGHT_RED "\033[1;31m"
#define GREEN "\033[0;32;32m"
#define LIGHT_GREEN "\033[1;32m"
#define BLUE "\033[0;32;34m"
#define LIGHT_BLUE "\033[1;34m"
#define DARY_GRAY "\033[1;30m"
#define CYAN "\033[0;36m"
#define LIGHT_CYAN "\033[1;36m"
#define PURPLE "\033[0;35m"
#define LIGHT_PURPLE "\033[1;35m"
#define BROWN "\033[0;33m"
#define YELLOW "\033[1;33m"
#define LIGHT_GRAY "\033[0;37m"
#define WHITE "\033[1;37m"


#ifdef NUTTX
#define printf lib_lowprintf
#endif

static int syslog=5;
static char *dump_description ="[DUMP]";

void dbghdrclass(unsigned int level, const int codeline, const char *func)
{
    // we define important error message for level 0
    if(level ==0){
        printf(RED TAG_NAME);
        printf("[%s]....@%d",func,codeline);
        printf(LIGHT_GREEN TAG_NAME);
    }
    else if(level < syslog){
        printf(LIGHT_GREEN TAG_NAME);
        printf("[%s]....@%d",func,codeline);
        printf(NONE);
    }
}

static inline void __dbgtext_va(const char *format_str, va_list ap) PRINTF_ATTRIBUTE(1,0);
static inline void __dbgtext_va(const char *format_str, va_list ap)
{
      char *msgbuf = NULL;
      bool ret = true;
      int res;

      res = vasprintf(&msgbuf, format_str, ap);
      if (res != -1) {
          format_debug_text(msgbuf);
      } else {
          ret = false;
      }
      SAFE_FREE(msgbuf);
      return ret;
  }

void dbgtext_va(const char *format_str, va_list ap)
{
    return __dbgtext_va(format_str, ap);
}

void dbgtext(const char *format_str, ... )
{
    va_list ap;
    bool ret;

    va_start(ap, format_str);
    ret = __dbgtext_va(format_str, ap);
    va_end(ap);

    return ret;
}


void DUMP_DATA(char *description, void *buffer, unsigned int len, dump_type type )
{
    if(type==0)
        type=char_type;

    if(description == NULL){
        description = dump_description;
    }

    int i =0;
    printf(YELLOW "[%s]\n",description);
    unsigned char *dump_ptr=NULL;
    switch(type){
        case char_type:
            dump_ptr=(char*)buffer;
            break;
        case int32_type:
            dump_ptr=(int*)buffer;
            break;
        case uint32_type:
            dump_ptr=(unsigned*)buffer;
            break;
        default:
            printf(RED "unknmow type!!\n" NONE);
            break;
    }

    for (i=0; i< len ;i++)
    {
        printf("%02x%c", (char*)dump_ptr[i],(i%17==16 || i == len-1 )?'\n':' ');
    }
    printf(NONE);
}
