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
    int which = ITIMER_VIRTUAL;

    getitimer(which, &value);

    // Time until next expiration
    value.it_value.tv_sec = 10;  // 10 seconds
    value.it_value.tv_usec = 10; // 10 microseconds

    // Interval for periodic timer
    value.it_interval.tv_sec = 10;
    value.it_interval.tv_usec = 10;

    setitimer(which, &value, NULL);

    while (1)
        ;
}