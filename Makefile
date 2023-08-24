all: main.c linear.o
	gcc -Wall main.c linear.o

linear.o: linear.c linear.h
	gcc -c -Wall linear.c

clean:
	rm -f *.o

purge: clean
	rm -f a.out
