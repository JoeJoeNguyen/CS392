// TEAM MEMBERS: Son Nguyen
// LEAD PROGRAMMER: Son Nguyen ( my vm doesnt work!!!)

// Credit: Chris Kauffman
// University of Minnesota
// CSCI 4061 - Spring 2021
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>  // uncomment if using wait() / waitpid() system call

// TODO
// 1. Understand how many processes are created and their structure. 
// Is it a chain (each process has at most one child), a fan (one parent with many children), or a tree?
// WRITE YOUR ANSWER HERE
/* It is a tree because one parent id has one or more children, and each child also has one or more children.

(an example with 4 iteration)
|START| pid: 401 parent_pid: 1
FINISH| pid: 401 parent_pid: 1
FINISH| pid: 403 parent_pid: 401
FINISH| pid: 404 parent_pid: 401
FINISH| pid: 402 parent_pid: 401
FINISH| pid: 406 parent_pid: 403
FINISH| pid: 407 parent_pid: 403
FINISH| pid: 408 parent_pid: 404
FINISH| pid: 409 parent_pid: 402
FINISH| pid: 410 parent_pid: 402
FINISH| pid: 405 parent_pid: 401
FINISH| pid: 411 parent_pid: 402
FINISH| pid: 412 parent_pid: 406
FINISH| pid: 413 parent_pid: 409
FINISH| pid: 414 parent_pid: 409
FINISH| pid: 415 parent_pid: 410
FINISH| pid: 416 parent_pid: 413


*/
// 2. Modify the program to make sure that there are 5 processes which complete in the same order each run. 
// The easiest way to do this is to have parent processes use the `wait()' or `waitpid()' system call
// after creating children which will "block" the parent until the child completes.  This should give 
// a consistent ordering of the output and prevent any orphan processes.

int main(void) {
    printf("|START| pid: %d parent_pid: %d\n", getpid(), getppid());
    fflush(stdout);               // flush stdout to preven I/O duplication
    for(int i=0; i<2; i++){
        fork();
    }
    printf("FINISH| pid: %d parent_pid: %d\n", getpid(), getppid());
    sleep(2);     // what happens if you remove this?
    return 0;
}
