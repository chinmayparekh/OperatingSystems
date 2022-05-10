//  Program number 6
//  Chinmay Parekh - IMT2020069
//  Date - 21-2-2022
// Write a program to take input from STDIN and display on STDOUT. Use only read/write system calls
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>

int main()
{
    char buf[80] = {0};
    read(0, buf, sizeof(buf));
    write(1, buf, sizeof(buf));
}