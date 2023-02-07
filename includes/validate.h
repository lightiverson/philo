/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   validate.h                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: kgajadie <kgajadie@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/12/16 13:18:07 by kgajadie      #+#    #+#                 */
/*   Updated: 2023/02/07 12:08:34 by kgajadie      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef VALIDATE_H
# define VALIDATE_H

/* Public libraries */
# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>

/* Private libraries */
# include "ft_mini.h"
# include "structs.h"

bool	are_cla_valid(const char *argv[5]);
bool	are_args_mem_valid(t_args args);

#endif