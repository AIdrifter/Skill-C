#include <stdio.h>
#include <stdlib.h>
#include <dlfcn.h>

int dynamic_lib(char *file_name, char *fun_name){
    void *handle;
    double (*main_printf)(double);
    char *error;
    handle = dlopen (file_name, RTLD_LAZY);
    if (!handle) {
        fprintf (stderr, "%s\n", dlerror());
        return -1;
    }
    
    main_printf = dlsym(handle, fun_name);
    if ((error = dlerror()) != NULL)  {
        fprintf (stderr, "%s\n", error);
        return -1;
    }
    
    main_printf(100);
    puts("");
    dlclose(handle);
    
}


int main(int argc, char **argv) {
    dynamic_lib("./libA.so", "A_printf");
    dynamic_lib("./libB.so", "printf_B");
    return 0;
}


/*
*  If this program were in a file named "foo.c", you would build the program with the following command:
*  gcc -rdynamic -o foo foo.c -ldl
*/
