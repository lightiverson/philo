/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_calloc.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: kgajadie <kgajadie@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/03 16:13:04 by kgajadie      #+#    #+#                 */
/*   Updated: 2023/02/03 16:16:24 by kgajadie      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

# include "ft_mini.h"

static void	*ft_memset(void *b, int c, size_t len)
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

static void	ft_bzero(void *s, size_t n)
{
	ft_memset(s, '\0', n);
}

void	*ft_calloc(size_t count, size_t size)
{
	void	*a;

	if ((count == 0) || (size == 0))
	{
		count = 1;
		size = 1;
	}
	a = malloc(count * size);
	if (a)
		ft_bzero(a, count * size);
	return (a);
}
