/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strjoin.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: kgajadie <kgajadie@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/22 11:11:34 by kgajadie      #+#    #+#                 */
/*   Updated: 2020/11/24 14:07:38 by kgajadie      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	clen;
	char	*ret;

	if (!s1 && !s2)
		return (NULL);
	else if (!s1)
		return (ft_strdup(s2));
	else if (!s2)
		return (ft_strdup(s1));
	clen = ft_strlen(s1) + ft_strlen(s2);
	ret = malloc(clen + 1);
	if (!ret)
		return (NULL);
	ft_strlcpy(ret, s1, clen + 1);
	ft_strlcat(ret, s2, clen + 1);
	return (ret);
}
