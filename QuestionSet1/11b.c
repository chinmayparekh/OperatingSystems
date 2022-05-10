//  Program number 11b
//  Chinmay Parekh - IMT2020069
//  Date - 21-2-2022
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>

int main()
{
    int file_desc = open("11b", O_CREAT | O_RDWR, 0744);

    // here the newfd is the file descriptor of stdout (i.e. 1)
    dup2(file_desc, 1);
    // All the printf statements will be written in the file
    // "tricky.txt"
    printf("I will be printed in 11b\n");

    return 0;
}