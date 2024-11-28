/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 20:14:15 by marvin            #+#    #+#             */
/*   Updated: 2024/11/29 01:10:50 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int eating(t_philo *philo)
{
	pthread_mutex_lock(&philo->program->lock_dead);
	// printf("<<PHILO DIE OR NOT>> %d\n", philo->program->dead);
	if(philo->program->dead == 1)
	{
		pthread_mutex_unlock(&philo->program->lock_dead);
		return (1);
	}
	pthread_mutex_unlock(&philo->program->lock_dead);
	if(philo->program->num_of_philo == 1)
	{
		pthread_mutex_lock(philo->l_fork);
		print_message(philo, "has taken a fork");
		pthread_mutex_unlock(philo->l_fork);
		usleep(philo->program->time_to_die * 1000);
		return (1);
	}
	if (philo->id % 2 == 0)
	{
		pthread_mutex_lock(philo->l_fork);
		print_message(philo, "has taken a fork");
		pthread_mutex_lock(philo->r_fork);
		print_message(philo, "has taken a fork");
	}
	else
	{
		pthread_mutex_lock(philo->r_fork);
		print_message(philo, "has taken a fork");
		pthread_mutex_lock(philo->l_fork);
		print_message(philo, "has taken a fork");
	}
	philo->eating = 1;
	print_message(philo, "is eating");
	
	pthread_mutex_lock(&philo->program->lock_meal);
	philo->last_eat_time = current_time_of_day();
	pthread_mutex_unlock(&philo->program->lock_meal);
	
	pthread_mutex_lock(&philo->lock_meal_count);
	philo->count_eaten++;
	pthread_mutex_unlock(&philo->lock_meal_count);
	
	usleep(philo->program->time_to_eat * 1000);
	philo->eating = 0;
	pthread_mutex_unlock(philo->r_fork);
	pthread_mutex_unlock(philo->l_fork);
	return (0);
}

size_t sleeping(t_philo *philo)
{
	struct timeval tv;
	
	pthread_mutex_lock(&philo->program->lock_dead);
	// printf("<<PHILO DIE OR NOT SLEEPING>> %d\n", philo->program->dead);
	if(philo->program->dead == 1)
	{
		pthread_mutex_unlock(&philo->program->lock_dead);
		return (1);
	}
	pthread_mutex_unlock(&philo->program->lock_dead);
	if (gettimeofday(&tv, NULL) == 0)
	{
		print_message(philo, "is sleeping");
		usleep(philo->program->time_to_sleep * 1000);
		return (tv.tv_sec * 1000 + tv.tv_usec / 1000);
	}
	printf("Error in gettimeofday.\n");
	return (0);
}

int thinking(t_philo *philo)
{
	size_t time_to_think;

	pthread_mutex_lock(&philo->program->lock_dead);
	// printf("<<PHILO DIE OR NOT THINKING>> %d\n", philo->program->dead);
	if(philo->program->dead == 1)
	{
		pthread_mutex_unlock(&philo->program->lock_dead);
		return (1);
	}
	pthread_mutex_unlock(&philo->program->lock_dead);
	time_to_think = 200;
	print_message(philo, "is thinking");
	pthread_mutex_lock(&philo->program->lock_meal);
	if(current_time_of_day() - philo->last_eat_time + philo->program->time_to_eat > philo->program->time_to_die)
		time_to_think = 0;
	pthread_mutex_unlock(&philo->program->lock_meal);
	usleep(time_to_think * 1000);
	return (0);
}

void *action(void *args)
{
	t_philo *philo = (t_philo *)args;

	while (1)
	{
		pthread_mutex_lock(&philo->program->lock_dead);
		if(philo->program->dead == 1)
		{
			pthread_mutex_unlock(&philo->program->lock_dead);
			break;
		}
		pthread_mutex_unlock(&philo->program->lock_dead);
		if (philo->program->num_of_philo == 1)
		{
			eating(philo);
			break;
		}
		if (eating(philo) == 1 || sleeping(philo) == 1|| thinking(philo) == 1)
			break;
		
	}
	return (NULL);
}
