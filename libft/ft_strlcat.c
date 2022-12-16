/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strlcat.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: kgajadie <kgajadie@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/17 16:33:39 by kgajadie      #+#    #+#                 */
/*   Updated: 2020/11/17 16:35:31 by kgajadie      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	Description:
**	The strlcat() function appends string src to the end of dst. It takes the
**	full size of the destination buffer and guarantees NUL-termination.
**	Room for the NUL-termator should be included in dstsize.
**
**	Returns:
**	total length of string it tries to create, aka the initial length
**	of dst plus the length of src.
*/

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	int		i;
	size_t	dst_len;
	size_t	dst_len_o;

	i = 0;
	dst_len = ft_strlen(dst);
	dst_len_o = ft_strlen(dst);
	if (dstsize > dst_len)
	{
		while (dst_len < dstsize - 1 && src[i])
		{
			dst[dst_len] = src[i];
			dst_len++;
			i++;
		}
		dst[dst_len] = '\0';
		return (dst_len_o + ft_strlen(src));
	}
	return (dstsize + ft_strlen(src));
}
