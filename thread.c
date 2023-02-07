#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

void *sum_thread(void *arg)
{
    int n = *(int *)arg;
    int sum = 0;
    for (int i = 1; i <= n; i++)
        sum += i;
    printf("Sum of first %d integers is %d\n", n, sum);
    pthread_exit(0);
}

int main(int argc, char *argv[])
{
    int n;
    pthread_t thread_id;
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <integer value>\n", argv[0]);
        return -1;
    }
    if (sscanf(argv[1], "%d", &n) != 1) {
        fprintf(stderr, "Invalid integer value: %s\n", argv[1]);
        return -1;
    }
    if (pthread_create(&thread_id, NULL, sum_thread, &n) != 0) {
        perror("Error creating thread");
        return -1;
    }
    pthread_exit(0);
}
