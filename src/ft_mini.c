/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_mini.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: kgajadie <kgajadie@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/03 15:57:20 by kgajadie      #+#    #+#                 */
/*   Updated: 2023/02/03 16:30:11 by kgajadie      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_mini.h"

size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (*s++)
	{
		len++;
	}
	return (len);
}

static void	ft_putstr_fd(char *s, int fd)
{
	size_t	s_len;

	if (!s)
		return ;
	s_len = ft_strlen(s);
	write(fd, s, s_len);
}

void	ft_putendl_fd(char *s, int fd)
{
	ft_putstr_fd(s, fd);
	write(fd, "\n", 1);
}

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
	{
		return (1);
	}
	else
	{
		return (0);
	}
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned char	*u1;
	unsigned char	*u2;
	size_t			i;

	u1 = (unsigned char *)s1;
	u2 = (unsigned char *)s2;
	i = 0;
	while (i < n)
	{
		if (u1[i] != u2[i])
		{
			return (u1[i] - u2[i]);
		}
		if (u1[i] == '\0')
		{
			return (0);
		}
		i++;
	}
	return (0);
}
