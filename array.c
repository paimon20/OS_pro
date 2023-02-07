#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

#define NUM_THREADS 2
#define N 10

int arr[N];

void *bubble_sort(void *arg)
{
    int temp;
    for (int i = 0; i < N - 1; i++)
    {
        for (int j = 0; j < N - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
    pthread_exit(0);
}

void *selection_sort(void *arg)
{
    int min_idx;
    int temp;
    for (int i = 0; i < N - 1; i++)
    {
        min_idx = i;
        for (int j = i + 1; j < N; j++)
        {
            if (arr[j] < arr[min_idx])
                min_idx = j;
        }
        temp = arr[min_idx];
        arr[min_idx] = arr[i];
        arr[i] = temp;
    }
    pthread_exit(0);
}

int main(void)
{
    pthread_t threads[NUM_THREADS];
    for (int i = 0; i < N; i++)
        scanf("%d", &arr[i]);
    pthread_create(&threads[0], NULL, bubble_sort, NULL);
    pthread_create(&threads[1], NULL, selection_sort, NULL);
    pthread_join(threads[0], NULL);
    pthread_join(threads[1], NULL);
    printf("Sorted array: ");
    for (int i = 0; i < N; i++)
        printf("%d ", arr[i]);
    printf("\n");
    return 0;
}
