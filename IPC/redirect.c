#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(){
    static int idx=0;
    while(++idx){
        fprintf(stdin, "(%d)stdin hello world\n" ,idx);
        fprintf(stdout,"(%d)stdout hello world\n",idx);
        fprintf(stderr,"#(%d)stderr hello world#\n",idx);
    }
}
