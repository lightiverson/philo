/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_isalpha.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: kgajadie <kgajadie@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/17 15:53:43 by kgajadie      #+#    #+#                 */
/*   Updated: 2021/03/04 20:18:54 by kawish        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* Tests if c is an alphabetic character */

int	ft_isalpha(int c)
{
	if (((c >= 'A') && (c <= 'Z')) || ((c >= 'a') && (c <= 'z')))
	{
		return (1);
	}
	else
	{
		return (0);
	}
}
