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
    pthread_mutex_t *r_fork;
    pthread_mutex_t *l_fork;
} t_philo;

typedef struct s_program
{
    pthread_mutex_t lock_dead;
    pthread_mutex_t lock_meal;
    pthread_mutex_t lock_write;
    t_philo *philo;
} t_program;

int	ft_atoi(const char *str);
int prog_init(t_program *prog, t_philo *philo);
int fork_init(pthread_mutex_t *forks, int total_philo);
void eat_philo(pthread_mutex_t *forks, t_philo *philo);
size_t sleep_philo(t_philo *philo);
void args_input(t_philo *philo, char** av);
void* routine();
size_t current_time_of_day();
void thread_init(t_philo *philo);
void philo_init(t_philo *philo, char** av);

#endif