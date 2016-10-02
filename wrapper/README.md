# warpper function
1. find caller
http://stackoverflow.com/questions/16100090/how-can-we-know-the-caller-functions-name
	a.c

2. wrapper system call (symbol colliction problem)
http://stackoverflow.com/questions/3662856/how-to-reimplement-or-wrap-a-syscall-function-in-linux
gcc -c malloc_wrapper.c
gcc -c testapp.c
gcc -Wl,-wrap,malloc testapp.o malloc_wrapper.o -o testapp
