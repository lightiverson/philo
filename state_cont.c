/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   state_cont.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: kgajadie <kgajadie@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/12 15:13:45 by kgajadie      #+#    #+#                 */
/*   Updated: 2023/01/31 16:00:10 by kgajadie      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "state.h"

void	take_forks(t_philo *philo)
{
	pthread_mutex_lock(philo->left_fork);
	pthread_mutex_lock(philo->right_fork);
}

void	put_forks(t_philo *philo)
{
	pthread_mutex_unlock(philo->right_fork);
	pthread_mutex_unlock(philo->left_fork);
}

pthread_mutex_t	*left(t_philo *philo, int i)
{
	pthread_mutex_t	*left;

	left = &philo->shared->forks[i];
	return (left);
}

pthread_mutex_t	*right(t_philo *philo, int i)
{
	pthread_mutex_t	*right;

	right = &philo->shared->forks[(i + 1) % philo->args.n_of_philos];
	return (right);
}
