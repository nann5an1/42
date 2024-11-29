/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 16:42:23 by marvin            #+#    #+#             */
/*   Updated: 2024/11/29 18:22:37 by marvin           ###   ########.fr       */
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

int	is_digit(unsigned char c)
{
	if ((c >= '0' && c <= '9') || c == '+')
		return (0);
	return (1);
}

int	validate_digits(char **argv)
{
	int	i;
	int	j;

	i = 0;
	while (argv[++i])
	{
		j = -1;
		while (argv[i][++j])
		{
			if (is_digit (argv[i][j]) == 1)
				return (1);
		}
	}
	return (0);
}

void	print_message(t_philo *philo, const char *message)
{
	pthread_mutex_lock(&philo->program->lock_write);
	printf("%ld %d %s\n", current_time_of_day() - philo->start_time, \
	philo->id, message);
	pthread_mutex_unlock(&philo->program->lock_write);
}
