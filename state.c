/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   state.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: kgajadie <kgajadie@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/12/21 17:46:06 by kgajadie      #+#    #+#                 */
/*   Updated: 2023/01/12 13:58:15 by kgajadie      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "state.h"

void set_has_died_mutex(t_philo *philo)
{
	pthread_mutex_lock(&philo->shared->critical_region);
	philo->shared->has_died = true;
	pthread_mutex_unlock(&philo->shared->critical_region);
}

bool get_has_died_mutex(t_philo	*philo)
{
	bool	has_died;

	pthread_mutex_lock(&philo->shared->critical_region);
	has_died = philo->shared->has_died;
	pthread_mutex_unlock(&philo->shared->critical_region);
	return (has_died);
}

bool has_starved(t_philo *philo)
{
	return (get_current_timestamp_in_ms() - philo->last_meal > philo->args.time_to_die);
}

void	eat(t_philo *philo)
{
	if (philo->last_meal && has_starved(philo))
	{
		set_has_died_mutex(philo);
		return;
	}
	printf("%ld\t%d\tis eating\n", get_current_timestamp_in_ms() - philo->args.start_time, philo->id);
	usleep(philo->args.time_to_eat * 1000);
	philo->last_meal = get_current_timestamp_in_ms();
}

void	_sleep(t_philo *philo)
{
	if (philo->last_meal && has_starved(philo))
	{
		set_has_died_mutex(philo);
		return;
	}
	printf("%ld\t%d\tis sleeping\n", get_current_timestamp_in_ms() - philo->args.start_time, philo->id);
	usleep(philo->args.time_to_sleep * 1000);
}

void	think(t_philo *philo)
{
	if (philo->last_meal && has_starved(philo))
	{
		set_has_died_mutex(philo);
		return;
	}
	printf("%ld\t%d\tis thinking\n", get_current_timestamp_in_ms() - philo->args.start_time, philo->id);
}

void	has_died(t_philo *philo)
{
	printf("%ld\t%d\tdied\n", get_current_timestamp_in_ms() - philo->args.start_time, philo->id);
}

void take_forks(t_philo *philo)
{
	int		i_philo;
	int		i_philo_right;
	t_philo	*arr_start;
	t_philo	*philo_right;

	i_philo = philo->id - 1;
	i_philo_right = (i_philo + 1) % philo->args.n_of_philos;
	arr_start = philo - i_philo;
	philo_right = &arr_start[i_philo_right];

	printf("%ld\t%d\tis trying to take forks\n", get_current_timestamp_in_ms() - philo->args.start_time, philo->id);

	// Pick up left fork
	pthread_mutex_lock(&philo->fork);
	// Pick up right fork
	pthread_mutex_lock(&philo_right->fork);
}

void put_forks(t_philo *philo)
{
	int		i_philo;
	int		i_philo_right;
	t_philo	*arr_start;
	t_philo	*philo_right;

	i_philo = philo->id - 1;
	i_philo_right = (i_philo + 1) % philo->args.n_of_philos;
	arr_start = philo - i_philo;
	philo_right = &arr_start[i_philo_right];

	// Put down right fork
	pthread_mutex_unlock(&philo_right->fork);
	// Put down left fork
	pthread_mutex_unlock(&philo->fork);
}

void*	philosophize(void* arg)
{
	t_philo	*philo;
	
	philo = (t_philo*)arg;

	// take_forks(p);
	// put_forks(p);

	// 0. loop zolang een philo niet is doodgegaan - maar kan een philo niet dood zijn gegaan terwijl een andere philo nog in de while loop zit?
	//     voeg nog check toe voor elke state functie om te kijken of een philo leeft
	// 1. check of time_to_die niet verstreken is sinds de start van het programma
	// 2.

	philo->args.start_time = get_current_timestamp_in_ms();
	if (get_current_timestamp_in_ms() - philo->args.start_time > philo->args.time_to_die)
		set_has_died_mutex(philo);
	while (true)
	{
		if (get_has_died_mutex(philo))
			break ;
		eat(philo);
		if (get_has_died_mutex(philo))
			break ;
		_sleep(philo);
		if (get_has_died_mutex(philo))
			break ;
		think(philo);
	}

	return (0);
}
