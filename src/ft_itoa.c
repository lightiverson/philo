/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_itoa.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: kgajadie <kgajadie@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/03 16:08:25 by kgajadie      #+#    #+#                 */
/*   Updated: 2023/02/07 10:32:09 by kgajadie      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_mini.h"

static	int	ft_int2pwr(int x, int n)
{
	int	i;
	int	result;

	i = 0;
	result = 1;
	while (i < n)
	{
		result *= x;
		i++;
	}
	return (result);
}

static	size_t	ft_intlen(int n)
{
	size_t	len;

	len = 1;
	if (n < 0)
	{
		n = n * -1;
		len++;
	}
	while (n > 9)
	{
		len++;
		n = n / 10;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	int		i;
	size_t	len;
	char	*str;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	i = 0;
	len = ft_intlen(n);
	str = ft_calloc(len + 1, sizeof(*str));
	if (!str)
		return (0);
	if (n < 0)
	{
		n = n * -1;
		str[i] = '-';
		i++;
	}
	len = len - i;
	while (len > 0)
	{
		str[i] = ((n / ft_int2pwr(10, len - 1)) % 10) + '0';
		i++;
		len--;
	}
	return (str);
}
