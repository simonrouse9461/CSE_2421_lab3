%.o: %.c
	gcc -g -c -o $@ $<
all: integer
integer: main.o integer.o
	gcc main.o integer.o -o integer
main.o: main.c
	gcc -c main.c
integer.o: integer.c
	gcc -c integer.c
clean:
	rm -f *.o integer
