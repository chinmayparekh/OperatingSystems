// ftok(): is use to generate a unique key.

// shmget(): int shmget(key_t,size_tsize,intshmflg); upon successful completion, shmget() returns an identifier for the shared memory segment.

// shmat(): Before you can use a shared memory segment, you have to attach yourself
// to it using shmat(). void *shmat(int shmid ,void *shmaddr ,int shmflg);
// shmid is shared memory id. shmaddr specifies specific address to use but we should set
// it to zero and OS will automatically choose the address.

// shmdt(): When you’re done with the shared memory segment, your program should
// detach itself from it using shmdt(). int shmdt(void *shmaddr);

// shmctl(): when you detach from shared memory,it is not destroyed. So, to destroy
// shmctl() is used. shmctl(int shmid,IPC_RMID,NULL);
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
    shmid = shmget(key, 1024, IPC_CREAT | 0744);
    //  attach to the shm
    data = (char *)shmat(shmid, NULL, 0); // 0 will look for the free space return unused space address, flag as 0 = read+write

    printf("Enter Text : ");
    scanf("%s", data);

    return 0;
}