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

t_shared *shared_init(void)
{
	t_shared	*shared;

	shared = malloc(sizeof(*shared));
	if (!shared)
	{
		ft_putendl_fd("Error: malloc()", STDERR_FILENO);
		return (0);
	}
	shared->has_died = false;
	if (pthread_mutex_init(&shared->critical_region_mtx, 0))
	{
		free(shared);
		ft_putendl_fd("Error: pthread_mutex_init(critical_region_mtx)", STDERR_FILENO);
		return (0);
	}
	if (pthread_mutex_init(&shared->output_mtx, 0))
	{
		free(shared);
		ft_putendl_fd("Error: pthread_mutex_init(output_mtx)", STDERR_FILENO);
		return (0);
	}
	return (shared);
}

int	philos_monitor_join(t_args args, pthread_t *monitor, t_philo *philos)
{
	int	i;

	if (pthread_join(*monitor, 0))
	{
		free(monitor);
		free(philos->shared);
		free(philos);
		ft_putendl_fd("Error: joining monitor failed", STDERR_FILENO);
		return (0);
	}
	i = 0;
	while (i < args.n_of_philos)
	{
		if (pthread_join(philos[i].thread, 0)) // If successful, pthread_mutex_init() will return zero and put the new mutex id into mutex, otherwise an error number will be returned to indicate the error.
		{
			free(monitor);
			free(philos->shared);
			free(philos);
			ft_putendl_fd("Error: joining philos failed", STDERR_FILENO);
			return (0);
		}
		i++;
	}
	return (1);
}

int	main (int argc, const char *argv[5])
{
	t_args		args;
	t_philo		*philos;
	t_shared	*shared;
	pthread_t	*monitor;

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

	shared = shared_init();
	if (!shared)
	{
		ft_putendl_fd("Error: shared_init()", STDERR_FILENO);
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

	monitor = monitor_init_start(philos);
	if (!monitor)
	{
		ft_putendl_fd("Error: monitor_init_start()", STDERR_FILENO);
		return (EXIT_FAILURE);
	}

	if(!philos_monitor_join(args, monitor, philos))
	{
		ft_putendl_fd("Error: philos_monitor_join()", STDERR_FILENO);
		return (EXIT_FAILURE);
	}

	if (!philos)
	{
		ft_putendl_fd("Error: initializing philos failed", STDERR_FILENO);
		return (EXIT_FAILURE);
	}
	// print_philos(philos, args.n_of_philos);

	return (0);
}

// Moet ik ook mutex gebruiken om stdout te locken?
