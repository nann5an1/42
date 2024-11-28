/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 23:20:43 by marvin            #+#    #+#             */
/*   Updated: 2024/11/29 01:02:42 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void program_init(pthread_mutex_t *forks, t_program *program, t_philo *philo, int total_philos)
{
    int i;
    
    i = 0;
    program->dead = 0;
    program->philo = philo;
    pthread_mutex_init(&program->lock_dead, NULL);
    pthread_mutex_init(&program->lock_meal, NULL);
    pthread_mutex_init(&program->lock_write, NULL);

    while (i < total_philos)
    {
        pthread_mutex_init(&philo[i].lock_meal_count, NULL);
        pthread_mutex_init(&forks[i], NULL);
        i++;
    }
}

void philo_init(t_program *program, t_philo *philo_arr, char** av, pthread_mutex_t *forks)
{
    int i;
    i = 0;
    args_input(program, av);
    while (i < ft_atoi(av[1]))
    {
        philo_arr[i].id = i + 1;
        philo_arr[i].eating = 0;
        philo_arr[i].start_time = current_time_of_day();
        philo_arr[i].last_eat_time = current_time_of_day();
        philo_arr[i].count_eaten = 0;
        philo_arr[i].l_fork =  &forks[i];
        philo_arr[i].r_fork = &forks[(i + 1) % ft_atoi(av[1])];
        philo_arr[i].program = program;
        i++;
    }
}


void args_input(t_program *program, char **av)
{
    program->num_of_philo = ft_atoi(av[1]);
    program->time_to_die =  ft_atoi(av[2]);
    program->time_to_eat =  ft_atoi(av[3]);
    program->time_to_sleep =  ft_atoi(av[4]);
    if (av[5])
        program->num_of_times_to_eat =  ft_atoi(av[5]);
    else
        program->num_of_times_to_eat = -1;
}

