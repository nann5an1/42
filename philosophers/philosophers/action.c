/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 20:14:15 by marvin            #+#    #+#             */
/*   Updated: 2024/11/21 21:00:11 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

// void eating(t_philo *philo)
// {
//     // printf("inside eating\n");
//     int i;
//     i = 0;
//     // printf("num of philo from struct : %ld \n", philo->num_of_philo);
//     while (i < philo->num_of_philo)
//     {
//         printf("philo id: %d \n", philo[i].id);
//         // printf("inside while eating\n");
//         if (philo[i].id % 2 == 0)
//         {
//             // printf("inside while eating1\n");
//             pthread_mutex_lock(philo[i].r_fork);
//             // printf("inside eating after right fork\n");
//             printf("Philo %d has taken the right fork\n", philo[i].id);
//             pthread_mutex_lock(philo[i].l_fork);
//             printf("Philo %d has taken the left fork\n", philo[i].id);
//         }
//         else
//         {
//             // printf("inside while eating2\n");
//             pthread_mutex_lock(philo[i].l_fork);
//             // printf("inside eating after left fork\n");
//             printf("Philo %d has taken the left fork\n", philo[i].id);
//             pthread_mutex_lock(philo[i].r_fork);
//             printf("Philo %d has taken the right fork\n", philo[i].id);
//         }

//         // pthread_mutex_lock(&prog->lock_meal);

//         philo[i].eating = 1;
//         printf("%d is eating\n", philo[i].id);
//         usleep(500 * 1000);
//         philo[i].count_eaten++;
//         // printf("philo %d has eaten %d times\n", philo[i].id, philo[i].count_eaten);
//         // pthread_mutex_unlock(&prog->lock_meal);
//         pthread_mutex_unlock(philo[i].l_fork);
//         pthread_mutex_unlock(philo[i].r_fork);
//         i++;
//     }
// }


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