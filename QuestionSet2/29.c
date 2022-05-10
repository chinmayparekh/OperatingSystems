//  Program number 29
//  Chinmay Parekh - IMT2020069
//  Date - 22-04-2022
// Write a program to remove the message queue.
#include <unistd.h>
#include <stdio.h>
#include <sys/ipc.h>
#include <sys/msg.h>

int main()
{
    key_t key;
    int msqid;
    key = ftok(".", 'a');

    msqid = msgget(key, IPC_CREAT | 0666);
    printf("MSG ID : %d\n", msqid);
    // to destroy the message queue
    msgctl(msqid, IPC_RMID, NULL);
    execlp("ipcs", "ipcs", "-q", NULL);
}
