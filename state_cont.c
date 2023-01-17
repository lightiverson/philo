/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   state_cont.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: kgajadie <kgajadie@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/12 15:13:45 by kgajadie      #+#    #+#                 */
/*   Updated: 2023/01/17 17:25:42 by kgajadie      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "state.h"

void	print_state(t_philo *philo, char *str)
{
	pthread_mutex_lock(&philo->shared->output_mtx);
	printf(str, get_current_timestamp_in_ms() - philo->args.start_time,
		philo->id);
	pthread_mutex_unlock(&philo->shared->output_mtx);
}

void	set_has_died_mutex(t_philo *philo)
{
	pthread_mutex_lock(&philo->shared->critical_region_mtx);
	if (!philo->shared->has_died)
		has_died(philo);
	philo->shared->has_died = true;
	pthread_mutex_unlock(&philo->shared->critical_region_mtx);
}

bool	get_has_died_mutex(t_philo	*philo)
{
	bool	has_died;

	pthread_mutex_lock(&philo->shared->critical_region_mtx);
	has_died = philo->shared->has_died;
	pthread_mutex_unlock(&philo->shared->critical_region_mtx);
	return (has_died);
}

void	take_forks(t_philo *philo)
{
	int		i_philo;
	int		i_philo_right;
	t_philo	*arr_start;
	t_philo	*philo_right;

	i_philo = philo->id - 1;
	i_philo_right = (i_philo + 1) % philo->args.n_of_philos;
	arr_start = philo - i_philo;
	philo_right = &arr_start[i_philo_right];

	// Pick up left fork
	pthread_mutex_lock(&philo->fork);
	// Pick up right fork
	pthread_mutex_lock(&philo_right->fork);
}

void	put_forks(t_philo *philo)
{
	int		i_philo;
	int		i_philo_right;
	t_philo	*arr_start;
	t_philo	*philo_right;

	i_philo = philo->id - 1;
	i_philo_right = (i_philo + 1) % philo->args.n_of_philos;
	arr_start = philo - i_philo;
	philo_right = &arr_start[i_philo_right];

	// Put down right fork
	pthread_mutex_unlock(&philo_right->fork);
	// Put down left fork
	pthread_mutex_unlock(&philo->fork);
}
