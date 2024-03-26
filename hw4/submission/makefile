#Author Son [Joe] Nguyen
# I pledge my Honor that I have abided by the Stevens Honor System

#the GNU C Compiler
$(CC) = gcc

final: maxfile.o
	$(CC) maxfile.o -o maxfile

maxfile.o: maxfile.c
	$(CC) -c maxfile.c


clean:
	rm -f *.o maxfile