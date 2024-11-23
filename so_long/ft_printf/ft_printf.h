/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsan <nsan@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/15 17:04:06 by nsan              #+#    #+#             */
/*   Updated: 2024/06/24 19:46:55 by nsan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>
# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>

int		ft_printf(const char *str, ...);
void	ft_string(char *str, int *len);
void	ft_char_nlen(int c, int *len);
void	ft_digit(int num, int *len);
void	ft_pointer(void *ptr, int *len);
void	ft_unsigned_dec(unsigned int dec, int *len);
void	ft_num_hexa(unsigned long long hex, int *len, int upper);
void	ft_putstr_fd(char *s, int fd);

#endif