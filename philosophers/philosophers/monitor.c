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

// int dead_check(t_philo *philo)
// {
//     // printf("Last eating time : %d\n", philo->last_eat_time);
//     if(current_time_of_day() - philo->last_eat_time > philo->time_to_die)
//     {
//         // printf("The philo has died\n");
//         return (1);
//     }
//     return (0); 
// }