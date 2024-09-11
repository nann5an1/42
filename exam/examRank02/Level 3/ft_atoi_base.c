/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/25 12:08:43 by marvin            #+#    #+#             */
/*   Updated: 2024/08/25 12:08:43 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

// int	ft_atoi_base(const char *str, int str_base)
// {
// 	int	res;
// 	int	sign;
// 	int	i;

// 	if (str_base < 2 || str_base > 16)
// 		return (0);
// 	res = 0;
// 	sign = 1;
// 	i = 0;
// 	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n' || str[i] == '\r' || str[i] == '\v' || str[i] == '\f')
// 		i++;
// 	if (str[i] == '-')
// 	{
// 		sign = -1;
// 		i++;
// 	}
// 	else if (str[i] == '+')
// 		i++;
// 	while (str[i] >= '0' && str[i] <= '9' && str[i] - '0' < str_base)
// 	{
// 		res = res * str_base + (str[i] - '0');
// 		i++;
// 	}
// 	while (str[i] >= 'A' && str[i] <= 'F' && str[i] - 'A' < str_base - 10)
// 	{
// 		res = res * str_base + (str[i] - 'A' + 10);
// 		i++;
// 	}
// 	while (str[i] >= 'a' && str[i] <= 'f' && str[i] - 'a' < str_base - 10)
// 	{
// 		res = res * str_base + (str[i] - 'a' + 10);
// 		i++;
// 	}
// 	return (res * sign);
// }

int	ft_atoi_base(const char *str, int str_base)
{
	int sign = 1;
	int i = 0;
	int res = 0;
	while(str[i] == '\t' || str[i] == '\v' || str[i] == '\r' || str[i] == '\f')
		i++;
	if(str[i] == '+')
		i++;
	else if(str[i] == '-')
		sign = -1;
	while(str[i] >= '0' && str[i] <= '9' && str[i] - '0' < str_base)
	{
		res = res * str_base + str[i] - '0';
		i++;
	}
	while(str[i] >= 'A' && str[i] <= 'F' && str[i] - 'A' < str_base - 10)
	{
		res = res * str_base + (str[i] - 'F' + 10);
		i++;
	}
	while(str[i] >= 'a' && str[i] <= 'f' && str[i] - 'a' < str_base - 10)
	{
		res = res * str_base + (str[i] - 'a' + 10);
		i++;
	}	
	return (res * sign);
}
int main()
{
    char* str = "125";
    printf("%d", ft_atoi_base(str, 2));
}

