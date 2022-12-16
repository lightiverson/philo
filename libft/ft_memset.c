/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memset.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: kgajadie <kgajadie@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/17 15:31:12 by kgajadie      #+#    #+#                 */
/*   Updated: 2020/11/26 14:11:54 by kawish        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** DESCRIPTION
** The memset() function writes len bytes of value c (converted to an
** unsigned char) to the string b.
**
** RETURN VALUES
** The memset() function returns its first argument.
*/

void	*ft_memset(void *b, int c, size_t len)
{
	size_t			i;
	unsigned char	*new_ptr;

	i = 0;
	new_ptr = b;
	while (i < len)
	{
		new_ptr[i] = (unsigned char)c;
		i++;
	}
	return (b);
}
