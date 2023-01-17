/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   timestamp.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: kgajadie <kgajadie@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/12/15 16:56:39 by kgajadie      #+#    #+#                 */
/*   Updated: 2023/01/17 17:04:43 by kgajadie      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "timestamp.h"

long	timeval_to_ms(struct timeval tv)
{
	return (tv.tv_sec * 1000 + tv.tv_usec / 1000);
}

long	get_current_timestamp_in_ms(void)
{
	struct timeval	current_time;

	gettimeofday(&current_time, 0);
	// Hoe error check je gettimeofday?
	return (timeval_to_ms(current_time));
}

void	better_sleep(int miliseconds)
{
	long	target_time;

	target_time = get_current_timestamp_in_ms() + miliseconds;
	while (get_current_timestamp_in_ms() < target_time)
		usleep(100);
}
