all:main
	gcc main.o
	mv a.out main
main.o:main.s
	gcc -c main.o main.s
main.s:main.i
	gcc -S main.s main.i
main.i:main.c
	gcc -E main.i main.c





#gcc -E main.c > main.i
#gcc -S main.i  # out comes main.s
#gcc -c main.s  # out comes main.o
#gcc main.o     # out comes a.out
#

