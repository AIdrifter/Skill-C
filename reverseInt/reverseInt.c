#include <stdio.h>
#include <stdlib.h>

int reverseInt(int A){
    unsigned int A0 = A & 0xff000000;
    unsigned int A1 = A & 0x00ff0000;
    unsigned    int A2 = A & 0x0000ff00;
    unsigned    int A3 = A & 0x000000ff;
    unsigned    int C0 = A0 >> (6*4);
    unsigned    int C1 = A1 >> (2*4);
    unsigned    int C2 = A2 << (2*4);
    unsigned    int C3 = A3 << (6*4);


    printf("A0 = %08x\n",A0);
    printf("A1 = %08x\n",A1);
    printf("A2 = %08x\n",A2);
    printf("A3 = %08x\n",A3);


    printf("C0 = %08x\n",C0);
    printf("C1 = %08x\n",C1);
    printf("C2 = %08x\n",C2);
    printf("C3 = %08x\n",C3);

    //unsigned  int out = (A0>>6) + (A1>>2) + (A2<<2) + (A3<<6);
    unsigned  int out = C0 + C1 + C2 + C3;
    return out;
}

#define REV(X)      ((X << 24) | (((X>>16)<<24)>>16) | (((X<<16)>>24)<<16) | (X>>24))



int main(){
    unsigned int A=0x12345678;
    printf("A = %0x\n",A);
    printf("reverse A = %0x\n",reverseInt(A));
    printf("reverse1 A = %0x\n",REV(A));
    printf("reverse1 A = %0x\n",A);

}
