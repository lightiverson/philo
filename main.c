/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: kgajadie <kgajadie@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/24 16:16:45 by kgajadie      #+#    #+#                 */
/*   Updated: 2023/01/31 17:20:05 by kgajadie      ########   odam.nl         */
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

int	main(int argc, const char *argv[5])
{
	t_args		args;
	t_philo		*philos;
	t_shared	*shared;

	if (argc < 5 || argc > 6)
		return (log_and_exit("Error: incorrect amount of args"));

	are_cla_valid(++argv);

	args = args_parse(argc, argv);
	if (!are_philo_mem_pos(args))
		return (log_and_exit("Error: args are not postive numbers"));

	shared = shared_init(args);
	if (!shared)
		return (log_and_exit("Error: shared_init()"));

	if (forks_init(shared->forks, args.n_of_philos))
	{
		ft_putendl_fd("Error: forks_init()", STDERR_FILENO);
		shared_destroy(shared);
		return (EXIT_FAILURE);
	}

	print_args_struct(args);

	philos = philos_init(args, shared);
	if (!philos)
	{
		ft_putendl_fd("Error: philos_init()", STDERR_FILENO);
		forks_destroy(shared->forks, args.n_of_philos);
		shared_destroy(shared);
		return (EXIT_FAILURE);
	}

	if (last_meal_mtx_init(philos, args.n_of_philos))
	{
		ft_putendl_fd("Error: last_meal_mtx_init()", STDERR_FILENO);
		philos_destroy(philos, args.n_of_philos);
		forks_destroy(shared->forks, args.n_of_philos);
		shared_destroy(shared);
		return (EXIT_FAILURE);
	}

	if (!philos_start(args, philos))
	{
		ft_putendl_fd("Error: philos_start()", STDERR_FILENO);
		// voeg error management en cleanup toe
		return (EXIT_FAILURE);
	}

	monitor(philos);

	if (philos_join(args, philos))
	{
		ft_putendl_fd("Error: philos_join()", STDERR_FILENO);
		// voeg error management en cleanup toe
		return (EXIT_FAILURE);
	}

	philos_destroy(philos, args.n_of_philos);
	forks_destroy(shared->forks, args.n_of_philos);
	shared_destroy(shared);
	return (0);
}
