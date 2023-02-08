#include <stdio.h>
#include <signal.h>
 
 
int main ()
{
    pid_t pid = fork();
    signal(SIGINT,SIG_IGN);
    printf("\n Cannot be terminated using Ctrl+C \n");
    fflush(stdout);
    while(1)
    {        
    }
    return 0;
}