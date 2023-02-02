/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   state.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: kgajadie <kgajadie@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/12/21 17:45:35 by kgajadie      #+#    #+#                 */
/*   Updated: 2023/02/02 19:32:14 by kgajadie      ########   odam.nl         */
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
# include "libft/libft.h"
# include "setter_getter.h"

/* state_cont.c */
void			take_forks(t_philo *philo);
void			put_forks(t_philo *philo);
pthread_mutex_t	*left(t_philo *philo, int i);
pthread_mutex_t	*right(t_philo *philo, int i);

/* state.c */
void			print_state(t_philo *philo, char *str);
void			eat(t_philo *philo);
void			_sleep(t_philo *philo);
void			think(t_philo *philo);
void			has_died(t_philo *philo);

#endif
