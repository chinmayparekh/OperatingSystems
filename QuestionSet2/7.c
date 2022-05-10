//  Program number 7
//  Chinmay Parekh - IMT2020069
//  Date - 22-04-2022
// Write a simple program to print the created thread ids.
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

// g++ 7.c -lpthread

// The function to be executed by all threads
void *myThreadFunction(void *vargp)
{
    // Store the value argument passed to this thread
    int *id = (int *)vargp;
    printf("Thread id = %lu\n", pthread_self());//Or follow whatever is done in q6
}
int main()
{
    pthread_t tid;

    // Let us create three threads
    for (int i = 0; i < 3; i++)
        pthread_create(&tid, NULL, myThreadFunction, (void *)&tid);

    pthread_exit(NULL);
    return 0;
}