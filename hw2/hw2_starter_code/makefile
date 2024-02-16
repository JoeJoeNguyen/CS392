$(CC) = gcc

final: main.o bubble.o utils.o
		$(CC) main.o bubble.o utils.o -o a.out
main.o: main.c
		$(CC) -c main.c
bubble.o: bubble.c bubble.h
		$(CC) -c bubble.c
utils.o: utils.c utils.h
		$(CC) -c utils.c

clean:
	rm *.o a.out
