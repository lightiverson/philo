/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: kgajadie <kgajadie@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/24 16:16:45 by kgajadie      #+#    #+#                 */
/*   Updated: 2023/02/10 15:54:48 by kgajadie      ########   odam.nl         */
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
	args.number_of_times_to_eat = -1;
	if (argc == 6)
		args.number_of_times_to_eat = ft_atoi(argv[4]);
	return (args);
}

void	monitor(t_philo *philos)
{
	int		i;
	int		n;
	int		philos_done_eating;
	t_args	args;

	args = philos->args;
	i = 0;
	n = philos->args.n_of_philos;
	philos_done_eating = 0;
	while (1)
	{
		while (i < n)
		{
			pthread_mutex_lock(&philos[i].meals_left_mtx);
			if ((args.number_of_times_to_eat != -1) && (philos[i].meals_left == args.number_of_times_to_eat))
			{
				philos_done_eating++;
				philos[i].meals_left++;
			}
			pthread_mutex_unlock(&philos[i].meals_left_mtx);
			if (get_current_timestamp_in_ms() - get_last_meal(&philos[i]) > args.time_to_die || philos_done_eating == n)
			{
				set_has_died(philos->shared);
				if ((args.number_of_times_to_eat != -1) && (get_meals_left(&philos[i]) > args.number_of_times_to_eat))
					return ;
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
	if (philo->args.n_of_philos == 1)
	{
		while (get_has_died(philo->shared))
			break ;
		return (0);
	}
	while (!get_has_died(philo->shared))
	{
		take_forks(philo);
		eat(philo);
		put_forks(philo);
		set_meals_left(philo);
		_sleep(philo);
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
	if (lv >= 7)
		philos_meals_left_mtx_destroy(philos, n);
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
	if (!are_cla_valid(++argv))
		return ((int)error_handle("Error: invalid cla(s)", 0, shared, philos));
	args = args_parse(argc, argv);
	if (!are_args_mem_valid(args))
		return ((int)error_handle("Error: invalid args", 0, shared, philos));
	// print_args_struct(args);
	shared = shared_init(args);
	if (!shared)
		return ((int)error_handle("Error: shared_init()", 0, shared, philos));
	philos = philos_init(args, shared);
	if (!philos)
		return ((int)error_handle("Error: philos_init()", 0, shared, philos));
	if (philos_start(args, philos))
		return ((int)error_handle("Error: philos_start()", 7, shared, philos));
	monitor(philos);
	if (philos_join(args, philos))
		return ((int)error_handle("Error: philos_join()", 7, shared, philos));
	return (destroy(philos, args, shared));
}
