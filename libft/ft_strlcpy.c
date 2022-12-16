/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strlcpy.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: kgajadie <kgajadie@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/17 16:36:31 by kgajadie      #+#    #+#                 */
/*   Updated: 2020/11/17 16:41:11 by kgajadie      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**  Description:
**  The strlcpy() function copies up to dstsize - 1 characters from the string
**  src to dst, NUL-terminating the result if dstsize is not 0.
**  Room for the NUL-terminator should be included in dstsize.
**
**  Returns:
**  total length of string it tries to create, aka length of src.
*/

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	unsigned long	srclen;
	size_t			i;

	if (!src || !dst)
		return (0);
	srclen = ft_strlen(src);
	i = 0;
	if (dstsize == 0)
		return (srclen);
	if (srclen == 0)
	{
		dst[0] = '\0';
		return (srclen);
	}
	while ((src[i] != '\0') && (i < (dstsize - 1)))
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (srclen);
}
