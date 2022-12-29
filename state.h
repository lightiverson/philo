/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   state.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: kgajadie <kgajadie@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/12/21 17:45:35 by kgajadie      #+#    #+#                 */
/*   Updated: 2022/12/27 13:44:12 by kawish        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef STATE_H
# define STATE_H

/* Public libraries */
# include <stdio.h>

/* Private libraries */
# include "structs.h"
# include "timestamp.h"

void	eat(int i);
void	philo_sleep(int i);
void	has_died(int i);
void	think(t_philo *philo);

#endif