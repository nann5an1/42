/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 19:31:39 by marvin            #+#    #+#             */
/*   Updated: 2024/11/29 18:32:59 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	philo_died(t_philo *philo)
{
	time_t	time_since_last_eat;

	pthread_mutex_lock(&philo->program->lock_meal);
	time_since_last_eat = current_time_of_day() - philo->last_eat_time;
	pthread_mutex_unlock(&philo->program->lock_meal);
	if (time_since_last_eat >= philo->program->time_to_die)
	{
		pthread_mutex_lock(&philo->program->lock_dead);
		philo->program->dead = 1;
		pthread_mutex_unlock(&philo->program->lock_dead);
		print_message (philo, "has died");
		return (1);
	}
	return (0);
}

int	check_if_died(t_program *program)
{
	int	i;

	i = -1;
	while (++i < program->num_of_philo)
	{
		if (philo_died (&program->philo[i]) == 1)
			return (1);
	}
	return (0);
}

int	check_if_all_eaten(t_philo *philo)
{
	int	i;
	int	done_eating;

	i = -1;
	done_eating = 1;
	if (philo->program->num_of_times_to_eat == -1)
		return (0);
	while (++i < philo->program->num_of_philo)
	{
		pthread_mutex_lock(&philo[i].lock_meal_count);
		if (philo[i].count_eaten < philo->program->num_of_times_to_eat)
		{
			done_eating = 0;
			return (pthread_mutex_unlock(&philo[i].lock_meal_count), 0);
		}
		pthread_mutex_unlock(&philo[i].lock_meal_count);
	}
	if (done_eating == 1)
	{
		pthread_mutex_lock(&philo->program->lock_dead);
		philo->program->dead = 1;
		return (pthread_mutex_unlock(&philo->program->lock_dead), 1);
	}
	return (0);
}

void	*monitor(void *args)
{
	t_program	*program;

	program = (t_program *)args;
	while (1)
	{
		if (check_if_died(program) == 1 || \
		check_if_all_eaten(program->philo) == 1)
			break ;
		else
			continue ;
		usleep(1000);
	}
	return (NULL);
}
