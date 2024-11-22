/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 20:14:15 by marvin            #+#    #+#             */
/*   Updated: 2024/11/22 15:35:59 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void eating(t_philo *philo)
{
    // printf("num of philo from struct : %ld \n", philo->num_of_philo);
        // printf("philo id: %d \n", philo->id);
        if (philo->id % 2 == 0)
        {
            pthread_mutex_lock(philo->r_fork);
            pthread_mutex_lock(philo->l_fork);
        }
        else
        {
            pthread_mutex_lock(philo->l_fork);
            pthread_mutex_lock(philo->r_fork);
        }
        // pthread_mutex_lock(philo->lock_meal);
        printf("%ld %d has taken a fork\n", current_time_of_day() - philo->start_time, philo->id);
        // msg_output("has taken a fork", philo, philo->id);
        philo->eating = 1;
        // msg_output("is eating", philo, philo->id);
        printf("%ld %d is eating\n", current_time_of_day() - philo->start_time, philo->id);
        usleep(500 * 1000);
        philo->count_eaten++;
        printf("philo id %d count eaten : %d\n", philo->id, philo->count_eaten);
        philo->last_eat_time = current_time_of_day();
        // pthread_mutex_unlock(philo->lock_meal);
        pthread_mutex_unlock(philo->r_fork);
        pthread_mutex_unlock(philo->l_fork);
}

size_t sleeping(t_philo *philo)
{
    struct timeval tv;
    if (gettimeofday(&tv, NULL) == 0)
    {
        printf("%ld %d is sleeping\n", current_time_of_day() - philo->start_time, philo->id);
        usleep(1000000);
        return (tv.tv_sec * 1000 + tv.tv_usec / 1000);
    }
    printf("Error in gettimeofday.\n");
    return (0);
}


void thinking(t_philo *philo)
{
    
    printf("%ld %d is thinking\n", current_time_of_day() - philo->start_time, philo->id);
    usleep(300 * 1000);
    // msg_output(philo->id, philo, "is thinking");
    // printf("start time: %d\n", philo->start_time);
}