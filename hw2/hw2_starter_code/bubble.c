#include "bubble.h"
#include <string.h>

/*
	IMPORTANT: because this is a generic implementation, in bubble.c you must not use if-else to
	discriminate different data types in your code. Your code must be able to deal with any data type possible.
	Therefore, we limit the usage of the following primitive types:
	- int or size_t: only allowed as loop iterators;
	- char or u_int8_t: can be used as you wish;
	- Types that are used in the declarations of iSort() and iPrint(): feel free to use them for their _original_
      purpose;
	- All other types are not allowed to appear in bubble.c: no exceptions, no matter if you actually used
	  them, or what purpose it is. If other types appear, they may be penalized.

	You are free to create helper functions only in bubble.c; you must declare and implement them in the
    .c file instead of the header files. Do not change any of the header files.
	
*/



void bubble_sort(void* base, size_t nel, size_t width, int (*compare)(void*,void*)) {

    char* array = (char*)base; //type cast char into base
    char* temp = malloc(width);
    // allocate memory with size width and returns the pointer -temp- point to the first
    //byte of of the allocated space
    int swapped;

    do {
        swapped = 0;
        for (size_t i = 0; i < nel - 1; i++) {
            char* elem_i = array + i * width;
            char* elem_i1 = array + (i + 1) * width;
            if (compare(elem_i, elem_i1) > 0) {
                memcpy(temp, elem_i, width);
                memcpy(elem_i, elem_i1, width);
                memcpy(elem_i1, temp, width);
                swapped = 1;
            }
        }
    } while (swapped);

    free(temp);
}


void bubble_print(void* base, size_t nel, size_t width, void (*print)(void*)) {

	char* array = (char*) base;
    for(size_t i = 0; i < nel; i++){
        char* elem_i = array + (i * width);
        print(elem_i);
    }
	
}