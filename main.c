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

void	print_args_struct(t_args *args)
{
	printf("t_args args\n");
	printf("{\n");
	printf("\tn_of_philos = %d\n", args->n_of_philos);
	printf("\ttime_to_die = %d\n", args->time_to_die);
	printf("\ttime_to_eat = %d\n", args->time_to_eat);
	printf("\ttime_to_sleep = %d\n", args->time_to_sleep);
	printf("\tnumber_of_times_to_eat = %d\n", args->number_of_times_to_eat);
	printf("}\n");
}

void	print_philo_struct(t_philo *philo)
{
	printf("t_philo philo\n");
	printf("{\n");
	printf("\tstate = %d\n", philo->state);
	printf("\tis_alive = %d\n", philo->is_alive);
	printf("\t*args = %p\n", philo->args);
	printf("}\n");
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
		philos[i].state = THINKING; // wat is een philo zn oorspronkelijke staat? Thinking?
		philos[i].is_alive = true;
		philos[i].args = args;
		i++;
	}
	return (philos);
}

int main (int argc, const char *argv[5])
{
	if (argc < 5 || argc > 6) // correct amount of args
	{
		ft_putendl_fd("Error: incorrect amount of args", STDERR_FILENO);
		return (EXIT_FAILURE);
	}

	are_cla_valid(++argv);

	t_args	args;
	args = parse_args(argc, argv);
	if (!are_philo_mem_pos(&args))
	{
		ft_putendl_fd("Error: args are not postive numbers", STDERR_FILENO);
		return (EXIT_FAILURE);
	}
	print_args_struct(&args);

	t_philo	*philos;
	philos = init_philos(&args);
	print_philo_struct(philos);

	return (0);
}
