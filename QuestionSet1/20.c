//  Program number 20
//  Chinmay Parekh - IMT2020069
//  Date - 21-2-2022
// Find out the priority of your running program. Modify the priority with nice command.

// use: renice -n -20 -p <pid>
// This changes the priority of the process to -20
// printf("priority = %d\n",getpriority(PRIO_PROCESS,0));

#include <sys/resource.h>
#include <stdio.h>
#include <unistd.h>
int main()
{
    int a = getpriority(PRIO_PROCESS, getpid());
    printf("%d\n", a);
    nice(-20); // use sudo as priority is increasing
    a = getpriority(PRIO_PROCESS, getpid());
    printf("%d\n", a);
    return 0;
}
