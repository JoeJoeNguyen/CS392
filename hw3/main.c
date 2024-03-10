//
// Created by Joe Nguyen on 3/1/24.
//
// Usage: oocmerge <N> <output filename>
#include "oocmerge.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <dirent.h>
#include <limits.h>

#define TEMP_DIR "temp"

void merge(char* filename1, char* filename2, char* output_filename) {
    FILE* file1 = fopen(filename1, "rb");
    FILE* file2 = fopen(filename2, "rb");
    FILE* output_file = fopen(output_filename, "wb");

    if (file1 == NULL || file2 == NULL || output_file == NULL) {
        perror("Error opening files");
        exit(EXIT_FAILURE);
    }

    float num1, num2;
    size_t read1, read2;

    read1 = fread(&num1, sizeof(float), 1, file1);
    read2 = fread(&num2, sizeof(float), 1, file2);

    while (read1 > 0 && read2 > 0) {
        if (num1 <= num2) {
            fwrite(&num1, sizeof(float), 1, output_file);
            read1 = fread(&num1, sizeof(float), 1, file1);
        } else {
            fwrite(&num2, sizeof(float), 1, output_file);
            read2 = fread(&num2, sizeof(float), 1, file2);
        }
    }
void merge(char* filename1, char* filename2, char* output_filename) {
    FILE* file1 = fopen(filename1, "rb");
    FILE* file2 = fopen(filename2, "rb");
    FILE* output_file = fopen(output_filename, "wb");

    float num1, num2;
    fread(&num1, sizeof(float), 1, file1);
    fread(&num2, sizeof(float), 1, file2);

    while (!feof(file1) && !feof(file2)) {
        if (num1 <= num2) {
            fwrite(&num1, sizeof(float), 1, output_file);
            fread(&num1, sizeof(float), 1, file1);
        } else {
            fwrite(&num2, sizeof(float), 1, output_file);
            fread(&num2, sizeof(float), 1, file2);
        }
    }

    while (!feof(file1)) {
        fwrite(&num1, sizeof(float), 1, output_file);
        fread(&num1, sizeof(float), 1, file1);
    }

    while (!feof(file2)) {
        fwrite(&num2, sizeof(float), 1, output_file);
        fread(&num2, sizeof(float), 1, file2);
    }

    fclose(file1);
    fclose(file2);
    fclose(output_file);

    remove(filename1);
    remove(filename2);
}

    // Copy the remaining elements from file1
    while (read1 > 0) {
        fwrite(&num1, sizeof(float), 1, output_file);
        read1 = fread(&num1, sizeof(float), 1, file1);
    }

    // Copy the remaining elements from file2
    while (read2 > 0) {
        fwrite(&num2, sizeof(float), 1, output_file);
        read2 = fread(&num2, sizeof(float), 1, file2);
    }

    fclose(file1);
    fclose(file2);
    fclose(output_file);
    remove(filename1);
    remove(filename2);
}

void sort_and_merge(char* filename) {
    // Removed the TEMP_DIR from the filepath
    char filepath[256];
    sprintf(filepath, "%s", filename);

    FILE* file = fopen(filepath, "rb");
    if (file == NULL) {
        perror("Failed to open file");
        return;
    }

    int file_count = 0;
    float num;
    while (fread(&num, sizeof(float), 1, file) == 1) {
        char temp_filepath[256];
        sprintf(temp_filepath, "%s/%d", TEMP_DIR, file_count);

        FILE* temp_file = fopen(temp_filepath, "wb");
        fwrite(&num, sizeof(float), 1, temp_file);
        fclose(temp_file);

        file_count++;
    }

    fclose(file);

    while (file_count > 1) {
        char filepath1[256], filepath2[256], output_filepath[256];
        sprintf(filepath1, "%s/%d", TEMP_DIR, file_count - 2);
        sprintf(filepath2, "%s/%d", TEMP_DIR, file_count - 1);
        sprintf(output_filepath, "%s/%d", TEMP_DIR, file_count - 2);

        merge(filepath1, filepath2, output_filepath);

        file_count--;
    }

    char final_filepath[256];
    sprintf(final_filepath, "%s/%d", TEMP_DIR, 0);
    rename(final_filepath, filepath);
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
    //char command[256];
    //sprintf(command, "rm -rf %s", TEMP_DIR);
    //system(command);

    return 0;
}
