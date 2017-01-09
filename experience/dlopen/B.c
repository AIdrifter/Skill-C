#include <stdio.h>
#include <stdlib.h>

int printf_B(double input){
    printf("Hello B *2 (%f)  %s %s %d,",input*2,__FUNCTION__,__FILE__,__LINE__);
}
