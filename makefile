CFLAGS = -Wall -g
LDFLAGS = -lm

CC = gcc

objects = main.o SortFunc.o SearchFunc.o

all: main

main: $(objects)
	$(CC) $^ -o $@ $(LDFLAGS)

main.o: main.c SortFunc.h SearchFunc.h
	$(CC) -c $< $(CFLAGS)

SortFunc.o: SortFunc.c SearchFunc.h
	$(CC) -c $< $(CFLAGS)

SearchFunc.o: SearchFunc.c
	$(CC) -c $< $(CFLAGS)

clean:
	rm -f $(objects)

purge:
	rm -f $(objects) main
