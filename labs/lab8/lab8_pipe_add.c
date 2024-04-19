// TEAM MEMBERS:
// LEAD PROGRAMMER: Jack Bulas, Aidan Grisenthwaite

#include <ctype.h>
#include <errno.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
//#include <wait.h>



int main(int argc, char *argv[]) {

    /*
      TODO:
      Use fork() and pipe(), but NOT popen().

      Create a pipe through which a child process will send two integers to 
      the parent. The parent will add the integers and print the result to 
      the terminal. 

      OPTIONAL:
      Make a second child, which will do the addition. In this case, the parent
      waits for the children to terminate. 
    */
    int pid;
    int fd[2];
    int status;
    char line[1024];

    pipe(fd);

    if((pid = fork()) < 0){
        return 1;
    } else if(pid == 0){ //child
        close(fd[0]);
        write(fd[1], "1", 1);
        write(fd[1], "3", 1);
        close(fd[1]);

        return 0;
    }else{  //parent
        if((pid = fork()) < 0){
            return 1;
        }else if (pid == 0) { //second child
            read(fd[0], line, 1);
            int n1 = atoi(line);
            read(fd[0], line, 1);
            int n2 = atoi(line);
            int n3 = n2 + n1;
            write(fd[1], &n3, sizeof(int));
            close(fd[1]);
            close(fd[0]);
            return 0;
        }else{
            wait(&status);
            int result;
            close(fd[1]);//close writing
            read(fd[0], &result, sizeof(int));
            printf("result = %d \n", result);
            close(fd[0]);
            return 0;
        }
    }












    
    return EXIT_SUCCESS;
}
