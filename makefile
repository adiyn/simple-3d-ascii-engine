OBJS= main.o src/shapes.o src/renderer.o src/math_utils.o
CC=gcc
CFLAGS=-I./src -lm

all: cube
cube: $(OBJS)
	$(CC) -o cube $(OBJS) $(CFLAGS)
shapes.o: src/shapes.c
	$(CC) -c src/shapes.c $(CFLAGS)
renderer.o: src/renderer.c	
	$(CC) -c src/renderer.c $(CFLAGS)
math_utils.o: src/math_utils.c
	$(CC) -c src/math_utils.c $(CFLAGS)
main.o: main.c
	$(CC) -c main.c $(CFLAGS)
clean:
	rm -f *.o