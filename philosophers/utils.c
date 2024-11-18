/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 16:42:23 by marvin            #+#    #+#             */
/*   Updated: 2024/11/08 16:42:23 by marvin           ###   ########.fr       */
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
}