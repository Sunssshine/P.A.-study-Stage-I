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
        pid_t p3 = fork();
        if(!p3)
        {
            // process 3
            printf("\nProcess #3 say:\n - My PID is: %d\n - My PPID is: %d\n", getpid(), getppid());
            return 0;
        }
        pid_t p4 = fork();
        if(!p4)
        {
            // process 4
            printf("\nProcess #4 say:\n - My PID is: %d\n - My PPID is: %d\n", getpid(), getppid());
            return 0;
        }
        if(p3 && p4)
        {
            // process 2
            int * state = NULL;
            wait(state);
            wait(state);
        }
    }
    else
    {
        // process 1
        int * state = NULL;

        wait(state);
    }


    //printf("Hello World!\n");
    return 0;
    
    
}