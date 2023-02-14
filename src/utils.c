/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utils.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: kawish <kawish@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/12/27 12:51:25 by kawish        #+#    #+#                 */
/*   Updated: 2023/02/14 14:30:46 by kgajadie      ########   odam.nl         */
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
