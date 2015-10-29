#include <stdio.h>
#include <stdlib.h>

int A_printf(double input){
    printf("Hello A(%f)  %s %s %d,",input,__FUNCTION__,__FILE__,__LINE__);
}
