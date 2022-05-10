//  Program number 27
//  Chinmay Parekh - IMT2020069
//  Date - 22-04-2022
// Write a program to receive messages from the message queue.
// a. with 0 as a flag
// b. with IPC_NOWAIT as a flag
#include <stdio.h>
#include <sys/ipc.h>
#include <sys/msg.h>

// structure for message queue
struct mesg_buffer
{
    long mesg_type;
    char mesg_text[100];
} message;

int main()
{
    key_t key;
    int msgid;

    // ftok to generate unique key
    key = ftok(".", 11);

    // msgget creates a message queue
    // and returns identifier
    msgid = msgget(key, 0666 | IPC_CREAT);

    // msgrcv to receive message
    msgrcv(msgid, &message, sizeof(message), 1, IPC_NOWAIT);
    perror("msgrcv");
    // display the message
    printf("Data Received is : %s \n",
           message.mesg_text);

    return 0;
}