/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   shared.h                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: kgajadie <kgajadie@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/27 15:06:39 by kgajadie      #+#    #+#                 */
/*   Updated: 2023/02/14 14:30:29 by kgajadie      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHARED_H
# define SHARED_H

/* Public libraries */

/* Private libraries */
# include "structs.h"
# include "ft_mini.h"

/* shared.c */
t_shared	*shared_init(t_args args);
int			shared_forks_init(pthread_mutex_t *forks, int n_philos);
int			shared_forks_destroy(pthread_mutex_t *forks, int n_init_forks);

#endif