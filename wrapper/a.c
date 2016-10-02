#include <stdio.h>
#include <stdlib.h>

void a(int size)
{
	printf("hello world %d",size);
   /* Your code */
}

void caller(int size,const char* caller_name )
{
    printf( "a was called from [ %s() ]", caller_name );
    a(size);
}

#define a(size) caller(size  ,__func__)

void b()
{
	int num=10;
    a(num);
}

int main(){
	b();
}
