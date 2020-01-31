/*
 * Adrianna Guevarra
 */

#ifndef _GNU_SOURCE
// This is so we can get to a couple helpful GNU-isms.
# define _GNU_SOURCE
#endif // _GNU_SOURCE
#include <stdio.h>
#include <signal.h>
#include <string.h>
#include <errno.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

void sigint(int signo);
void sigusr(int signo); 
void sigterm(int signo); 
void sigalrm(int sgino);
void sigkill(int signo);
void sigusr(int signo);

int main(int argc, char *argv[])
{
 
    printf("This is my pid: %d\n", getpid());
    signal(SIGINT, sigint);
    signal(SIGTERM, sigterm);
    signal(SIGUSR1, sigusr);
    signal(SIGUSR2, sigusr);
    signal(SIGALRM, sigalrm);
    signal(SIGKILL, sigkill);
    // signal(SIGUSR2, sigusr);
    alarm(3);
    while( 1 ) 
        sleep(1);
    return 0;

}

// void sigusr(int signo) 


// printf("test");
// }

void sigusr(int signo){
    // printf("received SIGUSR1\n");
    // {
   switch (signo)
{
    case SIGUSR1: printf("SIGUSR1 caught\n");
        break;
    case SIGUSR2: printf("SIGUSR2 caught\n");
        break;
  
    }
}

void sigint(int signo) 
{
    char answer[15];
    printf("Do you want to exit the program?");
    scanf("%s", answer);
    if (strcasecmp(answer, "yes") == 0)
    exit(0);

}

// When this called, it will terminate the program because you cannot send
// a signal to sigkill 
void sigkill(int signo)
{
    printf("fail\n");
}



void sigterm(int signo) 
{
    printf("received SIGTERM\n");
    exit(0);
}




void sigalrm(int sgino)
{
    time_t current_time;
    time(&current_time);
    printf("Your current time is: %s\n", ctime(&current_time) );
}



