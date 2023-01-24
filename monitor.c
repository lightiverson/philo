/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   monitor.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: kgajadie <kgajadie@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/18 11:53:20 by kgajadie      #+#    #+#                 */
/*   Updated: 2023/01/24 15:14:58 by kgajadie      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philos.h"

void	set_has_died_mutex(t_shared *shared)
{
	pthread_mutex_lock(&shared->has_died_mtx);
	shared->has_died = true;
	pthread_mutex_unlock(&shared->has_died_mtx);
}

long	get_last_meal_timestamp(t_philo *philo)
{
	long	last_meal_timestamp;

	pthread_mutex_lock(&philo->last_meal_timestamp_mtx);
	last_meal_timestamp = philo->last_meal_timestamp;
	pthread_mutex_unlock(&philo->last_meal_timestamp_mtx);
	return (last_meal_timestamp);
}

void	monitor(t_philo *philos)
{
	int		i;
	int		n;

	i = 0;
	n = philos->args.n_of_philos;
	while (1)
	{
		while (i < n)
		{
			if (get_current_timestamp_in_ms()
				- get_last_meal_timestamp(&philos[i])
				> philos[i].args.time_to_die)
			{
				set_has_died_mutex(philos->shared);
				has_died(&philos[i]);
				return ;
			}
			i++;
		}
		i = 0;
	}
}
