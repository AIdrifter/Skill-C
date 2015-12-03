#include <stdio.h>
#include <stdlib.h>

struct man_t{
    char name[100];
    int ages;
};
typedef struct man_t man;

int main(){
    man pinky,ball;
    printf("pinky address %p\n",&pinky);
    man *ptr=&pinky;
    printf("ptr %p\n",ptr);
    printf("ptr + 1 %p\n",ptr+1);
    printf("ptr + 2 %p\n",ptr+2);

}
