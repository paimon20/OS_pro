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
	 else if(pid=0)
	{
		for (i = 0; i < 10; i++)
        {
            printf("Child:%d\n",i);
        }
        
	}
	
	//child process
	else
	{
		//parent
	}
	return 0;
}