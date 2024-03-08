//
// Created by Joe Nguyen on 3/1/24.
//
// Usage: oocmerge <N> <output filename>

#include <string.h>
#include "oocmerge.h"
#define TEMP_DIR "temp"
void merge(float* arr, int l, int m, int r) {
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;

    float* L = (float*) malloc(n1 * sizeof(float));
    float* R = (float*) malloc(n2 * sizeof(float));

    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }

    free(L);
    free(R);
}

void mergeSort(float* arr, int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;

        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);

        merge(arr, l, m, r);
    }
}

void sort_and_merge(char* filename) {
    char filepath[256];
    sprintf(filepath, "%s/%s", TEMP_DIR, filename);

    int fd = open(filepath, O_RDWR);
    if (fd == -1) {
        perror("Failed to open file for reading and writing");
        exit(EXIT_FAILURE);
    }

    struct stat st;
    fstat(fd, &st);
    int n = st.st_size / sizeof(float);

    float* arr = (float*) malloc(n * sizeof(float));
    if (arr == NULL) {
        perror("Failed to allocate memory");
        exit(EXIT_FAILURE);
    }

    read(fd, arr, n * sizeof(float));
    lseek(fd, 0, SEEK_SET);

    mergeSort(arr, 0, n - 1);

    write(fd, arr, n * sizeof(float));

    free(arr);
    close(fd);
}

int main(int argc, char **argv) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <number of floats> <output file>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    int n = atoi(argv[1]);
    char* filename = argv[2];

    mkdir(TEMP_DIR, S_IRUSR | S_IWUSR | S_IXUSR);

    generate_numbers(n, filename);
    sort_and_merge(filename);
    verify_and_print(filename);

    // Delete the temp directory and its contents.
    char command[256];
    sprintf(command, "rm -rf %s", TEMP_DIR);
    system(command);

    return 0;
}