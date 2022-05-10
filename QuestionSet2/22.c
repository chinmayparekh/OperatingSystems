//  Program number 22
//  Chinmay Parekh - IMT2020069
//  Date - 22-04-2022
// Write a program to wait for data to be written into FIFO within 10 seconds, use select
// system call with FIFO.
#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>

int main(void)
{
    fd_set rfds;
    struct timeval tv;
    int retval;

    /* Watch stdin (fd 0) to see when it has input. */

    FD_ZERO(&rfds);
    FD_SET(0, &rfds);

    /* Wait up to ten seconds. */

    tv.tv_sec = 10;
    tv.tv_usec = 0;

    retval = select(1, &rfds, NULL, NULL, &tv);
    /* Don't rely on the value of tv now! */

    if (retval == -1)
        perror("select()");
    else if (retval)
    {
        printf("Data is available in 10 sec.\n");
        int fd = open("pipe", O_RDWR);
        char *buf = "Hello";
        write(fd, buf, 6);
        read(fd, buf, 6);
    }
    /* FD_ISSET(0, &rfds) will be true. */
    else
        printf("No data is written within ten seconds.\n");

    exit(EXIT_SUCCESS);
}