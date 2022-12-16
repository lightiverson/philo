/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   timestamp.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: kgajadie <kgajadie@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/12/15 16:56:18 by kgajadie      #+#    #+#                 */
/*   Updated: 2022/12/15 16:56:29 by kgajadie      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef TIMESTAMP_H
# define TIMESTAMP_H

/* Public libraries */
# include <sys/time.h>

unsigned long	timeval_to_ms(struct timeval tv);
unsigned long	get_current_timestamp_in_ms(void);

#endif