# comment
# notice that the space before cc must a TAB,Not a four sapces

# variable rule
A=a
AB=ab

# toolchain
CC = gcc

# Using wildcard 
OBJS=a.o b.o c.o


# auto variable
#   $@ 表示目前的規則名稱
#   $< 表示第一個相依規則名稱
#   $^ 表示所有的相依規則名稱

test:test.o label
	@echo "-----label test"
	$(CC) -o test test.o
test.o:test.c
	@echo "----label test.o"
	$(CC) -c test.o test.c
label:
	@echo "----label , just label"
variable_rule:
	@echo "----label variable_rule"
	C=CCCCCCCCC
	@echo "$AB"
	@echo "$(AB)"
	# source probelm ?
	@echo "$(C)"
	@echo "$C"
all:wildcard test
	@echo "----label all"
%.o:%.c
	@echo '----label %.o:%.c'
	$(CC) -c $@ $<
wildcard:$(OBJS)
	@echo "----label wildcard"
	$(CC) -o test $^

clean:
	echo "label clean"
	rm *.o
