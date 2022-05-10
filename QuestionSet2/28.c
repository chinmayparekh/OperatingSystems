//  Program number 28
//  Chinmay Parekh - IMT2020069
//  Date - 22-04-2022
// Write a program to change the exiting message queue permission. (use msqid_ds structure)
#include <stdio.h>
#include <sys/ipc.h>
#include <sys/msg.h>

int main()
{
    key_t key;
    int msqid;
    key = ftok(".", 11);

    msqid = msgget(key, 0666 | IPC_CREAT);
    struct msqid_ds ms_info;
    msgctl(msqid, IPC_STAT, &ms_info);
    struct ipc_perm *permissions = &ms_info.msg_perm;

    printf("Current permissions : %d \n", permissions->mode);

    // changing mode.
    permissions->mode = 777;
    ms_info.msg_perm = *permissions;
    msgctl(msqid, IPC_SET, &ms_info);

    printf("\nNew permissions set\n");

    msgctl(msqid, IPC_STAT, &ms_info);

    printf("New permissions : %d \n", permissions->mode);
    return 0;
}
