#Author Son [Joe] Nguyen
# I pledge my Honor that I have abided by the Stevens Honor System

#the GNU C Compiler
$(CC) = gcc

final: msh.o sighandler.o
	$(CC) msh.o sighandler.o -o msh

msh.o: msh.c
	$(CC) -c msh.c

sighandler.o: sighandler.c sighandler.h
	$(CC) -c sighandler.c

clean:
	rm -f *.o
	rm -f msh
