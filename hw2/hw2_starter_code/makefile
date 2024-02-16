#Author Son [Joe] Nguyen
# I pledge my Honor that I have abided by the Stevens Honor System

#the GNU C Compiler
$(CC) = gcc

final: main.o bubble.o utils.o
		$(CC) main.o bubble.o utils.o -o a.out
main.o: main.c
		$(CC) -c main.c
bubble.o: bubble.c bubble.h
		$(CC) -c bubble.c
utils.o: utils.c utils.h
		$(CC) -c utils.c


#make clean to clean all the object files and exe then recompile it
clean:
	rm *.o a.out
