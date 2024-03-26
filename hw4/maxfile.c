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
#include <unistd.h>

int is_writable(char *filename) {
    if (access(filename, W_OK) != -1) {
        // The file is writable
        return 1;
    } else {
        // The file is not writable or do   es not exist
        return 0;
    }
}

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
    }
    if(S_ISDIR(fileStat.st_mode)){
        DIR* subdirec = opendir(fpath);
        //if the file is a directory, open the directory
        if(subdirec == NULL){
            fprintf( stderr, "Cannot open the sub directory %s\n", fpath);
            return;
        }
        struct dirent *entry;
        while((entry = readdir(subdirec)) != NULL){
            if (strcmp(basename(fpath), ".") == 0 || strcmp(basename(fpath), "..") == 0) {
                continue;
            }else {
                snprintf(newpath, PATH_MAX, "%s/%s", fpath, entry->d_name);
                //create a new path for the subdirectory
                super(newpath, LargestFile, size);
                //recursively call the function to check the subdirectory
            }
        }

    }

}

void super2 (char *path, int *totalsize){
    struct stat fileStat;
    char newpath[PATH_MAX];
    if(stat(path, &fileStat)<0){
        return;
    }
    if(S_ISREG(fileStat.st_mode)) {
        *totalsize += fileStat.st_size;
        if(is_writable(path) == 1){
            printf("the file %s has %ld bytes - writable\n", basename(path), fileStat.st_size);
        }else{
            printf("the file %s has %ld bytes - non-writable\n", basename(path), fileStat.st_size);
        }

    }
    if(S_ISDIR(fileStat.st_mode)){
        DIR* subdirec = opendir(path);
        //if the file is a directory, open the directory
        if(subdirec == NULL){
            fprintf( stderr, "Cannot open the sub directory %s\n", path);
            return;
        }
        struct dirent *entry;
        while((entry = readdir(subdirec)) != NULL){
            if (strcmp(basename(path), ".") == 0 || strcmp(basename(path), "..") == 0) {
                continue;
            }else {
                snprintf(newpath, PATH_MAX, "%s/%s", path, entry->d_name);
                //create a new path for the subdirectory
                super2(newpath, totalsize);
                //recursively call the function to check the subdirectory
            }
        }

    }
}

int main(int argc, char** argv ){
    if(argc != 2){
        fprintf(stderr, "Usage: %s <directory>\n", argv[0]);
        return 1;
    }
    DIR* direc = opendir(argv[1]);

    if(direc == NULL){
        fprintf( stderr, "Cannot open the directory %s\n", argv[1]);
        return 1;
    }

    struct dirent *entry;
    char *path[PATH_MAX];
    char LargestFile[PATH_MAX] = "";
    int size = 0;
    int totalsize = 0;
    while((entry = readdir(direc)) != NULL){
        snprintf((char *) path, PATH_MAX, "%s/%s", argv[1], entry -> d_name);
        super((char *) path, LargestFile, &size); //this is to find the largest file
        super2((char *) path, &totalsize); //this is to find the total disk usage
    }
    printf("The largest file is %s with size %d bytes\n", basename(LargestFile), size);
    printf("The total size of all regular files in the directory is %d bytes\n", totalsize);
    closedir(direc);
    return 0;



}
