/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: kgajadie <kgajadie@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/24 16:16:45 by kgajadie      #+#    #+#                 */
/*   Updated: 2023/02/02 10:43:08 by kgajadie      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philos.h"
#include "setter_getter.h"

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
	if (!(philo->id % 2))
	{
		better_sleep(philo->args.time_to_eat);
	}
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

int	error_handle(char *err_msg, int lv, t_shared *shared, t_philo *philos)
{
	int	n;

	n = philos->args.n_of_philos;
	ft_putendl_fd(err_msg, STDERR_FILENO);
	if (lv > 2)
		philos_destroy(philos, n);
	if (lv > 1)
		forks_destroy(shared->forks, n);
	if (lv > 0)
		shared_destroy(shared);
	return (EXIT_FAILURE);
}

int	destroy(t_philo *philos, t_args args, t_shared *shared)
{
	philos_destroy(philos, args.n_of_philos);
	forks_destroy(shared->forks, args.n_of_philos);
	shared_destroy(shared);
	return (EXIT_SUCCESS);
}

int	main(int argc, const char *argv[5])
{
	t_args		args;
	t_philo		*philos;
	t_shared	*shared;

	if (argc < 5 || argc > 6)
		return (error_handle("Error: incorrect amount of args", 0, shared, philos));
	are_cla_valid(++argv);
	args = args_parse(argc, argv);
	if (!are_philo_mem_pos(args))
		return (error_handle("Error: args are not postive numbers", 0, shared, philos));
	shared = shared_init(args);
	if (!shared)
		return (error_handle("Error: shared_init()", 0, shared, philos));
	if (forks_init(shared->forks, args.n_of_philos))
		return (error_handle("Error: forks_init()", 1, shared, philos));
	philos = philos_init(args, shared);
	if (!philos)
		return (error_handle("Error: philos_init()", 2, shared, philos));
	if (last_meal_mtx_init(philos, args.n_of_philos))
		return (error_handle("Error: last_meal_mtx_init()", 3, shared, philos));
	if (philos_start(args, philos))
		return (error_handle("Error: philos_start()", 3, shared, philos));
	monitor(philos);
	if (philos_join(args, philos))
		return (error_handle("Error: philos_join()", 3, shared, philos));
	return (destroy);
}
