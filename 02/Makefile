CC = gcc
main:main.o add.o div.o
	$(CC)	main.o add.o div.o -o main
main.o:main.c e02.h
	$(CC)	$(CFLAGS) -c main.c -o main.o
add.o:add.c
	$(CC)	$(CFLAGS) -c add.c -o add.o
div.o:div.c
	$(CC)	$(CFLAGS) -c div.c -o div.o
clean:
	rm -rf *.o
