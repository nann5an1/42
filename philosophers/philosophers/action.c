/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsan <nsan@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 20:14:15 by marvin            #+#    #+#             */
/*   Updated: 2024/11/20 20:09:11 by nsan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void eating(t_philo *philo, char **av)
{
    // printf("inside eating\n");
    int i;
    i = 0;
    while (i < ft_atoi(av[1]))
    {
        printf("philo id: %d \n", philo[i].id);
        // printf("inside while eating\n");
        if (philo[i].id % 2 == 0)
        {
            // printf("inside while eating1\n");
            pthread_mutex_lock(philo[i].r_fork);
            // printf("inside eating after right fork\n");
            printf("Philo %d has taken the right fork\n", philo[i].id);
            pthread_mutex_lock(philo[i].l_fork);
            printf("Philo %d has taken the left fork\n", philo[i].id);
        }
        else
        {
            // printf("inside while eating2\n");
            pthread_mutex_lock(philo[i].l_fork);
            // printf("inside eating after left fork\n");
            printf("Philo %d has taken the left fork\n", philo[i].id);
            pthread_mutex_lock(philo[i].r_fork);
            printf("Philo %d has taken the right fork\n", philo[i].id);
        }

        // pthread_mutex_lock(&prog->lock_meal);

        philo[i].eating = 1;
        printf("%d is eating\n", philo[i].id);
        usleep(500 * 1000);
        philo[i].count_eaten++;
        // printf("philo %d has eaten %d times\n", philo[i].id, philo[i].count_eaten);
        // pthread_mutex_unlock(&prog->lock_meal);
        pthread_mutex_unlock(philo[i].l_fork);
        pthread_mutex_unlock(philo[i].r_fork);
        i++;
    }
}

size_t sleeping(t_philo *philo)
{
    struct timeval tv;
    if (gettimeofday(&tv, NULL) == 0)
    {
        printf("%d is sleeping\n", philo->id);
        usleep(1000000);
        return (tv.tv_sec * 1000 + tv.tv_usec / 1000);
    }
    printf("Error in gettimeofday.\n");
    return (0);
}


// void think()
// {


// }