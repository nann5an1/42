/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 15:23:05 by marvin            #+#    #+#             */
/*   Updated: 2024/11/08 15:23:05 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
#define PHILO_H

#ifndef PHILOMAX
#define PHILOMAX 200
#endif

#include <unistd.h>
#include <stdlib.h>
#include <sys/time.h>
#include <stdio.h>
#include <pthread.h>



typedef struct s_philo
{
    int start_time;
    int end_time;
    int id;
    int eating;
    int count_eaten;
    pthread_t thread;
    size_t num_of_philo;
    size_t time_to_die;
    size_t time_to_eat;
    size_t time_to_sleep;
    size_t num_of_times_to_eat;
    pthread_t *forks;

} t_philo;

typedef struct s_program
{
    pthread_mutex_t lock_dead;
    pthread_mutex_t lock_meal;
    pthread_mutex_t lock_write;
    t_philo *philo;
} t_program;

#endif