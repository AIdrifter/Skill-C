#include <string.h>
#include <stdio.h>
#include "api.h"

struct person
{
    char name[255];
    int age;
};

int set_person(void* person_t,char* name, int age){
    if(person_t==NULL)
        return 1;
    struct person *ptr=(struct person*)person_t;
    memcpy(ptr->name,name,sizeof(char)*strlen(name));
    ptr->age = age;
}


int set_person_2(void* person_t){
    if(person_t==NULL)
        return 1;
    struct person *ptr=(struct person*)person_t;
    ptr->age = ptr->age*2;
}


int display_person(void* person_t){
    if(person_t==NULL)
        return 1;
    struct person *ptr=(struct person*)person_t;
    printf("display name %s\n",ptr->name);
    printf("display age %d\n",ptr->age);
}
