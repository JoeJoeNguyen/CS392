//
// Created by Joe Nguyen on 3/20/24.
// I pledge my honor that I have abided by the Stevens Honor System.

#include <string.h>
#include <stdio.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <dirent.h>
#include <sys/param.h>
#include <libgen.h>

void super(char *fpath, char* LargestFile, int *size){
    struct stat fileStat;
    // the structure is used to store the information about the file.
    char newpath[PATH_MAX];
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
    }else if(S_ISDIR(fileStat.st_mode)){
        DIR* subdirec = opendir(fpath);
        //if the file is a directory, open the directory
        if(subdirec == NULL){
            //if the directory cannot be opened, return
            return;
        }
        struct dirent *entry;
        while((entry = readdir(subdirec)) != NULL){
            snprintf(newpath, PATH_MAX, "%s/%s", fpath, entry -> d_name);
            //create a new path for the subdirectory
            super(newpath, LargestFile, size);
            //recursively call the function to check the subdirectory
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
    printf("The largest file is %s with size %d bytes\n", basename(LargestFile), size);
    closedir(direc);
    return 0;



}
