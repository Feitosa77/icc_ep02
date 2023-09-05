CC = gcc
CFLAGS = -O3 -mavx -march=native -Wall
LIKWID_C = -DLIKWID_PERFMON -I${LIKWID_INCLUDE}
LIKWID_O = -L${LIKWID_LIB} -llikwid


TARGET = perfEG

all: main.c linear.o elimination.o
	$(CC) $(CFLAGS) $(LIKWID_C) -c main.c
	$(CC) -o $(TARGET) main.o linear.o elimination.o $(LIKWID_O)

linear.o: linear.c linear.h
	$(CC) -c -Wall linear.c

elimination.o: linear.o elimination.c elimination.h
	$(CC) -c -Wall elimination.c -lm

clean:
	rm -f *.o

purge: clean
	rm -f $(TARGET)

