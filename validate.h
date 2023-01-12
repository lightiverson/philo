/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   validate.h                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: kgajadie <kgajadie@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/12/16 13:18:07 by kgajadie      #+#    #+#                 */
/*   Updated: 2023/01/12 10:16:17 by kgajadie      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef VALIDATE_H
# define VALIDATE_H

/* Public libraries */
# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>

/* Private libraries */
# include "libft/libft.h"
# include "structs.h"

bool	are_cla_valid(const char *argv[5]);
bool	are_philo_mem_pos(t_args args);

#endif