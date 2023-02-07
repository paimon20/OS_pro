#include <pthread.h>
#include <stdio.h>
#include <string.h>

void *reverse_thread(void *arg)
{
    char *string = (char *)arg;
    int length = strlen(string);
    for (int i = 0; i < length / 2; i++) {
        char temp = string[i];
        string[i] = string[length - i - 1];
        string[length - i - 1] = temp;
    }
    printf("Reversed string: %s\n", string);
    pthread_exit(0);
}

int main(int argc, char *argv[])
{
    pthread_t thread_id;
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <string>\n", argv[0]);
        return -1;
    }
    if (pthread_create(&thread_id, NULL, reverse_thread, argv[1]) != 0) {
        perror("Error creating thread");
        return -1;
    }
    pthread_exit(0);
}
