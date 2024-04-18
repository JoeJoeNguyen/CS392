/*
Filip Sigda
Justin Vilchez
Son Nguyen
I pledge my honor that I have abided by the Stevens Honor System.
*/

#include <ctype.h>
#include <errno.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <wait.h>

int main(int argc, char *argv[]) {
  if (argc != 2) {
    fprintf(stderr, "Usage: %s <num forks>\n", argv[0]);
    return EXIT_FAILURE;
  }
  int num_forks = atoi(argv[1]);
  if (num_forks <= 0) {
    fprintf(stderr, "Error: Invalid number of forks '%s'.\n", argv[1]);
    return EXIT_FAILURE;
  }

  pid_t list[200];
  /*
    TODO:
    Use fork() and execl().

    Create num_forks children processes.
    If any call to fork fails, an error message should be printed and
    the loop should continue.
    Keep track of how many children were actually spawned.
    The error message will be of the form:
    Error: fork[fork_index] failed. %s.
       fork_index will be an integer [1, ..., num_forks]
       %s will be strerror(errno)

    The children should execute randomsleep with no arguments.
    If execl fails, an error message should be printed and
    EXIT_FAILURE should returned.
    The error message will be of the form:
    Error: execl() failed for pid %ld. %s.
       %s will be strerror(errno)
  */
  uint index = 0;
  pid_t parentID = getpid();
  for (int i = 0; i < num_forks; i++) {
    pid_t p = fork();
    if (getpid() <= 0) {
      printf("Error: fork[%d] failed. %s. \n", i, strerror(getpid()));
      continue;
    }
    if (getpid() != parentID) {
      break;
    } else {
      list[0] = p;
      index++;
    }
  }

  /*
    TODO:
    Use wait().

    We are in the parent here. Wait for all children that were actually
    spawned. As each child terminates, print the message:
    Child with pid <pid> has terminated.
    If an error occurs during waiting, instead print the message:
    Error: wait() failed. %s.
       %s will be strerror(errno)
  */
  if (getpid() != parentID) {
    if (execl("./randomsleep", "","",NULL)) {
      printf("Error: execl() failed for pid %d. %s.", getpid(),
             strerror(getpid()));
    }
    return EXIT_SUCCESS;
  }

  int waitindex = 0;
  for (int i = 0; i < index + 1; i++) {
    wait(&list[waitindex]);
    waitindex += 1;
  }

  printf("All children are done sleeping.\n");
  return EXIT_SUCCESS;
}
