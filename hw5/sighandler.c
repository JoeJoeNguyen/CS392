//
// Created by Joe Nguyen on 4/9/24.
//


#include "sighandler.h"
void sigchld_handler(int sig) {
    int status;
    pid_t pid;
    while ((pid = waitpid((pid_t)(-1), &status, WNOHANG)) > 0) {
        printf("pid %d done\n", pid);
    }
}

void sigint_handler(int sig) {
    printf("\nShell cannot be terminated like this\n");
    //cannot control C to exit shell
}