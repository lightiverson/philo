/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   setter_getter.h                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: kgajadie <kgajadie@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/31 16:05:56 by kgajadie      #+#    #+#                 */
/*   Updated: 2023/02/10 10:47:20 by kgajadie      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef SETTER_GETTER_H
# define SETTER_GETTER_H

/* Private libraries */
# include "structs.h"
# include "timestamp.h"

/* setter_getter.h */
void	set_has_died(t_shared *shared);
bool	get_has_died(t_shared *shared);
int		get_meals_left(t_philo *philo);
void	set_meals_left(t_philo *philo);
long	get_last_meal(t_philo *philo);
void	set_last_meal(t_philo *philo);

#endif
