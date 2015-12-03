C = gcc
INC = -I ./include
OBJ= main.o op.o

# $@ 指的就是該 command 所屬的 target，所以範例中的 $@ 代表的就是 test
# $< 指的是則第一個相依檔案

test: ${OBJ}
	 $(CC) -o $@ ${OBJ}
%.o: %.c
	 ${CC} $< ${INC} -c

.PHONY: clean
clean:
	rm -f test ${OBJ}
