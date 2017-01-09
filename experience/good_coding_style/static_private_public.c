#include "ifdefMacro.h"
#include <stdio.h>

// MS
int g_xxx=100;

int ShareCnt=0;

// Becuase we use static define function on ifdefMacro.c
// add_fun's namespace is limit at ifdefMacro.c
// Don't worry about multiple definiation
int add_fun(int a, int b){return a+b+100;};
int sub_fun(int a, int b){return a-b+100;};
int mul_fun(int a, int b){return a*b+100;};

int main(){
    // nameing
    // Microsoft
    {
        int m_xxx=10; // local
        int cntTemp; // local function
    }

    {
        int cFoo_; // C++ members
    }

    int a=10,b=100;
    operation_type oper = add;
    chose_operation(oper);
    printf("call operation %d ",call_operation(a,b));
    printf("call operation %d ",add_fun(a,b));

}
