/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   shared.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: kgajadie <kgajadie@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/27 11:07:06 by kgajadie      #+#    #+#                 */
/*   Updated: 2023/01/27 14:58:46 by kgajadie      ########   odam.nl         */
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
		free(shared);
		ft_putendl_fd("Error: calloc()", STDERR_FILENO);
		return (0);
	}
	shared->has_died = false;
	return (shared);
}

void	shared_destroy(t_shared *shared)
{
	free(shared->forks);
	free(shared);
}

int	forks_init(pthread_mutex_t *forks, int n_of_philos)
{
	int	i;

	i = 0;
	while (i < n_of_philos)
	{
		if (pthread_mutex_init(&forks[i], 0))
		{
			ft_putendl_fd("Error: mutex_init()", STDERR_FILENO);
			if (forks_destroy(forks, i))
				return (2);
			return (1);
		}
		i++;
	}
	return (0);
}

int	forks_destroy(pthread_mutex_t *forks, int n_init_forks)
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
