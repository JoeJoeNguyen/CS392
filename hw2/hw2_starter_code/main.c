#include "bubble.h"
#include "utils.h"


int main() {
	
	/* You can assume command-line arguments are always correct:
		e.g., ./a.out filename.txt %d
		The file doesn't necessarily exist, though.
		The format is always one of these two: %d, or %lf.
	
		With the provide test file, your command should be:
		./a.out testint %d
	
		The lines below are for integer inputs.
	*/
	

	size_t len = 0;
	int* arr = read_array(argv[1], argv[2], &len);
	
	iSort(arr, len, sizeof(int), &cmpr_int);
	iPrint(arr, len, sizeof(int), &print_int);
	
	free(arr);
	
	
	exit(EXIT_SUCCESS);
}


