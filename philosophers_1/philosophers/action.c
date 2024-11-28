/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 20:14:15 by marvin            #+#    #+#             */
/*   Updated: 2024/11/27 09:57:58 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void eating(t_philo *philo)
{
	if(philo->num_of_philo == 1)
	{
		pthread_mutex_lock(philo->r_fork);
		printf("%ld %d has taken a fork\n", current_time_of_day() - philo->start_time, philo->id);
		return ;
	}
		if (philo->id % 2 == 0)
		{
			pthread_mutex_lock(philo->l_fork);
			printf("%ld %d has taken a fork\n", current_time_of_day() - philo->start_time, philo->id);
			pthread_mutex_lock(philo->r_fork);
			printf("%ld %d has taken a fork\n", current_time_of_day() - philo->start_time, philo->id);
		}
		else
		{
			pthread_mutex_lock(philo->r_fork);
			printf("%ld %d has taken a fork\n", current_time_of_day() - philo->start_time, philo->id);
			pthread_mutex_lock(philo->l_fork);
			printf("%ld %d has taken a fork\n", current_time_of_day() - philo->start_time, philo->id);
		}
		philo->eating = 1;
		printf("%ld %d is eating\n", current_time_of_day() - philo->start_time, philo->id);
		pthread_mutex_lock(philo->lock_meal);
		philo->last_eat_time = current_time_of_day();
		philo->count_eaten++;
		pthread_mutex_unlock(philo->lock_meal);
		usleep(philo->time_to_eat * 1000);
		philo->eating = 0;
		pthread_mutex_unlock(philo->r_fork);
		pthread_mutex_unlock(philo->l_fork);
}

size_t sleeping(t_philo *philo)
{
	struct timeval tv;
	if (gettimeofday(&tv, NULL) == 0)
	{
		printf("%ld %d is sleeping\n", current_time_of_day() - philo->start_time, philo->id);
		usleep(philo->time_to_sleep * 1000);
		return (tv.tv_sec * 1000 + tv.tv_usec / 1000);
	}
	printf("Error in gettimeofday.\n");
	return (0);
}


void thinking(t_philo *philo)
{

	printf("%ld %d is thinking\n", current_time_of_day() - philo->start_time, philo->id);
	usleep(500);
}