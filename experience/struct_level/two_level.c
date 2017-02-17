#include <stdio.h>
#include <stdlib.h>

int add(int a ,int b) { return a+b; }
int sub(int a ,int b) { return a-b; }
int mul(int a ,int b) { return a*b; }
int s_div(int a ,int b) { return (b!=0 ? a/b:b);  }

typedef struct fun_table
{
    int (*binary_operation)(int,int);
}fun_table_t;


typedef struct computer{
    char *value;
    fun_table_t *ptr;
}computer_t;


int main()
{


}
