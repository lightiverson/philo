/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memccpy.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: kgajadie <kgajadie@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/22 12:08:07 by kgajadie      #+#    #+#                 */
/*   Updated: 2020/11/24 15:13:39 by kgajadie      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	Description:
**	The memccpy() function copies up to n bytes from src to dst.
**	If the character c occurs in the string src, the copy stops. The copy
**	does include the character c.
**
**	When source and destination strings overlap, behavior is undefined.
**
**	Returns:
**	a pointer to the byte after the first c in the string dst
**	if c not in string, return NULL pointer
*/

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t			i;
	char			*d;
	const char		*s;

	i = 0;
	d = dst;
	s = src;
	while (i < n)
	{
		d[i] = s[i];
		if (d[i] == (char)c)
		{
			return (&d[i + 1]);
		}
		i++;
	}
	return (0);
}
