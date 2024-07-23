/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsan <nsan@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/15 17:04:06 by nsan              #+#    #+#             */
/*   Updated: 2024/06/22 19:15:57 by nsan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>

#ifndef FT_PRINT_H
#define FT_PRINT_H

int ft_printf(const char *str, ...);
void ft_string(char *str, int *len);
void ft_char_nlen(int c, int *len);
void ft_digit(int num, int *len);
void    ft_pointer(unsigned int ptr, int *len);
void    ft_unsigned_dec(unsigned int dec, int *len);
void    ft_num_hexa(unsigned int hex, int *len, int upper);

#endif