/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   validate.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: kgajadie <kgajadie@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/12/16 13:17:49 by kgajadie      #+#    #+#                 */
/*   Updated: 2022/12/22 16:38:09 by kgajadie      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "validate.h"

static bool	str_is_numeric(const char *str)
{
	char			*arr;
	unsigned int	i;

	i = 0;
	if (str[0] == '-')
		i++;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (false);
		i++;
	}
	arr = ft_itoa(ft_atoi(str));
	if (!arr)
	{
		printf("Error: malloc()\n");
		return (false);
	}
	if (ft_strlen(str) != ft_strlen(arr))
	{
		free(arr);
		return (false);
	}
	free(arr);
	return (true);
}

static bool	is_valid_cla(const char *cla)
{
	if (!(*cla))
	{
		printf("Error: <%s> is empty string\n", cla);
		return (false);
	}
	if (!str_is_numeric(cla))
	{
		printf("Error: <%s> is not numerical OR cla underflows/overflows\n",
			cla);
		return (false);
	}
	return (true);
}

bool	are_cla_valid(const char *cla[5])
{
	while (*cla)
	{
		if (!is_valid_cla(*cla))
			return (false);
		cla++;
	}
	return (true);
}

static bool	is_pos(int philo_mem)
{
	if (philo_mem < 1)
		return (false);
	return (true);
}

bool	are_philo_mem_pos(t_args *args)
{
	return (
		is_pos(args->n_of_philos)
		&& is_pos(args->time_to_die)
		&& is_pos(args->time_to_eat)
		&& is_pos(args->time_to_sleep)
		&& is_pos(args->number_of_times_to_eat)
	);
}
