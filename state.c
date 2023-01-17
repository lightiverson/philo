/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   state.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: kgajadie <kgajadie@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/12/21 17:46:06 by kgajadie      #+#    #+#                 */
/*   Updated: 2023/01/17 17:25:42 by kgajadie      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "state.h"

void	eat(t_philo *philo)
{
	print_state(philo, "%ld\t%d\tis eating\n");
	better_sleep(philo->args.time_to_eat);
	pthread_mutex_lock(&philo->shared->critical_region_mtx);
	philo->last_meal_timestamp = get_current_timestamp_in_ms();
	pthread_mutex_unlock(&philo->shared->critical_region_mtx);
}

void	_sleep(t_philo *philo)
{
	print_state(philo, "%ld\t%d\tis sleeping\n");
	better_sleep(philo->args.time_to_sleep);
}

void	think(t_philo *philo)
{
	print_state(philo, "%ld\t%d\tis thinking\n");
}

void	has_died(t_philo *philo)
{
	print_state(philo, "%ld\t%d\tdied\n");
}
