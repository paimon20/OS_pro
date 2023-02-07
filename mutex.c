#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

#define VECTOR_SIZE 10
#define NUM_THREADS 4

int vector1[VECTOR_SIZE];
int vector2[VECTOR_SIZE];
int dot_product = 0;
pthread_mutex_t dot_product_mutex;

void *calculate_dot_product(void *arg)
{
    int thread_num = *(int *)arg;
    int start = thread_num * (VECTOR_SIZE / NUM_THREADS);
    int end = start + (VECTOR_SIZE / NUM_THREADS);
    int thread_dot_product = 0;
    for (int i = start; i < end; i++)
        thread_dot_product += vector1[i] * vector2[i];
    pthread_mutex_lock(&dot_product_mutex);
    dot_product += thread_dot_product;
    pthread_mutex_unlock(&dot_product_mutex);
    pthread_exit(0);
}

int main(void)
{
    pthread_t threads[NUM_THREADS];
    int thread_nums[NUM_THREADS];
    for (int i = 0; i < VECTOR_SIZE; i++) {
        vector1[i] = i + 1;
        vector2[i] = i + 1;
    }
    pthread_mutex_init(&dot_product_mutex, NULL);
    for (int i = 0; i < NUM_THREADS; i++) {
        thread_nums[i] = i;
        pthread_create(&threads[i], NULL, calculate_dot_product, &thread_nums[i]);
    }
    for (int i = 0; i < NUM_THREADS; i++)
        pthread_join(threads[i], NULL);
    printf("Dot product: %d\n", dot_product);
    pthread_mutex_destroy(&dot_product_mutex);
    return 0;
}
