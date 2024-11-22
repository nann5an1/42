/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 15:11:37 by nsan              #+#    #+#             */
/*   Updated: 2024/11/22 16:18:56 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
void *action(void *args)
{
    t_philo *philo = (t_philo *)args;
    while (!philo->count_eaten || philo->count_eaten < philo->num_of_times_to_eat)
    {
        // if(philo->count_eaten >= philo->num_of_philo)
        //     break;
        // else
        // {
            eating(philo);
            sleeping(philo);
            thinking(philo);
        // }
    }
   
    return (NULL);
}

void thread_init(t_philo *philo, t_program *prog)
{
    pthread_t monitor_thread;

    int i = 0;
    // printf("num of philo from struct : %ld \n", philo->num_of_philo);
    
    //thread creation of philo monitoring
    // while (i < philo->num_of_philo)
    // {
    if (pthread_create(&monitor_thread, NULL, monitor, prog->philo) != 0)
        printf("Error in creating thread for philo monitoring\n");
    //     i++;
    // }
    i = 0;
    //thread creation for philo action
    while (i < philo->num_of_philo)
    {
        if (pthread_create(&philo[i].thread, NULL, action, (void *)&philo[i]) != 0)
            printf("Error in creating thread.\n");
        i++;
    }
        
    i = 0;
    //thread joining for waiting all actions of each philos
    printf("num of philos: %ld\n", philo->num_of_philo);
    while (i < philo->num_of_philo)
    {
        if (pthread_join(philo[i].thread, NULL) != 0)
            printf("Error in joining thread for philo threads\n");
        i++;
    }

        
    if(pthread_join(monitor_thread, NULL) != 0)
        printf("Error in joining thread for monitoring");
}