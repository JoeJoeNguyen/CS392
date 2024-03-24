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
    // the structure is used to store the information about the file.

    if(stat(fpath, &fileStat)<0){
        //the stat() function retrieves information about the file at fpath and stores it in the fileStat
        //if stat return a negative value, it means an error occurred, so the function return.
        return;
    }
    if(S_ISREG(fileStat.st_mode)){
        //check if the file is a regular file
        if(fileStat.st_size> *size){
            //if it is a regular file, if the file size is larger
            *size = fileStat.st_size;
            //update it size
            strcpy(LargestFile, fpath);
            //also coppy the current path to the largestFile path
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
    DIR* subdirec;
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
