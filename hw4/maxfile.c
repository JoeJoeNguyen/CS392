//
// Created by Joe Nguyen on 3/20/24.
//

#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
int main(int argc, char** argv ){
    if(argc != 2){
        fprintf(stderr, "Usage: %s <directory>\n", argv[0]);
    }
    //create a directory of any name using mkdir
    mkdir(argv[1], S_IRUSR | S_IWUSR | S_IXUSR);

    //within that directory make at least 2 subdirectories
    char sub1[256], sub2[256];
    sprintf(sub1, "%s/sub1", argv[1]);
    sprintf(sub2, "%s/sub2", argv[1]);
    mkdir(sub1, S_IRUSR | S_IWUSR | S_IXUSR);
    mkdir(sub2, S_IRUSR | S_IWUSR | S_IXUSR);
}
