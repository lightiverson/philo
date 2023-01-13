/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   state.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: kgajadie <kgajadie@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/12/21 17:45:35 by kgajadie      #+#    #+#                 */
/*   Updated: 2023/01/13 11:37:32 by kgajadie      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef STATE_H
# define STATE_H

/* Public libraries */
# include <stdio.h>
# include <unistd.h>

/* Private libraries */
# include "structs.h"
# include "timestamp.h"
# include "utils.h"

/* state_cont.c */
void	set_has_died_mutex(t_philo *philo);
bool	get_has_died_mutex(t_philo	*philo);
void	take_forks(t_philo *philo);
void	put_forks(t_philo *philo);
void	printf_mutex_lock(t_philo *philo, char *str);

/* state.c */
void	eat(t_philo *philo);
void	_sleep(t_philo *philo);
void	think(t_philo *philo);
void	has_died(t_philo *philo);

#endif
