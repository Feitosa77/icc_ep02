all: main.c linear.o elimination.o
	gcc -Wall main.c linear.o elimination.o

linear.o: linear.c linear.h
	gcc -c -Wall linear.c

elimination.o: linear.o elimination.c elimination.h
	gcc -c -Wall elimination.c

clean:
	rm -f *.o

purge: clean
	rm -f a.out
