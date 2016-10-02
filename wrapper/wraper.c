#include  <stdio.h>
#include  <stdlib.h>
#include  <dlfcn.h>
#include  <stdint.h>
#include  <unistd.h>
#include  <string.h>
#include  <inttypes.h>


size_t total_size=0;

#define malloc(x) malloc_replace(x, __FILE__, __LINE__)
void *malloc_replace (size_t size,const char* file,const char *name)
{
	printf("%s %s",file,name);
	printf("allocate size is %lu total is %lu",size,total_size);
	total_size+=size;
	return malloc(size);
}

//void free (void *ptr)
//{
//	printf("free size is %lu total is %lu",total_size);
//	total_size-=size;
//	free(size);
//}
//
int main()
{
	int *ptr=malloc(sizeof(int));
}
