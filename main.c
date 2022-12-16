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

bool	str_is_numeric(const char *str)
{
	char			*arr;
	unsigned int	i;

	i = 0;
	if (str[0] == '-')
		i++;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (false);
		i++;
	}
	arr = ft_itoa(ft_atoi(str));
	if (!arr)
	{
		printf("Error: malloc()\n");
		return (false);
	}
	if (ft_strlen(str) != ft_strlen(arr))
	{
		free(arr);
		return (false);
	}
	free(arr);
	return (true);
}

t_args	*parse_cla(int argc, const char *argv[5])
{
	t_args	*args;

	args = malloc(sizeof(*args));
	if (!args)
		return (0);
	args->n_of_philos = argv[1];
	args->time_to_die = argv[2];
	args->time_to_eat = argv[3];
	args->time_to_sleep = argv[4];
	args->number_of_times_to_eat = -1;
	if (argc == 6)
		args->number_of_times_to_eat = argv[5];
	return (args);
}

bool	is_valid_cla(const char *arg)
{
	if (!(*arg))
	{
		printf("No empty strings allowed\n");
		return (false);
	}
	if (!str_is_numeric(arg))
	{
		printf("Only numeric characters are accepted\n");
		return (false);
	}
}

int main (int argc, const char *argv[5])
{
	// size_t i = 0;
	// think(i);
	// eat(i);
	// sleep(i);

	t_args	*args;

	if (argc < 5 || argc > 6) // correct amount of args
		return (-1);

	args = parse_args(argc, argv);
	if (!args)
		return (-1);


	return (0);
}
