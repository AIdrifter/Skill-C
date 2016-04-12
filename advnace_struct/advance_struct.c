#include <stdio.h>
#include <stdlib.h>

typedef struct{
    char name[50];
    int studentNo;
    int age;
}student_t;

void display_array(int *array, int size, char *name){
    int i;
    printf("======= %s =======\n",name);
    for(i = 0; i < size; i++){
        printf("%d%c",array[i] ,(i%10==9 || i==size-1) ? '\n' : ' ');
    }
}

int main(){

   // Dot assign
    student_t st1={
        .name="John",
        .age=20,
        .studentNo=10372
    };

    // interesting array
    int a[7] = {[4]=0,1,[2]=2};
    display_array(a,sizeof(a)/sizeof(int),"small");

    // comb 1+2
    student_t S_array[5]={
        [0]={
            .name="Tom",
            .studentNo=0,
            .age=17
        },
        [4]={
            .name="Tom4",
            .studentNo=4,
            .age=17
        }
    };

    // sequence assign
    int sequence[]={ [0 ... 9] = 1,[20 ... 99] = 100};
    display_array(sequence,sizeof(sequence)/sizeof(int),"sequence");
}
