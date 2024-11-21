/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 15:23:05 by marvin            #+#    #+#             */
/*   Updated: 2024/11/21 19:46:11 by marvin           ###   ########.fr       */
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
    // int end_time;
    int id;
    int eating;
    int count_eaten;
    int last_eat_time;
    pthread_t thread;
    size_t num_of_philo;
    size_t time_to_die;
    size_t time_to_eat;
    size_t time_to_sleep;
    size_t num_of_times_to_eat;
    // pthread_t *forks;
    pthread_mutex_t *r_fork;
    pthread_mutex_t *l_fork;
    pthread_mutex_t *lock_dead;
    pthread_mutex_t *lock_meal;
    pthread_mutex_t *lock_write;
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
void eating(t_philo *philo);
size_t sleeping(t_philo *philo);
void thinking(t_philo *philo);
void args_input(t_philo *philo, char **av);
size_t current_time_of_day();
void thread_init(t_philo *philo);
void philo_init(t_philo *philo_arr, char** av, pthread_mutex_t *forks);
void sleep_func(size_t millisec);
void *action(void *args);
int fork_destroy(pthread_mutex_t *forks, int total_philo);
void thread_init(t_philo *philo);
int dead_check(t_philo *philo);
// void msg_output(int id, t_philo *philo, char *str);


#endif