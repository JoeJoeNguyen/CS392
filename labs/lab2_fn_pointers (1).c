// Credit: Shudong Hao

// TEAM MEMBERS: Jack Bulas, Son Nguyen [Joe]
// LEAD PROGRAMMER: Jack 


#include <stdio.h>

// TODO: minus_one() must accept parameters that include a function pointer,
// the number of elements in the array and the size of each element
// it must NOT accept any parameters directly revealing the data type

// THEN: add the functionality to find the maximum in an array. 
// The function should return the index of the maximum in the array.
// Implementing it for one type is sufficient.

void subI(void *data){
    int *p;
    p = (int*)data;
    --*p;
}
void subD(void *data){
    double *p;
    p = (double *)data;
    --*p;
}

void minus_one(void (*funct) (void *data), int elems, int elemSize, void* arr){

    char *ptr = (char *)arr;
    int i;
    for (i=0; i< elems; i++)
        funct(ptr + i*elemSize);
    }
int compare(void *data1, void *data2){
    int *p1;
    int *p2;
    p1 = (int*) data1;
    p2 = (int*) data2;
    if()
}

int main() {

    int test1[] = {1, 2, 3, 4, 5};
    minus_one(&subI, 5, 4, &test1);
    for (size_t i = 0; i < 5; i ++) printf("%d\n", test1[i]);

    double test2[] = {0.3, -0.2, 1.34};
    minus_one(&subD, 3, 8, &test2);
    for (size_t i = 0; i < 3; i ++) printf("%lf\n", test2[i]);

    char test3[] = {'3', 'a', 'Z', '?'};
    minus_one(&subI, 4, 1, &test3);
    for (size_t i = 0; i < 4; i ++) printf("%c\n", test3[i]);

    return 0;
}
