#include <stdio.h>

// 32 bit machine
// C memory address + 1 = one byte

// total 12 byes
typedef struct aligen_test12{
    char x;
    // char padding0[3];
    int y;
    short int z;
    // char padding0[2];
}aligen_t12;

// total 8 byes
typedef struct aligen_test8{
    char x;
    short int z;
    // char padding0[0];
    int y;
}aligen_t8;

// [Linux data aligment]
// #pragma pack(push)  /* push current alignment to stack */
// #pragma pack(n)     /* set alignment to n byte boundary
//                         => Any member < n bytes will be pendding to n bytes */
//
// #pragma pack()     /* cancel previous alignment to n byte boundary */
//
//
// #pragma pack(push)  /* pop previous alignment to stack */
//
// attribute__ ((pack(n))) /* 要求某個structure使用pack(n) */
//       http://mark-shih.blogspot.tw/2012/10/compiler-data-alignment.html
#pragma pack(push) // push current aligment to stack
#pragma pack(1)  // set aligment to n byte boundary : total size % n = 0
typedef struct aligen_testpack{
    char x;
    int y;
    short int z;
}aligen_tpack;
#pragma pack(pop) //restore orginal aligment from stack

int main(){
    aligen_t12 Aligen;
    printf("Aligen struct size = %ld \n",sizeof(Aligen));
    printf("x =%p sizeof : %ld\n",&Aligen.x,sizeof(Aligen.x));
    printf("y =%p sizeof : %ld\n",&Aligen.y,sizeof(Aligen.y));
    printf("z =%p sizeof : %ld\n",&Aligen.z,sizeof(Aligen.z));

    aligen_t8 Aligen8;
    printf("Aligen struct size = %ld \n",sizeof(Aligen8));
    printf("x =%p sizeof : %ld\n",&Aligen8.x,sizeof(Aligen8.x));
    printf("y =%p sizeof : %ld\n",&Aligen8.y,sizeof(Aligen8.y));
    printf("z =%p sizeof : %ld\n",&Aligen8.z,sizeof(Aligen8.z));

    aligen_tpack AligenPack;
    printf("Aligen struct size = %ld \n",sizeof(AligenPack));
    printf("x =%p sizeof : %ld\n",&AligenPack.x,sizeof(AligenPack.x));
    printf("y =%p sizeof : %ld\n",&AligenPack.y,sizeof(AligenPack.y));
    printf("z =%p sizeof : %ld\n",&AligenPack.z,sizeof(AligenPack.z));

}
