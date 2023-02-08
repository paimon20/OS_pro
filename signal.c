#include<stdio.h>
#include<signal.h>
#include<sys/types.h>
#include<unistd.h>


int main()
{
	pid_t pid = fork();
	int i;
	
	if(pid<0)
	{
		perror("Error creating child process:");
		return -1;
	}
	
	//parent process
	if(pid>0)
	{
		sleep(10);
		printf("Sending %u to child process..\n",SIGQUIT);
		kill(pid,SIGQUIT);//send signal from parent to child.
		printf("Exiting parent process..\n");
	}
	
	//child process
	else
	{
		i=1;
		signal(SIGQUIT, SIG_IGN);
		while(i)
		{
			printf("Child process(%u): i=%d\n",getpid(),i);
			i++;
			sleep(1);
		}
		//kill(getpid(),2);//to send signal from child to parent.
	}
	return 0;
}