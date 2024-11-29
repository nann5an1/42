/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 15:11:37 by nsan              #+#    #+#             */
/*   Updated: 2024/11/29 18:16:18 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	thread_init(t_philo *philo, t_program *program)
{
	pthread_t	monitor_thread;
	int			i;

	i = -1;
	while (++i < program->num_of_philo)
	{
		if (pthread_create(&philo[i].thread, NULL, \
		&action, (void *)&philo[i]) != 0)
			printf("Error in creating thread.\n");
		usleep(100);
	}
	if (pthread_create(&monitor_thread, NULL, &monitor, (void *)program) != 0)
		printf("Error in creating thread for philo monitoring\n");
	if (pthread_join(monitor_thread, NULL) != 0)
		printf("Error in joining thread for monitoring");
	i = -1;
	while (++i < program->num_of_philo)
	{
		if (pthread_join(philo[i].thread, NULL) != 0)
			printf("Error in joining thread for philo threads\n");
	}
}
