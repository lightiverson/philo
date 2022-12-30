/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   state.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: kgajadie <kgajadie@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/12/21 17:46:06 by kgajadie      #+#    #+#                 */
/*   Updated: 2022/12/30 14:29:37 by kawish        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "state.h"

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
	(void)i;
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

// think(&philos[0]);
// take_forks(&philos[0]);
// eat(&philos[0]);
void*	philosophize(void* arg)
{
	t_philo	*p;
	
	p = (t_philo*)arg;
	think(p);
	return (0);
}
