/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   timestamp.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: kgajadie <kgajadie@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/12/15 16:56:18 by kgajadie      #+#    #+#                 */
/*   Updated: 2023/02/03 11:57:13 by kgajadie      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef TIMESTAMP_H
# define TIMESTAMP_H

/* Public libraries */
# include <sys/time.h>
# include <unistd.h>

long	timeval_to_ms(struct timeval tv);
long	get_current_timestamp_in_ms(void);
// void	better_sleep(int miliseconds);
void	better_sleep(long time);

#endif