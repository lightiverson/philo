/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   structs.h                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: kgajadie <kgajadie@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/12/15 16:57:36 by kgajadie      #+#    #+#                 */
/*   Updated: 2023/01/13 11:24:42 by kgajadie      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

/* Public libraries */
# include <stdbool.h>
# include <pthread.h>

/* Private libraries */

typedef struct s_shared
{
	pthread_mutex_t	critical_region_mtx;
	pthread_mutex_t	output_mtx;
	bool			has_died;
}	t_shared;

typedef struct s_args
{
	int			n_of_philos;
	int			time_to_die;
	int			time_to_eat;
	int			time_to_sleep;
	int			number_of_times_to_eat;
	long int	start_time;
}	t_args;

typedef struct s_philo
{
	int				id;
	t_args			args;
	long int		last_meal_timestamp;
	t_shared		*shared;
	pthread_mutex_t	fork;
	pthread_t		thread;
}	t_philo;

#endif
