#include "state.h"

void eat(size_t i)
{
    // mutex forks
    // print timestamp_in_ms X is eating
    printf("%ld %ld is eating\n", get_current_timestamp_in_ms(), i);
    // simulate eating by sleeping for eat_duration?
    // put forks back on the table
    // start sleeping
}

void sleep(size_t i)
{
    printf("%ld %ld is sleeping\n", get_current_timestamp_in_ms(), i);
}

void has_died(size_t i)
{
    // timestamp_in_ms X died
    ;
}

void think(size_t i)
{
    printf("%ld %ld is thinking\n", get_current_timestamp_in_ms(), i);
}