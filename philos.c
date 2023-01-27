/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   philos.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: kgajadie <kgajadie@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/18 11:48:41 by kgajadie      #+#    #+#                 */
/*   Updated: 2023/01/27 15:27:54 by kgajadie      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philos.h"

pthread_mutex_t	*left(t_philo *philo, int i)
{
	pthread_mutex_t	*left;

	left = &philo->shared->forks[i];
	return (left);
}

pthread_mutex_t	*right(t_philo *philo, int i)
{
	pthread_mutex_t	*right;

	right = &philo->shared->forks[(i + 1) % philo->args.n_of_philos];
	return (right);
}

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
		philos[i].last_meal_timestamp = 0;
		philos[i].shared = shared;
		philos[i].left_fork = left(&philos[i], i);
		philos[i].right_fork = right(&philos[i], i);
		i++;
	}
	return (philos);
}

int	last_meal_timestamp_mtxs_init(t_philo *philos, int n_of_philos)
{
	int	i;

	i = 0;
	while (i < n_of_philos)
	{
		if (pthread_mutex_init(&(philos[i].last_meal_timestamp_mtx), 0))
		{
			ft_putendl_fd("Error: mutex_init()", STDERR_FILENO);
			if (last_meal_timestamp_mtxs_destroy(philos, i))
				return (2);
			return (1);
		}
		i++;
	}
	return (0);
}

int	last_meal_timestamp_mtxs_destroy(t_philo *philos, int n_of_mtxs)
{
	int	i;

	i = 0;
	while (i < n_of_mtxs)
	{
		if (pthread_mutex_destroy(&philos[i].last_meal_timestamp_mtx))
		{
			ft_putendl_fd("Error: mutex_destroy()", STDERR_FILENO);
			return (1);
		}
		i++;
	}
	return (0);
}


// t_philo	*philos_init(t_args args, t_shared *shared)
// {
// 	t_philo	*philos;
// 	int		i;

// 	philos = ft_calloc(args.n_of_philos, sizeof(*philos));
// 	if (!philos)
// 	{
// 		ft_putendl_fd("Error: ft_calloc() failed", STDERR_FILENO);
// 		return (0);
// 	}
// 	i = 0;
// 	while (i < args.n_of_philos)
// 	{
// 		philos[i].id = i + 1;
// 		philos[i].args = args;
// 		philos[i].last_meal_timestamp = 0;
// 		if (pthread_mutex_init(&(philos[i].last_meal_timestamp_mtx), 0))
// 		{
// 			ft_putendl_fd("Error: pthread_mutex_init()", STDERR_FILENO);
// 			return (0);
// 		}
// 		philos[i].shared = shared;
// 		philos[i].left_fork = left(&philos[i], i);
// 		philos[i].right_fork = right(&philos[i], i);
// 		i++;
// 	}
// 	return (philos);
// }

int	philos_start(t_args args, t_philo *philos)
{
	int		i;
	long	start_time;

	i = 0;
	start_time = get_current_timestamp_in_ms();
	while (i < args.n_of_philos)
	{
		philos[i].args.start_time = start_time;
		philos[i].last_meal_timestamp = start_time;
		if (pthread_create(&(philos[i].thread), 0,
				philo_routine, (void *)&philos[i]))
		{
			ft_putendl_fd("Error: pthread_create(thread)", STDERR_FILENO);
			return (0);
		}
		i++;
	}
	return (1);
}

void	*philo_routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	if (!(philo->id % 2))
	{
		better_sleep(philo->args.time_to_eat);
	}
	while (1)
	{
		if (get_has_died_mutex(philo->shared))
			break ;
		take_forks(philo);
		eat(philo);
		put_forks(philo);
		if (get_has_died_mutex(philo->shared))
			break ;
		_sleep(philo);
		if (get_has_died_mutex(philo->shared))
			break ;
		think(philo);
	}
	return (0);
}
