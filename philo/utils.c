/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 16:42:23 by marvin            #+#    #+#             */
/*   Updated: 2024/11/29 12:59:22 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_atoi(const char *str)
{
	int	i;
	int	sign;
	int	nb;

	i = 0;
	sign = 1;
	nb = 0;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n' || str[i] == '\v'
		|| str[i] == '\f' || str[i] == '\r')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		nb = nb * 10 + (str[i] - '0');
		i++;
	}
	return (nb * sign);
}

int is_digit(unsigned char c)
{
    if((c >= '0' && c <= '9') || c == '+')
        return (0);
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

time_t current_time_of_day()
{
	struct timeval tv;
	if (gettimeofday(&tv, NULL) == 0)
        return ((tv.tv_sec * 1000) + (tv.tv_usec / 1000));
    printf("Error in gettimeofday.\n");
	return (0);
}

int flag_death_check(t_philo *philo)
{
	int temp;

	pthread_mutex_lock(&philo->program->lock_dead);
	temp = philo->program->dead;
	pthread_mutex_unlock(&philo->program->lock_dead);
	return (temp);
}

void print_message(t_philo *philo, const char *message)
{
    pthread_mutex_lock(&philo->program->lock_write);
    printf("%ld %d %s\n", current_time_of_day() - philo->start_time, philo->id, message);
    pthread_mutex_unlock(&philo->program->lock_write);
}

void destroy_all(t_program *program, pthread_mutex_t *forks)
{
	int i;

	i = 0;
	pthread_mutex_destroy(&program->lock_dead);
	pthread_mutex_destroy(&program->lock_meal);
	pthread_mutex_destroy(&program->lock_write);
	while(i < program->num_of_philo)
	{
		pthread_mutex_destroy(&program->philo[i].lock_meal_count);
		pthread_mutex_destroy(&forks[i]);
		i++;
	}
}




