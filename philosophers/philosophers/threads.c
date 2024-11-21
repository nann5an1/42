/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 15:11:37 by nsan              #+#    #+#             */
/*   Updated: 2024/11/21 14:31:03 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"


// void *action(void *arg)
// {
// 	t_philo *philo;
// 	philo = (t_philo *)arg;
// 	// eating(philo, prog, av);
// 	sleeping(philo);
// 	return (NULL);
// }

void *action(void *args)
{
    t_philo *philo = (t_philo *)args;
    eating(philo);
    sleeping(philo);
    return (NULL);
}

// void *action(void *arg, t_philo *philo, t_program *prog, char **av)
// {
// 	eating(philo, prog, av);
// 	sleeping(philo);
// 	return (NULL);
// }

void thread_init(t_philo *philo)
{
    pthread_t thread;

    int i = 0;
    printf("num of philo from struct : %ld \n", philo->num_of_philo);
    while (i < philo->num_of_philo)
    {
        pthread_create(&thread, NULL, action, (void *)&philo[i]);
        pthread_join(thread, NULL);
        i++;
    }
}