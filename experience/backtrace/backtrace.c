#include "./debug/debug.h"
#include <stdio.h>
#include <execinfo.h>
#include <signal.h>
#include <stdlib.h>
#include <unistd.h>

//  gcc -g -rdynamic ./backtrace.c -o backtrace

void handler(int sig) {
  void *array[10];
  size_t size;

  // get void*'s for all entries on the stack
  size = backtrace(array, 10);

  // print out all the frames to stderr
  fprintf(stderr, "Error: signal %d:\n", sig);
  backtrace_symbols_fd(array, size, STDERR_FILENO);
  exit(1);
}

void baz() {
 int *foo = (int*)-1; // make a bad pointer
  printf("%d\n", *foo);       // causes segfault
}

void bar() { baz(); }
void foo() { bar(); }


int main(int argc, char **argv)
{
  int dr=0;
  int test_level=11;
  int array[]={[10]=0,[10]=1,[99]=3};

  // error message test
  DEBUG_PRINT(0,(" error hello world %d \n",test_level));

  // warnning message test
  DEBUG_PRINT(1,(" warnning Message  %d \n",++test_level));

  // array dump
  DUMP_DATA("test_dump",array,sizeof(array),int32_type);


  ChkBOOL(1,3);
  printf("after first check\n");
  ChkBOOL(0,4);
  printf("after second check\n");

  signal(SIGSEGV, handler);   // install our handler
  foo(); // this will call foo, bar, and baz.  baz segfaults.


ErrorExit:
  printf("END\n");

  return dr;
}



