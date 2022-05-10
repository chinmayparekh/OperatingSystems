// // shmdt(shm_ptr);
//  Program number 30
//  Chinmay Parekh - IMT2020069
//  Date - 22-04-2022
// Write a program to create a shared memory.
// a. write some data to the shared memory
// b. attach with O_RDONLY and check whether you are able to overwrite.
// c. detach the shared memory
// d. remove the shared memory
#include <sys/ipc.h>
#include <sys/shm.h>
#include <stdio.h>

int main()
{
    key_t key = ftok(".", 11);
    int shmid = shmget(key, 1024, 0);
    char *str = (char *)shmat(shmid, (void *)0, 0);
    printf("Data read from memory: %s\n", str);
    shmdt(str);
    printf("shared memory is detached\n");

    return 0;
}
