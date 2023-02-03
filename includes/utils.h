/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utils.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: kawish <kawish@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/12/27 12:52:02 by kawish        #+#    #+#                 */
/*   Updated: 2023/02/03 16:26:02 by kgajadie      ########   odam.nl         */
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
void	print_args_struct(t_args args);
void	print_philo_struct(t_philo *philo);
void	print_philos(t_philo	*philos, int n_of_philos);
int		my_printf(t_philo *philo, const char *format, ...);
int		destroy(t_philo *philos, t_args args, t_shared *shared);

#endif
