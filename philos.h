/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   philos.h                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: kgajadie <kgajadie@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/12/21 17:46:54 by kgajadie      #+#    #+#                 */
/*   Updated: 2023/01/31 16:13:04 by kgajadie      ########   odam.nl         */
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
# include "shared.h"

/* Public libraries */
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <pthread.h>

/* last_meal.c */
int		last_meal_mtx_init(t_philo *philos, int n_of_philos);
int		last_meal_mtx_destroy(t_philo *philos, int n_of_mtxs);

/* philos.c */
t_philo	*philos_init(t_args args, t_shared *shared);
int		philos_destroy(t_philo *philos, int n_of_philos);
int		philos_start(t_args args, t_philo *philos);
int		philos_join(t_args args, t_philo *philos);

/* main.c */
void	*philo_routine(void *arg);

#endif
