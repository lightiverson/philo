/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strnstr.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: kgajadie <kgajadie@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/17 16:44:20 by kgajadie      #+#    #+#                 */
/*   Updated: 2021/03/04 21:15:01 by kawish        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* The strnstr() function locates the first occurrence of the null-ter-
minated string needle in the string haystack, where not more than len
characters are searched. Characters that appear after a `\0' charac-
ter are not searched.

a pointer to the first character of the needle in haystack
if needle is not in haystack, NULL is returned
if needle is empty string, haystack is returned */

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (needle[0] == '\0')
	{
		return ((char *)haystack);
	}
	while ((i < len) && (haystack[i] != '\0'))
	{
		while (((haystack[i + j] == needle[j])
				&& ((i + j) < len)) || (needle[j] == '\0'))
		{
			if (needle[j] == '\0')
			{
				return ((char *)&haystack[i]);
			}
			j++;
		}
		j = 0;
		i++;
	}
	return (0);
}
