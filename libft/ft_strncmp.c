/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strncmp.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: kgajadie <kgajadie@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/17 16:42:20 by kgajadie      #+#    #+#                 */
/*   Updated: 2021/03/04 21:10:21 by kawish        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* Convert const char* s1 and const char* s2 into unsigned char.
Loop up from 0 till n.
If i'th character of s1 is different than i'th character of s2,
strings are not the same
So return int value of s1[i] - s2[i].
If i'th character of s1 equals null terminating character, then the loop
has completed without finding differences. So the strings up to n are the
same. So return (0).
If the while loop is not executed n equals 0. In this case return (0). */

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned char	*u1;
	unsigned char	*u2;
	size_t			i;

	u1 = (unsigned char *)s1;
	u2 = (unsigned char *)s2;
	i = 0;
	while (i < n)
	{
		if (u1[i] != u2[i])
		{
			return (u1[i] - u2[i]);
		}
		if (u1[i] == '\0')
		{
			return (0);
		}
		i++;
	}
	return (0);
}
