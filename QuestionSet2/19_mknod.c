//  Program number 19
//  Chinmay Parekh - IMT2020069
//  Date - 22-04-2022

// Create a FIFO file by
// a. mknod command
// b. mkfifo command
// c. use strace command to find out, which command (mknod or mkfifo) is better.
// c. mknod system call
// d. mkfifo library function
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
int main()
{
    const char *buf = "pipe";
    mknod(buf, S_IFIFO | 0, 0);
}
