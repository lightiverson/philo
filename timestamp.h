/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   timestamp.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: kgajadie <kgajadie@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/12/15 16:56:18 by kgajadie      #+#    #+#                 */
/*   Updated: 2022/12/29 16:49:29 by kawish        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef TIMESTAMP_H
# define TIMESTAMP_H

/* Public libraries */
# include <sys/time.h>

long int	timeval_to_ms(struct timeval tv);
long int	get_current_timestamp_in_ms(void);

#endif