#Author Son [Joe] Nguyen
# I pledge my Honor that I have abided by the Stevens Honor System

#the GNU C Compiler
$(CC) = gcc

final: main.o oocmerge.o
	$(CC) main.o oocmerge.o -o a.out

main.o: main.c
	$(CC) -c main.c

oocmerge.o: oocmerge.c oocmerge.h
	$(CC) -c oocmerge.c

clean:
	rm -f *.o a.out
	rm -rf temp
	rm -f output