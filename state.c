/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   state.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: kgajadie <kgajadie@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/12/21 17:46:06 by kgajadie      #+#    #+#                 */
/*   Updated: 2023/01/31 16:00:04 by kgajadie      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "state.h"

void	print_state(t_philo *philo, char *str)
{
	pthread_mutex_lock(&philo->shared->output_mtx);
	if (!get_has_died(philo->shared))
		printf("%ld\t%d\t%s\n", get_current_timestamp_in_ms()
			- philo->args.start_time, philo->id, str);
	else if (!ft_strncmp(str, "died", 5))
		printf("%ld\t%d\t%s\n", get_current_timestamp_in_ms()
			- philo->args.start_time, philo->id, str);
	pthread_mutex_unlock(&philo->shared->output_mtx);
}

void	eat(t_philo *philo)
{
	set_last_meal_timestamp(philo);
	print_state(philo, "is eating");
	better_sleep(philo->args.time_to_eat);
}

/*
Voeg check toe of philo dood zal gaan
in z'n slaap. Zo ja slaap tot dan en set_has_died()
Betekend dit niet dat deze check in de monitor moet?
De monitor is de enige die set_has_died() kan callen
*/
void	_sleep(t_philo *philo)
{
	print_state(philo, "is sleeping");
	better_sleep(philo->args.time_to_sleep);
}

void	think(t_philo *philo)
{
	print_state(philo, "is thinking");
}

void	has_died(t_philo *philo)
{
	print_state(philo, "died");
}
