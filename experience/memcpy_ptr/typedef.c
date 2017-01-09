#include <stdio.h>
#include <stdlib.h>

typedef struct MAN{
    char array[100];
} sign_100;

char B[] = {'B','B','B','B','B','B','B','B','B'};

dump_data(char *string,char *ptr,unsigned int size){
    int i;
    for(i=0;i<10;i++)
        printf("%d%c",i,(i%9==0 && i!=0)?'\n':' ');

    for(i=0;i<100;i++)
        printf("%c%c",ptr[i],(i%9==0 && i!=0)?'\n':' ');
}

int main(){
   sign_100 A={0};
   sign_100 *ptr=NULL;
   A.array[1]='0';
   A.array[2]='1';
   ptr=&A;

   int i;
   for(i=0;i<100;i++)
    printf("%c%c",A.array[i],(i%9==0 && i!=0)?'\n':' ');

   memcpy(ptr->array+10,B,5);

   dump_data("test",ptr,100);
   dump_data("test",ptr->array,100);
}
