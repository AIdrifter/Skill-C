#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define test_str "test1234"

void set_str(char *str){
    memcpy(str,test_str,sizeof(test_str));
}



int main()
{
    char str[100];
    set_str(str);
    printf("%s\n",str);

}
