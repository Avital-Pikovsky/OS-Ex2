#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <string.h>
#include <sys/wait.h>
#include <signal.h>
#include "ping_pong.h"

enum boolean {True = 1, False = 0};


static int n = 0;
static int b = True;  //boolean for know when n==5
static int process;      //procces id
static int fd1[2]; //pipe

//signal handler stop when n==5
void handler(int sig)
{
    if (n > 5)
        b = False;
}

//Read & write function
void readAndWrite()
{
    static int x = 0;
    if (process < 0)
    {
        fprintf(stderr, "fork Failed");
        exit(True);
    }

    // child process
    else if (process == 0)
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
            printf("Parent is going to be terminated\n"); //Already terminated
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
            b = False;
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
        return True;
    }

    process = fork();
    // incarse n and send 5 time with readAndWrite function
    while (b == True)
    {
        readAndWrite();
    }

    return 0;
}
