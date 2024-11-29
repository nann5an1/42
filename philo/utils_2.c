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

int pick_up_fork(t_philo *philo)
{
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
    return (0);
}