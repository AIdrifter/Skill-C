#include <string.h>
#include <stdio.h>
#include <stdbool.h>

int main(){
    char *a = "DeF";
    char *b = "dEf";
    char *c = "ABC";
    char *d = "abc";
    char *e = "Ghi";



    printf("%d %s =%s\n",strncasecmp(a, b, 3), a, b);
    printf("%d %s =%s\n",strncasecmp(a, c, 3), a, b);
    printf("%d %s =%s\n",strncasecmp(a, d, 3), a, b);
    printf("%d %s =%s\n",strncasecmp(a, e, 3), a, b);


    /*
     *  0  DeF =dEf
     *  3  DeF =dEf
     *  3  DeF =dEf
     * -3  DeF =dEf
     * /

}

