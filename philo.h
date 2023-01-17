/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   philo.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: kgajadie <kgajadie@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/12/21 17:46:54 by kgajadie      #+#    #+#                 */
/*   Updated: 2023/01/17 16:25:59 by kgajadie      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

/* Private libraries */
# include "structs.h"
# include "state.h"
# include "timestamp.h"
# include "libft/libft.h"
# include "validate.h"
# include "utils.h"

/* Public libraries */
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <pthread.h>

void*	monitor_routine(void* arg);
void*	philo_routine(void* arg);

#endif
