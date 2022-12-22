/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   state.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: kgajadie <kgajadie@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/12/21 17:46:06 by kgajadie      #+#    #+#                 */
/*   Updated: 2022/12/21 17:46:21 by kgajadie      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "state.h"

void	eat(size_t i)
{
	// mutex forks
	// print timestamp_in_ms X is eating
	printf("%ld %ld is eating\n", get_current_timestamp_in_ms(), i);
	// simulate eating by sleeping for eat_duration?
	// put forks back on the table
	// start sleeping
}

void	philo_sleep(size_t i)
{
	printf("%ld %ld is sleeping\n", get_current_timestamp_in_ms(), i);
}

void	has_died(size_t i)
{
	// timestamp_in_ms X died
	;
}

void	think(size_t i)
{
	printf("%ld %ld is thinking\n", get_current_timestamp_in_ms(), i);
}