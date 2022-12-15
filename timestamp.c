#include "timestamp.h"

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
