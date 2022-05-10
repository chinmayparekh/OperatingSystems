//  Program number 3
//  Chinmay Parekh - IMT2020069
//  Date - 21-2-2022
// Write a program to create a file and print the file descriptor value. Use creat ( ) system call
#include <stdio.h>
#include <fcntl.h>
int main()
{
    int fd = creat("create.txt", O_CREAT|0744);
    printf("%d\n", fd);
}