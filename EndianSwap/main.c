#include <stdio.h>
#include <stdlib.h>
#include <byteswap.h>

<<<<<<< HEAD
#define BIG_NUMBER__SIZE 8
=======
#define ECC_P256_INTEGER_SIZE_IN_DIGITS 8
>>>>>>> d8b41592f95654584b91d9fc532c81de29b4d424

inline void endian_swap_char(unsigned short int *x)
{
*x = (*x>>8) |
    (*x<<8);
}

inline void endian_swap(unsigned int *x)
{
    *x = (*x>>24) |
    ((*x<<8) & 0x00FF0000) |
    ((*x>>8) & 0x0000FF00) |
    (*x<<24);
}

<<<<<<< HEAD
unsigned int ConstB[ BIG_NUMBER__SIZE ] =
=======
unsigned int ConstB[ ECC_P256_INTEGER_SIZE_IN_DIGITS ] =
>>>>>>> d8b41592f95654584b91d9fc532c81de29b4d424
{
    0x29c4bddf, 0xd89cdf62, 0x78843090, 0xacf005cd,
    0xf7212ed6, 0xe5a220ab, 0x04874834, 0xdc30061d
};

<<<<<<< HEAD
unsigned int ConstA[ BIG_NUMBER__SIZE ] =
=======
unsigned int ConstA[ ECC_P256_INTEGER_SIZE_IN_DIGITS ] =
>>>>>>> d8b41592f95654584b91d9fc532c81de29b4d424
{
    0xfffffffc, 0xffffffff, 0xffffffff, 0x00000003,
    0x00000000, 0x00000000, 0x00000004, 0xfffffffc
};

<<<<<<< HEAD
unsigned int P256[ BIG_NUMBER__SIZE ] =
=======
unsigned int P256[ ECC_P256_INTEGER_SIZE_IN_DIGITS ] =
>>>>>>> d8b41592f95654584b91d9fc532c81de29b4d424
{
    0xffffffff, 0xffffffff, 0xffffffff, 0x00000000,
    0x00000000, 0x00000000, 0x00000001, 0xffffffff
};


int k[8] = {
    0xa30e0215,0x78febb4c,
    0xa2110996,0xfc4fb0a9,
    0x7e60a819,0x78d892b1,
    0x7175446c,0xe663a0ea
};

int C1_x[8] = {
    0x8041e25a,0xe15d9927,
    0xe42e4e37,0x2afdfde6,
    0x2460828f,0xdfc8598f,
    0xcd88cd56,0x658f3083,
};

int C1_y[8] ={
    0xd06d19e5,0xa62ef184,
    0x1581f0ec,0xfa54a70d,
    0xfd0a1d26,0x3a0e2297,
    0x8d6435ef,0xcd45ea0d
};


int result[16]  = {
    0xc0158709,0x89e1e212,
    0xd11acb11,0xcd953698,
    0x74fc2377,0x88906b82,
    0x12ecb4e8,0xf53c7668,
    0x0f1e0585,0x014a9321,
    0xffee9e1d,0xcdce027e,
    0x4d63d86b,0x115a3827,
    0xfc4efedf,0x68d26e6a
};

int reverseInt(unsigned int *str,unsigned int length){
    if(str==NULL)
        return -1;

    int i,j,c;
    for(i=0,j = length-1 ; i<j ; i++,--j){
        c=str[i],str[i]=str[j],str[j]=c;
    }
}



void reverse_to_MS32(char *name,int *str,int length){
    int i;
    printf("%s\n",name);
    for(i=0;i<length;i++)
        printf("%08x ",str[i]);

    for(i=0;i<length;i++)
        endian_swap(&str[i]);

    puts("");
    for(i=0;i<length;i++)
        printf("%08x ",str[i]);

    puts("");
    reverseInt(str,length);

    for(i=0;i<length;i++)
        printf("%08x",str[i]);
    puts("");

}




int main(){
    reverse_to_MS32("[constB]",ConstB,8);
    reverse_to_MS32("[constA]",ConstA,8);
    reverse_to_MS32("[P256]",P256,8);
    reverse_to_MS32("[C1_x]",C1_x,8);
    reverse_to_MS32("[C2_y]",C1_y,8);
    reverse_to_MS32("[K]",k,8);
    reverse_to_MS32("[Result]",result,16);
}
