//
// Created by Joe Nguyen on 3/1/24.
//
// Usage: oocmerge <N> <output filename>

#include <string.h>
#include "oocmerge.h"

int main(int argc, char **argv) {
    int n = atoi(argv[1]);
    char* filename = argv[2];

    generate_numbers(n, filename);
    create_temp_dir();

    // TODO: Implement sorting and merging using temporary files in the temp directory

    verify_and_print(filename);

    return 0;
}
