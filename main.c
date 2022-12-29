#include "philo.h"
// Moet ik ook mutex gebruiken om stdout te locken?

size_t left(size_t i)
{
	return (i);
}

size_t right(size_t i, size_t num_of_philos)
{
	return ((i + 1) % num_of_philos);
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

t_philo	*init_philos(t_args *args)
{
	int		i;
	t_philo	*philos;

	philos = malloc(sizeof(*philos) * args->n_of_philos);
	if (!philos)
		return (0);
	i = 0;
	while (i < args->n_of_philos)
	{
		philos[i].id = i + 1;
		philos[i].state = THINKING; // wat is een philo zn oorspronkelijke staat? Thinking?
		philos[i].is_alive = true;
		philos[i].args = args;
		i++;
	}
	return (philos);
}

int main (int argc, const char *argv[5])
{
	t_args	args; // Moet sowieso op stack mem blijven.

	args.start_time = get_current_timestamp_in_ms();

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

	t_philo	*philos;
	philos = init_philos(&args);
	print_philos(philos, args.n_of_philos);

	think(&philos[0]);

	return (0);
}
