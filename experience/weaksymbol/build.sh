#
# Reference: 
# http://www.cnblogs.com/kernel_hcy/archive/2010/01/27/1657411.html
#

# pre-processor
gcc -E MacroTest.c x -o MacroTest_E.c

# build shared libraries
gcc -g -o -fPIC fun_c.o fun_c.c 
gcc -shared -o libfun_c.so fun_c.o

# link shared libraries
gcc weak.c -o test -L./ -lfun_c

# link static libraries
gcc weak.c fun_c.o 
