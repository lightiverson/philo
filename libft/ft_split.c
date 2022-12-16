/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_split.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: kgajadie <kgajadie@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/22 11:42:42 by kgajadie      #+#    #+#                 */
/*   Updated: 2021/03/04 20:29:21 by kawish        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	ft_words_count(char const *s, char c)
{
	int	i;
	int	len;
	int	k;

	i = 0;
	len = 0;
	k = 0;
	while (s[i])
	{
		while ((s[i] != c) && (s[i] != '\0'))
		{
			len++;
			i++;
		}
		if (len > 0)
		{
			k++;
			len = 0;
		}
		else
			i++;
	}
	return (k);
}

static	char	**ft_free_td_array(char **td_array, int index)
{
	int	i;

	i = 0;
	while (i < index)
	{
		free(td_array[i]);
		i++;
	}
	free(td_array);
	return (NULL);
}

static	char	**ft_create_td_array(char const *s, char c)
{
	char	**td_array;
	int		words_count;

	words_count = ft_words_count(s, c);
	td_array = ft_calloc((words_count + 1), sizeof(*td_array));
	if (!td_array)
		return (ft_free_td_array(td_array, 0));
	return (td_array);
}

static	char	**ft_fill_td_array(char const *s, char c, char **td_array)
{
	int		i;
	int		len;
	int		j;

	i = 0;
	j = 0;
	while (s[i])
	{
		len = 0;
		while ((s[i] != c) && (s[i] != '\0'))
		{
			len++;
			i++;
		}
		if (len > 0)
		{
			td_array[j] = ft_substr(s, i - len, len);
			if (td_array[j] == NULL)
				return (ft_free_td_array(td_array, j));
			j++;
		}
		else
			i++;
	}
	return (td_array);
}

/* Allocates (with malloc(3)) and returns an array
of strings obtained by splitting ’s’ using the
character ’c’ as a delimiter.  The array must beended by a NULL pointer. */

char	**ft_split(char const *s, char c)
{
	char	**td_array;

	if (!s)
		return (NULL);
	td_array = ft_create_td_array(s, c);
	if (!td_array)
		return (NULL);
	td_array = ft_fill_td_array(s, c, td_array);
	if (!td_array)
		return (NULL);
	return (td_array);
}
