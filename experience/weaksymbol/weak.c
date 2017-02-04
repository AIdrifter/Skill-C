//gcc –E MacroTest.c –o MacroTest_E.c


#include <stdio.h>
#include <string.h>
/* malloc example */
#include <stdio.h>
#include <string.h>
#include "fun_c.h"
//#include <process.h>
//extern void f();
//void f () __attribute__ ((weak, alias ("__f")));


#define STR(string) #string

#define CHECK_WEAK_SYMBOL(ret_type, WEAK_FUN, ...)\
extern ret_type WEAK_FUN(__VA_ARGS__) __attribute__ ((weak,alias (STR(__##WEAK_FUN))));\
ret_type __##WEAK_FUN(__VA_ARGS__)\
{\
    printf(#WEAK_FUN "  is not implemented in optee\n");\
}

#define NONE "\033[m"
#define WHITE "\033[1;37m"

CHECK_WEAK_SYMBOL(void,fun_c,void);
CHECK_WEAK_SYMBOL(void,fun_b,void);
//extern void fun_c(void)__attribute__ ((weak));

#define trace(format, args...) printf( WHITE"[TRACE][%s:%d]" format NONE, __FUNCTION__, __LINE__, ##args)

int main(void)
{
  trace("[1234]\n");
  fun_b();
  fun_c();
  return 0;
}


