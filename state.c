/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   state.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: kgajadie <kgajadie@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/12/21 17:46:06 by kgajadie      #+#    #+#                 */
/*   Updated: 2023/01/01 18:36:34 by kawish        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "state.h"

void	_sleep_think(t_philo *philo)
{
	if (philo->last_meal && (get_current_timestamp_in_ms() - philo->last_meal > philo->args->time_to_die))
	{
		has_died(philo);
		philo->args->has_died = true;
		return;
	}
	printf("%ld\t%d\tis sleeping\n", get_current_timestamp_in_ms() - philo->args->start_time, philo->id);
	usleep(philo->args->time_to_sleep * 1000);
	printf("%ld\t%d\tis thinking\n", get_current_timestamp_in_ms() - philo->args->start_time, philo->id);
}

void	has_died(t_philo *philo)
{
	printf("%ld\t%d\tdied\n", get_current_timestamp_in_ms() - philo->args->start_time, philo->id);
}

void take_forks(t_philo *philo)
{
	int		i_philo;
	int		i_philo_right;
	t_philo	*arr_start;
	t_philo	*philo_right;

	i_philo = philo->id - 1;
	i_philo_right = (i_philo + 1) % philo->args->n_of_philos;
	arr_start = philo - i_philo;
	philo_right = &arr_start[i_philo_right];

	printf("%ld\t%d\tis trying to take forks\n", get_current_timestamp_in_ms() - philo->args->start_time, philo->id);

	// Pick up left fork
	pthread_mutex_lock(&philo->fork);
	// Pick up right fork
	pthread_mutex_lock(&philo_right->fork);
}

void	eat(t_philo *philo)
{
	if (philo->last_meal && (get_current_timestamp_in_ms() - philo->last_meal > philo->args->time_to_die))
	{
		has_died(philo);
		philo->args->has_died = true;
		return;
	}
	printf("%ld\t%d\tis eating\n", get_current_timestamp_in_ms() - philo->args->start_time, philo->id);
	usleep(philo->args->time_to_eat * 1000);
	philo->last_meal = get_current_timestamp_in_ms();
}

void put_forks(t_philo *philo)
{
	int		i_philo;
	int		i_philo_right;
	t_philo	*arr_start;
	t_philo	*philo_right;

	i_philo = philo->id - 1;
	i_philo_right = (i_philo + 1) % philo->args->n_of_philos;
	arr_start = philo - i_philo;
	philo_right = &arr_start[i_philo_right];

	// Put down right fork
	pthread_mutex_unlock(&philo_right->fork);
	// Put down left fork
	pthread_mutex_unlock(&philo->fork);
}

void*	philosophize(void* arg)
{
	t_philo	*p;
	
	p = (t_philo*)arg;

	// take_forks(p);
	// put_forks(p);

	if (get_current_timestamp_in_ms() - p->args->start_time > p->args->time_to_die)
	{
		p->args->has_died = true;
		has_died(p);
	}
	if (!p->args->has_died)
		eat(p);
	if (!p->args->has_died)
		_sleep_think(p);

	return (0);
}
