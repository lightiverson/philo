/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   philos.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: kgajadie <kgajadie@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/18 11:48:41 by kgajadie      #+#    #+#                 */
/*   Updated: 2023/01/24 12:06:40 by kgajadie      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philos.h"

int my_printf(t_philo *philo, const char *format, ...)
{
	int ret;
	va_list args;

	pthread_mutex_lock(&philo->shared->output_mtx);
	va_start(args, format);
	ret = vprintf(format, args);
	va_end(args);
	pthread_mutex_unlock(&philo->shared->output_mtx);

	return ret;
}

pthread_mutex_t	*left(t_philo *philo, int i)
{
	pthread_mutex_t *left;

	left = &philo->shared->forks[i];
	printf("Index of left fork is forks[%i]\n", i);
	return (left);
}

pthread_mutex_t	*right(t_philo *philo, int i)
{
	pthread_mutex_t *right;

	right = &philo->shared->forks[i + 1 % philo->args.n_of_philos];
	printf("Index of right fork is forks[%i]\n", i + 1 % philo->args.n_of_philos);
	return (right);
}

t_philo	*philos_init(t_args args, t_shared *shared)
{
	t_philo	*philos;
	int		i;

	// philos = malloc(sizeof(*philos) * args.n_of_philos);
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
		if (pthread_mutex_init(&(philos[i].last_meal_timestamp_mtx), 0))
		{
			free(shared);
			free(philos);
			ft_putendl_fd("Error: pthread_mutex_init(last_meal_timestamp_mtx)", STDERR_FILENO);
			return (0);
		}
		philos[i].shared = shared;
		philos[i].left_fork = left(&philos[i], i);
		philos[i].left_fork = right(&philos[i], i);
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
		philos[i].last_meal_timestamp = philos[i].args.start_time;
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
	// if (!(philo->id % 2))
	// {
	// 	usleep(100);
	// }
	// while (!get_has_died_mutex(philo))
	// {
	// 	// take_forks(philo);
	// 	eat(philo);
	// 	// put_forks(philo);
	// 	_sleep(philo);
	// 	think(philo);
	// }
	while (1)
	{
		if (get_has_died_mutex(philo))
			break;
		eat(philo);
		if (get_has_died_mutex(philo))
			break;
		_sleep(philo);
		if (get_has_died_mutex(philo))
			break;
		think(philo);
	}
	return (0);
}
