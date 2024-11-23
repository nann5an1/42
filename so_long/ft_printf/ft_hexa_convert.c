/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexa_convert.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsan <nsan@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 19:25:32 by nsan              #+#    #+#             */
/*   Updated: 2024/06/24 21:33:31 by nsan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*ft_hexa_conversion(char *dest, unsigned long long hex, \
								int str_len, int case_flag)
{
	unsigned int	remainder;
	char			*str;

	if (case_flag)
		str = "abcdef";
	else
		str = "ABCDEF";
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

void	ft_num_hexa(unsigned long long hex, int *len, int case_flag)
{
	char				*dest;
	int					str_len;
	unsigned long long	h;
	char				*final;

	h = hex;
	str_len = 0;
	if (hex == 0)
	{
		*len += write(1, "0", 1);
		return ;
	}
	while (h != 0)
	{
		str_len++;
		h = h / 16;
	}
	dest = malloc(sizeof(char) * str_len + 1);
	dest[str_len] = '\0';
	final = ft_hexa_conversion(dest, hex, str_len, case_flag);
	ft_string(dest, len);
	free(dest);
}

void	ft_pointer(void *ptr, int *len)
{	
	if (!ptr)
	{
		*len += write(1, "(nil)", 5);
		return ;
	}
	(*len) += write(1, "0x", 2);
	ft_num_hexa((unsigned long long)ptr, len, 1);
}
