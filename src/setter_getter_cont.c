/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   setter_getter_cont.c                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: kgajadie <kgajadie@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/18 11:53:20 by kgajadie      #+#    #+#                 */
/*   Updated: 2023/02/14 13:47:41 by kgajadie      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "setter_getter.h"

long	get_last_meal(t_philo *philo)
{
	long	last_meal;

	pthread_mutex_lock(&philo->last_meal_mtx);
	last_meal = philo->last_meal;
	pthread_mutex_unlock(&philo->last_meal_mtx);
	return (last_meal);
}

void	set_last_meal(t_philo *philo)
{
	pthread_mutex_lock(&philo->last_meal_mtx);
	philo->last_meal = get_current_timestamp_in_ms();
	pthread_mutex_unlock(&philo->last_meal_mtx);
}
