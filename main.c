// Moet ik ook mutex gebruiken om stdout te locken?

#include <stdlib.h>
#include <sys/time.h>
#include <stdio.h>

unsigned long timeval_to_ms(struct timeval tv)
{
    return (tv.tv_sec * 1000 + tv.tv_usec / 1000);
}

unsigned long get_current_timestamp_in_ms(void)
{
	struct timeval	current_time;

	gettimeofday(&current_time, 0);
	return (timeval_to_ms(current_time));
}

size_t left(size_t i)
{
    return (i);
}

size_t right(size_t i, size_t num_of_philos)
{
    return ((i + 1) % num_of_philos);
}

void think(size_t i)
{
    printf("%ld %ld is thinking\n", get_current_timestamp_in_ms(), i);
}

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

enum e_state {
    THINKING = 0,  // philosopher is THINKING
    HUNGRY = 1,    // philosopher is trying to get forks
    EATING = 2,    // philosopher is EATING
    SLEEPING = 3,  // philosopher is SLEEPING
};

typedef struct s_philosopher
{
    size_t  time_to_die;
    size_t  time_to_eat;
    size_t  time_to_sleep;
    size_t  number_of_times_to_eat;
    size_t  number;
    int     state;
}   t_philosopher;

int main (int argc, char *argv[5])
{
    // struct timeval tv;
    // struct timezone tz;
    // gettimeofday(&tv, &tz);
    // printf("tv.tv_sec = %ld\n", tv.tv_sec);
    // printf("tv.tv_usec = %d\n", tv.tv_usec);
    // printf("tz.tz_minuteswest = %d\n", tz.tz_minuteswest);
    // printf("tz.tz_dsttime = %d\n", tz.tz_dsttime);

    // printf("%ld\n", get_current_timestamp_in_ms());

    size_t i = 0;

    think(i);
    eat(i);
    sleep(i);

    return (0);
}