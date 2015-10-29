#include <stdio.h>
#include <stdlib.h>

char SRM[]="default message";

int GetDefaultSrm(const unsigned char** Buf, unsigned int *InOutLen);


int main(){
    const unsigned char     *theDefaultSRM;
    unsigned int            theDefaultSRMLen = 0;
    GetDefaultSrm(&theDefaultSRM, &theDefaultSRMLen);
    puts(theDefaultSRM);
}


int GetDefaultSrm(const unsigned char** aBuf, unsigned int *aInOutLen){
    *aBuf=SRM;//igonre memory copy ...
    *aInOutLen=sizeof(SRM);
}
