//  Program number 26
//  Chinmay Parekh - IMT2020069
//  Date - 22-04-2022

// Write a program to send messages to the message queue. Check $ipcs -q
#include <stdio.h>
#include <unistd.h>
#include <sys/msg.h>
#include <sys/ipc.h>
#include <sys/types.h>

#define MAX 10 // structure for message queue
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
    message.mesg_type = 1;

    printf("Write Data : ");
    fgets(message.mesg_text, MAX, stdin);

    // msgsnd to send message
    msgsnd(msgid, &message, sizeof(message), 0);

    // display the message
    printf("Data sent to the message queue is : %s \n", message.mesg_text);
    execlp("ipcs", "ipcs", "-q", NULL);

    return 0;
}