/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   state_cont.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: kgajadie <kgajadie@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/12 15:13:45 by kgajadie      #+#    #+#                 */
/*   Updated: 2023/01/24 12:12:15 by kgajadie      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "state.h"

void	print_state(t_philo *philo, char *str)
{
	if (get_has_died_mutex(philo))
		return ;
	pthread_mutex_lock(&philo->shared->output_mtx);
	printf("%ld\t%d\t%s\n", get_current_timestamp_in_ms() - philo->args.start_time, philo->id, str);
	pthread_mutex_unlock(&philo->shared->output_mtx);
}

void	set_last_meal_timestamp(t_philo *philo)
{
	pthread_mutex_lock(&philo->last_meal_timestamp_mtx);
	philo->last_meal_timestamp = get_current_timestamp_in_ms();
	pthread_mutex_unlock(&philo->last_meal_timestamp_mtx);
}

long	get_last_meal_timestamp(t_philo *philo)
{
	long	last_meal_timestamp;

	pthread_mutex_lock(&philo->last_meal_timestamp_mtx);
	last_meal_timestamp = philo->last_meal_timestamp;
	pthread_mutex_unlock(&philo->last_meal_timestamp_mtx);
	return (last_meal_timestamp);
}

void	set_has_died_mutex(t_philo *philo)
{
	pthread_mutex_lock(&philo->shared->has_died_mtx);
	philo->shared->has_died = true;
	pthread_mutex_unlock(&philo->shared->has_died_mtx);
}

bool	get_has_died_mutex(t_philo	*philo)
{
	bool	has_died;

	pthread_mutex_lock(&philo->shared->has_died_mtx);
	has_died = philo->shared->has_died;
	pthread_mutex_unlock(&philo->shared->has_died_mtx);
	return (has_died);
}

// void	take_forks(t_philo *philo)
// {
// 	int		i_philo;
// 	int		i_philo_right;
// 	t_philo	*arr_start;
// 	t_philo	*philo_right;

// 	i_philo = philo->id - 1;
// 	i_philo_right = (i_philo + 1) % philo->args.n_of_philos;
// 	arr_start = philo - i_philo;
// 	philo_right = &arr_start[i_philo_right];

// 	// Pick up left fork
// 	pthread_mutex_lock(&philo->fork);
// 	print_state(philo, "Has taken left fork");
// 	// Pick up right fork
// 	pthread_mutex_lock(&philo_right->fork);
// 	print_state(philo, "Has taken right fork");
// }

// void	put_forks(t_philo *philo)
// {
// 	int		i_philo;
// 	int		i_philo_right;
// 	t_philo	*arr_start;
// 	t_philo	*philo_right;

// 	i_philo = philo->id - 1;
// 	i_philo_right = (i_philo + 1) % philo->args.n_of_philos;
// 	arr_start = philo - i_philo;
// 	philo_right = &arr_start[i_philo_right];

// 	// Put down right fork
// 	pthread_mutex_unlock(&philo_right->fork);
// 	print_state(philo, "Has put down right fork");
// 	// Put down left fork
// 	pthread_mutex_unlock(&philo->fork);
// 	print_state(philo, "Has put down left fork");
// }
