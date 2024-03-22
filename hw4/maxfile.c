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
    struct stat fileStat;
    if(stat(fpath, &fileStat)<0){
        return;
    }
    if(S_ISREG(fileStat.st_mode)){
        if(fileStat.st_size> *size){
            *size = fileStat.st_size;
            strcpy(LargestFile, fpath);
        }
    }
}



int main(int argc, char** argv ){
    if(argc != 2){
        fprintf(stderr, "Usage: %s <directory>\n", argv[0]);
    }
    DIR* direc = opendir(argv[1]);

    if(direc == NULL){
        fprintf( stderr, "Cannot open the directory %s", argv[1]);
    }

    struct dirent *entry;
    char *path[PATH_MAX];
    char LargestFile[PATH_MAX] = "";
    int size = 0;
    while((entry = readdir(direc)) != NULL){
        snprintf((char *) path, PATH_MAX, "%s/%s", argv[1], entry -> d_name);
        super((char *) path, LargestFile, &size);
    }
    printf("The largest file is %s with size %d bytes\n", LargestFile, size);
    closedir(direc);
    return 0;



}
