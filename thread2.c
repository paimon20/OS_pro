#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main(void)
{
    pid_t pid1 = fork();
    if (pid1 == 0) {
        for (int i = 1; i <= 100; i++)
            printf("Child 1: %d\n", i);
        return 0;
    }
    pid_t pid2 = fork();
    if (pid2 == 0) {
        for (int i = 100; i >= 1; i--)
            printf("Child 2: %d\n", i);
        return 0;
    }
    waitpid(pid1, NULL, 0);
    waitpid(pid2, NULL, 0);
    return 0;
}
