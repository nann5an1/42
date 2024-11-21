/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsan <nsan@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 15:11:37 by nsan              #+#    #+#             */
/*   Updated: 2024/11/20 20:10:35 by nsan             ###   ########.fr       */
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

// void *action(void *arg, t_philo *philo, t_program *prog, char **av)
// {
// 	eating(philo, prog, av);
// 	sleeping(philo);
// 	return (NULL);
// }

// void thread_init(t_philo *philo)
// {
//     pthread_t thread;

//     pthread_create(&thread, NULL, action, (void *)philo);
//     pthread_join(thread, NULL);
//     // pthread_detach(thread);
// }