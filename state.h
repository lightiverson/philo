/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   state.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: kgajadie <kgajadie@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/12/21 17:45:35 by kgajadie      #+#    #+#                 */
/*   Updated: 2022/12/21 17:45:51 by kgajadie      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef STATE_H
# define STATE_H

/* Public libraries */
# include <stdio.h>

/* Private libraries */
# include "timestamp.h"

void	eat(size_t i);
void	philo_sleep(size_t i);
void	has_died(size_t i);
void	think(size_t i);

#endif