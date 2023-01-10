/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   structs.h                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: kgajadie <kgajadie@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/12/15 16:57:36 by kgajadie      #+#    #+#                 */
/*   Updated: 2023/01/10 17:13:32 by kgajadie      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

/* Public libraries */
# include <stdbool.h>
# include <pthread.h>

/* Private libraries */


/*
Moet je checken of de linkervork beschikbaar is EN de rechtervork?

In the philosophers dining problem, it is typically necessary to check for the availability of both the left and right chopsticks separately.
Each philosopher can only eat if they have both chopsticks in their hands, so they need to make sure that they can pick up both chopsticks before they begin eating.

One way to check for the availability of both chopsticks is to have each philosopher first request the left chopstick, and then the right chopstick.
If the left chopstick is available, the philosopher picks it up and then requests the right chopstick. If both chopsticks are available, the philosopher picks them up and begins eating. 
If either chopstick is not available, the philosopher releases the chopstick they have and goes back to thinking.

Another way is to have philosophers using two seperate monitors, to check for left and right fork.
In this case, the philosopher requests access to both chopsticks at the same time, and if both are available, the philosopher picks them up and begins eating.
If either chopstick is not available, the philosopher releases the chopstick they have and goes back to thinking.

It's worth noting that depending on the implementation,checking both chopsticks separately or at the same time may have subtle differences in behavior and starvation possibilities.

It's important to note that the philosophers should not be able to pick up the right fork if left fork is not available to them, and vice versa, to prevent deadlocks.
*/

/*
Wat is het verschil tussen shared data en unshared data?

Shared data is data that is accessed by multiple threads simultaneously, while unshared data is data that is only accessed by a single thread.

When multiple threads access shared data, you need to use synchronization mechanisms like mutexes to ensure that the threads don't interfere with each other and that the data remains in a consistent state.
For example, you might use a mutex to protect a shared data structure so that only one thread can modify it at a time.

Unshared data, on the other hand, can be accessed and modified by a single thread without any synchronization, because it is guaranteed that no other thread will access it simultaneously.

In general, it's best to minimize the amount of shared data in your program and to use unshared data whenever possible.
Using unshared data reduces the need for synchronization and can make your program run faster and with less overhead.
However, it's not always possible to avoid shared data altogether, particularly in multithreaded programs where multiple threads need to communicate with each other and share information.
*/

/*
Welke data moeten de threads tegelijkertijd weten
- of een thread dood is
- of de linkervork beschikbaar is
- of de rechtervork beschikbaar is

elke philo moet zelf bijhouden of hij/zij op tijd heeft gegeten, zo niet moet ie shared data aangeven dat die dedjes is.
*/

/*
In Dijkstra's oorspronkelijke oplossing gebruikt hij de test functie om voor philo 2 naar de staat van philo 1 en philo 3 te kijken. Staat is zijn philo 1 en philo 3 aan het eten of niet en wilt philo 1 eten.
In onze opdracht mogen de philos niet met elkaar communiceren dus dit kan niet. Wat wel kan is dat philo 2 de mutex probeert te pakken van philo 1, als dit lukt de mutex pakt van philo 3,
als het niet lukte de mutex van philo 1 los laat
*/


/*
zorg dat al die input gekopierd word naar een philo ipv pointer naar args
*/
// typedef struct s_args
// {
// 	pthread_mutex_t	critical_region;
// 	bool		has_died;
// 	int			n_of_philos;
// 	int			time_to_die;
// 	int			time_to_eat;
// 	int			time_to_sleep;
// 	int			number_of_times_to_eat;
// 	long int	start_time;
// }	t_args;

typedef struct s_shared
{
	pthread_mutex_t	critical_region;
	bool		has_died;
}	t_shared;

typedef struct s_args
{
	int			n_of_philos;
	int			time_to_die;
	int			time_to_eat;
	int			time_to_sleep;
	int			number_of_times_to_eat;
	long int	start_time;
}	t_args;

typedef struct s_philo
{
	int				id;
	t_args			args;
	long int		last_meal;
	t_shared		*shared;
	pthread_mutex_t	fork;
	pthread_t		thread;
}	t_philo;

#endif
