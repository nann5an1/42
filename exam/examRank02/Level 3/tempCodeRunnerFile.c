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

#include <unistd.h>
#include <stdio.h>

char toLower(char c)
{
	if(c >= 'A' && c <= 'Z')
		return (c - ('a' - 'A'));
	return (c);
}
int getDigit(char c, int base)
{
	int max_digit;

	if(base <= 10)
		max_digit = base - 1 + '0';
	else
		max_digit = base - 10 - 1 + 'a';

	if(c >= '0' && c <= '9' && c <= max_digit)
		return (c - '0');
	else if(c >= 'a' && c <= 'z' && c <= max_digit)
		return (10 + c - 'a');
	else
		return (-1);
}
int	ft_atoi_base(const char *str, int str_base)
{

	int sign = 1;
	int result = 0;

	if(str == NULL || str_base < 2 || str_base > 16)
		return (0);
	if(*str == '-')
	{
		sign = -1;
		++str;
	}
	
	while(*str)
	{
		int digit = getDigit(toLower((*str)), str_base);
		if(digit = -1)
			break;
		result = result * str_base + digit;
		++str;
	}
	return (sign * result);
}
int main()
{
    char* str = "125";
    printf("%d", ft_atoi_base(str, 10));
}