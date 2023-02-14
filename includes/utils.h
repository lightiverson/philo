/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utils.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: kawish <kawish@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/12/27 12:52:02 by kawish        #+#    #+#                 */
/*   Updated: 2023/02/14 18:07:13 by kgajadie      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

/* Private libraries */
# include "structs.h"
# include "ft_mini.h"
# include "philos.h"

/* Public libraries */
# include <unistd.h>
# include <stdio.h>
# include <stdarg.h>
# include <stdlib.h>

/* utils.c */
int			destroy(t_philo *philos, t_args args, t_shared *shared);
t_args		args_parse(int argc, const char *argv[5]);
t_monitor_d	d_init(t_philo *philos);

#endif
