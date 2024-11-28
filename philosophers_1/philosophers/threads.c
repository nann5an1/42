/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 15:11:37 by nsan              #+#    #+#             */
/*   Updated: 2024/11/28 12:09:02 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void *action(void *args)
{
	t_philo *philo = (t_philo *)args;
	while (1)
	{
		pthread_mutex_lock(program->lock_dead);
		if(philo->dead)
		{
			pthread_mutex_unlock(program->lock_dead);
			break;
		}
		pthread_mutex_unlock(program->lock_dead);
		if(flag_death_check(philo) == 0)
		{
			if (philo->num_of_philo == 1)
			{
				eating(philo);
				break;
			}
			eating(philo);
			sleeping(philo);
			thinking(philo);
		}
		else
			break ;
	}
	// while (*philo->dead == 0 && (philo->num_of_times_to_eat == -1|| philo->count_eaten <= philo->num_of_philo))
	// {
	//     if(flag_death_check(philo) == 0)
	//     {
	//         eating(philo);
	//         sleeping(philo);
	//         thinking(philo);
	//     }
	//     else
	//         break;
	// }
	return (args);
}

void thread_init(t_philo *philo, t_program *prog)
{
	pthread_t monitor_thread;

	int i;

	i = 0;
	//thread creation for philo action
	while (i < philo->num_of_philo)
	{
		if (pthread_create(&philo[i].thread, NULL, action, (void *)&philo[i]) != 0)
			printf("Error in creating thread.\n");
		i++;
	}

	if (pthread_create(&monitor_thread, NULL, monitor, (void *)prog) != 0)
	    printf("Error in creating thread for philo monitoring\n");


	i = 0;
	while (i < philo->num_of_philo)
	{
		if (pthread_join(philo[i].thread, NULL) != 0)
			printf("Error in joining thread for philo threads\n");
		i++;
	}

	if(pthread_join(monitor_thread, NULL) != 0)
	    printf("Error in joining thread for monitoring");
}
