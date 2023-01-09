/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   structs.h                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: kgajadie <kgajadie@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/12/15 16:57:36 by kgajadie      #+#    #+#                 */
/*   Updated: 2023/01/01 18:56:44 by kawish        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

/* Public libraries */
# include <stdbool.h>
# include <pthread.h>
/* Private libraries */

/*
Dit kan je ook gebruiken om state bij te houden
typedef struct s_state
{
	bool	thinking
	bool	hungry
	bool	eating
	bool	sleeping
	bool	is_alive
}	t_state;
*/

enum e_state {
	THINKING = 0,
	HUNGRY = 1,
	EATING = 2,
	SLEEPING = 3,
};

typedef struct s_args
{
	pthread_mutex_t	critical_region;
	bool		has_died;
	int			n_of_philos;
	int			time_to_die;
	int			time_to_eat;
	int			time_to_sleep;
	int			number_of_times_to_eat;
	long int	start_time;
}	t_args;

typedef struct s_philo
{
	long int		last_meal;
	int				id;
	int				state;
	bool			is_alive;
	t_args			*args;
	pthread_mutex_t	fork;
	pthread_t		thread;
}	t_philo;

#endif
