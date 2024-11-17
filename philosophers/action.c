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
void eat(pthread_mutex_t *forks, t_philo *philo)
{
    int l_fork = philo->id;
    int r_fork = (philo->id + 1);

    pthread_mutex_lock(&forks[l_fork]);
    pthread_mutex_lock(&forks[r_fork]);

    printf("%d is eating\n", philo->id);
    
    pthread_mutex_unlock(&forks[l_fork]);
    pthread_mutex_unlock(&forks[r_fork]);
}

// void sleep()
// {

// }


// void think()
// {


// }