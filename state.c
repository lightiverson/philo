/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   state.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: kgajadie <kgajadie@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/12/21 17:46:06 by kgajadie      #+#    #+#                 */
/*   Updated: 2023/01/20 14:43:29 by kgajadie      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "state.h"

void	eat(t_philo *philo)
{
	set_last_meal_timestamp(philo);
	print_state(philo, "is eating");
	better_sleep(philo->args.time_to_eat);
}

// voeg check toe of philo doodgaat in slaap, zo ja moet ie slapen tot dan
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
