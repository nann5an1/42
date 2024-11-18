/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 20:14:15 by marvin            #+#    #+#             */
/*   Updated: 2024/11/17 20:14:15 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
void eat_philo(pthread_mutex_t *forks, t_philo *philo)
{
    int l_fork = philo->id;
    int r_fork = (philo->id + 1);

    pthread_mutex_lock(&forks[l_fork]);
    pthread_mutex_lock(&forks[r_fork]);

    printf("%d is eating\n", philo->id);

    pthread_mutex_unlock(&forks[l_fork]);
    pthread_mutex_unlock(&forks[r_fork]);
}


size_t sleep_philo(t_philo *philo)
{
    struct timeval tv;
    if (gettimeofday(&tv, NULL) == 0)
    {
        printf("%d is sleeping\n", philo->id);
        usleep(1000000);
        return (tv.tv_sec * 1000 + tv.tv_usec / 1000);
    }
    printf("Error in gettimeofday.\n");
   
}


// void think()
// {


// }