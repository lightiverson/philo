/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   monitor.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: kgajadie <kgajadie@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/18 11:53:20 by kgajadie      #+#    #+#                 */
/*   Updated: 2023/01/18 12:05:14 by kgajadie      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philos.h"

pthread_t	*monitor_init_start(t_philo *philos)
{
	pthread_t	*monitor;

	monitor = malloc(sizeof(*monitor));
	if (!monitor)
	{
		free(philos->shared);
		free(philos);
		ft_putendl_fd("Error: malloc()", STDERR_FILENO);
		return (0);
	}
	if (pthread_create(monitor, 0, monitor_routine, (void *)philos))
	{
		free(monitor);
		free(philos->shared);
		free(philos);
		ft_putendl_fd("Error: creating monitor thread failed", STDERR_FILENO);
		return (0);
	}
	return (monitor);
}

void	*monitor_routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	while (1)
	{
		pthread_mutex_lock(&philo->shared->critical_region_mtx);
		if (get_current_timestamp_in_ms()
			- philo->last_meal_timestamp >= philo->args.time_to_die)
		{
			pthread_mutex_unlock(&philo->shared->critical_region_mtx);
			has_died(philo);
			return (0);
		}
		pthread_mutex_unlock(&philo->shared->critical_region_mtx);
	}
}
