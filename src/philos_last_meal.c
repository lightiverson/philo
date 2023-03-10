/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   philos_last_meal.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: kgajadie <kgajadie@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/31 14:35:35 by kgajadie      #+#    #+#                 */
/*   Updated: 2023/02/14 18:04:00 by kgajadie      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philos.h"

int	philos_last_meal_mtx_init(t_philo *philos, int n_philos)
{
	int	i;

	i = 0;
	while (i < n_philos)
	{
		if (pthread_mutex_init(&(philos[i].last_meal_mtx), 0))
		{
			ft_putendl_fd("Error: last_meal_mtx_init()", STDERR_FILENO);
			if (philos_last_meal_mtx_destroy(philos, i))
				return (2);
			return (1);
		}
		i++;
	}
	return (0);
}

int	philos_last_meal_mtx_destroy(t_philo *philos, int n_of_mtxs)
{
	int	i;

	i = 0;
	while (i < n_of_mtxs)
	{
		if (pthread_mutex_destroy(&philos[i].last_meal_mtx))
		{
			ft_putendl_fd("Error: last_meal_mtx_destroy()", STDERR_FILENO);
			return (1);
		}
		i++;
	}
	return (0);
}

int	philos_meals_left_mtx_init(t_philo *philos, int n_philos)
{
	int	i;

	i = 0;
	while (i < n_philos)
	{
		if (pthread_mutex_init(&(philos[i].meals_left_mtx), 0))
		{
			ft_putendl_fd("Error: meals_left_mtx_init()", STDERR_FILENO);
			if (philos_meals_left_mtx_destroy(philos, i))
				return (2);
			return (1);
		}
		i++;
	}
	return (0);
}

int	philos_meals_left_mtx_destroy(t_philo *philos, int n_of_mtxs)
{
	int	i;

	i = 0;
	while (i < n_of_mtxs)
	{
		if (pthread_mutex_destroy(&philos[i].meals_left_mtx))
		{
			ft_putendl_fd("Error: meals_left_mtx_destroy()", STDERR_FILENO);
			return (1);
		}
		i++;
	}
	return (0);
}
