/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   timestamp.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: kgajadie <kgajadie@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/12/15 16:56:39 by kgajadie      #+#    #+#                 */
/*   Updated: 2022/12/15 16:57:27 by kgajadie      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "timestamp.h"

unsigned long	timeval_to_ms(struct timeval tv)
{
	return (tv.tv_sec * 1000 + tv.tv_usec / 1000);
}

unsigned long	get_current_timestamp_in_ms(void)
{
	struct timeval	current_time;

	gettimeofday(&current_time, 0);
	return (timeval_to_ms(current_time));
}