#include <stdio.h>
#include <stdlib.h>
#include <byteswap.h>

#define BIG_NUMBER__SIZE 8

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

unsigned int ConstB[ BIG_NUMBER__SIZE ] =
{
    0x29c4bddf, 0xd89cdf62, 0x78843090, 0xacf005cd,
    0xf7212ed6, 0xe5a220ab, 0x04874834, 0xdc30061d
};

unsigned int ConstA[ BIG_NUMBER__SIZE ] =
{
    0xfffffffc, 0xffffffff, 0xffffffff, 0x00000003,
    0x00000000, 0x00000000, 0x00000004, 0xfffffffc
};

unsigned int P256[ BIG_NUMBER__SIZE ] =
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


int P3_x[]={0x70eca9db,0x1cb230c1,0x1007dc28,0x415d8d89,0x42c85a52,0x197332f2,0x3adb60e9,0x3e159550};
int P3_y[]={0x03b0cc0a,0x6e1ab418,0x92a7a937,0xcbd61eb7,0x196b53f9,0x53aa2db3,0xd957b012,0x9c976966};

int P1_x[]={
    0x4eebc127,
    0xffac3f90,
    0x087d81fb,
    0xb027f84a,
    0x87cbbc98,
    0x66ad77dd,
    0xb6ff747e,
    0x26936a3f
};


int P1_y[]={
    0xc983a7eb,
    0xb04c5c1f,
    0x0861fe1a,
    0x583e47ad,
    0x1a2ee98e,
    0x78820831,
    0xe587cc07,
    0xd5f06a29
};

int R_x[]={
    0x3e77664a,
    0x40394737,
    0x346cee3e,
    0x55ae744f,
    0x5b17a3ad,
    0xd50a961a,
    0x54213673,
    0x13074b59
};
int R_y[]={
    0xd377e44b,
    0x93d36220,
    0xadff14b5,
    0x299c2b53,
    0xef639f11,
    0xf424d44c,
    0x4a07f75f,
    0xa4c9916d
};

int t2[]={
0x02fce030,0x1b59facc,0xddb32487,0xc1ce4135,0xe0f6d28e,0x396cb92d,0x53ce08b7,0x178ca44a};

int y11[]={
0x017e7018,0x8dacfd66,0xeed99243,0x60e7209a,0xf07b6947,0x9cb65c96,0x29e7045b,0x0bc65225};

int p1_x[]=
{
    0x26936a3f,0xb6ff747e,0x66ad77dd,0x87cbbc98,0xb027f84a,0x087d81fb,0xffac3f90,0x4eebc127
};
int p1_y[]=
{
    0xd5f06a29,0xe587cc07,0x78820831,0x1a2ee98e,0x583e47ad,0x0861fe1a,0xb04c5c1f,0xc983a7eb
};


int G_x[]=
{
    0x18905f76,0xa53755c6,0x79fb732b,0x77622510,0x75ba95fc,0x5fedb601,0x79e730d4,0x18a9143c
};

int G_y[]=
{
    0x8571ff18,0x25885d85,0xd2e88688,0xdd21f325,0x8b4ab8e4,0xba19e45c,0xddf25357,0xce95560a
};



void reverse_to_MS32(char *name,int *str,int length){
    int i;
    printf("%s\n",name);
    for(i=0;i<length;i++)
        printf("%08x ",str[i]);

//    for(i=0;i<length;i++)
//        endian_swap(&str[i]);

//    puts("");
//    for(i=0;i<length;i++)
//        printf("%08x ",str[i]);

    puts("");
    reverseInt(str,length);
     for(i=0;i<length;i++)
        printf("%08x ",str[i]);
//
    puts("");
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
    reverse_to_MS32("P1x",P1_x,8);
    reverse_to_MS32("P1y",P1_y,8);
    reverse_to_MS32("R1x",R_x,8);
    reverse_to_MS32("t2",t2,8);
    reverse_to_MS32("y11",y11,8);
    reverse_to_MS32("p1_x",p1_x,8);
    reverse_to_MS32("p1_y",p1_y,8);
    reverse_to_MS32("G_x",G_x,8);
    reverse_to_MS32("G_y",G_y,8);

    reverse_to_MS32("P3_x",P3_x,8);
    reverse_to_MS32("P3_y",P3_y,8);


}
