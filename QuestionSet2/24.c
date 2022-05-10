//  Program number 24
//  Chinmay Parekh - IMT2020069
//  Date - 22-04-2022
// Write a program to create a message queue and print the key and message queue id.
#include <stdio.h>
#include <unistd.h>
#include <sys/msg.h>
#include <sys/ipc.h>
#include <sys/types.h>

int main()
{
    int msgid;
    key_t key;
    // ftok to generate unique key
    key = ftok(".", 11);
    // msgget creates a message queue
    // and returns identifier
    msgid = msgget(key, IPC_CREAT | 0744); // Pass 0 if already exists

    printf("Key value is %d \nMessage queue id is %d \n", key, msgid);
}