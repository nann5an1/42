/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 19:31:39 by marvin            #+#    #+#             */
/*   Updated: 2024/11/21 19:31:39 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int check_if_died(t_philo *philo)
{
    int i;
    i = 0;
    printf("time to die for philo %d : %ld\n", philo[i].id, philo[i].time_to_die);
    while (i < philo->num_of_philo)
    {
        if((current_time_of_day() - philo[i].last_eat_time > philo[i].time_to_die) || (philo[i].time_to_die < philo[i].time_to_eat))   //one of the philo has died
            return (1);
       i++;
    }
    // printf("Last eating time : %d\n", philo->last_eat_time);
    return (0); 
}

int check_if_all_eaten(t_philo *philo)
{
    int i;

    int total_philo = philo->num_of_philo;
    i = 0;
    while (i < total_philo)
    {
        printf("num of times to eat for philo %d : %ld\n", philo[i].id, philo[i].num_of_times_to_eat);
        if(philo[i].count_eaten < philo[i].num_of_times_to_eat) //all of the philo has eaten all no. of times
            return (0);
        i++;
    }
    return (1);
}

void *monitor(void *args)
{
    t_philo *philo = (t_philo *)args;
    // if (check_if_died(philo) == 1)
    int i;
    i = 1;
   
    printf("<<<NUM OF PHILOS>>> %ld", philo[1].num_of_philo);
    while (i <= philo->num_of_philo)
    {
        printf("inside while of check death");
        printf("time to die for philo %d : %ld\n", philo[i].id, philo[i].time_to_die);
        if((current_time_of_day() - philo[i].last_eat_time > philo[i].time_to_die) || (philo[i].time_to_die < philo[i].time_to_eat))   //one of the philo has died
            printf("Philo has died\n");
       i++;
    }
        // printf("Philo has died\n");
    if (check_if_all_eaten(philo) == 1) //all the philo has eaten all
        printf("All philos can eat everything\n");
    else
        printf("not all philos have eaten all\n");
    return (NULL);
}