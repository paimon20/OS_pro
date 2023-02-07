#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 50

typedef struct student {
    int roll;
    char name[MAX_NAME_LENGTH];
    int age;
} STUDENT;

void *print_student_info(void *arg)
{
    STUDENT *student = (STUDENT *)arg;
    printf("ROLL: %d\n", student->roll);
    printf("NAME: %s\n", student->name);
    printf("AGE: %d\n", student->age);
    pthread_exit(0);
}

int main(void)
{
    pthread_t thread;
    STUDENT student;
    student.roll = 1;
    strcpy(student.name, "John Doe");
    student.age = 20;
    pthread_create(&thread, NULL, print_student_info, &student);
    pthread_join(thread, NULL);
    return 0;
}
