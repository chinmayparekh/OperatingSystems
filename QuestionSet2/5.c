//  sysconf - get configuration information at run time
//  Program number 5
//  Chinmay Parekh - IMT2020069
//  Date - 22-04-2022
// Write a program to print the system limitation of
// a. maximum length of the arguments to the exec family of functions.
// b. maximum number of simultaneous process per user id.
// c. number of clock ticks (jiffy) per second.
// d. maximum number of open files
// e. size of a page
// f. total number of pages in the physical memory
// g. number of currently available pages in the physical memory
#include <unistd.h>
#include <stdio.h>
#include <limits.h>

int main()
{
    printf("maximum length of the arguments to the exec family of functions = %ld\n", sysconf(_SC_ARG_MAX));
    printf("maximum number of simultaneous process per user id = %ld\n", sysconf(_SC_CHILD_MAX));
    printf("number of clock ticks (jiffy) per second = %ld\n", sysconf(_SC_CLK_TCK));
    printf("maximum number of open files = %ld\n", sysconf(_SC_ARG_MAX));
    printf("size of a page = %ld\n", sysconf(_SC_PAGESIZE));
    printf("total number of pages in the physical memory = %ld\n", sysconf(_SC_PHYS_PAGES));
    printf("number of currently available pages in the physical memory = %ld\n", sysconf(_SC_AVPHYS_PAGES));
    return 0;
}