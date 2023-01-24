/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   state.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: kgajadie <kgajadie@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/12/21 17:45:35 by kgajadie      #+#    #+#                 */
/*   Updated: 2023/01/24 15:25:50 by kgajadie      ########   odam.nl         */
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

/* state_cont.c */
void	print_state(t_philo *philo, char *str);
void	set_last_meal_timestamp(t_philo *philo);
bool	get_has_died_mutex(t_shared *shared);
void	take_forks(t_philo *philo);
void	put_forks(t_philo *philo);

/* state.c */
void	eat(t_philo *philo);
void	_sleep(t_philo *philo);
void	think(t_philo *philo);
void	has_died(t_philo *philo);

#endif
