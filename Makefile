CC = gcc
CFLAGS = -Wall -g
OBJ = obj/src/main.o obj/src/operations.o

calc: $(OBJ)
	$(CC) $(OBJ) -o calc

obj/src/main.o: src/main.c
	$(CC) $(CFLAGS) -c src/main.c -o obj/src/main.o

obj/src/operations.o: src/operations.c src/operations.h
	$(CC) $(CFLAGS) -c src/operations.c -o obj/src/operations.o

clean:
	rm -f obj/src/*.o calc

