#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <string.h>
#include <sys/wait.h>
#include <signal.h>
#include "ping-pong.h"

static int n = 0;
static int b = 1;  //boolean for know when n==5
static int p;      //procces id
static int fd1[2]; //pipe

//signal handler stop when n==5
void handler(int sig)
{
    if (n > 5)
        b = 0;
}

// function read & write
void foo()
{
    static int x = 0;
    if (p < 0)
    {
        fprintf(stderr, "fork Failed");
        exit(1);
    }

    // child process
    else if (p == 0)
    {
        write(fd1[1], &x, sizeof(x)); // Write a val and close writing end
        kill(getppid(), SIGUSR1);     //send a SIGUSR1 to parent
        pause();                      // wait to a siganal from father
        read(fd1[0], &x, sizeof(x));  // Read a string using first pipe
        printf("Child = %d\n", x);
        x++;
        if (x >= 5) //Child and Parent is going to be terminated
        {
            printf("Child is going to be terminated\n");
            printf("Parent is going to be terminated\n");
        }
    }

    // Parent process
    else
    {
        pause();                     // wait to a siganal from child
        read(fd1[0], &x, sizeof(x)); // Read a val from child, print it and close
        printf("Parent = %d\n", x);
        x++;
        write(fd1[1], &x, sizeof(x)); // Write input string and close writing end of first pipe.
        kill(0, SIGUSR1);             //send a SIGUSR1 to son
        if (x >= 5)
        {
            b = 0;
           // printf("Parent is going to be terminated\n");
        }
    }
}

int main()
{
    signal(SIGUSR1, handler); //choosing signalhandler

    if (pipe(fd1) == -1)
    {
        fprintf(stderr, "Pipe Failed");
        return 1;
    }

    p = fork();
    // incarse n and send 5 time with foo function
    while (b == 1)
    {
        foo();
    }

    return 0;
}
