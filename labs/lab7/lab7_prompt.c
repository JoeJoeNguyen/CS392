// TEAM MEMBERS: Son Nguyen
// LEAD PROGRAMMER: Son Nguyen

#include<stdio.h> 
#include<stdlib.h> 
#include<unistd.h> 
#include<sys/types.h>
#include<sys/wait.h>
#include <pwd.h>
#include<string.h>
#include<sys/errno.h>

#define MAX_INPUT 1024
int main()
{
    /*
      1. Use getuid, getpwuid, getcwd to retrieve the username and home
      directory of the current user
      2. Change the directory to the user's home directory
      3. Print the prompt as specified in homework 5 and wait for user input
    */
    uid_t uid = getuid();
    struct passwd *pw = getpwuid(uid); //get the password file entry for the user ID

    if (pw == NULL) {
        fprintf(stderr, "Error: Cannot get passwd entry. %s.\n", strerror(errno));
        return 1;
    }

    char cwd[1024];

    if (getcwd(cwd, sizeof(cwd)) == NULL){
        fprintf(stderr, "Error: Cannot get current working directory. %s.\n", strerror(errno));
        return 1;
    }

    printf("Username: %s\n", pw->pw_name); // Print the username
    printf("Home Directory: %s\n", pw->pw_dir); // Print the home directory
    printf("Current Working Directory: %s\n", cwd); // Print the current working directory

    if (chdir(pw->pw_dir) != 0) {
        fprintf(stderr, "Error: Cannot change directory to %s. %s.\n", pw->pw_dir, strerror(errno));
        return 1;
    }


    /* 
      TODO:
      1. Handle cd commands entered by the user. Check that a single argument 
      is provided. Ignore other commands, but don't exit. Change the current 
      directory according to the user's input.
      2. Handle the exit command. Ensure that it is followed by no arguments.

      ** If tokenizing is giving you trouble, allow the user to omit cd and
      consider the received string as the target directory. There should be 
      no directory named `exit'
    */
    char input[MAX_INPUT];
    char *command, *arg;

    while (1) {
        printf("> ");
        if (fgets(input, MAX_INPUT, stdin) == NULL) {
            break;
        }
        input[strcspn(input, "\n")] = 0;

        command = strtok(input, " ");
        arg = strtok(NULL, " ");

        if (strcmp(command, "cd") == 0) {
            if (arg == NULL) {
                fprintf(stderr, "cd: argument required\n");
            } else {
                if (chdir(arg) != 0) {
                    fprintf(stderr, "cd: %s: %s\n", arg, strerror(errno));
                }
            }
        } else if (strcmp(command, "exit") == 0) {
            if (arg != NULL) {
                fprintf(stderr, "exit: too many arguments\n");
            } else {
                break;
            }
        }
    }
    
    return EXIT_SUCCESS;
}