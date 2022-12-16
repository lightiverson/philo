/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_substr.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: kgajadie <kgajadie@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/22 11:10:49 by kgajadie      #+#    #+#                 */
/*   Updated: 2020/11/24 11:47:11 by kgajadie      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*res;
	unsigned int	end;
	int				i;

	if (!s)
		return (NULL);
	end = start + len;
	res = malloc(len + 1);
	i = 0;
	if (res == NULL)
		return (NULL);
	if (start >= ft_strlen(s))
	{
		ft_bzero(res, 1);
		return (res);
	}
	while (start < end)
	{
		res[i] = s[start];
		start++;
		i++;
	}
	res[i] = '\0';
	return (res);
}
