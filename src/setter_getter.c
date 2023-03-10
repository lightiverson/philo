/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   setter_getter.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: kgajadie <kgajadie@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/18 11:53:20 by kgajadie      #+#    #+#                 */
/*   Updated: 2023/02/14 13:48:06 by kgajadie      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "setter_getter.h"

void	set_has_died(t_shared *shared)
{
	pthread_mutex_lock(&shared->has_died_mtx);
	shared->has_died = true;
	pthread_mutex_unlock(&shared->has_died_mtx);
}

bool	get_has_died(t_shared *shared)
{
	bool	has_died;

	pthread_mutex_lock(&shared->has_died_mtx);
	has_died = shared->has_died;
	pthread_mutex_unlock(&shared->has_died_mtx);
	return (has_died);
}

void	set_meals_left(t_philo *philo)
{
	pthread_mutex_lock(&philo->meals_left_mtx);
	philo->meals_left++;
	pthread_mutex_unlock(&philo->meals_left_mtx);
}

int	get_meals_left(t_philo *philo)
{
	int	meals_left;

	pthread_mutex_lock(&philo->meals_left_mtx);
	meals_left = philo->meals_left;
	pthread_mutex_unlock(&philo->meals_left_mtx);
	return (meals_left);
}
