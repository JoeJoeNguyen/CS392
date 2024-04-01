//
// Created by Joe Nguyen on 3/27/24.
//

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

float random_float() {
    return (float)rand() / (float)RAND_MAX;
}

int main(int argc, char *argv[]) {

    float x = random_float();

    printf("Program to sleep for %f second in Linux.\n", x);

    sleep(x);

    printf("This line will be executed after %f second. \n", x);

}