//
// Created by joejoe on 4/9/24.
//
/**************************************************************************************
 * Name        : minishell.c
 * Author      : Harris Hamid
 * Pledge      : I pledge my honor that I have abided by the Stevens Honor System.
 **************************************************************************************/
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <pwd.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/wait.h>
#include <signal.h>
#include <errno.h>
#include <sys/stat.h>

#define BLUE "\x1b[34;1m"
#define DEFAULT "\x1b[0m"

volatile sig_atomic_t interrupted = 0;

// cd command
void cd(char *pathname)
{
    // Case of no arguments or ~
    if (pathname == NULL || strcmp(pathname, "~") == 0)
    {
        struct passwd *pw;
        pw = getpwuid(getuid());
        if (pw == NULL)
        {
            fprintf(stderr, "Error: Cannot get password entry. %s.\n", strerror(errno));
            exit(EXIT_FAILURE);
        }

        if (chdir(pw->pw_dir) != 0)
        {
            fprintf(stderr, "Error: Cannot change directory to %s. %s.\n", pathname, strerror(errno));
        }
    }

        // Case of a provided path
    else
    {
        if (pathname[0] == '~' && pathname[1] == '/')
        {
            struct passwd *pw;
            pw = getpwuid(getuid());
            if (chdir(pw->pw_dir) != 0)
            {
                fprintf(stderr, "Error: Cannot change directory to %s. %s.\n", pathname, strerror(errno));
            }
            pathname += 2;
            if (chdir(pathname) != 0)
            {
                fprintf(stderr, "Error: Cannot change directory to %s. %s.\n", pathname, strerror(errno));
            }
            pathname -= 2;
        }
        else
        {
            if (chdir(pathname) != 0)
            {
                fprintf(stderr, "Error: Cannot change directory to %s. %s.\n", pathname, strerror(errno));
            }
        }
    }
}

// pwd command (pg 70)
void pwd()
{
    char *pathname = getcwd(NULL, 0);
    if (pathname == NULL)
    {
        fprintf(stderr, "Error: Cannot get current working directory. %s.\n", strerror(errno));
        exit(EXIT_FAILURE);
    }
    printf("%s\n", pathname);
    free(pathname);
}

// lf command
void lf()
{
    DIR *dp;
    struct dirent *dirp;

    dp = opendir(".");
    if (dp == NULL)
    {
        fprintf(stderr, "Cannot open directory. %s.\n", strerror(errno));
        exit(EXIT_FAILURE);
    }

    // Use readdir in loop
    while ((dirp = readdir(dp)) != NULL)
    {
        // Skip . and ..
        if ((strcmp(dirp->d_name, ".") == 0) || (strcmp(dirp->d_name, "..") == 0))
        {
            continue;
        }
        printf("%s\n", dirp->d_name);
    }
    closedir(dp);
}

// Signal Hanlding
void sig_hanlder(int sig)
{
    interrupted = 1; // if its been seen update the flag
    printf("\n");
}

// Approach for List Processes
// Open the /proc directory.
// Iterate over all entries in the directory.
// For each entry get process(num), read the uid from the status file, and the command line from the cmdline file.
// Sort uisng qsort the list of processes by PID.
// Print out

// struct to store process fields
struct process
{
    int pid;
    char username[256];
    char command[256];
};

// comparator function to assist with qsort
int compare(const void *a, const void *b)
{
    struct process *processA = (struct process *)a;
    struct process *processB = (struct process *)b;
    return processA->pid - processB->pid;
}

// readInput functin reads input from the cmdline file
void readInput(int pid, char *buffer, int size)
{
    char path[256];
    FILE *cmdline_file;
    snprintf(path, sizeof(path), "/proc/%d/cmdline", pid);
    cmdline_file = fopen(path, "r");

    if (cmdline_file)
    {
        fgets(buffer, size, cmdline_file);
        fclose(cmdline_file);
    }
    else
    {
        buffer[0] = '\0';
    }
}

