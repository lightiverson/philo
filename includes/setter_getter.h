/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   setter_getter.h                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: kgajadie <kgajadie@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/31 16:05:56 by kgajadie      #+#    #+#                 */
/*   Updated: 2023/02/14 13:48:53 by kgajadie      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef SETTER_GETTER_H
# define SETTER_GETTER_H

/* Private libraries */
# include "structs.h"
# include "timestamp.h"

/* setter_getter.c */
void	set_has_died(t_shared *shared);
bool	get_has_died(t_shared *shared);
void	set_meals_left(t_philo *philo);
int		get_meals_left(t_philo *philo);

/* setter_getter_cont.c */
long	get_last_meal(t_philo *philo);
void	set_last_meal(t_philo *philo);

#endif
