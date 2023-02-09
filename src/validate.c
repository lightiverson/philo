/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   validate.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: kgajadie <kgajadie@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/12/16 13:17:49 by kgajadie      #+#    #+#                 */
/*   Updated: 2023/02/07 17:22:42 by kgajadie      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "validate.h"

static bool	str_is_numeric(const char *str)
{
	char			*arr;
	unsigned int	i;

	i = 0;
	if (str[0] == '-')
		return (false);
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
		printf("Error: <%s> is not numerical OR underflows/overflows OR is negative\n",
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

bool	are_args_mem_valid(t_args args)
{
	if (args.n_of_philos < 1 || args.n_of_philos > 200)
	{
		ft_putendl_fd("Error: invalid n of philo(s)", STDERR_FILENO);
		return (false);
	}
	if (args.time_to_die < 60 || args.time_to_eat < 60
		|| args.time_to_sleep < 60)
	{
		ft_putendl_fd("Error: time_to_x to low", STDERR_FILENO);
		return (false);
	}
	if (!args.number_of_times_to_eat)
	{
		ft_putendl_fd("Error: times_to_eat to low", STDERR_FILENO);
		return (false);
	}
	return (true);
}
