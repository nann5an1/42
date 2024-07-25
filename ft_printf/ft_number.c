/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_number.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsan <nsan@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 16:04:51 by nsan              #+#    #+#             */
/*   Updated: 2024/06/22 19:42:06 by nsan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void ft_digit(int num, int *len)
{
	long	n;
	n = num;
	
	if (n < 0)
	{
		n = -n;
		ft_char_nlen('-', len);
	}
	if (n >= 10)
	{
		ft_digit(n / 10, len);
		ft_digit(n % 10, len);
	}
	else
	{
		ft_char_nlen((n + '0'), len);
	}
}

static void put_ptr(unsigned int ptr, int* len)
{
	if (ptr >= 16)
	{
		put_ptr((ptr / 16), len);
		put_ptr((ptr % 16), len);
	}
	else
	{
		if (ptr <= 9)
			ft_char_nlen(ptr + '0' , len);
		else
			ft_char_nlen(ptr - 10 + 'a', len);
	}
}

void    ft_pointer(unsigned int ptr, int *len)
{
	write(1,"0x", 2);
	put_ptr(ptr, len);
}

void    ft_unsigned_dec(unsigned int dec, int *len)
{
	if (dec >= 10)
		ft_unsigned_dec((dec / 10), len);
	ft_char_nlen((dec % 10 )+ '0', len);
}
static char *hexa_conversion(char *dest, unsigned int hex, int str_len, int case_flag)
{
	unsigned int remainder;
	char *str;
	
	if (case_flag == 1)
		str = "ABCDEF";
	else
		str = "abcdef";
	
	if (hex == 0)
		dest[0] = '0';
	while (hex != 0)
	{
		remainder = hex % 16;
		if (remainder <= 9)
			dest[--str_len] = remainder + '0';
		else if (remainder >= 10 && remainder <= 15)
			dest[--str_len] = str[remainder - 10];
		hex = hex / 16;
	}
	return (dest);
}

void    ft_num_hexa(unsigned int hex, int *len, int case_flag)
{
	char            *dest;
	char            *final;
	int             str_len;
	int             s_len;
	unsigned int    h;
	int i;
	h = hex;
	str_len = 0;
	i = 0;

	if (hex == 0)
		str_len++;
	while (h != 0)
	{
		str_len++;
		h = h /16;
	}
	s_len = str_len;
	dest = malloc(sizeof(char) * str_len + 1);
	dest[str_len] = '\0';
	final = hexa_conversion(dest, hex, str_len, case_flag);
	while (i < s_len)
		ft_char_nlen(final[i++], len);
}