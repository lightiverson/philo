/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utils.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: kawish <kawish@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/12/27 12:52:02 by kawish        #+#    #+#                 */
/*   Updated: 2023/01/12 10:17:34 by kgajadie      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include "structs.h"
# include <stdio.h>

void	print_args_struct(t_args args);
void	print_philo_struct(t_philo *philo);
void	print_philos(t_philo	*philos, int n_of_philos);

#endif
