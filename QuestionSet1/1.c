//  Program number 1
//  Chinmay Parekh - IMT2020069
//  Date - 21-2-2022

// Create the following types of a files using (i) shell command (ii) system call
// a. soft link (symlink system call)
// b. hard link (link system call)
// c. FIFO (mkfifo Library Function or mknod system call)

#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>

int main()
{
    const char *target = "2.c";
    const char *linkpath = "soft_link";
    const char *pathname = "2.c";
    const char *linkname = "hard_link";
    const char *fifopath = "2.c";

    int soft_link = symlink(target, linkpath);//ls -ia to check all inode numbers
    int hard_link = link(pathname, linkname);
    int fifo = mknod(fifopath, S_IFIFO, 0666);

    perror(fifopath);
    perror(linkname);
    perror(linkpath);

    printf("soft link = %d\n", soft_link);
    printf("hard link = %d\n", hard_link);
    printf("fifo = %d\n", fifo);
    return 0;
}