#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>


int main()
{
    pid_t p;
    p = fork();
    if(p)
    {
        printf("In parent:\n - Current process pid = %d\n - Child process pid = %d\n - Parent process pid = %d\n\n", getpid(), p, getppid());
    }
    else
    {
        printf("In child:\n - Current process pid = %d\n - Parent process pid = %d\n", getpid(), getppid());
    }


    //printf("Hello World!\n");
    return 0;
    
    
}