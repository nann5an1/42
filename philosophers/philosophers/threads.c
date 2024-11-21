/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 15:11:37 by nsan              #+#    #+#             */
/*   Updated: 2024/11/21 18:11:32 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
void *action(void *args)
{
    t_philo *philo = (t_philo *)args;
    eating(philo);
    sleeping(philo);
    thinking(philo);
    return (NULL);
}

void thread_init(t_philo *philo)
{
    pthread_t thread;

    int i = 0;
    printf("num of philo from struct : %ld \n", philo->num_of_philo);
    while (i < philo->num_of_philo)
    {
        pthread_create(&thread, NULL, action, (void *)&philo[i]);
        i++;
    }
    i = 0;
    while (i < philo->num_of_philo)
    {
        pthread_join(thread, NULL);
        i++;
    }
}