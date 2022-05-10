//  Program number 19
//  Chinmay Parekh - IMT2020069
//  Date - 21-2-2022
// Write a program to find out time taken to execute getpid system call. Use time stamp counter.
#include <sys/types.h>
#include <unistd.h>
#include <time.h>
#include <stdio.h>

void main()
{

    clock_t start_time, end_time;
    start_time = clock();
    getpid();
    end_time = clock();
    float t = ((double)(end_time - start_time)) / CLOCKS_PER_SEC;
    printf("Time taken to execute the function is %f sec\n", t);
}