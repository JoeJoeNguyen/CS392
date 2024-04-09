#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <pwd.h>
#include <string.h>
#include <signal.h>
#include <errno.h>

#define MAX_INPUT 1024

void sigchld_handler(int sig) {
    while (waitpid((pid_t)(-1), 0, WNOHANG) > 0) {}
}

void sigint_handler(int sig) {
    printf("Shell cannot be terminated like this\n");
}

int main() {
    signal(SIGINT, sigint_handler);
    signal(SIGCHLD, sigchld_handler);

    uid_t uid = getuid();
    struct passwd *pw = getpwuid(uid);

    if (pw == NULL) {
        fprintf(stderr, "Error: Cannot get passwd entry. %s.\n", strerror(errno));
        return 1;
    }

    char cwd[1024];
    char input[MAX_INPUT];
    char *tokenizedInput[16];

    while (1) {
        if (getcwd(cwd, sizeof(cwd)) == NULL) {
            fprintf(stderr, "Error: Cannot get current working directory. %s.\n", strerror(errno));
            return 1;
        }

        printf("msh:%s:%s$ ", pw->pw_name, cwd);

        if (fgets(input, sizeof(input), stdin) == NULL) {
            continue;
        }

        input[strcspn(input, "\n")] = 0;

        int i = 0;
        char *token = strtok(input, " ");
        while (token != NULL) {
            tokenizedInput[i++] = token;
            token = strtok(NULL, " ");
        }

        tokenizedInput[i] = NULL;

        char *command = tokenizedInput[0];
        char *arg = NULL;
        if (tokenizedInput[1] != NULL) {
            arg = tokenizedInput[1];
        }

        if (strcmp(command, "exit") == 0) {
            if (arg != NULL && strcmp(arg, "&") == 0) {
                fprintf(stderr, "Error: exit cannot be followed by &.\n");
                continue;
            }
            break;
        } else if (strcmp(command, "cd") == 0) {
            if (arg == NULL || strcmp(arg, "~") == 0) {
                arg = pw->pw_dir;
            }
            if (chdir(arg) != 0) {
                fprintf(stderr, "Error: Cannot change directory to %s. %s.\n", arg, strerror(errno));
            }
        } else {
            pid_t pid;
            int background = 0;
            if (strcmp(tokenizedInput[i - 1], "&") == 0) {
                background = 1;
                tokenizedInput[i - 1] = NULL;
            }

            if ((pid = fork()) < 0) {
                fprintf(stderr, "Error: fork() failed. %s.\n", strerror(errno));
                exit(EXIT_FAILURE);
            } else if (pid == 0) {
                if (execvp(command, tokenizedInput) < 0) {
                    fprintf(stderr, "Error: exec() failed. %s.\n", strerror(errno));
                    exit(EXIT_FAILURE);
                }
                exit(EXIT_SUCCESS);
            } else {
                if (background) {
                    printf("pid: %d cmd: %s\n", pid, command);
                } else {
                    wait(NULL);
                }
            }
        }
    }

    return 0;
}