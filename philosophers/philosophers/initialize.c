/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 23:20:43 by marvin            #+#    #+#             */
/*   Updated: 2024/11/21 19:34:18 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int prog_init(t_program *prog, t_philo *philo)
{
    //mutex initialization
    prog->philo = philo;
    printf("Philo thead has been created\n");
    return (0);
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
    return (0);
}

int fork_destroy(pthread_mutex_t *forks, int total_philo)
{
    int i;

    i = 0;
    while (i < total_philo)
    {
        pthread_mutex_destroy(&forks[i]);
        i++;
    }
    printf("fork mutex has been destroyed\n");
    return (0);
}

void philo_init(t_philo *philo_arr, char** av, pthread_mutex_t *forks)
{
    int i;
    i = 0;
    while (i < ft_atoi(av[1]))
    {
        // printf("i value in philo_init : %d\n", i);
        philo_arr[i].id = i + 1;
        philo_arr[i].eating = 0;
        args_input(&philo_arr[i], av);
        philo_arr[i].start_time = current_time_of_day();
        philo_arr[i].last_eat_time = current_time_of_day();
        philo_arr[i].count_eaten = 0;
        philo_arr[i].l_fork =  &forks[i];
        philo_arr[i].r_fork = &forks[i] + 1 % ft_atoi(av[1]);
        // printf("philo id %d\n", philo_arr[i].id);
        // printf("philo start time %d\n", philo_arr[i].start_time);
        // printf("philo end time %d\n", philo_arr[i].end_time);
        // printf("philo eaten count %d\n\n", philo_arr[i].count_eaten);
        // thread_init(philo);
        i++;
    }
}

void args_input(t_philo *philo, char **av)
{

    // printf("args input\n");
    // printf("%d\n", ft_atoi(av[1]));
    philo->num_of_philo = ft_atoi(av[1]);
    //  printf("NUM OF PHILOS\n");
    philo->time_to_die =  ft_atoi(av[2]);
    philo->time_to_eat =  ft_atoi(av[3]);
    philo->time_to_sleep =  ft_atoi(av[4]);
    if (av[5])
        philo->num_of_times_to_eat =  ft_atoi(av[5]);
    // printf("before malloc\n");
    // philo = malloc(sizeof(t_philo) * philo->num_of_philo);
    // printf("%ld\n", philo->num_of_philo);
    // printf("%ld\n", philo->time_to_die);
    // printf("%ld\n", philo->time_to_sleep);
    // printf("%ld\n", philo->time_to_eat);
    // printf("%ld\n", philo->num_of_times_to_eat);
}

