//
// Created by Joe Nguyen on 3/1/24.
//
// this is where the function is implemented
#include "oocmerge.h"

#define TEMP_DIR "temp"

void generate_numbers(int n, char* filename) {
    int fd = open(filename, O_WRONLY | O_CREAT, S_IRUSR | S_IWUSR);
    if (fd == -1) {
        perror("File failed to open");
        exit(1);
    }

    for (int i = 0; i < n; i++) {
        float num = ((float)rand() / (float)RAND_MAX) * 200.0 - 100.0;
        write(fd, &num, sizeof(float));
    }

    close(fd);
}

void create_temp_dir() {
    mkdir(TEMP_DIR, S_IRUSR | S_IWUSR | S_IXUSR);
}

void verify_and_print(char* filename) {
    int fd = open(filename, O_RDONLY);
    if (fd == -1) {
        perror("File failed to open");
        exit(1);
    }

    float prev_num, curr_num;
    read(fd, &prev_num, sizeof(float));

    while (read(fd, &curr_num, sizeof(float)) > 0) {
        if (curr_num < prev_num) {
            printf("Numbers are not sorted.\n");
            close(fd);
            return;
        }
        printf("%f\n", curr_num);
        prev_num = curr_num;
    }

    printf("Numbers are sorted.\n");
    close(fd);
}



