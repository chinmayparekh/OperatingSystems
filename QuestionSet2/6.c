//  Program number 6
//  Chinmay Parekh - IMT2020069
//  Date - 22-04-2022
// Write a simple program to create three threads.
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

// g++ 6.c -lpthread

// The function to be executed by all threads
void *myThreadFunction(void *vargp)
{
    // Store the value argument passed to this thread
    int *id = (int *)vargp;
    printf("Thread ID: %d\n", *id);
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