/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   structs.h                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: kgajadie <kgajadie@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/12/15 16:57:36 by kgajadie      #+#    #+#                 */
/*   Updated: 2022/12/15 16:58:32 by kgajadie      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

/* Private libraries */
#include "philo.h"

enum e_state {
	THINKING = 0,
	HUNGRY = 1,
	EATING = 2,
	SLEEPING = 3,
};

typedef struct s_philosopher
{
	size_t	time_to_die;
	size_t	time_to_eat;
	size_t	time_to_sleep;
	size_t	number_of_times_to_eat;
	size_t	number;
	int		state;
}	t_philosopher;

#endif