// lp command itself
void lp()
{
    DIR *procDIR = opendir("/proc");
    struct dirent *dirp;
    struct process process_list[256];
    int processesCount = 0;

    if (procDIR == NULL)
    {
        fprintf(stderr, "Failed to open /proc directory. %s.\n", strerror(errno));
        return;
    }

    while ((dirp = readdir(procDIR)) != NULL)
    {
        if (dirp->d_type == DT_DIR)
        {
            int pid = atoi(dirp->d_name);
            if (pid > 0)
            {
                char status_path[256];
                snprintf(status_path, sizeof(status_path), "/proc/%d", pid);
                struct stat info;

                if (stat(status_path, &info) == 0)
                {
                    struct passwd *pw = getpwuid(info.st_uid);
                    if (pw)
                    {
                        strcpy(process_list[processesCount].username, pw->pw_name);
                    }
                    else
                    {
                        strcpy(process_list[processesCount].username, "");
                    }
                }
                process_list[processesCount].pid = pid;
                // Read the command
                readInput(pid, process_list[processesCount].command, sizeof(process_list[processesCount].command));
                processesCount++;
            }
        }
    }
    closedir(procDIR);

    // Sort and print
    qsort(process_list, processesCount, sizeof(struct process), compare);
    for (int i = 0; i < processesCount; i++)
    {
        printf("%d %s %s\n", process_list[i].pid, process_list[i].username, process_list[i].command);
    }
}

int main()
{
    // input size
    char userInput[256];
    char *currDir;

    // pg 114
    struct sigaction new = {0};
    new.sa_handler = sig_hanlder;
    int sigRus = sigaction(SIGINT, &new, NULL);

    if (sigRus != 0)
    {
        fprintf(stderr, "Error: Cannot register single handler. %s.\n", strerror(errno));
        exit(EXIT_FAILURE);
    }

    while (1)
    {
        char *tokenizedInput[16];
        for (int i = 0; i < 16; i++)
        {
            tokenizedInput[i] = NULL;
        }
        // Check for Ctrl+C
        if (interrupted)
        {
            interrupted = 0;
            continue;
        }

        // Get current working directory
        currDir = getcwd(NULL, 0);
        if (currDir == NULL)
        {
            fprintf(stderr, "Error: Cannot get current working directory. %s.\n", strerror(errno));
            exit(EXIT_FAILURE);
        }

        // BLUE
        printf(BLUE "[%s]" DEFAULT " > ", currDir);
        free(currDir);

        if (fgets(userInput, sizeof(userInput), stdin) == NULL)
        {
            continue;
        }

        userInput[strcspn(userInput, "\n")] = 0;

        // Use strtok to tokenize the input
        int i = 0;
        char *token = strtok(userInput, " \t\n");
        while (token != NULL)
        {
            tokenizedInput[i++] = token;
            token = strtok(NULL, " \t\n");
        }

        char *command = tokenizedInput[0];
        char *arg = NULL;
        if (tokenizedInput[1] != NULL)
        {
            arg = tokenizedInput[1];
        }

        if (strcmp(command, "exit") == 0)
        {
            break;
        }
        else if (strcmp(command, "pwd") == 0)
        {
            pwd();
        }
        else if (strcmp(command, "cd") == 0)
        {
            if (tokenizedInput[2] == NULL)
            {
                cd(arg);
            }
            else
            {
                fprintf(stderr, "Error: Too many arguments to cd.\n");
            }
        }
        else if (strcmp(command, "lf") == 0)
        {
            lf();
        }
        else if (strcmp(command, "lp") == 0)
        {
            lp();
        }
        else
        {
            pid_t pid;
            int stat;
            if ((pid = fork()) < 0)
            {
                fprintf(stderr, "Error: fork() failed. %s.\n", strerror(errno));
                exit(EXIT_FAILURE);
            }
            else if (pid == 0)
            {
                if (execvp(command, tokenizedInput) < 0)
                {
                    fprintf(stderr, "Error: exec() failed. %s.\n", strerror(errno));
                    exit(EXIT_FAILURE);
                }
                exit(EXIT_SUCCESS);
            }
            else
            {
                (wait(&stat));
            }
        }
    }

    return 0;
}