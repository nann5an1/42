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

int prog_init(t_program *prog, t_philo *philo)
{
    //mutex initialization
    prog->philo = philo;
    printf("Philo thead has been created\n");
}

int fork_init(pthread_mutex_t *forks, int total_philo)
{
    int i;

    i = 0;
    while (i < total_philo)
    {
        pthread_mutex_init(&forks[i], NULL);
        i++;
    }
    printf("fork mutex has been has been initiated\n");
}

void philo_init(t_philo *philo, char** av)
{
    int i;
    i = 0;
    while (i < ft_atoi(av[1]))
    {
        // printf("%d\n", i);
        philo[i].id = i + 1;
        philo[i].eating = 0;
        philo[i].start_time = current_time_of_day();
        philo[i].end_time = current_time_of_day();
        philo[i].count_eaten = 0;
        // printf("philo id %d\n", philo[i].id);
        // printf("philo start time %d\n", philo[i].start_time);
        // printf("philo end time %d\n", philo[i].end_time);
        // printf("philo eaten count %d\n\n", philo[i].count_eaten);
        thread_init(philo);
        i++;
    }
}

void args_input(t_philo *philo, char** av)
{
    philo->num_of_philo = ft_atoi(av[1]);
    philo->time_to_die =  ft_atoi(av[2]);
    philo->time_to_eat =  ft_atoi(av[3]);
    philo->time_to_sleep =  ft_atoi(av[4]);
    if (av[5])
        philo->num_of_times_to_eat =  ft_atoi(av[5]);
    printf("%ld\n", philo->num_of_philo);
    printf("%ld\n", philo->time_to_die);
    printf("%ld\n", philo->time_to_sleep);
    printf("%ld\n", philo->time_to_eat);
    printf("%ld\n", philo->num_of_times_to_eat);
}

void thread_init(t_philo *philo)
{
    pthread_t thread;

    pthread_create(&thread, NULL, &routine, NULL);
    pthread_join(thread, NULL);
    pthread_detach(thread);
}