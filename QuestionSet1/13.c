//  Program number 13
//  Chinmay Parekh - IMT2020069
//  Date - 21-2-2022
// Write a program to wait for a STDIN for 10 seconds using select. Write a proper print statement to
// verify whether the data is available within 10 seconds or not (check in $man 2 select).

#include <unistd.h>
#include <stdio.h>
#include <sys/time.h>

int main()
{
    fd_set readfds;
    FD_ZERO(&readfds);
    FD_SET(0, &readfds);

    struct timeval timeout;
    timeout.tv_sec = 10;
    timeout.tv_usec = 0;

    int ret;
    ret = select(1, &readfds, NULL, NULL, &timeout);

    if (ret == 0)
    {
        printf("Data not available\n");
    }
    else if (ret > 0)
    {
        printf("Data available\n");
    }
}