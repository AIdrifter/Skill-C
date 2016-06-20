#include <stdio.h>
#include <stdlib.h>


 /*
 ** Compile-time asserts cause PREfast warnings regarding the comparison of two constants.
 ** So, enable this macro only when the PREfast tool is not analyzing the code.
 */
 #ifndef _PREFAST_
     #define DRMSIZEASSERT(x,y)  \
         {switch(0){case ((x)==(y)?0:(y)):case (y):;}} \
         {switch(0){case ((y)==(x)?0:(x)):case (x):;}}
 #endif


#define COMPILER_INT int
#define COMPILER_CHAR char

int main(){

    // if COMPILER_INT !=4 , gcc will be terminated
    // PASS
    DRMSIZEASSERT(sizeof (COMPILER_INT),  4);


    // FAILED
    DRMSIZEASSERT(sizeof (COMPILER_CHAR),  4);
}
