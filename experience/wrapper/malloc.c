#include <stdio.h>
#include <stdlib.h>

//void malloc()
//{
//	printf("hello world");
//   /* Your code */
//}

void caller( const char* caller_name )
{
    printf( "malloc was called from [ %s() ]", caller_name );
}

#define malloc() caller(__func__)

void b()
{
    int *ptr=malloc(sizeof(int));
}

int main(){
	b();
}
