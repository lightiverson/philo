/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: kgajadie <kgajadie@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/24 16:16:45 by kgajadie      #+#    #+#                 */
/*   Updated: 2023/01/27 14:57:30 by kgajadie      ########   odam.nl         */
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

int	philos_join(t_args args, t_philo *philos)
{
	int	i;

	i = 0;
	while (i < args.n_of_philos)
	{
		if (pthread_join(philos[i].thread, 0))
		{
			ft_putendl_fd("Error: joining philos failed", STDERR_FILENO);
			return (0);
		}
		i++;
	}
	return (1);
}

int	main(int argc, const char *argv[5])
{
	t_args		args;
	t_philo		*philos;
	t_shared	*shared;

	if (argc < 5 || argc > 6)
	{
		ft_putendl_fd("Error: incorrect amount of args", STDERR_FILENO);
		return (EXIT_FAILURE);
	}
	are_cla_valid(++argv);

	args = args_parse(argc, argv);
	if (!are_philo_mem_pos(args))
	{
		ft_putendl_fd("Error: args are not postive numbers", STDERR_FILENO);
		return (EXIT_FAILURE);
	}

	shared = shared_init(args);
	if (!shared)
	{
		ft_putendl_fd("Error: shared_init()", STDERR_FILENO);
		return (EXIT_FAILURE);
	}

	if (forks_init(shared->forks, args.n_of_philos))
	{
		shared_destroy(shared);
		ft_putendl_fd("Error: forks_init()", STDERR_FILENO);
		return (EXIT_FAILURE);
	}

	print_args_struct(args);

	philos = philos_init(args, shared);
	if (!philos)
	{
		ft_putendl_fd("Error: philos_init()", STDERR_FILENO);
		return (EXIT_FAILURE);
	}

	if (!philos_start(args, philos))
	{
		ft_putendl_fd("Error: philos_start()", STDERR_FILENO);
		return (EXIT_FAILURE);
	}

	monitor(philos);

	if (!philos_join(args, philos))
	{
		ft_putendl_fd("Error: philos_join()", STDERR_FILENO);
		return (EXIT_FAILURE);
	}

	return (0);
}
