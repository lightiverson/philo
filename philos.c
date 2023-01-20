/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   philos.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: kgajadie <kgajadie@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/18 11:48:41 by kgajadie      #+#    #+#                 */
/*   Updated: 2023/01/20 14:45:09 by kgajadie      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philos.h"

t_philo	*philos_init(t_args args, t_shared *shared)
{
	t_philo	*philos;
	int		i;

	philos = malloc(sizeof(*philos) * args.n_of_philos);
	if (!philos)
	{
		ft_putendl_fd("Error: malloc() failed", STDERR_FILENO);
		return (0);
	}
	i = 0;
	while (i < args.n_of_philos)
	{
		philos[i].id = i + 1;
		philos[i].args = args;
		philos[i].last_meal_timestamp = 0;
		if (pthread_mutex_init(&(philos[i].last_meal_timestamp_mtx), 0))
		{
			free(shared);
			free(philos);
			ft_putendl_fd("Error: pthread_mutex_init(last_meal_timestamp_mtx)", STDERR_FILENO);
			return (0);
		}
		philos[i].shared = shared;
		if (pthread_mutex_init(&(philos[i].fork), 0))
		{
			free(shared);
			free(philos);
			ft_putendl_fd("Error: pthread_mutex_init(fork)", STDERR_FILENO);
			return (0);
		}
		i++;
	}
	return (philos);
}

int	philos_start(t_args args, t_philo *philos)
{
	int	i;

	i = 0;
	while (i < args.n_of_philos)
	{
		philos[i].args.start_time = get_current_timestamp_in_ms();
		philos[i].last_meal_timestamp = get_current_timestamp_in_ms();
		if (pthread_create(&(philos[i].thread), 0,
			philo_routine, (void *)&philos[i]))
		{
			free(philos[i].shared);
			free(philos);
			ft_putendl_fd("Error: pthread_create(thread)", STDERR_FILENO);
			return (0);
		}
		i++;
	}
	return (1);
}

void	*philo_routine(void* arg)
{
	t_philo	*philo;
	
	philo = (t_philo *)arg;
	if (!(philo->id % 2))
	{
		usleep(100);
	}
	while (!get_has_died_mutex(philo))
	{
		take_forks(philo);
		eat(philo);
		put_forks(philo);
		_sleep(philo);
		think(philo);
	}
	return (0);
}
