// int getrlimit(int resource, struct rlimit *rlim);
//  Program number 2
//  Chinmay Parekh - IMT2020069
//  Date - 22-04-2022
// Write a program to print the system resource limits. Use getrlimit system call.
#include <sys/time.h>
#include <sys/resource.h>
#include <stdio.h>

int main()
{

    struct rlimit r;
    getrlimit(RLIMIT_AS, &r);
    printf("Soft Limit is = %lu \nHard Limit is = %lu\n\n", r.rlim_cur, r.rlim_max);
    getrlimit(RLIMIT_CORE, &r);
    printf("Soft Limit is = %lu \nHard Limit is = %lu\n\n", r.rlim_cur, r.rlim_max);
    getrlimit(RLIMIT_CPU, &r);
    printf("Soft Limit is = %lu \nHard Limit is = %lu\n\n", r.rlim_cur, r.rlim_max);
    getrlimit(RLIMIT_FSIZE, &r);
    printf("Soft Limit is = %lu \nHard Limit is = %lu\n\n", r.rlim_cur, r.rlim_max);
    return 0;
}