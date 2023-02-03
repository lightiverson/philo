/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_atoi.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: kgajadie <kgajadie@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/03 16:28:42 by kgajadie      #+#    #+#                 */
/*   Updated: 2023/02/03 16:29:23 by kgajadie      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_mini.h"

static int	ft_isspace(int c)
{
	if (c == '\t' || c == '\n' || c == '\v'
		|| c == '\f' || c == '\r' || c == ' ')
	{
		return (1);
	}
	else
	{
		return (0);
	}
}

int	ft_atoi(const char *str)
{
	int			i;
	long int	a;
	int			sign;

	i = 0;
	a = 0;
	sign = 1;
	while (ft_isspace(str[i]))
		i++;
	if (str[i] == '-')
		sign = -1;
	if ((str[i] == '-') || (str[i] == '+'))
		i++;
	while (ft_isdigit(str[i]) && (a <= 2147483648))
	{
		a = (a * 10) + (str[i] - '0');
		i++;
	}
	if ((a > 2147483648) && (sign == -1))
		return (0);
	if ((a > 2147483647) && (sign == 1))
		return (-1);
	if (sign == -1)
		a = a * sign;
	return (a);
}