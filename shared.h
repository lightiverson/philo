#ifndef SHARED_H
# define SHARED_H

/* Public libraries */

/* Private libraries */
# include "structs.h"
# include "libft/libft.h"

t_shared	*shared_init(t_args args);
void		shared_destroy(t_shared *shared);
int			forks_init(pthread_mutex_t *forks, int n_of_philos);
int			forks_destroy(pthread_mutex_t *forks, int n_init_forks);

#endif