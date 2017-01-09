#include <stdio.h>
#include <stdlib.h>
#include "api.h"

struct GG{
    char kitchen_name[100];
    int age;
};

int main(){
    printf("hello world\n");
    struct GG *MAN=malloc(sizeof(struct GG));
    int age=30;
    set_person(MAN,"ob_ov",age);
    display_person(MAN);
    set_person_2(MAN);
    display_person(MAN);
    struct GG KK={0,0};
    display_person(&KK);

    char *Sname="suck my ball";
    KK.kitchen_name=Sname;

    // display information
    printf(" %s \n",MAN->kitchen_name);
}
