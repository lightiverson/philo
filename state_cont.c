/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   state_cont.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: kgajadie <kgajadie@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/12 15:13:45 by kgajadie      #+#    #+#                 */
/*   Updated: 2023/01/24 15:25:41 by kgajadie      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "state.h"

void	print_state(t_philo *philo, char *str)
{
	pthread_mutex_lock(&philo->shared->output_mtx);
	if (!get_has_died_mutex(philo->shared))
		printf("%ld\t%d\t%s\n", get_current_timestamp_in_ms() - philo->args.start_time, philo->id, str);
	else if (!ft_strncmp(str, "died", 5))
		printf("%ld\t%d\t%s\n", get_current_timestamp_in_ms() - philo->args.start_time, philo->id, str);
	pthread_mutex_unlock(&philo->shared->output_mtx);
}

void	set_last_meal_timestamp(t_philo *philo)
{
	pthread_mutex_lock(&philo->last_meal_timestamp_mtx);
	philo->last_meal_timestamp = get_current_timestamp_in_ms();
	pthread_mutex_unlock(&philo->last_meal_timestamp_mtx);
}

bool	get_has_died_mutex(t_shared *shared)
{
	bool	has_died;

	pthread_mutex_lock(&shared->has_died_mtx);
	has_died = shared->has_died;
	pthread_mutex_unlock(&shared->has_died_mtx);
	return (has_died);
}

void	take_forks(t_philo *philo)
{
	// Pick up left fork
	pthread_mutex_lock(philo->left_fork);
	// print_state(philo, "Has taken left fork");
	// Pick up right fork
	pthread_mutex_lock(philo->right_fork);
	// print_state(philo, "Has taken right fork");
}

void	put_forks(t_philo *philo)
{
	// Put down right fork
	pthread_mutex_unlock(philo->right_fork);
	// print_state(philo, "Has put down right fork");
	// Put down left fork
	pthread_mutex_unlock(philo->left_fork);
	// print_state(philo, "Has put down left fork");
}
