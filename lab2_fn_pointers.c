// Credit: Shudong Hao

// TEAM MEMBERS:
// LEAD PROGRAMMER:  


#include <stdio.h>

// TODO: minus_one() must accept parameters that include a function pointer,
// the number of elements in the array and the size of each element
// it must NOT accept any parameters directly revealing the data type

// THEN: add the functionality to find the maximum in an array. 
// The function should return the index of the maximum in the array.
// Implementing it for one type is sufficient.

void minus_int(void *data){
    int * p;
    p = (int *) dat;
    * p = *p - 1;
}



void minus_one(void * arr, int n, int el_size, void (*fun) (void* dat)){

    char *ptr = (char *) arr;



    for(int i = 0; i < n ; i++ ){
        *arr[i] = (*fun)
    }
}

int main() {

    int test1[] = {1, 2, 3, 4, 5};
    minus_one(/* pass parameters */);
    for (size_t i = 0; i < 5; i ++) printf("%d\n", test1[i]);

    double test2[] = {0.3, -0.2, 1.34};
    minus_one(/* pass parameters */);
    for (size_t i = 0; i < 3; i ++) printf("%lf\n", test2[i]);

    char test3[] = {'3', 'a', 'Z', '?'};
    minus_one(/* pass parameters */);
    for (size_t i = 0; i < 4; i ++) printf("%c\n", test3[i]);

    return 0;
}
