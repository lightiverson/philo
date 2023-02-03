/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strdup.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: kgajadie <kgajadie@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/03 16:17:11 by kgajadie      #+#    #+#                 */
/*   Updated: 2023/02/03 16:30:40 by kgajadie      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

# include "ft_mini.h"

static void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	i;

	i = 0;
	if (!dst && !src)
		return (0);
	while (i < n)
	{
		((char *)dst)[i] = ((const char *)src)[i];
		i++;
	}
	return (dst);
}

char	*ft_strdup(const char *s1)
{
	size_t	s1_len;
	char	*res;

	s1_len = ft_strlen(s1) + 1;
	res = malloc(s1_len * sizeof(*res));
	if (!res)
		return (NULL);
	ft_memcpy(res, s1, s1_len);
	return (res);
}
