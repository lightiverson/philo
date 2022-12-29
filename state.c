/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   state.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: kgajadie <kgajadie@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/12/21 17:46:06 by kgajadie      #+#    #+#                 */
/*   Updated: 2022/12/29 18:09:50 by kawish        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "state.h"

// void test(t_philo *philo, size_t i) 
// { 
// 	 // i: philosopher number, from 0 to N-1
// 	if (state[i] == State::HUNGRY && state[left(i)] != State::EATING && state[right(i)] != State::EATING) 
// 	{
// 		state[i] = State::EATING;
// 		both_forks_available[i].release();
// 	}
// }

// void	take_forks(t_philo *philo)
// {
// 	// enter critical region
// 	philo->state = HUNGRY; // is trying to take a fork
// 	printf("%ld %d has taken a fork\n", get_current_timestamp_in_ms() - philo->args->start_time, philo->id);
// 	test(philo); // try to acquire 2 forks
// 	// exit critical region
// 	// block if forks were not aquired
// }

/*
mutex forks
print timestamp_in_ms X is eating
simulate eating by sleeping for eat_duration?
put forks back on the table
start sleeping
*/
void	eat(t_philo *philo)
{
	usleep(philo->args->time_to_eat * 1000);
	printf("%ld %d is eating\n", get_current_timestamp_in_ms() - philo->args->start_time, philo->id);
}

void	philo_sleep(int i)
{
	printf("%ld %d is sleeping\n", get_current_timestamp_in_ms(), i);
}

void	has_died(int i)
{
	// timestamp_in_ms X died
	;
}

/*
1. Slaap time_to_sleep lang
2. Mutex lock standard out
3. Print message
*/
void	think(t_philo *philo)
{
	usleep(philo->args->time_to_sleep * 1000);
	printf("%ld %d is thinking\n", get_current_timestamp_in_ms() - philo->args->start_time, philo->id);
}
