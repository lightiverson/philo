/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   state.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: kgajadie <kgajadie@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/12/21 17:46:06 by kgajadie      #+#    #+#                 */
/*   Updated: 2022/12/27 13:50:29 by kawish        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "state.h"

void	eat(int i)
{
	// mutex forks
	// print timestamp_in_ms X is eating
	printf("%ld %d is eating\n", get_current_timestamp_in_ms(), i);
	// simulate eating by sleeping for eat_duration?
	// put forks back on the table
	// start sleeping
}

void	philo_sleep(int i)
{
	printf("%ld %d is sleeping\n", get_current_timestamp_in_ms(), i);
}

void	has_died(int i)
{
	// timestamp_in_ms X died
	;
}

void	think(t_philo *philo)
{
	printf("%ld %d is thinking\n", get_current_timestamp_in_ms() - philo->args->start_time, philo->id);
}