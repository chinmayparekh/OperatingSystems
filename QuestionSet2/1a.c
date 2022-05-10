
// int setitimer(int which, struct itimerval *value, struct itimerval *ovalue);

// ITIMER_REAL
// This timer is marking real (clock) time. A SIGALRM signal is generated after each interval of time.
// ITIMER_VIRTUAL
// This timer is marking process virtual time. Process virtual time is the amount of time spent while executing in the process, and can be thought of as a CPU timer. A SIGVTALRM signal is generated after each interval of time.
// ITIMER_PROF
// This timer is marking process virtual time plus time spent while the system is running on behalf of the process. A SIGPROF signal is generated after each interval of time.


//  Program number 1
//  Chinmay Parekh - IMT2020069
//  Date - 22-04-2022
// Write a separate program (for each time domain) to set a interval timer in 10sec and
// 10micro second
// a. ITIMER_REAL
// b. ITIMER_VIRTUAL
// c. ITIMER_PROF
#include <stdio.h>
#include <sys/time.h>

int main()
{

    struct itimerval value;
    int which = ITIMER_REAL;

    getitimer(which, &value);

    // Time until next expiration
    value.it_value.tv_sec = 10; //10 seconds
    value.it_value.tv_usec = 10; //10 microseconds

    // Interval for periodic timer
    value.it_interval.tv_sec = 10;
    value.it_interval.tv_usec = 10;

    setitimer(which, &value, NULL);

    while (1)
        ;
}