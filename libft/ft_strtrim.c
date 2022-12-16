/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strtrim.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: kgajadie <kgajadie@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/22 11:35:38 by kgajadie      #+#    #+#                 */
/*   Updated: 2021/03/05 11:58:11 by kawish        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	in_set(const char *set, char c)
{
	int	i;

	i = 0;
	while (set[i] != '\0')
	{
		if (set[i] == c)
		{
			return (1);
		}
		i++;
	}
	return (0);
}

/* Allocates (with malloc(3)) and returns a copy of’s1’ 
with the characters specified in ’set’ removed
from the beginning and the end of the string */

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*n;
	size_t	s1_start;
	size_t	s1_end;

	s1_start = 0;
	if (!s1)
		return (NULL);
	s1_end = (ft_strlen(s1) - 1);
	while (s1[s1_start] != '\0')
	{
		if (!(in_set(set, s1[s1_start])))
			break ;
		s1_start++;
	}
	while (s1_end > s1_start)
	{
		if (!(in_set(set, s1[s1_end])))
			break ;
		s1_end--;
	}
	s1_end++;
	n = ft_substr(s1, s1_start, (s1_end - s1_start));
	return (n);
}
