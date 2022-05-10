//  Program number 10
//  Chinmay Parekh - IMT2020069
//  Date - 21-2-2022
// Write a program to open a file with read write mode, write 10 bytes, move the file pointer by 10
// bytes (use lseek) and write again 10 bytes.
// a. check the return value of lseek
// b. open the file with od and check the empty spaces in between the data.
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
int main()
{
    int fd = open("10.txt", O_CREAT|O_RDWR,0744);
    char buf[10] = {'1', '2', '3', '4', '5', '6', '7', '8', '9', '0'};
    write(fd, buf, 10);
    int x = lseek(fd, 10, SEEK_CUR);
    printf("lseek returns %d\n", x);
    write(fd, buf, 10);
    close(fd);

    system("od -c file10.txt");
}