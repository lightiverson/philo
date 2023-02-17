/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   philos.h                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: kgajadie <kgajadie@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/12/21 17:46:54 by kgajadie      #+#    #+#                 */
/*   Updated: 2023/02/14 14:30:29 by kgajadie      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOS_H
# define PHILOS_H

/* Private libraries */
# include "structs.h"
# include "state.h"
# include "timestamp.h"
# include "ft_mini.h"
# include "validate.h"
# include "utils.h"
# include "shared.h"
# include "setter_getter.h"

/* Public libraries */
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <pthread.h>

/* last_meal.c */
int		philos_last_meal_mtx_init(t_philo *philos, int n_philos);
int		philos_last_meal_mtx_destroy(t_philo *philos, int n_of_mtxs);
int		philos_meals_left_mtx_init(t_philo *philos, int n_philos);
int		philos_meals_left_mtx_destroy(t_philo *philos, int n_philos);

/* philos.c */
t_philo	*philos_init(t_args args, t_shared *shared);
int		philos_start(t_args args, t_philo *philos);
int		philos_join(t_args args, t_philo *philos);

/* main.c */
void	*philo_routine(void *arg);
void	*error_handle(char *err_msg, int lv, t_shared *shared, t_philo *philos);

#endif
