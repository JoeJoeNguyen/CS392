#include <unistd.h>
#include <printf.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#define MSGSIZE 60

//
//  Author: Son [Joe] Nguyen
//  I pledge my honor that I have abided by the Stevens Honor System
int main(int argc, char *argv[]) {
    //create 2 pipes
    int pid;
    int pc[2];
    int cp[2];
    int status;
    int randomNumber;
    int guess = 0;
    char msg[MSGSIZE] = "start";
    char rcv[MSGSIZE] = "start";
    if(pipe(pc) < 0 || pipe(cp) < 0){
        fprintf(stderr, "fail piping");
        return 1;
    }

    if((pid = fork()) < 0){
        fprintf(stderr, "fork fail");
    }else if(pid != 0){ //parent
        close(pc[0]); //close parent to child reading
        close(cp[1]);//close child to parent writing
        srand(time(NULL));
        randomNumber = (rand() % 32) + 1; //generate random number from 1 - 31
        while(guess != randomNumber){
            read(cp[0], &guess, sizeof(int));
            if(guess < randomNumber){
                printf("too low\n");
                strcpy(msg, "higher");

            }else if(guess > randomNumber){
                printf("too high\n");
                strcpy(msg, "lower");

            }else{
                printf("bingo: %d\n", randomNumber );
                strcpy(msg, "correct");

            }
            write(pc[1], &msg, MSGSIZE);
        }
        close(pc[1]); //close parent to child writing
        close(cp[0]);//close the child to parent reading


    }else{ //if it is the child
        close(pc[1]);//close the parent to child writing
        close(cp[0]);//close the child to parent reading

        while (strcmp(rcv, "correct") != 0){
            printf("Enter your guess: ");
            scanf("%d", &guess); //taking input from the user

            // Send the guess to the parent process
            write(cp[1], &guess, sizeof(int));

            // Read the message from the parent process
            read(pc[0], rcv, MSGSIZE);

            // Print the message received from the parent process
            //printf("Message from parent: %s\n", rcv);
        }
        close(pc[0]); //close the parent to child reading
        close(cp[1]); //close the child to parent writing
        return 0;
    }
}