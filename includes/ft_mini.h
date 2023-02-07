/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_mini.h                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: kgajadie <kgajadie@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/03 15:57:46 by kgajadie      #+#    #+#                 */
/*   Updated: 2023/02/07 10:31:34 by kgajadie      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MINI_H
# define FT_MINI_H

/* Public libraries */
# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>

/* ft_calloc.c */
void	*ft_calloc(size_t count, size_t size);

/* ft_mini.c */
size_t	ft_strlen(const char *s);
void	ft_putendl_fd(char *s, int fd);
int		ft_isdigit(int c);
int		ft_strncmp(const char *s1, const char *s2, size_t n);

/* ft_itoa.c */
char	*ft_itoa(int n);

/* ft_strdup.c */
char	*ft_strdup(const char *s1);

/* ft_atoi.c */
int		ft_atoi(const char *str);

#endif
