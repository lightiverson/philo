/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utils.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: kawish <kawish@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/12/27 12:51:25 by kawish        #+#    #+#                 */
/*   Updated: 2023/02/14 16:30:08 by kgajadie      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void	print_args_struct(t_args args)
{
	printf("t_args args\n");
	printf("{\n");
	printf("\tn_of_philos = %d\n", args.n_philos);
	printf("\ttime_to_die = %d\n", args.time_to_die);
	printf("\ttime_to_eat = %d\n", args.time_to_eat);
	printf("\ttime_to_sleep = %d\n", args.time_to_sleep);
	printf("\tnumber_of_times_to_eat = %d\n", args.n_times_to_eat);
	printf("\tstart_time = %ld\n", args.start_time);
	printf("}\n\n");
}

void	print_philo_struct(t_philo *philo)
{
	printf("t_philo philo\n");
	printf("{\n");
	printf("\tid = %d\n", philo->id);
	printf("\tlast_meal = %ld\n", philo->last_meal);
	printf("}\n");
}

void	print_philos(t_philo	*philos, int n_philos)
{
	int	i;

	i = 0;
	while (i < n_philos)
	{
		print_philo_struct(&philos[i]);
		i++;
	}
}

int	my_printf(t_philo *philo, const char *format, ...)
{
	int		ret;
	va_list	args;

	pthread_mutex_lock(&philo->shared->output_mtx);
	va_start(args, format);
	ret = vprintf(format, args);
	va_end(args);
	pthread_mutex_unlock(&philo->shared->output_mtx);
	return (ret);
}

int	destroy(t_philo *philos, t_args args, t_shared *shared)
{
	philos_meals_left_mtx_destroy(philos, args.n_philos);
	philos_last_meal_mtx_destroy(philos, args.n_philos);
	free(philos);
	pthread_mutex_destroy(&shared->has_died_mtx);
	pthread_mutex_destroy(&shared->output_mtx);
	shared_forks_destroy(shared->forks, args.n_philos);
	free(shared->forks);
	free(shared);
	return (0);
}

t_args	args_parse(int argc, const char *argv[5])
{
	t_args	args;

	args.n_philos = ft_atoi(argv[0]);
	args.time_to_die = ft_atoi(argv[1]);
	args.time_to_eat = ft_atoi(argv[2]);
	args.time_to_sleep = ft_atoi(argv[3]);
	args.n_times_to_eat = -1;
	if (argc == 6)
		args.n_times_to_eat = ft_atoi(argv[4]);
	return (args);
}

t_monitor_d	d_init(t_philo *philos)
{
	t_monitor_d	d;

	d.i = 0;
	d.done_eating = 0;
	d.n_philos = philos->args.n_philos;
	d.n_times_to_eat = philos->args.n_times_to_eat;
	d.time_to_die = philos->args.time_to_die;
	return (d);
}
