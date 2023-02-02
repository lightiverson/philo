/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   philos.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: kgajadie <kgajadie@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/18 11:48:41 by kgajadie      #+#    #+#                 */
/*   Updated: 2023/01/31 17:25:02 by kgajadie      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philos.h"

t_philo	*philos_init(t_args args, t_shared *shared)
{
	t_philo	*philos;
	int		i;

	philos = ft_calloc(args.n_of_philos, sizeof(*philos));
	if (!philos)
	{
		ft_putendl_fd("Error: ft_calloc() failed", STDERR_FILENO);
		return (0);
	}
	i = 0;
	while (i < args.n_of_philos)
	{
		philos[i].id = i + 1;
		philos[i].args = args;
		philos[i].last_meal = 0;
		philos[i].shared = shared;
		philos[i].left_fork = left(&philos[i], i);
		philos[i].right_fork = right(&philos[i], i);
		i++;
	}
	return (philos);
}

int	philos_destroy(t_philo *philos, int n_of_philos)
{
	int	i;

	i = 0;
	while (i < n_of_philos)
	{
		free(&philos[i]);
		i++;
	}
	return (0);
}

int	philos_start(t_args args, t_philo *philos)
{
	int		i;
	long	start_time;

	i = 0;
	start_time = get_current_timestamp_in_ms();
	while (i < args.n_of_philos)
	{
		philos[i].args.start_time = start_time;
		philos[i].last_meal = start_time;
		if (pthread_create(&(philos[i].thread), 0,
				philo_routine, (void *)&philos[i]))
		{
			ft_putendl_fd("Error: pthread_create(thread)", STDERR_FILENO);
			return (1);
		}
		i++;
	}
	return (0);
}

int	philos_join(t_args args, t_philo *philos)
{
	int	i;

	i = 0;
	while (i < args.n_of_philos)
	{
		if (pthread_join(philos[i].thread, 0))
		{
			ft_putendl_fd("Error: joining philos failed", STDERR_FILENO);
			return (1);
		}
		i++;
	}
	return (0);
}
