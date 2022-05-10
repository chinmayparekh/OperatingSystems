//  Program number 4
//  Chinmay Parekh - IMT2020069
//  Date - 22-04-2022
// Write a program to measure how much time is taken to execute 100 getppid ( )
// system call. Use time stamp counter.
#include <stdio.h>
#include <time.h>
#include <sys/types.h>
#include <unistd.h>

unsigned long long rdtsc()
{

    unsigned long long dst;
    __asm__ __volatile__("rdtsc"
                         : "=A"(dst));

    return dst;
}
void function()
{
    for (int i = 0; i < 100; i++)
    {
        getppid();
    }
}
int main()
{
    double start, end;

    start = rdtsc();

    function();

    end = rdtsc();

    printf("Time (difference) : %lf \n", (end - start) / CLOCKS_PER_SEC);
}