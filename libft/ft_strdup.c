/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strdup.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: kgajadie <kgajadie@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/17 17:11:21 by kgajadie      #+#    #+#                 */
/*   Updated: 2020/11/24 13:59:58 by kgajadie      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** DESCRIPTION
** The strdup() function allocates
** sufficient memory for a copy of the string s1, does the
** copy, and returns a pointer to it.
** The pointer may subsequently be used as an argument
** to the function free(3).
**
** If insufficient memory is available,
** NULL is returned and errno is set to ENOMEM.
*/

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
