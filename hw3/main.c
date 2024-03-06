//
// Created by Joe Nguyen on 3/1/24.
//
// Usage: oocmerge <N> <output filename>

#include <string.h>
#include "oocmerge.h"
#define TEMP_DIR "temp"
void merge(int arr[], int l, int m, int r);
void merge_sort(int arr[], int l, int r);

void sort_and_merge(char* filename) {
    char filepath[256];
    sprintf(filepath, "%s/%s", TEMP_DIR, filename);

    FILE* file = fopen(filepath, "r");
    if (file == NULL) {
        perror("Failed to open file");
        return;
    }

    int arr[1000];  // Adjust size as needed
    int i = 0;

    while (fscanf(file, "%d", &arr[i]) != EOF) {
        i++;
    }

    fclose(file);

    int n = i;  // Number of elements in the array
    merge_sort(arr, 0, n - 1);

    file = fopen(filename, "w");
    if (file == NULL) {
        perror("Failed to open file");
        return;
    }

    for (i = 0; i < n; i++) {
        fprintf(file, "%d\n", arr[i]);
    }

    fclose(file);
}

void merge_sort(int arr[], int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;

        merge_sort(arr, l, m);
        merge_sort(arr, m + 1, r);

        merge(arr, l, m, r);
    }
}

void merge(int arr[], int l, int m, int r) {
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;

    int L[n1], R[n2];

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
}

int main(int argc, char **argv) {
    int n = atoi(argv[1]);
    char* filename = argv[2];

    generate_numbers(n, filename);


    sort_and_merge(filename);


    verify_and_print(filename);

    return 0;
}
