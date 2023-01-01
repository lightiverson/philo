/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   state.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: kgajadie <kgajadie@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/12/21 17:45:35 by kgajadie      #+#    #+#                 */
/*   Updated: 2023/01/01 17:17:56 by kawish        ########   odam.nl         */
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

void	eat(t_philo *philo);
void	_sleep(t_philo *philo);
void	has_died(t_philo *philo);
void	think(t_philo *philo);
void*	philosophize(void* arg);

#endif