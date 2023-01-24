/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utils.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: kawish <kawish@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/12/27 12:51:25 by kawish        #+#    #+#                 */
/*   Updated: 2023/01/24 14:29:35 by kgajadie      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void	print_args_struct(t_args args)
{
	printf("t_args args\n");
	printf("{\n");
	printf("\tn_of_philos = %d\n", args.n_of_philos);
	printf("\ttime_to_die = %d\n", args.time_to_die);
	printf("\ttime_to_eat = %d\n", args.time_to_eat);
	printf("\ttime_to_sleep = %d\n", args.time_to_sleep);
	printf("\tnumber_of_times_to_eat = %d\n", args.number_of_times_to_eat);
	printf("\tstart_time = %ld\n", args.start_time);
	printf("}\n\n");
}

void	print_philo_struct(t_philo *philo)
{
	printf("t_philo philo\n");
	printf("{\n");
	printf("\tlast_meal = %ld\n", philo->last_meal_timestamp);
	printf("\tid = %d\n", philo->id);
	// printf("\tfork = %p\n", &philo->fork);
	printf("}\n");
}

void	print_philos(t_philo	*philos, int n_of_philos)
{
	int	i;

	i = 0;
	while (i < n_of_philos)
	{
		print_philo_struct(&philos[i]);
		i++;
	}
}

int my_printf(t_philo *philo, const char *format, ...)
{
	int ret;
	va_list args;

	pthread_mutex_lock(&philo->shared->output_mtx);
	va_start(args, format);
	ret = vprintf(format, args);
	va_end(args);
	pthread_mutex_unlock(&philo->shared->output_mtx);

	return ret;
}
