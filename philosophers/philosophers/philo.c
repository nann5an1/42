/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsan <nsan@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 15:22:40 by marvin            #+#    #+#             */
/*   Updated: 2024/11/20 20:10:16 by nsan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_atoi(const char *str);

int is_digit(char c)
{
    if(c >= '0' && c <= '9')
        return (0);
    else if((c >= 33 && c <= 47) || c >= 58 && c <= 127)
        return (2);
    return (1);
}
int validate_digits(char **argv)
{
    int i;
    int j;

   i = 0;
   while(argv[++i])
   {
        j = -1;
        while(argv[i][++j])
        {
            if(is_digit(argv[i][j]) == 1)
                return (1);
        }
   }
   return (0);
}



int validate_args(char **argv)
{
    if (validate_digits(argv) == 1)
        return (printf("Number range is less than 0.\n"), 1);
    else if (validate_digits(argv) == 2)
        return (printf("Invalid characters in the range.\n"),2);
    if(ft_atoi(argv[1]) <= 0 || ft_atoi(argv[1]) > PHILOMAX)
        return (printf("Philosopher numbers invalid.\n"), 1);
    else if(ft_atoi(argv[2]) <= 0)
        return (printf("Time to die cannot be less than 0.\n"), 1);
    else if(ft_atoi(argv[3]) <= 0)
        return (printf("Time to eat cannot be less than 0.\n"), 1);
    else if(ft_atoi(argv[4]) <= 0)
        return (printf("Time to sleep cannot be less than 0.\n"), 1);
    else if(argv[5] && ft_atoi(argv[5]) < 0)
        return (printf("Invalid number of times to eat.\n"), 1);
    return (0);
}

int main(int argc, char** argv)
{
    pthread_t thread;
    t_program prog;
    t_philo philo[PHILOMAX];
    pthread_mutex_t forks[PHILOMAX];

    if (argc < 5 || argc > 6)
        return(printf("Total Arguments Must either be 5 or 6.\n"), 1);
    if (validate_args(argv) == 1 || validate_args(argv) == 2)
        return (1);
    else
        printf("All okay:)\n");
    // args_input(&philo, argv);
    printf("inside main\n");

    // prog_init(&prog, &philo);
    fork_init(forks, ft_atoi(argv[1]));
    // philo_arr = malloc(sizeof(t_philo) * philo.num_of_philo);
    printf("malloc done\n");
    philo_init(philo, argv, forks);
    // eating(philo, &prog, argv);
    fork_destroy(forks, ft_atoi(argv[1]));
    // thread_init(philo); //--> thread and philo creation

    // printf("%ld\n", sleep_philo(&philo));


}

//input argument --> total 6 arguments
//number_of_philosophers > time_to_die > time_to_eat > time_to_sleep > number_of_times_each_philosopher_must_eat(optional)
//check for input arguments --> must be numbers and not be less than 0 or more than the number of philosophers
