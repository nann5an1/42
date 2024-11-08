/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 23:20:43 by marvin            #+#    #+#             */
/*   Updated: 2024/11/08 23:20:43 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int init_prog(t_program *prog, t_philo *philo)
{
    pthread_create(philo, NULL, prog, NULL);
    prog->philo = philo;

}

int init_fork(pthread_mutex_t *forks, int total_philo)
{
    pthread_t fork;
    int i;
    i = 0;
    while (i < total_philo)
    {
        pthread_mutex_init(&forks[i], NULL);
        i++;
    }
}