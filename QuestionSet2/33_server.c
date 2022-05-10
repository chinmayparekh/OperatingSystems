//  Program number 33
//  Chinmay Parekh - IMT2020069
//  Date - 22-04-2022#include <stdio.h>
// Write a program to communicate between two machines using socket.
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>

int main()
{
    struct sockaddr_in serv, cli;

    int sd = socket(AF_INET, SOCK_STREAM, 0);

    serv.sin_family = AF_INET;
    serv.sin_addr.s_addr = INADDR_ANY;
    serv.sin_port = htons(5555);

    bind(sd, (struct sockaddr *)&serv, (sizeof(serv)));
    listen(sd, 5);

    int addrlen = sizeof(cli);
    int nsd = accept(sd, (struct sockaddr *)&cli, &addrlen);

    char buf[100];
    read(nsd, buf, sizeof(buf));
    write(nsd, "Hi", 10);

    printf("%s\n", buf);

    return 0;
}