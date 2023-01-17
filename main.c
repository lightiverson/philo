#include "philo.h"

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
			free(shared);
			free(philos);
			ft_putendl_fd("Error: pthread_mutex_init(fork)", STDERR_FILENO);
			return (0);
		}
		i++;
	}
	return (philos);
}

/*
if 1 -> exit
*/
int	philos_start(t_args args, t_philo *philos)
{
	int	i;

	i = 0;
	while (i < args.n_of_philos)
	{
		if (pthread_create(&(philos[i].thread), 0, philo_routine, (void*)&philos[i])) // If successful, pthread_mutex_init() will return zero and put the new mutex id into mutex, otherwise an error number will be returned to indicate the error.
		{
			free(philos[i].shared);
			free(philos);
			ft_putendl_fd("Error: pthread_create(thread)", STDERR_FILENO);
			return (0);
		}
		philos[i].last_meal_timestamp = get_current_timestamp_in_ms();
		i++;
	}
	return (1);
}

/*
if 0 -> exit
*/
pthread_t	*monitor_init_start(t_philo *philos)
{
	pthread_t	*monitor;

	monitor = malloc(sizeof(*monitor));
	if (!monitor)
	{
		free(philos->shared);
		free(philos);
		ft_putendl_fd("Error: malloc()", STDERR_FILENO);
		return (0);
	}
	if (pthread_create(monitor, 0, monitor_routine, (void*)philos))
	{
		free(monitor);
		free(philos->shared);
		free(philos);
		ft_putendl_fd("Error: creating monitor thread failed", STDERR_FILENO);
		return (0);
	}
	return (monitor);
}

/*
if 1 -> exit
*/
int	philos_monitor_join(t_args args, pthread_t *monitor, t_philo *philos)
{
	int	i;

	if (pthread_join(*monitor, 0))
	{
		free(monitor);
		free(philos->shared);
		free(philos);
		ft_putendl_fd("Error: joining monitor failed", STDERR_FILENO);
		return (1);
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
			return (1);
		}
		i++;
	}
	return (0);
}

void*	monitor_routine(void* arg)
{
	t_philo	*philo;

	philo = (t_philo*)arg;
	while (1)
	{
		pthread_mutex_lock(&philo->shared->critical_region_mtx);
		if (get_current_timestamp_in_ms() - philo->last_meal_timestamp >= philo->args.time_to_die)
		{
			pthread_mutex_unlock(&philo->shared->critical_region_mtx);
			has_died(philo);
			return (0);
		}
		pthread_mutex_unlock(&philo->shared->critical_region_mtx);
	}
}

void*	philo_routine(void* arg)
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
		// take_forks(philo);
		eat(philo);
		// put_forks(philo);
		_sleep(philo);
		think(philo);
	}

	return (0);
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
	philos_monitor_join(args, monitor, philos);
	if (!philos)
	{
		ft_putendl_fd("Error: initializing philos failed", STDERR_FILENO);
		return (EXIT_FAILURE);
	}
	// print_philos(philos, args.n_of_philos);

	return (0);
}

// Moet ik ook mutex gebruiken om stdout te locken?
