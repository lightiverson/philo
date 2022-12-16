/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_isprint.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: kgajadie <kgajadie@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/17 15:59:07 by kgajadie      #+#    #+#                 */
/*   Updated: 2021/03/04 20:21:06 by kawish        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* Tests if c is a printable character (including a space) */

int	ft_isprint(int c)
{
	if ((c >= ' ' && c <= '~'))
	{
		return (1);
	}
	else
	{
		return (0);
	}
}
