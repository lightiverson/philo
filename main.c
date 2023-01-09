#include "philo.h"
// Moet ik ook mutex gebruiken om stdout te locken?

t_args	parse_args(int argc, const char *argv[5])
{
	t_args	args;

	if (pthread_mutex_init(&args.critical_region, 0)) // If successful, pthread_mutex_init() will return zero and put the new mutex id into mutex, otherwise an error number will be returned to indicate the error.
	{
		ft_putendl_fd("Error: initializing mutex failed", STDERR_FILENO);
		// return (0);
	}
	args.has_died = false;
	args.n_of_philos = ft_atoi(argv[0]);
	args.time_to_die = ft_atoi(argv[1]);
	args.time_to_eat = ft_atoi(argv[2]);
	args.time_to_sleep = ft_atoi(argv[3]);
	args.number_of_times_to_eat = -1;
	if (argc == 6)
		args.number_of_times_to_eat = ft_atoi(argv[4]);
	return (args);
}

t_philo	*philos_init(t_args *args)
{
	int		i;
	t_philo	*philos;

	philos = malloc(sizeof(*philos) * args->n_of_philos);
	if (!philos)
	{
		ft_putendl_fd("Error: malloc() failed", STDERR_FILENO);
		return (0);
	}

	i = 0;
	while (i < args->n_of_philos)
	{
		philos[i].last_meal = 0;
		philos[i].id = i + 1;
		philos[i].state = THINKING; // wat is een philo zn oorspronkelijke staat? Thinking?
		philos[i].is_alive = true;
		philos[i].args = args;
		if (pthread_mutex_init(&(philos[i].fork), 0)) // If successful, pthread_mutex_init() will return zero and put the new mutex id into mutex, otherwise an error number will be returned to indicate the error.
		{
			ft_putendl_fd("Error: initializing mutex failed", STDERR_FILENO);
			return (0);
		}
		i++;
	}

	i = 0;
	args->start_time = get_current_timestamp_in_ms();
	while (i < args->n_of_philos)
	{
		if (pthread_create(&(philos[i].thread), 0, philosophize, (void*)&philos[i])) // If successful, pthread_mutex_init() will return zero and put the new mutex id into mutex, otherwise an error number will be returned to indicate the error.
		{
			ft_putendl_fd("Error: creating threads failed", STDERR_FILENO);
			return (0);
		}
		i++;
	}

	i = 0;
	while (i < args->n_of_philos)
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

int main (int argc, const char *argv[5])
{
	t_args	args; // Moet sowieso op stack mem blijven.
	t_philo	*philos;

	if (argc < 5 || argc > 6)
	{
		ft_putendl_fd("Error: incorrect amount of args", STDERR_FILENO);
		return (EXIT_FAILURE);
	}
	are_cla_valid(++argv);

	args = parse_args(argc, argv);
	if (!are_philo_mem_pos(&args))
	{
		ft_putendl_fd("Error: args are not postive numbers", STDERR_FILENO);
		return (EXIT_FAILURE);
	}
	print_args_struct(&args);

	philos = philos_init(&args);
	if (!philos)
	{
		ft_putendl_fd("Error: initializing philos failed", STDERR_FILENO);
		return (EXIT_FAILURE);
	}
	print_philos(philos, args.n_of_philos);

	return (0);
}

// ik moet checken of een philo gegeten heeft binnen 400ms nadat het programma gestart is.
// hiervoor heb je een variabel nodig -> timestamp wanneer voor het laatst gegeten.

// If a philosopher didn’t start eating time_to_die milliseconds since the beginning of their last meal or the beginning of the sim- ulation, they die.