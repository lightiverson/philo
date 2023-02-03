/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   timestamp.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: kgajadie <kgajadie@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/12/15 16:56:39 by kgajadie      #+#    #+#                 */
/*   Updated: 2023/02/03 11:56:35 by kgajadie      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "timestamp.h"

long	timeval_to_ms(struct timeval tv)
{
	return (tv.tv_sec * 1000 + tv.tv_usec / 1000);
}

/*
Voeg error check toe voor getttimeofday, of niet:)
*/
long	get_current_timestamp_in_ms(void)
{
	struct timeval	current_time;

	gettimeofday(&current_time, 0);
	return (timeval_to_ms(current_time));
}

// void	better_sleep(int miliseconds)
// {
// 	long	target_time;

// 	target_time = get_current_timestamp_in_ms() + miliseconds;
// 	while (get_current_timestamp_in_ms() < target_time)
// 		usleep(100);
// }

long	timestamp(void)
{
	struct timeval	tv;
	long			milliseconds;

	gettimeofday(&tv, NULL);
	milliseconds = (tv.tv_sec) * 1000 + (tv.tv_usec) / 1000;
	return (milliseconds);
}

void	better_sleep(long time)
{
	long	current_time;

	current_time = timestamp();
	while (timestamp() < current_time + time)
		usleep(time);
}