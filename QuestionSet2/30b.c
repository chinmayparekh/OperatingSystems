//  Program number 30
//  Chinmay Parekh - IMT2020069
//  Date - 22-04-2022
// Write a program to create a shared memory.
// a. write some data to the shared memory
// b. attach with O_RDONLY and check whether you are able to overwrite.
// c. detach the shared memory
// d. remove the shared memory
#include <stdio.h>
#include <unistd.h>
#include <sys/shm.h>

int main()
{

    int key, shmid;
    char *data;

    key = ftok(".", 11);
    shmid = shmget(key, 1024, 0);
    //  attach to the shm
    data = (char *)shmat(shmid, NULL, SHM_RDONLY);

    printf("Shm text : %s\n", data);

    return 0;
}