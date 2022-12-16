/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strmapi.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: kgajadie <kgajadie@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/22 12:04:03 by kgajadie      #+#    #+#                 */
/*   Updated: 2020/11/24 17:06:28 by kgajadie      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*answer;

	if (!s || !(*f))
		return (NULL);
	answer = ft_strdup(s);
	if (!answer)
		return (NULL);
	i = 0;
	while (s[i] != '\0')
	{
		answer[i] = (*f)(i, s[i]);
		if (!answer[i])
			return (NULL);
		i++;
	}
	return (answer);
}
