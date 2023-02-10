/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   philos_last_meal.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: kgajadie <kgajadie@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/31 14:35:35 by kgajadie      #+#    #+#                 */
/*   Updated: 2023/02/10 12:23:13 by kgajadie      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philos.h"

// Deze is niet goed
int	philos_mtx_init(t_philo *philos, int n_of_philos)
{
	int	i;

	i = 0;
	while (i < n_of_philos)
	{
		if (pthread_mutex_init(&(philos[i].last_meal_mtx), 0))
		{
			ft_putendl_fd("Error: mutex_init()", STDERR_FILENO);
			if (philos_mtx_destroy(philos, i))
				return (2);
			return (1);
		}
		if (pthread_mutex_init(&(philos[i].meals_left_mtx), 0))
		{
			ft_putendl_fd("Error: mutex_init()", STDERR_FILENO);
			if (philos_mtx_destroy(philos, i))
				return (2);
			return (1);
		}
		i++;
	}
	return (0);
}

// Deze is niet goed
int	philos_mtx_destroy(t_philo *philos, int n_of_mtxs)
{
	int	i;

	i = 0;
	while (i < n_of_mtxs)
	{
		if (pthread_mutex_destroy(&philos[i].last_meal_mtx))
		{
			ft_putendl_fd("Error: mutex_destroy()", STDERR_FILENO);
			return (1);
		}
		if (pthread_mutex_destroy(&philos[i].meals_left_mtx))
		{
			ft_putendl_fd("Error: mutex_destroy()", STDERR_FILENO);
			return (1);
		}
		i++;
	}
	return (0);
}
