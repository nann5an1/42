/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 16:42:23 by marvin            #+#    #+#             */
/*   Updated: 2024/11/22 14:23:58 by marvin           ###   ########.fr       */
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
// int	main(void)
// {
// 	char	str[] = "++278520005";
// 	printf("%d\n", ft_atoi(str));
// 	char *s = "++278520005";
// 	int res = atoi(s);
// 	printf("%d\n", res);
// }


size_t current_time_of_day()
{
	struct timeval tv;
	if (gettimeofday(&tv, NULL) == 0)
        return (tv.tv_sec * 1000 + tv.tv_usec / 1000);
    printf("Error in gettimeofday.\n");
	return (0);
}

void sleep_func(size_t millisec)
{
	size_t start;

	start = current_time_of_day();
	if (current_time_of_day() - start < millisec)
		usleep (500);
}

void destroy(t_philo *philo, pthread_mutex_t *forks)
{
	int i;

	i = 0;
	while(i < philo->num_of_philo)
	{
		pthread_mutex_destroy(&forks[i]);
		i++;
	}
	printf("mutex has been destroyed\n");
}

// int dead_lock(t_philo *philo)
// {
// 	pthread_mutex_lock(philo->lock_dead);
// 	if (*philo->dead == 1)
// 		return (pthread_mutex_unlock(philo->lock_dead), 1);
// 	return (pthread_mutex_unlock(philo->lock_dead), 0);
// }

// void msg_output(char *str, t_philo *philo, int id)
// {
// 	size_t time;

// 	pthread_mutex_lock(philo->lock_write);
// 	printf("Inside msg_output\n");
// 	// printf("start time: %d", philo->start_time);
// 	time = current_time_of_day() - philo->start_time;
// 	// printf("Inside msg_output 1\n");
// 	// printf("Time: %ld\n", time);
// 	if(dead_lock(philo) == 0)
// 		printf("%ld %d %s\n", time, id, str);
// 	pthread_mutex_unlock(philo->lock_write);
// }
