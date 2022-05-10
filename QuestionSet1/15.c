//  Program number 15
//  Chinmay Parekh - IMT2020069
//  Date - 21-2-2022
// Write a program to display the environmental variable of the user (use environ).
#include <stdio.h>

int main(int argc, char **argv, char **envp)
{
    int i = 0;
    while (envp[i])
        printf("%s\n", envp[i++]);
}