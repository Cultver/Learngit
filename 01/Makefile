OBJS1 := hello.o
OBJS2 := hello.c
CC := gcc
hello:$(OBJS1)
	$(CC) $^ -o $@
$(OBJS1):$(OBJS2)
	$(CC) -c $< -o $@
