# gcc -shared -o libhello.so -fPIC hello.c
all:main.c libA.so libB.so
	gcc -rdynamic -o main main.c -Wl,--no-as-neede -ldl
libA.so:A.c
	gcc -c -fPIC A.c -o A.o
	gcc A.o -shared -o libA.so
libB.so:B.c
	gcc -c -fPIC B.c -o B.o
	gcc B.o -shared -o libB.so
clean:
	rm *.so *.o main
