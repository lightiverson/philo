/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   monitor.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: kgajadie <kgajadie@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/18 11:53:20 by kgajadie      #+#    #+#                 */
/*   Updated: 2023/01/24 12:08:15 by kgajadie      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philos.h"

// verander arg set_has_died naar shared_data ipv philo
void	monitor(t_philo *philos)
{
	int		i;
	int		n;

	i = 0;
	n = philos->args.n_of_philos;
	while (1)
	{
		while (i < n)
		{
			if (get_current_timestamp_in_ms() - get_last_meal_timestamp(&philos[i]) > philos[i].args.time_to_die)
			{
				has_died(&philos[i]);
				set_has_died_mutex(&philos[i]);
				return ;
			}
			i++;
		}
		i = 0;
	}
}
