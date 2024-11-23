/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_number.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsan <nsan@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 16:04:51 by nsan              #+#    #+#             */
/*   Updated: 2024/06/24 21:28:44 by nsan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_digit(int num, int *len)
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
		ft_char_nlen((n + '0'), len);
}

void	ft_unsigned_dec(unsigned int dec, int *len)
{
	if (dec >= 10)
		ft_unsigned_dec ((dec / 10), len);
	ft_char_nlen ((dec % 10) + '0', len);
}
