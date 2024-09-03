/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoiBase.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 16:16:53 by marvin            #+#    #+#             */
/*   Updated: 2024/09/03 16:16:53 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
int	ft_atoi_base(const char *str, int str_base)
{
    int res = 0;
    int sign = 1;
    int i = 0;

    if(str == NULL || str_base < 2 || str_base > 16)
        return (0);
    
    if(str[i] == '-')
    {
        sign = -1;
        i++;
    }
    else if(str[i] == '+')
        i++;
    
    while(str[i] >= '0' && str[i] <= '9' && str[i] - '0' < str_base)
    {
        res = res * str_base + (str[i] - '0');
        i++;
    }
    while(str[i] >= 'A' && str[i] <= 'F' && str[i] - 'A' < str_base - 10)
    {
        res = res * str_base + (str[i] - 'A' + 10);
        i++;
    }
    while(str[i] >= 'a' && str[i] <= 'f' && str[i] - 'a' < str_base - 10)
    {
        res = res * str_base + (str_base - 'a' + 10);
        i++;
    }
    return (sign * res);
}
int main()
{
    char* str = "125";
    printf("%d", ft_atoi_base(str, 16));
}