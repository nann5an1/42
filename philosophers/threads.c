/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 13:49:12 by marvin            #+#    #+#             */
/*   Updated: 2024/11/19 13:49:12 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

//this function will include all the think, sleep, eat routine that the philo does inside create
void thread_init(t_philo *philo)
{
    pthread_t thread;

    pthread_create(&thread, NULL, &routine, NULL);
    pthread_join(thread, NULL);
    pthread_detach(thread);
}