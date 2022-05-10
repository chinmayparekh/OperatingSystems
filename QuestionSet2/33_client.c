//  Program number 33
//  Chinmay Parekh - IMT2020069
//  Date - 22-04-2022
// Write a program to communicate between two machines using socket.
#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>

int main()
{
    struct sockaddr_in serv;
    int sd = socket(AF_INET, SOCK_STREAM, 0);

    serv.sin_family = AF_INET;
    serv.sin_addr.s_addr = INADDR_ANY;
    serv.sin_port = htons(5555);

    connect(sd, (struct sockaddr *)&serv, sizeof(serv));

    char buf[100];

    write(sd, "Client", 6);
    read(sd, buf, 3);

    printf("%s\n", buf);

    return 0;
}