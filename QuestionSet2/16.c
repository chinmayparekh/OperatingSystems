//  Program number 16
//  Chinmay Parekh - IMT2020069
//  Date - 22-04-2022
// Write a program to send and receive data from parent to child vice versa. Use two way
// communication.
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>
#include <sys/wait.h>

int main()
{

    int fd1[2];
    int fd2[2];
    if (pipe(fd1) == -1 || pipe(fd2) == -1)
    {
        printf("Pipe Error\n");
        return 0;
    }

    int isParent = fork();
    if (!isParent)
    {

        char s[100];
        char concatStr[100] = "- child";
        close(fd1[1]); // closing writing end of first pipe
        read(fd1[0], s, 100);

        // printf("Child process, message recieved : %s \n",s);
        close(fd1[0]);
        close(fd2[0]); // close read

        strcat(s, concatStr);

        write(fd2[1], s, 100);
        return 0;
    }
    else
    {
        char buf[100] = "parent";
        char rcvbuf[100];
        close(fd1[0]); // closing the read end of the first pipe

        write(fd1[1], buf, 100);
        close(fd1[1]);
        close(fd2[1]);

        read(fd2[0], buf, 100);

        printf("%s \n", buf);
    }
    return 0;
}
