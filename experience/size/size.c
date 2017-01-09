#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>


#define DRMCASSERT( x ) switch(0){ case 0: case (x): ;}

int main()
{
    long a;uint64_t b;
    //bool c = (sizeof(a) > sizeof(b));
    //unsigned int c = (sizeof(long) > sizeof(uint64_t));
    DRMCASSERT( sizeof(long) == sizeof(uint64_t) );
    printf("%lu %lu\n",sizeof(a),sizeof(b));

}


