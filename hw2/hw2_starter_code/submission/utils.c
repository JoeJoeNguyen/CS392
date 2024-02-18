#include "utils.h"
#include <stdlib.h>
#include <string.h>
/*
	You are free to use any data type you like in this file.
    However, other than the five functions declared in "utils.h",
    DO NOT create any other functions.
	
*/

/*
 * Son Nguyen
 * I pledge my honor that I have abided by the Stevens Honor System
 * */

int cmpr_int(void* a, void* b) {

    int num1 = *((int*) a); //cast type int to a and then dereference to num1
    //num1 is an int value that a was pointing to
    int num2 = *((int*) b);

    if (num1 < num2) {
        return -1; //return -1 if a < b
    } else if (num1 > num2) {
        return 1; //return 1 if a > b
    } else {
        return 0; //return 0 if they are equal
    }
}

int cmpr_double(void* a,void* b) {

    double num1 = *((double*) a); //cast type double to a and then dereference to num1
    //num1 is a double value that a was pointing to
    double num2 = *((double*) b);

    if (num1 < num2) {
        return -1; //return -1 if a < b
    } else if (num1 > num2) {
        return 1; //return 1 if a > b
    } else {
        return 0; //return 0 if they are equal
    }
}

void print_int(void* a ) {
	
	printf("%d\n", *(int*) a);
}

void print_double(void* a ) {
	
	printf("%lf\n", *(double*) a);
}


void* read_array(char* filename, char* format, size_t* len) {

    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        fprintf(stderr, "File failed to open.\n");
        exit(1);
    }

    size_t count = 0;
    char line[256];
    while (fgets(line, sizeof(line), file)) {
        count++;
    }

    void* array;
    if (strcmp(format, "%d") == 0) {
        array = malloc(count * sizeof(int));
    } else if (strcmp(format, "%lf") == 0) {
        array = malloc(count * sizeof(double));
    }

    rewind(file);

    if (strcmp(format, "%d") == 0) {
        int* intArray = (int*)array;
        for (size_t i = 0; i < count; i++) {
            fscanf(file, format, &intArray[i]);
        }
    } else if (strcmp(format, "%lf") == 0) { /*strcmp compares 2 strings if they are equal or not */
        double* doubleArray = (double*)array;
        for (size_t i = 0; i < count; i++) {
            fscanf(file, format, &doubleArray[i]);
        }
    }
    fclose(file);
    *len = count;
    return array;

}