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
void eating(pthread_mutex_t *forks, t_philo *philo, char** av)
{
    int i;
    i = 1;
    int total_philo = ft_atoi(av[1]);
    while (i <= total_philo)
    {
        printf("i iterated no: %d\n", i);
        printf("philo id no: %d\n", philo->id);
        int l_fork = philo->id;
        printf("left fork %d\n", philo->id);
        int r_fork = (philo->id + 1);
        printf("right fork%d\n", philo->id);

        if (l_fork < r_fork)
        {
            printf("inside if\n");
            pthread_mutex_lock(&forks[l_fork]);
            pthread_mutex_lock(&forks[r_fork]);
        }
        else
        {
            pthread_mutex_lock(&forks[r_fork]);
            pthread_mutex_lock(&forks[l_fork]);
        }
        philo->eating = 1;
        usleep(philo->time_to_eat * 100);
        philo->count_eaten++;
        printf("philo %d is eating\n", philo->id);
        printf("philo no. of eaten times: %d\n", philo->count_eaten);

        philo->eating = 0;
        pthread_mutex_unlock(&forks[l_fork]);
        pthread_mutex_unlock(&forks[r_fork]);
        // philo->id++;
        printf("last line of while %d\n", i);
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
   
}


// void think()
// {


// }