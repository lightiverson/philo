#include "philo.h"

void*	monitor(void* arg)
{
	t_philo	*philo;

	philo = (t_philo*)arg;

	while (1)
	{
		pthread_mutex_lock(&philo->shared->critical_region_mtx);
		if (philo->last_meal_timestamp - get_current_timestamp_in_ms() <= philo->args.time_to_die)
		{
			pthread_mutex_unlock(&philo->shared->critical_region_mtx);
			has_died(philo);
			return (0);
		}
		pthread_mutex_unlock(&philo->shared->critical_region_mtx);
	}
}

void*	philosophize(void* arg)
{
	t_philo	*philo;
	
	philo = (t_philo*)arg;

	// take_forks(p);
	// put_forks(p);

	// 0. loop zolang een philo niet is doodgegaan - maar kan een philo niet dood zijn gegaan terwijl een andere philo nog in de while loop zit?
	//     voeg nog check toe voor elke state functie om te kijken of een philo leeft
	// 1. check of time_to_die niet verstreken is sinds de start van het programma
	// 2.
	// voor elke state change wil ik checken of iemand is doodgegaan

	philo->args.start_time = get_current_timestamp_in_ms();
	while (!get_has_died_mutex(philo))
	{
		take_forks(philo);
		// state
		eat(philo);
		put_forks(philo);
		// state
		_sleep(philo);
		// state
		think(philo);
	}

	return (0);
}

t_args	parse_args(int argc, const char *argv[5])
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

t_shared *make_shared(void)
{
	t_shared	*shared;

	shared = malloc(sizeof(*shared));
	if (!shared)
	{
		ft_putendl_fd("Error: malloc() failed", STDERR_FILENO);
		return (0);
	}
	shared->has_died = false;
	if (pthread_mutex_init(&shared->critical_region_mtx, 0))
	{
		ft_putendl_fd("Error: initializing mutex failed", STDERR_FILENO);
		return (0);
	}
	if (pthread_mutex_init(&shared->output_mtx, 0))
	{
		ft_putendl_fd("Error: initializing mutex failed", STDERR_FILENO);
		return (0);
	}
	return (shared);
}

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
		philos[i].shared = shared;
		if (pthread_mutex_init(&(philos[i].fork), 0)) // If successful, pthread_mutex_init() will return zero and put the new mutex id into mutex, otherwise an error number will be returned to indicate the error.
		{
			ft_putendl_fd("Error: initializing mutex failed", STDERR_FILENO);
			return (0);
		}
		i++;
	}

	i = 0;
	while (i < args.n_of_philos)
	{
		if (pthread_create(&(philos[i].thread), 0, philosophize, (void*)&philos[i])) // If successful, pthread_mutex_init() will return zero and put the new mutex id into mutex, otherwise an error number will be returned to indicate the error.
		{
			ft_putendl_fd("Error: creating threads failed", STDERR_FILENO);
			return (0);
		}
		i++;
	}

	i = 0;
	while (i < args.n_of_philos)
	{
		if (pthread_join(philos[i].thread, 0)) // If successful, pthread_mutex_init() will return zero and put the new mutex id into mutex, otherwise an error number will be returned to indicate the error.
		{
			ft_putendl_fd("Error: creating threads failed", STDERR_FILENO);
			return (0);
		}
		i++;
	}

	return (philos);
}

pthread_t	*monitor_init(t_philo *philos)
{
	pthread_t	*thread;

	thread = malloc(sizeof(*thread));
	if (!thread)
	{
		ft_putendl_fd("Error: malloc()\n", STDERR_FILENO);
		return (0);
	}
	if (pthread_create(thread, 0, monitor, (void*)philos))
	{
		ft_putendl_fd("Error: creating threads failed", STDERR_FILENO);
		return (0);
	}
	if (pthread_join(*thread, 0))
	{
		ft_putendl_fd("Error: creating threads failed", STDERR_FILENO);
		return (0);
	}
	return (thread);
}

int	main (int argc, const char *argv[5])
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

	args = parse_args(argc, argv);
	if (!are_philo_mem_pos(args))
	{
		ft_putendl_fd("Error: args are not postive numbers", STDERR_FILENO);
		return (EXIT_FAILURE);
	}

	shared = make_shared();
	if (!shared)
	{
		ft_putendl_fd("Error: make_shared()", STDERR_FILENO);
		return (EXIT_FAILURE);
	}

	print_args_struct(args);

	philos = philos_init(args, shared);
	monitor_init(philos);
	if (!philos)
	{
		ft_putendl_fd("Error: initializing philos failed", STDERR_FILENO);
		return (EXIT_FAILURE);
	}
	// print_philos(philos, args.n_of_philos);

	return (0);
}

// Moet ik ook mutex gebruiken om stdout te locken?
