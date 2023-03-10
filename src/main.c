/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: kgajadie <kgajadie@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/24 16:16:45 by kgajadie      #+#    #+#                 */
/*   Updated: 2023/02/17 14:57:58 by kgajadie      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philos.h"

static void	monitor_inner(int *done_eating, t_philo *philo)
{
	*done_eating = *done_eating + 1;
	set_meals_left(philo);
}

static void	monitor(t_philo *philos)
{
	t_monitor_d	d;

	d = d_init(philos);
	while (1)
	{
		while (d.i < d.n_philos)
		{
			d.philo = &philos[d.i];
			if ((d.n_times_to_eat != -1) && (get_meals_left(d.philo)
					== d.n_times_to_eat))
				monitor_inner(&d.done_eating, d.philo);
			if (get_current_timestamp_in_ms() - get_last_meal(d.philo)
				> d.time_to_die || d.done_eating == d.n_philos)
			{
				set_has_died(philos->shared);
				if ((d.n_times_to_eat != -1) && (get_meals_left(d.philo)
						> d.n_times_to_eat))
					return ;
				has_died(d.philo);
				return ;
			}
			d.i++;
		}
		d.i = 0;
	}
}

void	*philo_routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	if (philo->args.n_philos == 1)
		return (0);
	if (philo->id % 2 == 0)
		better_sleep(philo->args.time_to_eat);
	while (1)
	{
		if (get_has_died(philo->shared))
			break ;
		take_forks(philo);
		eat(philo);
		put_forks(philo);
		set_meals_left(philo);
		if (get_has_died(philo->shared))
			break ;
		_sleep(philo);
		if (get_has_died(philo->shared))
			break ;
		think(philo);
	}
	return (0);
}

void	*error_handle(char *err_msg, int lv, t_shared *shared, t_philo *philos)
{
	int	n;

	ft_putendl_fd(err_msg, STDERR_FILENO);
	if (!philos)
		return (0);
	n = philos->args.n_philos;
	if (lv >= 7)
		philos_meals_left_mtx_destroy(philos, n);
	if (lv >= 6)
		philos_last_meal_mtx_destroy(philos, n);
	if (lv >= 5)
		free(philos);
	if (lv >= 4)
		pthread_mutex_destroy(&shared->has_died_mtx);
	if (lv >= 3)
		pthread_mutex_destroy(&shared->output_mtx);
	if (lv >= 2)
		shared_forks_destroy(shared->forks, n);
	if (lv >= 1)
	{
		free(shared->forks);
		free(shared);
	}
	return (0);
}

int	main(int argc, const char *argv[5])
{
	t_args		args;
	t_philo		*philos;
	t_shared	*shared;

	philos = 0;
	shared = 0;
	if (argc < 5 || argc > 6)
		return ((int)error_handle("Error: arg count", 0, shared, philos));
	if (!are_cla_valid(++argv))
		return ((int)error_handle("Error: invalid cla(s)", 0, shared, philos));
	args = args_parse(argc, argv);
	if (!are_args_mem_valid(args))
		return ((int)error_handle("Error: invalid args", 0, shared, philos));
	shared = shared_init(args);
	if (!shared)
		return ((int)error_handle("Error: shared_init()", 0, shared, philos));
	philos = philos_init(args, shared);
	if (!philos)
		return ((int)error_handle("Error: philos_init()", 0, shared, philos));
	if (philos_start(args, philos))
		return ((int)error_handle("Error: philos_start()", 7, shared, philos));
	monitor(philos);
	if (philos_join(args, philos))
		return ((int)error_handle("Error: philos_join()", 7, shared, philos));
	return (destroy(philos, args, shared));
}
