//  Program number 7
//  Chinmay Parekh - IMT2020069
//  Date - 21-2-2022
// Write a program to copy file1 into file2 ($cp file1 file2).
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>

int main()
{
    // int fd, fd1;
    // char buf[80], buf1[80];
    // fd = open("newfile.txt", O_CREAT | O_RDWR, 0744);
    // printf("Writing to a file\n");
    // scanf("%s", buf);
    // write(fd, buf, sizeof(buf));
    // close(fd);
    // fd = open("newfile.txt", O_RDWR);
    // read(fd, buf1, sizeof(buf1));
    // printf("%s\n", buf1);
    // close(fd);

    // fd1 = open("copiedFile.txt", O_CREAT | O_RDWR, 0744);
    // write(fd1, buf1, sizeof(buf1));
    // close(fd1);

    // fd1 = open("copiedFile.txt", O_RDWR);
    // read(fd1, buf1, sizeof(buf1));
    // printf("Reading from copied file\n");
    // printf("%s\n", buf1);

    char buf[1000] = {0};
    int fd = open("7.c", O_RDONLY);
    int fd1 = open("copy.c", O_CREAT | O_RDWR, 0744);
    read(fd, buf, sizeof(buf));
    write(fd1, buf, sizeof(buf));
    close(fd);
    close(fd1);
    return 0;
}