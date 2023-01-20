/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   philos.h                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: kgajadie <kgajadie@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/12/21 17:46:54 by kgajadie      #+#    #+#                 */
/*   Updated: 2023/01/19 16:56:01 by kgajadie      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOS_H
# define PHILOS_H

/* Private libraries */
# include "structs.h"
# include "state.h"
# include "timestamp.h"
# include "libft/libft.h"
# include "validate.h"
# include "utils.h"

/* Public libraries */
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <pthread.h>

/* monitor.c */
void	monitor(t_philo *philos);

/* philos.c */
t_philo		*philos_init(t_args args, t_shared *shared);
int			philos_start(t_args args, t_philo *philos);
void		*philo_routine(void *arg);

#endif
