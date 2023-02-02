/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   shared.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: kgajadie <kgajadie@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/27 11:07:06 by kgajadie      #+#    #+#                 */
/*   Updated: 2023/02/02 18:54:34 by kgajadie      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "shared.h"

t_shared	*shared_init(t_args args)
{
	t_shared	*shared;

	shared = ft_calloc(1, sizeof(*shared));
	if (!shared)
	{
		ft_putendl_fd("Error: ft_calloc()", STDERR_FILENO);
		return (0);
	}
	shared->forks = ft_calloc(args.n_of_philos, sizeof(*shared->forks));
	if (!shared->forks)
	{
		ft_putendl_fd("Error: ft_calloc()", STDERR_FILENO);
		free(shared);
		return (0);
	}
	shared->has_died = false;
	if (shared_forks_init(shared->forks, args.n_of_philos))
	{
		ft_putendl_fd("Error: shared_forks_init()", STDERR_FILENO);
		free(shared->forks);
		free(shared);
		return (0);
	}
	return (shared);
}

int	shared_forks_init(pthread_mutex_t *forks, int n_of_philos)
{
	int	i;

	i = 0;
	while (i < n_of_philos)
	{
		if (pthread_mutex_init(&forks[i], 0))
		{
			ft_putendl_fd("Error: mutex_init()", STDERR_FILENO);
			if (shared_forks_destroy(forks, i))
				return (2);
			return (1);
		}
		i++;
	}
	return (0);
}

int	shared_forks_destroy(pthread_mutex_t *forks, int n_init_forks)
{
	int	i;

	i = 0;
	while (i < n_init_forks)
	{
		if (pthread_mutex_destroy(&forks[i]))
		{
			ft_putendl_fd("Error: mutex_destroy()", STDERR_FILENO);
			return (1);
		}
		i++;
	}
	return (0);
}
