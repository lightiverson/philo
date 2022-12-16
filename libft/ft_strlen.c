/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strlen.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: kgajadie <kgajadie@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/17 15:52:51 by kgajadie      #+#    #+#                 */
/*   Updated: 2021/03/04 21:00:38 by kawish        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* The strlen() function computes the length of the string s.  The strnlen()
function attempts to compute the length of s, but never scans beyond the
first maxlen bytes of s.

The strlen() function returns the number of characters that precede the
terminating NUL character.  The strnlen() function returns either the
same result as strlen() or maxlen, whichever is smaller. */

size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (*s++)
	{
		len++;
	}
	return (len);
}
