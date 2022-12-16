/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memmove.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: kgajadie <kgajadie@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/17 15:44:08 by kgajadie      #+#    #+#                 */
/*   Updated: 2020/11/26 14:10:20 by kawish        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** DESCRIPTION
** The memmove() function copies len bytes from string src to string dst.
** The two strings may overlap; the copy is always done in a non-destructive
** manner.
**
** RETURN VALUES
** The memmove() function returns the original value of dst.
*/

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char			*d;
	const char		*s;
	size_t			i;
	char			*d_last;
	const char		*s_last;

	d = dst;
	s = src;
	if (!dst && !src)
		return (0);
	if (d < s)
		while (len--)
			*d++ = *s++;
	else
	{
		i = 0;
		d_last = d + (len - 1);
		s_last = s + (len - 1);
		while (i < len)
		{
			*(d_last - i) = *(s_last - i);
			i++;
		}
	}
	return (dst);
}
