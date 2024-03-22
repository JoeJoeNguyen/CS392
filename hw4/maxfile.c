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
#include <dirent.h>

void super(char *fpath, char* LargestFile, int *size){

}



int main(int argc, char** argv ){
    if(argc != 2){
        fprintf(stderr, "Usage: %s <directory>\n", argv[0]);
    }
    DIR* direc = opendir(argv[1]);

    if(direc == NULL){
        printf(stderr, "Cannot open the directory %s", argv[1]);
    }

    struct dirent *entry;
    char *path[PATH_MAX];
    while((entry = readdir(direc)) != NULL){
        //entry->d_name;
        snprintf(path, PATH_MAX, "%s/%s", argv[0]);

    }



}
