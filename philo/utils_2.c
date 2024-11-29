/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 12:22:51 by marvin            #+#    #+#             */
/*   Updated: 2024/11/29 12:22:51 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	pick_up_fork(t_philo *philo)
{
	if (philo->program->num_of_philo == 1)
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
	return (0);
}

void	destroy_all(t_program *program, pthread_mutex_t *forks)
{
	int	i;

	i = -1;
	pthread_mutex_destroy(&program->lock_dead);
	pthread_mutex_destroy(&program->lock_meal);
	pthread_mutex_destroy(&program->lock_write);
	while (++i < program->num_of_philo)
	{
		pthread_mutex_destroy(&program->philo[i].lock_meal_count);
		pthread_mutex_destroy(&forks[i]);
	}
}

time_t	current_time_of_day(void)
{
	struct timeval	tv;

	if (gettimeofday(&tv, NULL) == 0)
		return ((tv.tv_sec * 1000) + (tv.tv_usec / 1000));
	printf("Error in gettimeofday.\n");
	return (0);
}

int	flag_death_check(t_philo *philo)
{
	int	temp;

	pthread_mutex_lock(&philo->program->lock_dead);
	temp = philo->program->dead;
	pthread_mutex_unlock(&philo->program->lock_dead);
	return (temp);
}
