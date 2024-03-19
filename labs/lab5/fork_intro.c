
// Credit: Vatika Tayal
// University of Regina
// CS 330 - Winter 2024
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>

int main(void)
{
	int status; 
	pid_t fork_return; 

	fork_return = fork(); 
	if ( fork_return <0) /* error */
	{
		printf("Fork error!\n");
		exit(1);
	}
	else if (fork_return == 0) /* child process */ 
	{ 
	  printf("I am the child!\n"); 
	  exit(0); 
	} 
	else if (fork_return > 0) /* parent process */ 
	{ 
	  wait(&status); 
	  printf("I am the parent!\n"); 
	  if (WIFEXITED(status))
	      printf("Child returned: %d\n", WEXITSTATUS(status));
	}
}