/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 15:22:40 by marvin            #+#    #+#             */
/*   Updated: 2024/11/29 01:06:10 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int validate_args(char **argv)
{
    if (validate_digits(argv) == 1)
        return (printf("Only whole positive numbers are valid for input.\n"), 1);
    if(ft_atoi(argv[1]) <= 0)
        return (printf("Philospher count cannot be 0.\n"), 1);
    // else if(ft_atoi(argv[1]) > PHILOMAX)
    //     return ()
    else if(ft_atoi(argv[2]) <= 0)
        return (printf("Time to die must be greater than 0.\n"), 1);
    else if(ft_atoi(argv[3]) <= 0)
        return (printf("Time to eat must be greater than 0.\n"), 1);
    else if(ft_atoi(argv[4]) <= 0)
        return (printf("Time to sleep must be greater than 0.\n"), 1);
    else if(argv[5] && ft_atoi(argv[5]) < 0)
        return (printf("Invalid number of times to eat.\n"), 1);
    return (0);
}

int main(int argc, char** argv)
{
    t_program program;
    t_philo philo[PHILOMAX];
    pthread_mutex_t forks[PHILOMAX];

    if (argc < 5 || argc > 6)
        return(printf("ERROR.Total Arguments Must either be 5 or 6.\n"), 1);
    if (validate_args(argv) == 1)
        return (1);
    program_init(forks, &program, philo, ft_atoi(argv[1]));
    philo_init(&program, philo, argv, forks);
    thread_init(philo, &program);
    destroy_all(&program, forks);
}

