#include <stdio.h>
#include <stdlib.h>

extern const char *__progname;

struct person
{
    int age;
    int height;
};

static struct person *johndoe;
static char report[255];

static void printout_struct(void* invar, char* structname){
    /* dumpstack(void) Got this routine from http://www.whitefang.com/unix/faq_toc.html
    ** Section 6.5. Modified to redirect to file to prevent clutter
    */
    /* This needs to be changed... */
    char dbx[160];

    sprintf(dbx, "echo 'p (struct %s)*%p\n' > gdbcmds", structname, invar );
    system(dbx);

    sprintf(dbx, "echo 'where\ndetach' | gdb -batch --command=gdbcmds %s %d > struct.dump", __progname, getpid() );
    system(dbx);

    sprintf(dbx, "cat struct.dump");
    system(dbx);

    return;
}

int main(){

    johndoe = (struct person *)calloc(1, sizeof(struct person));
    johndoe->age = 6;
    johndoe->height = 152;
    printout_struct(johndoe, "person");

}
