/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   structs.h                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: kgajadie <kgajadie@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/12/15 16:57:36 by kgajadie      #+#    #+#                 */
/*   Updated: 2023/02/09 10:41:50 by kgajadie      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

/* Public libraries */
# include <stdbool.h>
# include <pthread.h>

typedef struct s_shared
{
	bool			has_died;
	pthread_mutex_t	has_died_mtx;
	pthread_mutex_t	output_mtx;
	pthread_mutex_t	*forks;
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
	int				meals_left;
	int				id;
	long			last_meal;
	t_args			args;
	t_shared		*shared;
	pthread_t		thread;
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*right_fork;
	pthread_mutex_t	last_meal_mtx;
	pthread_mutex_t	meals_left_mtx;
}	t_philo;

#endif
