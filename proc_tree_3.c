#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>


int main()
{
    printf("\nProcess #1 say:\n - My PID is: %d\n - My PPID is: %d\n", getpid(), getppid());
    pid_t p2 = fork();
    if(!p2)
    {
        printf("\nProcess #2 say:\n - My PID is: %d\n - My PPID is: %d\n", getpid(), getppid());
    }
    else
    {
        pid_t p3 = fork();
        if(!p3)
        {
            // process 3
            printf("\nProcess #3 say:\n - My PID is: %d\n - My PPID is: %d\n", getpid(), getppid());
            pid_t p4 = fork();
            if(!p4)
            {
                printf("\nProcess #4 say:\n - My PID is: %d\n - My PPID is: %d\n", getpid(), getppid());
            }
            else
            {
                wait(); // wait for process 4
            }
        }
        else
        {
            wait(); // wait for process 3
        }
        wait(); // wait for process 2
    }
    return 0;
}