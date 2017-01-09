all:test_backtrace
test_backtrace: backtrace debug.o
	#gcc -g -rdynamic ./test.c -o test
	gcc -o backtrace_test backtrace debug.o

backtrace: backtrace.c
	gcc  -c -g -rdynamic backtrace.c -o backtrace

debug.o: ./debug/debug.c
	gcc -c -o debug.o ./debug/debug.c

clean:
	rm *.o; rm backtrace_test
