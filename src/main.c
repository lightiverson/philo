/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: kgajadie <kgajadie@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/24 16:16:45 by kgajadie      #+#    #+#                 */
/*   Updated: 2023/02/07 10:36:07 by kgajadie      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philos.h"

t_args	args_parse(int argc, const char *argv[5])
{
	t_args	args;

	args.n_of_philos = ft_atoi(argv[0]);
	args.time_to_die = ft_atoi(argv[1]);
	args.time_to_eat = ft_atoi(argv[2]);
	args.time_to_sleep = ft_atoi(argv[3]);
	args.number_of_times_to_eat = 1;
	if (argc == 6)
		args.number_of_times_to_eat = ft_atoi(argv[4]);
	return (args);
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
				set_has_died(philos->shared);
				has_died(&philos[i]);
				return ;
			}
			i++;
		}
		i = 0;
	}
}

void	*philo_routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	while (1)
	{
		if (get_has_died(philo->shared))
			break ;
		take_forks(philo);
		eat(philo);
		put_forks(philo);
		if (get_has_died(philo->shared))
			break ;
		_sleep(philo);
		if (get_has_died(philo->shared))
			break ;
		think(philo);
	}
	return (0);
}

void	*error_handle(char *err_msg, int lv, t_shared *shared, t_philo *philos)
{
	int	n;

	ft_putendl_fd(err_msg, STDERR_FILENO);
	if (!philos)
		return (0);
	n = philos->args.n_of_philos;
	if (lv >= 6)
		philos_last_meal_mtx_destroy(philos, n);
	if (lv >= 5)
		free(philos);
	if (lv >= 4)
		pthread_mutex_destroy(&shared->has_died_mtx);
	if (lv >= 3)
		pthread_mutex_destroy(&shared->output_mtx);
	if (lv >= 2)
		shared_forks_destroy(shared->forks, n);
	if (lv >= 1)
	{
		free(shared->forks);
		free(shared);
	}
	return (0);
}

int	main(int argc, const char *argv[5])
{
	t_args		args;
	t_philo		*philos;
	t_shared	*shared;

	philos = 0;
	shared = 0;
	if (argc < 5 || argc > 6)
		return ((int)error_handle("Error: arg count", 0, shared, philos));
	are_cla_valid(++argv);
	args = args_parse(argc, argv);
	print_args_struct(args);
	if (!are_philo_mem_pos(args))
		return ((int)error_handle("Error: non pos args", 0, shared, philos));
	shared = shared_init(args);
	if (!shared)
		return ((int)error_handle("Error: shared_init()", 0, shared, philos));
	philos = philos_init(args, shared);
	if (!philos)
		return ((int)error_handle("Error: philos_init()", 0, shared, philos));
	if (philos_start(args, philos))
		return ((int)error_handle("Error: philos_start()", 6, shared, philos));
	monitor(philos);
	if (philos_join(args, philos))
		return ((int)error_handle("Error: philos_join()", 6, shared, philos));
	return (destroy(philos, args, shared));
}

// voeg check toe aan sleep functie