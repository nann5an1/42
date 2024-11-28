/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 19:31:39 by marvin            #+#    #+#             */
/*   Updated: 2024/11/27 10:06:13 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int philo_died(t_philo *philo) //iterated through each philo to see if it has died
{
	pthread_mutex_lock(philo->lock_meal);
	// printf("%ld \n %d\n", current_time_of_day(), philo->last_eat_time);
	if(current_time_of_day() - philo->last_eat_time >= philo->time_to_die)
	{
		pthread_mutex_unlock(philo->lock_meal);
		return (1);
	}
	pthread_mutex_unlock(philo->lock_meal);
	return (0);
}

int check_if_died(t_philo *philo)
{
	int i;
	i = 0;
	while (i < philo->num_of_philo)
	{
		 if(philo_died(&philo[i]) == 1)
		{
			pthread_mutex_lock(philo[i].lock_dead);
			*philo[i].dead = 1;
			pthread_mutex_unlock(philo[i].lock_dead);
			printf("%ld %d has died\n", current_time_of_day() - philo->start_time, philo->id);
			if (philo->num_of_philo == 1)
				pthread_mutex_unlock(philo->r_fork);
			return (1);
		}
		i++;
	}
	return (0);
}

int	check_if_all_eaten(t_philo *philo)
{
	int i;
	int done_eating;

	i = 0;
	done_eating = 0;
	while (i < philo->num_of_philo)
	{
		pthread_mutex_lock(philo[i].lock_meal);
		// printf("philo id >> %d num of times to eat >> %zu\n", philo[i].id, philo[i].num_of_times_to_eat);
		if(philo[i].count_eaten >= philo[i].num_of_times_to_eat)
			done_eating++;
		pthread_mutex_unlock(philo[i].lock_meal);
		i++;
	}
	if (done_eating == philo->num_of_times_to_eat)
	{
		pthread_mutex_lock(philo->lock_dead);
		*philo->dead = 1;
		pthread_mutex_unlock(philo->lock_dead);
		return (1);
	}
	return (0);
}

void *monitor(void *args)
{
	t_program *prog = (t_program *)args;
	t_philo *philo = prog->philo;

	while (1)
	{
		if (check_if_died(philo) == 1)
			break ;
		if (philo->num_of_times_to_eat != -1)
		{
			// printf(">>>NUMBER OF TIMES TO EAT <<<< : %zu\n", philo->num_of_times_to_eat);
			if (check_if_all_eaten(philo) == 1)
			{
				printf("in monitoring function check if all eaten\n");
				break;
			}
		}
	}
	return (NULL);
	// printf("<<<NUM OF PHILOS>>> %ld\n", philo[1].num_of_philo);
	// return (NULL);
}
