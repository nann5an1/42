/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsan <nsan@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/15 15:32:20 by nsan              #+#    #+#             */
/*   Updated: 2024/10/27 19:28:46 by nsan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <limits.h>

static void	func_checker(char c, va_list *args, int *len)
{
	if (c == 'c')
		ft_char_nlen(va_arg(*args, int), len);
	else if (c == 's')
		ft_string(va_arg(*args, char *), len);
	else if (c == 'p')
		ft_pointer(va_arg(*args, void *), len);
	else if (c == 'd' || c == 'i')
		ft_digit(va_arg(*args, int), len);
	else if (c == 'u')
		ft_unsigned_dec(va_arg(*args, unsigned int), len);
	else if (c == 'x')
		ft_num_hexa(va_arg(*args, unsigned int), len, 1);
	else if (c == 'X')
		ft_num_hexa(va_arg(*args, unsigned int), len, 0);
	else if (c == '%')
		ft_char_nlen('%', len);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		i;
	int		len;

	i = 0;
	len = 0;
	va_start(args, str);
	while (str[i] != 0)
	{
		if (str[i] == '%')
		{
			i++;
			func_checker(str[i], &args, &len);
		}
		else
			ft_char_nlen(str[i], &len);
		i++;
	}
	va_end(args);
	return (len);
}

// int main()
// {
// 	int i = 1578111;
// 	char c = 'h';
// 	char *str = NULL;
// 	//characters
// 	ft_printf("Test char: %c\n", c);
// 	printf("Real char: %c\n", c);
// 	//string
// 	ft_printf("Test String: %s\n", str);
// 	printf("Real String: %s\n", str);
// 	//numbers
// 	ft_printf("Test number:%d\n", i);
// 	printf("Real number:%d\n", i);
// 	//percentage
//    	ft_printf("Test percentage: %d%%\n", i);
// 	printf("Real percentage: %d%%\n", i);
// 	//pointer
//     ft_printf("Test pointer addr:%p\n", &i);
// 	printf("Real Pointer addr:%p\n", &i);
// 	//unsigned integer
// 	ft_printf("Test unsigned dec: %u\n", i);
// 	printf("Real unsigned dec: %u\n", i);
// 	//base 16 lowercase format
// 	ft_printf("Test hexa lowercase:%x\n", c);
// 	printf("Real hexa lowercase: %x\n", c);
// 	//base 16 uppercase format
// 	ft_printf("Test hexa upper: %X\n", i);
// 	printf("Real hexa upper: %X ", i);
// 	//mix
// 	ft_printf("%d%%", 5);
// 	ft_printf("%i%c", 0, '*');
// }