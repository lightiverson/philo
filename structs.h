#ifndef STRUCTS_H
# define STRUCTS_H

/* Private libraries */
#include "philo.h"

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

#endif
