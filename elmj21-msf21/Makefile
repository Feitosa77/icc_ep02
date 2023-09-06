CC = gcc
CFLAGS = -O3 -mavx -march=native -Wall
LIKWID_C = -DLIKWID_PERFMON -I${LIKWID_INCLUDE}
LIKWID_O = -L${LIKWID_LIB} -llikwid

DISTFILES = *.c *.h LEIAME* Makefile
DISTDIR = `basename ${PWD}`

TARGET = perfEG

all: main.c linear.o elimination.o utils.o
	$(CC) $(CFLAGS) $(LIKWID_C) -c main.c
	$(CC) -o $(TARGET) main.o linear.o elimination.o utils.o $(LIKWID_O)

linear.o: linear.c linear.h
	$(CC) -c -Wall linear.c

elimination.o: linear.o elimination.c elimination.h
	$(CC) -c -Wall elimination.c -lm

utils.o: utils.c utils.h
	$(CC) -c utils.c

clean:
	rm -f *.o

purge: clean
	rm -f $(TARGET)
