#include "bubble.h"
#include "utils.h"
#include <string.h>

int main(int argc, char **argv) {
	
	/* You can assume command-line arguments are always correct:
		e.g., ./a.out filename.txt %d
		The file doesn't necessarily exist, though.
		The format is always one of these two: %d, or %lf.
	
		With the provide test file, your command should be:
		./a.out testint %d
	
		The lines below are for integer inputs.
	*/
	

	size_t len = 0;
	if(strcmp(argv[2], "%lf") == 0){ //check the type of input we are sorting if it is "lf" - decimal or "%d" - integer
	    double* arr = read_array(argv[1], argv[2], &len);
        bubble_sort(arr, len, sizeof(double), &cmpr_double);
        bubble_print(arr, len, sizeof(double), &print_double);
        free(arr);
	}else if(strcmp(argv[2], "%d") == 0){
        int* arr = read_array(argv[1], argv[2], &len);
        bubble_sort(arr, len, sizeof(int), &cmpr_int);
        bubble_print(arr, len, sizeof(int), &print_int);
        free(arr);
	}

	
	//iSort(arr, len, sizeof(int), &cmpr_int);
	//iPrint(arr, len, sizeof(int), &print_int);




	
	
	exit(EXIT_SUCCESS);
}


