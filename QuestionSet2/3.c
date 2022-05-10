// int setrlimit(int resource, const struct rlimit *rlim);
//  Program number 3
//  Chinmay Parekh - IMT2020069
//  Date - 22-04-2022
// Write a program to set (any one) system resource limit. Use setrlimit system call.
#include <stdio.h>
#include <sys/resource.h>
#include <sys/time.h>
int main()
{

    struct rlimit r;

    getrlimit(RLIMIT_CPU, &r);
    printf("Soft Limit is = %lu \nHard Limit is = %lu\n\n", r.rlim_cur, r.rlim_max);

    r.rlim_cur = 123;
    r.rlim_max = 345;

    setrlimit(RLIMIT_CPU, &r);

    getrlimit(RLIMIT_CPU, &r);
    printf("Soft Limit is = %lu \nHard Limit is = %lu\n\n", r.rlim_cur, r.rlim_max);
}