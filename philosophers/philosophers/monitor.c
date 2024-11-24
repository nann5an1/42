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


int philo_died(t_philo *philo) //iterated through each philo to see if it has died
{
    // printf("time to die for philo %d : %ld\n", philo[i].id, philo[i].time_to_die);
    pthread_mutex_lock(philo->lock_meal);
    if(current_time_of_day() - philo->last_eat_time >= philo->time_to_die) //|| (philo[i].time_to_die < philo[i].time_to_eat))   //one of the philo has died
        return (pthread_mutex_unlock(philo->lock_meal), 1);
    return (pthread_mutex_unlock(philo->lock_meal), 0);
}
int check_if_died(t_philo *philo)
{
    int i;
    i = 0;
    while (i < philo->num_of_philo)
    {
         if(philo_died(&philo[i]) == 1)
        {
            pthread_mutex_lock(philo->lock_dead);
            *philo->dead = 1;
            pthread_mutex_unlock(philo->lock_dead);
            return (1);
        }
        i++;
    }
    return (0);
}


// int check_if_all_eaten(t_philo *philo)
// {
//     int i;

//     int total_philo = philo->num_of_philo;
//     i = 0;
//     while (i < total_philo)
//     {
//         printf("num of times to eat for philo %d : %ld\n", philo[i].id, philo[i].num_of_times_to_eat);
//         if(philo[i].count_eaten < philo[i].num_of_times_to_eat) //all of the philo has eaten all no. of times
//             return (0);
//         i++;
//     }
//     return (1);
// }

void *monitor(void *args)
{
    t_philo *philo = (t_philo *)args;
    // if (check_if_died(philo) == 1)
    // int i;
    // i = 1;
   
   while (1)
   {
        if(check_if_died(philo) == 1)
            break;
   }
   return (args);
    // printf("<<<NUM OF PHILOS>>> %ld\n", philo[1].num_of_philo);
    // if (check_if_died(philo) == 1)
    //     printf("Philo has died\n");
    // if (check_if_all_eaten(philo) == 1) //all the philo has eaten all
    //     printf("All philos can eat everything\n");
    // else
    //     printf("not all philos have eaten all\n");
    // return (NULL);
}

// void *monitor(void *args)
// {
//     t_philo *philo = (t_philo *)args;
//     while (1)
//     {
//         if (check_if_died(philo))
//         {
//             pthread_mutex_lock(philo->lock_dead);
//             *philo->dead = 1;
//             pthread_mutex_unlock(philo->lock_dead);
//             break; // Exit the loop once a philosopher dies
//         }
//     }
//     return NULL;
// }