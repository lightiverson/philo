/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strrchr.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: kgajadie <kgajadie@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/17 16:33:10 by kgajadie      #+#    #+#                 */
/*   Updated: 2020/11/26 14:16:02 by kawish        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** DESCRIPTION
** The strchr() function locates the first occurrence of c (converted to a
** char) in the string pointed to by s.  The terminating null character is
** considered to be part of the string; therefore if c is `\0', the func-
** tions locate the terminating `\0'.
**
** The strrchr() function is identical to strchr(), except it locates the
** last occurrence of c.
**
** RETURN VALUES
** The functions strchr() and strrchr() return a pointer to the located
** character, or NULL if the character does not appear in the string.
*/

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	*located;

	i = 0;
	located = NULL;
	while (s[i] != '\0')
	{
		if (s[i] == (char)c)
		{
			located = ((char *)&(s[i]));
		}
		i++;
	}
	if ((char)c == '\0')
	{
		located = ((char *)&(s[i]));
	}
	if (located == NULL)
	{
		return (NULL);
	}
	return (located);
}
