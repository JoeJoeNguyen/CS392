//
// Created by Joe Nguyen on 3/1/24.
//
// this is where the function is implemented
#include "oocmerge.h"

#define TEMP_DIR "temp"

void generate_numbers(int n, char* filename) {
    mkdir(TEMP_DIR, S_IRUSR | S_IWUSR | S_IXUSR);
    char filepath[256];
    sprintf(filepath, "%s/%s", TEMP_DIR, filename);
    //take an integer n and a file to put randomly generated n numbers between -100 and 100 and put them to the file
    int fd = open(filepath, O_WRONLY | O_CREAT, S_IRUSR | S_IWUSR);
    //O_WRONLY: the file is open for writing only.
    //O_CREAT: the file will be created if it does not already exist
    //S_IRUSR | S_IWUSR: mode flags that set permissions of the file if it is created.
    //S_IRUSR sets the read permissions for the user(owner), and S_IWUSR sets the write permission for the user.
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



void verify_and_print(char* filename) {
    char filepath[256];
    sprintf(filepath, "%s/%s", TEMP_DIR, filename);

    int fd = open(filepath, O_RDONLY);
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



