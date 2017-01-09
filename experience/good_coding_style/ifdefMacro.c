#include <stdio.h>
int  ShareCount;

typedef enum{add=0,sub,mul} operation_type;
static int (*f_ptr) (int num1,int num2);

// static mean private
static int add_fun(int a, int b){return a+b;};
static int sub_fun(int a, int b){return a-b;};
static int mul_fun(int a, int b){return a*b;};

int chose_operation(operation_type operation){
    switch(operation)
    {
        case add:
            f_ptr=add_fun;
            break;
        case sub:
            f_ptr=sub_fun;
            break;
        case mul:
            f_ptr=mul_fun;
            break;
        default:
            printf("we don't implement this operation \n");
            return -1;
            break;
    }
    return 0;
}

int call_operation(int a ,int b){
    return f_ptr(a,b);
}
