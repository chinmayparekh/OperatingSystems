//  Program number 31
//  Chinmay Parekh - IMT2020069
//  Date - 22-04-2022
// Write a program to create a semaphore and initialize value to the semaphore.
// a. create a binary semaphore
// b. create a counting semaphore
#include <stdio.h>
#include <unistd.h>
#include <sys/sem.h>

union semun
{
    int val;
    struct semid_ds *buf;
    unsigned short int *array;
};

int main()
{
    union semun arg;
    int key, semid;

    key = ftok(".", 11);
    semid = semget(key, 1, IPC_CREAT | 0744);
    printf("%d\n", semid);
    arg.val = 1; // cause binary semaphore.

    semctl(semid, 0, SETVAL, arg);
    return 0;
}
