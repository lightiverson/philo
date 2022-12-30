/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   state.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: kgajadie <kgajadie@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/12/21 17:46:06 by kgajadie      #+#    #+#                 */
/*   Updated: 2022/12/30 15:33:46 by kawish        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "state.h"

/*
mutex forks
print timestamp_in_ms X is eating
simulate eating by sleeping for eat_duration?
put forks back on the table
start sleeping
*/
void	eat(t_philo *philo)
{
	usleep(philo->args->time_to_eat * 1000);
	printf("%ld %d is eating\n", get_current_timestamp_in_ms() - philo->args->start_time, philo->id);
}

void	philo_sleep(int i)
{
	printf("%ld %d is sleeping\n", get_current_timestamp_in_ms(), i);
}

void	has_died(int i)
{
	(void)i;
	// timestamp_in_ms X died
	;
}

/*
1. Slaap time_to_sleep lang
2. Mutex lock standard out
3. Print message
*/
void	think(t_philo *philo)
{
	usleep(philo->args->time_to_sleep * 1000);
	printf("%ld %d is thinking\n", get_current_timestamp_in_ms() - philo->args->start_time, philo->id);
}

// void take_forks(size_t i)
// {
// 	{
// 		std::lock_guard<std::mutex> lk{critical_region_mtx};  // enter critical region
// 		state[i] = State::HUNGRY;  // record fact that philosopher i is State::HUNGRY
// 		{
// 			std::lock_guard<std::mutex> lk(output_mtx);
// 			std::cout << "\t\t" << i << " is State::HUNGRY\n";
// 		}
// 		test(i);                        // try to acquire 2 forks
// 	}                                   // exit critical region
// 	both_forks_available[i].acquire();  // block if forks were not acquired
// }

void take_forks(t_philo *philo)
{
	// Pick up left fork
	// pthread_mutex_lock(&forks[id]);
	// pthread_mutex_lock(philo->fork);
	// Pick up right fork
	// pthread_mutex_lock(&forks[(id + 1) % NUM_PHILOSOPHERS]);

	int		i_curr_philo;
	int		i_right_philo;
	t_philo	*right;

	print_philo_struct(philo);

	i_curr_philo = philo->id - 1;
	// printf("i_curr_philo = %i\n", i_curr_philo);

	t_philo *start = philo - i_curr_philo;
	// print_philo_struct(start);

	i_right_philo = (i_curr_philo + 1) % philo->args->n_of_philos;
	// printf("i_right_philo = %i\n", i_right_philo);

	right = &start[i_right_philo];
	print_philo_struct(right);
	printf("\n");

	// printf("*current = %p\n", philo);
	// print_philo_struct(philo);

	// int index = philo->id - 1;
	// printf("index = %i\n", index);

	// int x = (index + 1) % philo->args->n_of_philos;
	// printf("x = %i\n", x);

	// t_philo *right = philo + x;
	// printf("*right = %p\n", right);

	// print_philo_struct(right);
}

// think(&philos[0]);
// take_forks(&philos[0]);
// eat(&philos[0]);
void*	philosophize(void* arg)
{
	t_philo	*p;
	
	p = (t_philo*)arg;
	// think(p);
	take_forks(p);
	return (0);
}
